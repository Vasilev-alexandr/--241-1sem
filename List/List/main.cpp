#include <iostream>
#include "..//Solver/CircularLinkedList.h"

using namespace mynamespace;

int main()
{
    std::setlocale(NULL, "ru_RU.UTF-8");

    mynamespace::CircularLinkedList<int> list = { 1, 2, 3, 4 };

    std::cout << "»сходный список: " << list.toString() << std::endl;

    std::cout << "¬ведите числа дл¤ добавлени¤ (закончите ввод нечисловым символом): ";
    std::cin >> list;

    std::cout << "—писок после добавлени¤: " << list.toString() << std::endl;

    std::cout << "¬ведите число дл¤ удалени¤: ";

    int valueToRemove;

    std::cin >> valueToRemove;

    list.remove(valueToRemove);

    std::cout << "—писок после удалени¤: " << list.toString() << std::endl;

    std::cout << "¬ведите число дл¤ вставки: ";

    int valueToInsert;
    std::cin >> valueToInsert;

    std::cout << "¬ведите число после которого вставл¤ть: ";
    int valueToInsertAfter;

    std::cin >> valueToInsertAfter;

    list.insertAfter(valueToInsertAfter, valueToInsert);

    std::cout << "—писок после вставки: " << list.toString() << std::endl;

    std::cout << "¬ведите число, после которого удалить: ";
    int valueToRemoveAfter;


    std::cin >> valueToRemoveAfter;

    list.removeAfter(valueToRemoveAfter);

    std::cout << "—писок после удалени¤ после: " << list.toString() << std::endl;

    std::cout << "¬ведите число дл¤ поиска: ";

    int valueToFind;

    std::cin >> valueToFind;

    if (list.find(valueToFind))
    {
        std::cout << "„исло найдено в списке." << std::endl;
    }
    else
    {
        std::cout << "„исло не найдено в списке." << std::endl;
    }

    return 0;
}