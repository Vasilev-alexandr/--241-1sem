#include "..//Solver/CircularLinkedList.h"

using namespace mynamespace;
/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main()
{
    CircularLinkedList list = { 1, 2, 3, 4 };
    std::cout << "Initial list: " << list.toString() << std::endl;
    std::cin >> list;
    std::cout << "After adding 5: " << list.toString() << std::endl;
    CircularLinkedList list2;
    list2 = list;
    std::cout << "Other list after assigning" << list2 << std::endl;
    return 0;
}