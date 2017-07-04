#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

llist_entry* llist_entry_init() {
  llist_entry* e = malloc(sizeof(llist_entry));
  e->val = 0;
  e->next = NULL;
  return e;
}

void llist_entry_destroy(llist_entry* e) {
  free(e);
}

llist* llist_init() {
  llist* l = malloc(sizeof(llist));
  l->size = 0;
  l->start = NULL;
  return l;
}

void llist_destroy(llist* l) {
  llist_entry* prev_entry;
  llist_entry* entry = l->start;

  while (entry != NULL) {
    prev_entry = entry;
    entry = entry->next;
    llist_entry_destroy(prev_entry);
  }

  free(l);
}

bool llist_is_empty(llist* l) {
  return true;
}

int llist_size(llist* l) {
  return -1;
}

void llist_add(llist* l, int val) {
}

bool llist_contains(llist* l, int val) {
  return false;
}

int llist_get(llist* l, int index) {
  return -1;
}

bool llist_remove(llist* l, int index) {
  return false;
}

void llist_to_string(llist* l, char* buf) {
}
