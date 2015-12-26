#ifndef __KALLSYMSPRINT_H__
#define __KALLSYMSPRINT_H__

#include <stdbool.h>
#include <stdio.h>

typedef struct _kallsyms kallsyms;

kallsyms *     kallsyms_in_memory_init          (unsigned long *mem, size_t len, int is64bit);
void           kallsyms_in_memory_free          (kallsyms *kallsyms);
unsigned long  kallsyms_in_memory_lookup_name   (kallsyms *kallsyms, const char *name, int is64bit);
bool           kallsyms_in_memory_lookup_names  (kallsyms *kallsyms, const char *name,
                                                 unsigned long *addresses, size_t n_addresses, int is64bit);
const char    *kallsyms_in_memory_lookup_address(kallsyms *kallsyms, unsigned long address, int is64bit);

bool is_address_in_kallsyms_table(kallsyms *kallsyms, void *mapped_address);

void kallsyms_in_memory_set_verbose(bool verbose);
void kallsyms_in_memory_print_all(kallsyms *kallsyms, int is64bit);
void kallsyms_in_memory_print_all_to_file(kallsyms *kallsyms, FILE *fp, int is64bit);

#endif /* __KALLSYMSPRINT_H__ */

/*
 vi:ts=2:nowrap:ai:expandtab:sw=2
 */
