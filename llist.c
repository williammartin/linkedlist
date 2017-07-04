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
  return l->size == 0;
}

int llist_size(llist* l) {
  return l->size;
}

llist_entry* __get_last(llist* l) {
  llist_entry* last = l->start;
  while (last->next != NULL) {
    last = last->next;
  }

  return last;
}

void llist_add(llist* l, int val) {
  llist_entry* new_entry = llist_entry_init();
  new_entry->val = val;

  if (l->start == NULL) {
    l->start = new_entry;
    l->size++;
    return;
  }

  llist_entry* last = __get_last(l);
  last->next = new_entry;
  l->size++;
}

bool llist_contains(llist* l, int val) {
  llist_entry* entry = l->start;
  while (entry != NULL) {
    if (entry->val == val) {
      return true;
    }
    entry = entry->next;
  }
  return false;
}

llist_entry* __get_entry(llist* l, int index) {
  int i = 0;
  llist_entry* entry = l->start;
  while (i < index) {
    entry = entry->next;
    i++;
  }

  return entry;
}

int llist_get(llist* l, int index) {
  llist_entry* entry = __get_entry(l, index);
  return entry->val;
}

bool llist_remove(llist* l, int index) {
  if (index < 0 || index >= llist_size(l)) {
    return false;
  }

  llist_entry* entry = __get_entry(l, index);
  if (index > 0) {
    llist_entry* prev_entry = __get_entry(l, index - 1);
    prev_entry->next = entry->next;
  } else {
    l->start = entry->next;
  }
  llist_entry_destroy(entry);

  return true;
}

void llist_to_string(llist* l, char* buf) {
  int next_char_idx = 0;

  // Head
  next_char_idx = sprintf(buf, "[");

  // Entries
  llist_entry* entry = l->start;
  while (entry != NULL) {
    next_char_idx += sprintf(&(buf[next_char_idx]), "%d, ", entry->val);
    entry = entry->next;
  }
  buf[next_char_idx-2] = ']';
  buf[next_char_idx-1] = '\0';
}
