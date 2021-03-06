// This file has been automatically generated by gen_deployment.
// Do not make manual modifications there or they will be lost.

#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#define POK_CONFIG_NB_PARTITIONS 2
#define POK_CONFIG_NB_PROCESSORS 1
#define POK_CONFIG_NB_THREADS 8
#define POK_CONFIG_PARTITIONS_NLOCKOBJECTS                                     \
  { 0, 0 }
#define POK_CONFIG_PARTITIONS_NTHREADS                                         \
  { 3, 3 }
#define POK_CONFIG_PARTITIONS_SIZE                                             \
  { 122880, 122880 }
#define POK_CONFIG_PROCESSOR_AFFINITY                                          \
  { 1, 1 }
#define POK_CONFIG_PROGRAM_NAME                                                \
  { "pr1/pr1.elf", "pr2/pr2.elf" }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 20000000
#define POK_CONFIG_SCHEDULING_NBSLOTS 2
#define POK_CONFIG_SCHEDULING_SLOTS                                            \
  { 10000000, 10000000 }
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION                                 \
  { 0, 1 }

#define POK_NEEDS_ASSERT 1
#define POK_NEEDS_CONSOLE 1
#define POK_NEEDS_SHUTDOWN 1

typedef enum {
  pok_part_identifier_pr1 = 0,
  pok_part_identifier_pr2 = 1
} pok_part_identifiers_t;

typedef enum { pok_part_id_pr1 = 0, pok_part_id_pr2 = 1 } pok_part_id_t;

typedef enum { pok_nodes_node1 = 0 } pok_node_id_t;

#endif // __POK_KERNEL_GENERATED_DEPLOYMENT_H_
