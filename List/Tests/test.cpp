#include <gtest/gtest.h>
#include "..//Solver/CircularLinkedList.h"

namespace mynamespace {

    class CircularLinkedListTest : public ::testing::Test {
    protected:
        CircularLinkedList<int> list;

        void SetUp() override {
        }

        void TearDown() override {
        }
    };

    TEST_F(CircularLinkedListTest, InitiallyEmpty) {
        EXPECT_TRUE(list.isEmpty());
    }

    TEST_F(CircularLinkedListTest, AddElements) {
        list.add(1);
        list.add(2);
        list.add(3);

        EXPECT_FALSE(list.isEmpty());
        EXPECT_EQ(list.toString(), "[1 2 3]");
    }

    TEST_F(CircularLinkedListTest, CopyConstructor) {
        list.add(1);
        list.add(2);
        list.add(3);

        CircularLinkedList<int> copy(list);
        EXPECT_EQ(copy.toString(), "[1 2 3]");
    }

    TEST_F(CircularLinkedListTest, AssignmentOperator) {
        list.add(1);
        list.add(2);

        CircularLinkedList<int> copy;
        copy = list;

        EXPECT_EQ(copy.toString(), "[1 2]");
    }

    TEST_F(CircularLinkedListTest, MoveConstructor) {
        list.add(1);
        list.add(2);

        CircularLinkedList<int> moved = std::move(list);
        EXPECT_EQ(moved.toString(), "[1 2]");
        EXPECT_TRUE(list.isEmpty());
    }

    TEST_F(CircularLinkedListTest, MoveAssignmentOperator) {
        list.add(1);
        list.add(2);

        CircularLinkedList<int> moved;
        moved = std::move(list);

        EXPECT_EQ(moved.toString(), "[1 2]");
        EXPECT_TRUE(list.isEmpty());
    }

    TEST_F(CircularLinkedListTest, HandleMultipleInsertions) {
        for (int i = 1; i <= 5; ++i) {
            list.add(i);
        }

        EXPECT_EQ(list.toString(), "[1 2 3 4 5]");
    }

    TEST_F(CircularLinkedListTest, DestructorEmptiesList) {
        {
            CircularLinkedList<int> tempList;
            tempList.add(1);
            tempList.add(2);
            tempList.add(3);
        }
    }

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}