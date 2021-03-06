#include "activity.h"
#include "deployment.h"
#include <assert.h>
#include <core/event.h>
#include <core/partition.h>
#include <core/thread.h>
#include <core/time.h>
#include <types.h>

/*****************************************************/
/*  This file was automatically generated by Ocarina */
/*  Do NOT hand-modify this file, as your            */
/*  changes will be lost when you re-run Ocarina     */
/*****************************************************/
#define POK_CONFIG_NB_THREADS 3
pok_event_id_t input_id;
uint32_t pok_threads[POK_CONFIG_NB_THREADS];
int main(void) {

  pok_thread_attr_t tattr;
  pok_ret_t ret;
  ret = pok_thread_attr_init(&(tattr));
  assert(!ret);
  tattr.entry = thr1_job;
  tattr.deadline = pok_time_milliseconds(1000);
  tattr.period = pok_time_milliseconds(1000);
  tattr.stack_size = 4096;
  tattr.time_capacity = 1;
  ret = pok_thread_create(&(pok_threads[1]), &(tattr));
  assert(!ret);
  /*  This thread was mapped from a thread component containedin this */
  /*  process. The function it executes is also generatedin the file */
  /*  activity.c.*/
  ret = pok_event_create(&(input_id));
  assert(!ret);
  ret = pok_thread_attr_init(&(tattr));
  assert(!ret);
  tattr.entry = thr2_job;
  tattr.deadline = pok_time_milliseconds(1000);
  tattr.period = pok_time_milliseconds(1000);
  tattr.stack_size = 4096;
  tattr.time_capacity = 2;
  ret = pok_thread_create(&(pok_threads[2]), &(tattr));
  assert(!ret);
  /*  This thread was mapped from a thread component containedin this */
  /*  process. The function it executes is also generatedin the file */
  /*  activity.c.*/
  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  /*  Now, we created all resources of the process. Consequently,this thread */
  /*  will not be used any more and it will be keptin a dormant state. By */
  /*  doing that, we also allow one morethread in this partition*/
  return (0);
}
