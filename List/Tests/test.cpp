#include <gtest/gtest.h>
#include "..//Solver/CircularLinkedList.h"

TEST(CircularLinkedListTest, DefaultConstructor) {
    CircularLinkedList list{};
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.toString(), "[]");
}

TEST(CircularLinkedListTest, AddSingleElement) {
    CircularLinkedList list{ 10 };
    list.add(10);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.toString(), "[10]");
}

TEST(CircularLinkedListTest, AddMultipleElements) {
    CircularLinkedList list{ 10,20,30 };
    list.add(10);
    list.add(20);
    list.add(30);

    EXPECT_EQ(list.toString(), "[10 20 30]");
}

TEST(CircularLinkedListTest, CopyConstructor) {
    CircularLinkedList original{ 10, 20 };
    original.add(10);
    original.add(20);

    CircularLinkedList copy(original);

    EXPECT_EQ(copy.toString(), "[10 20]");
    EXPECT_FALSE(copy.isEmpty());
}

TEST(CircularLinkedListTest, CopyAssignmentOperator) {
    CircularLinkedList original{ 10, 20 };
    original.add(10);
    original.add(20);

    CircularLinkedList copy{ 1, 2, 3 };
    copy = original;

    EXPECT_EQ(copy.toString(), "[10 20]");
    EXPECT_FALSE(copy.isEmpty());
}

TEST(CircularLinkedListTest, MoveConstructor) {
    CircularLinkedList original{ 10, 20 };
    original.add(10);
    original.add(20);

    CircularLinkedList moved(std::move(original));

    EXPECT_EQ(moved.toString(), "[10 20]");
    EXPECT_TRUE(original.isEmpty());
}

TEST(CircularLinkedListTest, MoveAssignmentOperator) {
    CircularLinkedList original{ 10, 20 };
    original.add(10);
    original.add(20);

    CircularLinkedList moved;
    moved = std::move(original);

    EXPECT_EQ(moved.toString(), "[10 20]");
    EXPECT_TRUE(original.isEmpty());
}

TEST(CircularLinkedListTest, InputOperator) {
    CircularLinkedList list{};
    std::istringstream input("15");
    input >> list;

    EXPECT_EQ(list.toString(), "[15]");
}

TEST(CircularLinkedListTest, OutputOperator) {
    CircularLinkedList list{ 10, 20 };
    list.add(10);
    list.add(20);

    std::ostringstream output;
    output << list;

    EXPECT_EQ(output.str(), "[10 20]");
}

