#include <iostream>
#include <string>
#include <initializer_list>
#include "Node.h"
#include <sstream>

namespace mynamespace
{
    template <typename T>
    class CircularLinkedList;

    /**
    * @brief Перегруженный оператор вывода в поток.
    * @param os Поток вывода.
    * @param list Циклический связный список.
    * @return Ссылка на поток вывода.
    */
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& list);

    /**
    * @brief Перегруженный оператор ввода из потока.
    *
    * @param is Поток ввода.
    * @param list Циклический связный список.
    * @return Ссылка на поток ввода.
    */
    template <typename T>
    std::istream& operator>>(std::istream& is, CircularLinkedList<T>& list);

    /**
    * @brief Класс, представляющий циклический связный список.
    * Этот класс реализует циклический связный список, где последний элемент списка связан с первым.
    * Он предоставляет методы для добавления элементов, проверки пустоты списка, преобразования списка в строку и перегрузки операторов
    * присваивания, вставки и извлечения элементов.
    * @tparam T Тип элементов, хранящихся в списке.
    */
    template<typename T>
    class CircularLinkedList final
    {
    private:
        /**
        * @brief Указатель на последний элемент списка.
        * Используется для облегчения операций вставки.
        */
        Node<T>* tail;
        /**
        * @brief Указатель на первый элемент списка.
        */
        Node<T>* head;
    public:
        /**
        * @brief Конструктор по умолчанию.
        * Инициализирует пустой циклический список.
        */
        CircularLinkedList();

        /**
        * @brief Конструктор копирования.
        * Инициализирует новый список как копию другого списка.
        * @param other Другой список для копирования.
        */
        CircularLinkedList(const CircularLinkedList<T>& other);

        /**
        * @brief Перегруженный оператор присваивания.
        * Копирует значения из другого списка в текущий.
        * @param other Другой список для копирования.
        * @return Ссылка на текущий список.
        */
        CircularLinkedList<T>& operator=(const CircularLinkedList<T>& other);

        /**
        * @brief Конструктор инициализации.
        * Инициализирует циклический список с помощью списка инициализации.
        * @param init Список значений для элементов списка.
        */
        CircularLinkedList(std::initializer_list<T> init);

        /**
        * @brief Деструктор.
        * Освобождает память, занимаемую узлами списка.
        */
        ~CircularLinkedList();

        /**
        * @brief Добавляет новый элемент в конец списка.
        * @param value Значение нового элемента.
        */
        void add(T value);

        /**
        * @brief Проверяет, является ли список пустым.
        * @return true, если список пуст, иначе false.
        */
        bool isEmpty() const;

        /**
        * @brief Преобразует список в строку.
        * Преобразует элементы списка в строку с их значениями, разделёнными пробелами.
        * @return Строковое представление списка.
        */
        std::string toString() const;

        /**
        * @brief Конструктор перемещения.
        * Перемещает данные из другого списка в текущий.
        * @param other Список для перемещения.
        */
        CircularLinkedList(CircularLinkedList<T>&& other) noexcept;

        /**
        * @brief Оператор перемещения.
        * Перемещает данные из другого списка в текущий.
        * @param other Список для перемещения.
        * @return Ссылка на текущий список.
        */
        CircularLinkedList<T>& operator=(CircularLinkedList<T>&& other) noexcept;
    };

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList() : head{ nullptr }, tail(nullptr) {}

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList(std::initializer_list<T> init) : CircularLinkedList()
    {
        for (const auto& value : init)
        {
            add(value);
        }
    }

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& other) : CircularLinkedList()
    {
        if (other.tail)
        {
            Node<T>* current = other.tail->next;
            do {
                add(current->data);
                current = current->next;
            } while (current != other.tail->next);
        }
    }

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList(CircularLinkedList<T>&& other) noexcept : head(other.head), tail(other.tail)
    {
        other.head = other.tail = nullptr;
    }

    template<typename T>
    CircularLinkedList<T>::~CircularLinkedList()
    {
        if (head)
        {
            Node<T>* current = head;
            Node<T>* nextNode;
            do {
                nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
    }

    template<typename T>
    CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& other)
    {
        if (this != &other) {
            this->~CircularLinkedList();

            if (other.tail)
            {
                Node<T>* current = other.tail->next;
                do {
                    add(current->data);
                    current = current->next;
                } while (current != other.tail->next);
            }
        }
        return *this;
    }

    template<typename T>
    bool CircularLinkedList<T>::isEmpty() const
    {
        return tail == nullptr;
    }

    template<typename T>
    std::string CircularLinkedList<T>::toString() const
    {
        std::stringstream buffer;

        if (isEmpty()) {
            return "[]";
        }

        buffer << "[";
        Node<T>* current = tail->next;

        do {
            buffer << current->data;
            current = current->next;

            if (current != tail->next) {
                buffer << " ";
            }
        } while (current != tail->next);

        buffer << "]";
        return buffer.str();
    }

    template<typename T>
    CircularLinkedList<T>& CircularLinkedList<T>::operator=(CircularLinkedList<T>&& other) noexcept
    {
        if (this != &other)
        {
            this->~CircularLinkedList();
            head = other.head;
            tail = other.tail;
            other.head = other.tail = nullptr;
        }
        return *this;
    }
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& list)
    {
        os << list.toString();
        return os;
    }

    template<typename T>
    std::istream& operator>>(std::istream& is, CircularLinkedList<T>& list)
    {
        T value;
        while (is >> value) {
            list.add(value);
        }
        return is;
    }

    template<typename T>
    void CircularLinkedList<T>::add(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
}