#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "merge_lists.h"

using namespace std;

TEST_CASE("A sorted linked list can be merged into another sorted linked list (empty)")
{
    DLinkedList<int> list;
    DLinkedList<int> other;
    list.addSorted(other);
    REQUIRE(list.empty());
}

TEST_CASE("A sorted linked list can be merged into another sorted linked list (this empty)")
{
    DLinkedList<int> list;
    DLinkedList<int> other;
    other.addBack(1);
    other.addBack(2);
    list.addSorted(other);
    REQUIRE_FALSE(list.empty());
    REQUIRE(list.front() == 1);
    list.removeFront();
    REQUIRE(list.front() == 2);
    list.removeFront();
    REQUIRE(list.empty());
}

TEST_CASE("A sorted linked list can be merged into another sorted linked list (interleaved, this first)")
{
    DLinkedList<int> listA;
    listA.addBack(1);
    listA.addBack(3);
    listA.addBack(5);
    DLinkedList<int> listB;
    listB.addBack(2);
    listB.addBack(4);
    listB.addBack(6);
    listA.addSorted(listB);
    REQUIRE(listA.front() == 1);
    listA.removeFront();
    REQUIRE(listA.front() == 2);
    listA.removeFront();
    REQUIRE(listA.front() == 3);
    listA.removeFront();
    REQUIRE(listA.front() == 4);
    listA.removeFront();
    REQUIRE(listA.front() == 5);
    listA.removeFront();
    REQUIRE(listA.front() == 6);
    listA.removeFront();
    REQUIRE(listA.empty());
}

TEST_CASE("A sorted linked list can be merged into another sorted linked list (interleaved, other first)")
{
    DLinkedList<int> listA;
    listA.addBack(2);
    listA.addBack(4);
    listA.addBack(6);
    DLinkedList<int> listB;
    listB.addBack(1);
    listB.addBack(3);
    listB.addBack(5);
    listA.addSorted(listB);
    REQUIRE(listA.front() == 1);
    listA.removeFront();
    REQUIRE(listA.front() == 2);
    listA.removeFront();
    REQUIRE(listA.front() == 3);
    listA.removeFront();
    REQUIRE(listA.front() == 4);
    listA.removeFront();
    REQUIRE(listA.front() == 5);
    listA.removeFront();
    REQUIRE(listA.front() == 6);
    listA.removeFront();
    REQUIRE(listA.empty());
}

TEST_CASE("A sorted linked list can be merged into another sorted linked list (disjoint)")
{
    DLinkedList<int> listA;
    listA.addBack(1);
    listA.addBack(2);
    listA.addBack(3);
    DLinkedList<int> listB;
    listB.addBack(4);
    listB.addBack(5);
    listB.addBack(6);
    listA.addSorted(listB);
    REQUIRE(listA.front() == 1);
    listA.removeFront();
    REQUIRE(listA.front() == 2);
    listA.removeFront();
    REQUIRE(listA.front() == 3);
    listA.removeFront();
    REQUIRE(listA.front() == 4);
    listA.removeFront();
    REQUIRE(listA.front() == 5);
    listA.removeFront();
    REQUIRE(listA.front() == 6);
    listA.removeFront();
    REQUIRE(listA.empty());
}
