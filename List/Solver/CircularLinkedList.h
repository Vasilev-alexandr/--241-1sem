#include <initializer_list>
#include <iostream>
#include <sstream>
#include "Node.h"

namespace mynamespace
{
    /*
    *@brief  класс, представл¤ющий циклический связный список.
    *@tparam Tип данных, хранимых в списке.
    */

    template <typename T>
    class CircularLinkedList;

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& list);

    template <typename T>
    std::istream& operator>>(std::istream& is, CircularLinkedList<T>& list);

    template <typename T>
    class CircularLinkedList
    {
    private:
        Node<T>* tail;
        Node<T>* head;

    public:
        CircularLinkedList();
        CircularLinkedList(const CircularLinkedList& other);
        CircularLinkedList& operator=(const CircularLinkedList& other);
        CircularLinkedList(std::initializer_list<T> init);
        ~CircularLinkedList();

        void add(T value);
        bool isEmpty() const;
        std::string toString() const;

        CircularLinkedList(CircularLinkedList&& other) noexcept;
        CircularLinkedList& operator=(CircularLinkedList&& other) noexcept;
    };
    template<typename T>
    CircularLinkedList<T>::CircularLinkedList() : head(nullptr), tail(nullptr) {}

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList& other)
    {
        head = tail = nullptr;
        Node* current = other.head;
        if (current != nullptr)
        {
            do {
                add(current->data);
                current = current->next;
            } while (current != other.head);
        }
    }

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList(std::initializer_list<T> init) : tail(nullptr)
    {
        for (int value : init)
        {
            add(value);
        }
    }

    template<typename T>
    CircularLinkedList<T>::~CircularLinkedList()
    {
        Node* current = head;
        Node* nextNode;
        while (current != tail && current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    template<typename T>
    void CircularLinkedList<T>::add(T value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

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

        if (tail == nullptr) {
            return "[]";
        }

        buffer << "[";
        Node* current = tail->next;

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
    CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList& other)
    {
        if (this != &other) {
            Node* current = head;
            while (current != nullptr && current != tail) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = tail = nullptr;

            current = other.head;
            if (current != nullptr) {
                do {
                    add(current->data);
                    current = current->next;
                } while (current != other.head);
            }
        }
        return *this;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, CircularLinkedList<T>& list)
    {
        os << list.toString();
        return os;
    }

    template<typename T>
    std::istream& operator>>(std::istream& is, CircularLinkedList<T>& list)

    {
        int value;
        while (is >> value) {
            list.add(value);
        }
        return is;
    }

    template<typename T>
    CircularLinkedList<T>::CircularLinkedList(CircularLinkedList<T>&& other) noexcept : head(other.head), tail(other.tail)
    {
        other.head = other.tail = nullptr;
    }

    template<typename T>
    CircularLinkedList<T>& CircularLinkedList<T>::operator=(CircularLinkedList<T>&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        head = other.head;
        tail = other.tail;
        other.head = other.tail = nullptr;

        return *this;
    }
}