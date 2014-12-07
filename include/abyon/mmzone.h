/*
 * include/abyon/mmzone.h
 * Copyright (C) <2014>  <@RKX1209>
 */
#ifndef _ABYON_MMZONE_H
#define _ABYON_MMZONE_H

struct bootmem_data;

typedef struct pglist_data{
struct bootmem_data *bdata; /* Boot allocator*/
struct pglist_data *pgdat_next;
}pg_data_t;
extern struct pglist_data *pgdat_list;

struct pglist_data node_data[1]; /* numbef of NUMA node is one */
#define NODE_DATA(nid)	(&node_data[nid])

#endif