#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cspecs/cspec.h>
#include "llist.h"

context (llist) {
  describe("Linked List") {
    llist* l;

    before {
      l = llist_init();
    } end

    after {
      llist_destroy(l);
    } end

    describe("Emptiness") {
      it("initialises as empty") {
        should_bool(llist_is_empty(l)) be equal to(true);
      } end

      skip("is not empty after adding an element") {
        llist_add(l, 1);
        should_bool(llist_is_empty(l)) be equal to(false);
      } end
    } end

    describe("Size") {
      skip("initialises with size of zero") {
        should_int(llist_size(l)) be equal to(0);
      } end

      skip("has a size of one after adding an element") {
        llist_add(l, 1);
        should_int(llist_size(l)) be equal to(1);
      } end

      skip("has a size of two after adding two elements") {
        llist_add(l, 1);
        llist_add(l, 4);
        should_int(llist_size(l)) be equal to(2);
      } end
    } end

    describe("Containment") {
      skip("does not contain an element that hasn't been added") {
        should_bool(llist_contains(l, 1)) be equal to(false);
      } end

      skip("contains an element that has been added") {
        llist_add(l, 1);
        should_bool(llist_contains(l, 1)) be equal to(true);
      } end

      skip("contains multiple elements that have been added") {
        llist_add(l, 1);
        llist_add(l, 4);
        should_bool(llist_contains(l, 1)) be equal to(true);
        should_bool(llist_contains(l, 4)) be equal to(true);
      } end
    } end

    describe("Getting") {
      skip("gets the first element at index zero") {
        llist_add(l, 5);
        should_int(llist_get(l, 0)) be equal to(5);
      } end

      skip("gets other elements by their indexes") {
        llist_add(l, 100);
        llist_add(l, 200);
        llist_add(l, 300);
        should_int(llist_get(l, 1)) be equal to(200);
        should_int(llist_get(l, 2)) be equal to(300);
      } end
    } end

    describe("Removal") {
      skip("removes the first element successfully") {
        llist_add(l, 100);
        llist_add(l, 200);
        llist_add(l, 300);
        llist_remove(l, 0);
        should_bool(llist_contains(l, 100)) be equal to (false);
        should_bool(llist_contains(l, 200)) be equal to (true);
        should_bool(llist_contains(l, 300)) be equal to (true);
      } end

      skip("removes the last element successfully") {
        llist_add(l, 100);
        llist_add(l, 200);
        llist_add(l, 300);
        llist_remove(l, 2);
        should_bool(llist_contains(l, 100)) be equal to (true);
        should_bool(llist_contains(l, 200)) be equal to (true);
        should_bool(llist_contains(l, 300)) be equal to (false);
      } end

      skip("removes the middle element successfully") {
        llist_add(l, 100);
        llist_add(l, 200);
        llist_add(l, 300);
        llist_remove(l, 1);
        should_bool(llist_contains(l, 100)) be equal to (true);
        should_bool(llist_contains(l, 200)) be equal to (false);
        should_bool(llist_contains(l, 300)) be equal to (true);
      } end

      skip("returns true when removal succeeds") {
        llist_add(l, 100);
        should_bool(llist_remove(l, 0)) be equal to(true);
      } end

      skip("returns false when removing a non-existent element") {
        should_bool(llist_remove(l, 0)) be equal to(false);
      } end
    } end

    describe("Stringifying") {
      skip("converts the list to a string") {
        llist_add(l, 100);
        llist_add(l, 200);
        llist_add(l, 300);
        char buf[2048];
        llist_to_string(l, buf);
        should_string(buf) be equal to("[100, 200, 300]");
      } end
    } end

    describe("Ordering") {
      skip("preserves ordering across modifcation operations") {
        llist_add(l, 100);
        llist_add(l, 200);
        llist_add(l, 300);
        char buf1[64];
        llist_to_string(l, buf1);
        should_string(buf1) be equal to("[100, 200, 300]");

        llist_remove(l, 1);
        char buf2[64];
        llist_to_string(l, buf2);
        should_string(buf2) be equal to("[100, 300]");

        llist_add(l, 400);
        char buf3[64];
        llist_to_string(l, buf3);
        should_string(buf3) be equal to("[100, 300, 400]");
      } end
    } end
  } end
}
