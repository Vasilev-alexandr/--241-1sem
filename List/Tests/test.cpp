#include <gtest/gtest.h>
#include "..//Solver/CircularLinkedList.h"

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

TEST(CircularLinkedListTest, IntListIsEmpty) {
    mynamespace::CircularLinkedList<int> intList;
    ASSERT_TRUE(intList.isEmpty());
}

TEST(CircularLinkedListTest, IntListEmptyToString) {
    mynamespace::CircularLinkedList<int> intList;
    ASSERT_EQ(intList.toString(), "[]");
}

TEST(CircularLinkedListTest, StringListIsEmpty) {
    mynamespace::CircularLinkedList<std::string> strList;
    ASSERT_TRUE(strList.isEmpty());
}

TEST(CircularLinkedListTest, StringListEmptyToString) {
    mynamespace::CircularLinkedList<std::string> strList;
    ASSERT_EQ(strList.toString(), "[]");
}

TEST(CircularLinkedListTest, PointListIsEmpty) {
    mynamespace::CircularLinkedList<Point> pointList;
    ASSERT_TRUE(pointList.isEmpty());
}

TEST(CircularLinkedListTest, PointListEmptyToString) {
    mynamespace::CircularLinkedList<Point> pointList;
    ASSERT_EQ(pointList.toString(), "[]");
}

TEST(CircularLinkedListTest, AddIntElement) {
    mynamespace::CircularLinkedList<int> intList;
    intList.add(1);
    ASSERT_FALSE(intList.isEmpty());
}

TEST(CircularLinkedListTest, IntListToStringAfterAdd) {
    mynamespace::CircularLinkedList<int> intList;
    intList.add(1);
    ASSERT_EQ(intList.toString(), "[1]");
}

TEST(CircularLinkedListTest, AddStringElement) {
    mynamespace::CircularLinkedList<std::string> strList;
    strList.add("Hello");
    ASSERT_FALSE(strList.isEmpty());
}

TEST(CircularLinkedListTest, StringListToStringAfterAdd) {
    mynamespace::CircularLinkedList<std::string> strList;
    strList.add("Hello");
    ASSERT_EQ(strList.toString(), "[Hello]");
}

TEST(CircularLinkedListTest, AddPointElement) {
    mynamespace::CircularLinkedList<Point> pointList;
    pointList.add(Point(1, 2));
    ASSERT_FALSE(pointList.isEmpty());
}

TEST(CircularLinkedListTest, PointListToStringAfterAdd) {
    mynamespace::CircularLinkedList<Point> pointList;
    pointList.add(Point(1, 2));
    ASSERT_EQ(pointList.toString(), "[(1, 2)]");
}

TEST(CircularLinkedListTest, AddMultipleIntElements) {
    mynamespace::CircularLinkedList<int> intList;
    intList.add(1);
    intList.add(2);
    intList.add(3);
    ASSERT_EQ(intList.toString(), "[1 2 3]");
}

TEST(CircularLinkedListTest, AddMultipleStringElements) {
    mynamespace::CircularLinkedList<std::string> strList;
    strList.add("Hello");
    strList.add("World");
    strList.add("!");
    ASSERT_EQ(strList.toString(), "[Hello World !]");
}

TEST(CircularLinkedListTest, AddMultiplePointElements) {
    mynamespace::CircularLinkedList<Point> pointList;
    pointList.add(Point(1, 2));
    pointList.add(Point(3, 4));
    pointList.add(Point(5, 6));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, RemoveIntElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.remove(2);
    ASSERT_EQ(intList.toString(), "[1 3 4]");
}

TEST(CircularLinkedListTest, RemoveStringElement) {
    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.remove("World");
    ASSERT_EQ(strList.toString(), "[Hello !]");
}

TEST(CircularLinkedListTest, RemovePointElement) {
    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.remove(Point(3, 4));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (5, 6)]");
}

TEST(CircularLinkedListTest, RemoveNonExistingIntElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.remove(5);
    ASSERT_EQ(intList.toString(), "[1 2 3 4]");
}

TEST(CircularLinkedListTest, RemoveNonExistingStringElement) {
    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.remove("Goodbye");
    ASSERT_EQ(strList.toString(), "[Hello World !]");
}

TEST(CircularLinkedListTest, RemoveNonExistingPointElement) {
    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.remove(Point(7, 8));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, FindIntElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    ASSERT_TRUE(intList.find(3));
}

TEST(CircularLinkedListTest, FindStringElement) {
    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    ASSERT_TRUE(strList.find("World"));
}

TEST(CircularLinkedListTest, FindPointElement) {
    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    ASSERT_TRUE(pointList.find(Point(3, 4)));
}

TEST(CircularLinkedListTest, CopyConstructorInt) {
    mynamespace::CircularLinkedList<int> intList1 = { 1, 2, 3 };
    mynamespace::CircularLinkedList<int> intList2(intList1);
    ASSERT_EQ(intList2.toString(), "[1 2 3]");
}

TEST(CircularLinkedListTest, CopyConstructorString) {
    mynamespace::CircularLinkedList<std::string> strList1 = { "Hello", "World", "!" };
    mynamespace::CircularLinkedList<std::string> strList2(strList1);
    ASSERT_EQ(strList2.toString(), "[Hello World !]");
}

TEST(CircularLinkedListTest, CopyConstructorPoint) {
    mynamespace::CircularLinkedList<Point> pointList1 = { Point(1, 2), Point(3, 4), Point(5, 6) };
    mynamespace::CircularLinkedList<Point> pointList2(pointList1);
    ASSERT_EQ(pointList2.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, MoveConstructorInt) {
    mynamespace::CircularLinkedList<int> intList1 = { 1, 2, 3 };
    mynamespace::CircularLinkedList<int> intList2(std::move(intList1));
    ASSERT_EQ(intList2.toString(), "[1 2 3]");
    ASSERT_TRUE(intList1.isEmpty());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}