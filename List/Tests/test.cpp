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

TEST(CircularLinkedListTest, EmptyList) {
    mynamespace::CircularLinkedList<int> intList;
    ASSERT_TRUE(intList.isEmpty());
    ASSERT_EQ(intList.toString(), "[]");

    mynamespace::CircularLinkedList<std::string> strList;
    ASSERT_TRUE(strList.isEmpty());
    ASSERT_EQ(strList.toString(), "[]");

    mynamespace::CircularLinkedList<Point> pointList;
    ASSERT_TRUE(pointList.isEmpty());
    ASSERT_EQ(pointList.toString(), "[]");
}

TEST(CircularLinkedListTest, AddElement) {
    mynamespace::CircularLinkedList<int> intList;
    intList.add(1);
    ASSERT_FALSE(intList.isEmpty());
    ASSERT_EQ(intList.toString(), "[1]");

    mynamespace::CircularLinkedList<std::string> strList;
    strList.add("Hello");
    ASSERT_FALSE(strList.isEmpty());
    ASSERT_EQ(strList.toString(), "[Hello]");

    mynamespace::CircularLinkedList<Point> pointList;
    pointList.add(Point(1, 2));
    ASSERT_FALSE(pointList.isEmpty());
    ASSERT_EQ(pointList.toString(), "[(1, 2)]");
}

