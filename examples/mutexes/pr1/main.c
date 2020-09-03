/*
 *                               POK header
 *
 * The following file is a part of the POK project. Any modification should
 * be made according to the POK licence. You CANNOT use this file or a part
 * of a file for your own project.
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2020 POK team
 */

#include "activity.h"
#include <core/mutex.h>
#include <core/partition.h>
#include <core/thread.h>
#include <libc/stdio.h>
#include <types.h>

uint8_t mid;

int main() {
  uint32_t tid;
  pok_ret_t ret;
  pok_thread_attr_t tattr;

  tattr.priority = 42;
  tattr.entry = pinger_job;

  ret = pok_thread_create(&tid, &tattr);

  tattr.priority = 42;
  tattr.entry = pinger_job2;

  ret = pok_thread_create(&tid, &tattr);

  ret = pok_mutex_create(&mid, POK_QUEUEING_DISCIPLINE_DEFAULT,
                         POK_LOCKING_DISCIPLINE_DEFAULT);
  printf("pok_mutex_create return=%d, mid=%d\n", ret, mid);

  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite();

  return (0);
}
