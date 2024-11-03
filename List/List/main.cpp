#include <iostream>
#include "..//Solver/CircularLinkedList.h"

using namespace mynamespace;

int main()
{
    std::setlocale(NULL, "ru_RU.UTF-8");

    mynamespace::CircularLinkedList<int> list = { 1, 2, 3, 4 };

    std::cout << "Initial list: " << list.toString() << std::endl;
    std::cout << "Enter numbers to add (end with non-numeric input): ";

    std::cin >> list;
    std::cout << "After adding: " << list.toString() << std::endl;

    mynamespace::CircularLinkedList<int> list2;
    list2 = list;
    std::cout << "Other list after assigning: " << list2 << std::endl;

    return 0;
}