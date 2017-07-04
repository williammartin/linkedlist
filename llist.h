#include <stdbool.h>

// Linked List Entry Definition
typedef struct __llist_entry {
  int val;
  struct __llist_entry* next;
} llist_entry;

llist_entry* llist_entry_init();

void llist_entry_destroy(llist_entry* l);

// Linked List Definition
typedef struct {
  int size;
  llist_entry* start;
} llist;

llist* llist_init();

void llist_destroy(llist* l);

bool llist_is_empty(llist* l);

int llist_size(llist* l);

void llist_add(llist* l, int val);

bool llist_contains(llist* l, int val);

int llist_get(llist* l, int index);

bool llist_remove(llist* l, int index);

// buffer overflow totes possible
void llist_to_string(llist* l, char* buf);
