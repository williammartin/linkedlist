# Linked List Exercise

In this repository you will find a `llist_test.c` file containing CSpec behavioural tests for a list of some kind (the tests don't really specify it's a linked list, so sue me) with the intention that you fill in the stubbed `llist.c` methods to make each test pass. I have left some filled in stubs for `init` and `destroy` for some structs to get you started, but you can totally ignore those if you like, the tests should be blackbox.

To get cspec and run the tests, in the parent folder to where you have cloned this linkedlist repo:

```
git clone https://github.com/mumuki/cspec.git
cd cspec
make
sudo make install
```

Then from the same parent folder:

```
cd linkedlist
gcc llist_test.c llist.c -o llist_test -lcspecs
./llist_test
```

I have skipped every test except the first one (which should pass due to its stubbed value). The tests are in the order I wrote them as I TDDed my linked list so as each one passes, you could change the next `skip` to `it` and continue. 

I won't guarantee the tests are an ideal linked list interface, but it's not bad.

Finally, in the initial commit of this project, you can see my implementation that satisfies the tests, in case you get stuck.

Good luck!