TEST(CircularLinkedListTest, AddMultipleElements) {
    mynamespace::CircularLinkedList<int> intList;
    intList.add(1);
    intList.add(2);
    intList.add(3);
    ASSERT_EQ(intList.toString(), "[1 2 3]");

    mynamespace::CircularLinkedList<std::string> strList;
    strList.add("Hello");
    strList.add("World");
    strList.add("!");
    ASSERT_EQ(strList.toString(), "[Hello World !]");

    mynamespace::CircularLinkedList<Point> pointList;
    pointList.add(Point(1, 2));
    pointList.add(Point(3, 4));
    pointList.add(Point(5, 6));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, RemoveElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.remove(2);
    ASSERT_EQ(intList.toString(), "[1 3 4]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.remove("World");
    ASSERT_EQ(strList.toString(), "[Hello !]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.remove(Point(3, 4));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (5, 6)]");
}

TEST(CircularLinkedListTest, RemoveNonExistingElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.remove(5);
    ASSERT_EQ(intList.toString(), "[1 2 3 4]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.remove("Goodbye");
    ASSERT_EQ(strList.toString(), "[Hello World !]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.remove(Point(7, 8));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, RemoveOnlyElement) {
    mynamespace::CircularLinkedList<int> intList = { 1 };
    intList.remove(1);
    ASSERT_TRUE(intList.isEmpty());
    ASSERT_EQ(intList.toString(), "[]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello" };
    strList.remove("Hello");
    ASSERT_TRUE(strList.isEmpty());
    ASSERT_EQ(strList.toString(), "[]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2) };
    pointList.remove(Point(1, 2));
    ASSERT_TRUE(pointList.isEmpty());
    ASSERT_EQ(pointList.toString(), "[]");
}

TEST(CircularLinkedListTest, InsertAfterElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.insertAfter(2, 5);
    ASSERT_EQ(intList.toString(), "[1 2 5 3 4]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.insertAfter("World", "Goodbye");
    ASSERT_EQ(strList.toString(), "[Hello World Goodbye !]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.insertAfter(Point(3, 4), Point(7, 8));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (7, 8) (5, 6)]");
}

TEST(CircularLinkedListTest, InsertAfterLastElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.insertAfter(4, 5);
    ASSERT_EQ(intList.toString(), "[1 2 3 4 5]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.insertAfter("!", "Goodbye");
    ASSERT_EQ(strList.toString(), "[Hello World ! Goodbye]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.insertAfter(Point(5, 6), Point(7, 8));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (5, 6) (7, 8)]");
}

TEST(CircularLinkedListTest, RemoveAfterElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.removeAfter(2);
    ASSERT_EQ(intList.toString(), "[1 2 4]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.removeAfter("World");
    ASSERT_EQ(strList.toString(), "[Hello World]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.removeAfter(Point(3, 4));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4)]");
}

TEST(CircularLinkedListTest, RemoveAfterLastElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    intList.removeAfter(4);
    ASSERT_EQ(intList.toString(), "[1 2 3]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    strList.removeAfter("!");
    ASSERT_EQ(strList.toString(), "[Hello World]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    pointList.removeAfter(Point(5, 6));
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4)]");
}

TEST(CircularLinkedListTest, FindElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    ASSERT_TRUE(intList.find(3));

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    ASSERT_TRUE(strList.find("World"));

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    ASSERT_TRUE(pointList.find(Point(3, 4)));
}

TEST(CircularLinkedListTest, FindNonExistingElement) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3, 4 };
    ASSERT_FALSE(intList.find(5));

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    ASSERT_FALSE(strList.find("Goodbye"));

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    ASSERT_FALSE(pointList.find(Point(7, 8)));
}

TEST(CircularLinkedListTest, CopyConstructor) {
    mynamespace::CircularLinkedList<int> intList1 = { 1, 2, 3 };
    mynamespace::CircularLinkedList<int> intList2(intList1);
    ASSERT_EQ(intList2.toString(), "[1 2 3]");

    mynamespace::CircularLinkedList<std::string> strList1 = { "Hello", "World", "!" };
    mynamespace::CircularLinkedList<std::string> strList2(strList1);
    ASSERT_EQ(strList2.toString(), "[Hello World !]");

    mynamespace::CircularLinkedList<Point> pointList1 = { Point(1, 2), Point(3, 4), Point(5, 6) };
    mynamespace::CircularLinkedList<Point> pointList2(pointList1);
    ASSERT_EQ(pointList2.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, MoveConstructor) {
    mynamespace::CircularLinkedList<int> intList1 = { 1, 2, 3 };
    mynamespace::CircularLinkedList<int> intList2(std::move(intList1));
    ASSERT_EQ(intList2.toString(), "[1 2 3]");
    ASSERT_TRUE(intList1.isEmpty());
    ASSERT_EQ(intList1.toString(), "[]");

    mynamespace::CircularLinkedList<std::string> strList1 = { "Hello", "World", "!" };
    mynamespace::CircularLinkedList<std::string> strList2(std::move(strList1));
    ASSERT_EQ(strList2.toString(), "[Hello World !]");
    ASSERT_TRUE(strList1.isEmpty());
    ASSERT_EQ(strList1.toString(), "[]");

    mynamespace::CircularLinkedList<Point> pointList1 = { Point(1, 2), Point(3, 4), Point(5, 6) };
    mynamespace::CircularLinkedList<Point> pointList2(std::move(pointList1));
    ASSERT_EQ(pointList2.toString(), "[(1, 2) (3, 4) (5, 6)]");
    ASSERT_TRUE(pointList1.isEmpty());
    ASSERT_EQ(pointList1.toString(), "[]");
}

TEST(CircularLinkedListTest, CopyAssignment) {
    mynamespace::CircularLinkedList<int> intList1 = { 1, 2, 3 };
    mynamespace::CircularLinkedList<int> intList2 = { 4, 5, 6 };
    intList2 = intList1;
    ASSERT_EQ(intList2.toString(), "[1 2 3]");

    mynamespace::CircularLinkedList<std::string> strList1 = { "Hello", "World", "!" };
    mynamespace::CircularLinkedList<std::string> strList2 = { "Goodbye", "Universe" };
    strList2 = strList1;
    ASSERT_EQ(strList2.toString(), "[Hello World !]");

    mynamespace::CircularLinkedList<Point> pointList1 = { Point(1, 2), Point(3, 4), Point(5, 6) };
    mynamespace::CircularLinkedList<Point> pointList2 = { Point(7, 8), Point(9, 10) };
    pointList2 = pointList1;
    ASSERT_EQ(pointList2.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

TEST(CircularLinkedListTest, MoveAssignment) {
    mynamespace::CircularLinkedList<int> intList1 = { 1, 2, 3 };
    mynamespace::CircularLinkedList<int> intList2 = { 4, 5, 6 };
    intList2 = std::move(intList1);
    ASSERT_EQ(intList2.toString(), "[1 2 3]");
    ASSERT_TRUE(intList1.isEmpty());
    ASSERT_EQ(intList1.toString(), "[]");

    mynamespace::CircularLinkedList<std::string> strList1 = { "Hello", "World", "!" };
    mynamespace::CircularLinkedList<std::string> strList2 = { "Goodbye", "Universe" };
    strList2 = std::move(strList1);
    ASSERT_EQ(strList2.toString(), "[Hello World !]");
    ASSERT_TRUE(strList1.isEmpty());
    ASSERT_EQ(strList1.toString(), "[]");

    mynamespace::CircularLinkedList<Point> pointList1 = { Point(1, 2), Point(3, 4), Point(5, 6) };
    mynamespace::CircularLinkedList<Point> pointList2 = { Point(7, 8), Point(9, 10) };
    pointList2 = std::move(pointList1);
    ASSERT_EQ(pointList2.toString(), "[(1, 2) (3, 4) (5, 6)]");
    ASSERT_TRUE(pointList1.isEmpty());
    ASSERT_EQ(pointList1.toString(), "[]");
}

TEST(CircularLinkedListTest, InitializerListConstructor) {
    mynamespace::CircularLinkedList<int> intList = { 1, 2, 3 };
    ASSERT_EQ(intList.toString(), "[1 2 3]");

    mynamespace::CircularLinkedList<std::string> strList = { "Hello", "World", "!" };
    ASSERT_EQ(strList.toString(), "[Hello World !]");

    mynamespace::CircularLinkedList<Point> pointList = { Point(1, 2), Point(3, 4), Point(5, 6) };
    ASSERT_EQ(pointList.toString(), "[(1, 2) (3, 4) (5, 6)]");
}

int main(int argc, char** argv)
{
    ::testing::InitOpenAITest(&argc, argv);
    return RUN_ALL_TESTS();
}