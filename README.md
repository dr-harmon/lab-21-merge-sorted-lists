# Lab 21: Merge Sorted Lists

In this lab, we will start with a doubly-linked list class and add some enhancements to it:

* a print method
* a method to add elements from another list in sorted order

The provided `DLinkedList` class is identical to the one in the textbook.

## Part 1: Printing

Start by adding a `print` method to `DLinkedList`, as you will likely find it useful for debugging. Simply print all elements in the list from beginning to end to `cout`. The formatting is up to you, but it is probably easiest to put each element on a line by itself.

Be sure to test the `print` method from `main` before continuing.

## Part 2: Merging

Next, add a method called `addSorted`:

    void addSorted(const DLinkedList<E>& other) { ... }

This method will take as input another doubly-linked list and add all of its elements to the current one. You can assume that both lists are in sorted order, and all elements are unique. That is, if an element appears in one list, it is not in the other list, and vice versa.

In addition, the `addSorted` method must adhere to the following constraints:

* It must keep both lists in sorted order.
* It must run in `O(n)` time.
* It must use `O(1)` space.

Be sure to test your code with the provided unit tests.

Hint: When implementing and debugging this method, it helps to draw a picture!
