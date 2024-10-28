#include "..//Solver/CircularLinkedList.h"
#include <utility>

CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr) {}

CircularLinkedList::CircularLinkedList(const CircularLinkedList& other)
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

CircularLinkedList::CircularLinkedList(std::initializer_list<int> init) : tail(nullptr)
{
    for (int value : init)
    {
        add(value);
    }
}

CircularLinkedList::~CircularLinkedList()
{
    Node* current = head;
    Node* nextNode;
    while (current != tail && current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void CircularLinkedList::add(int value)
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

bool CircularLinkedList::isEmpty() const
{
    return tail == nullptr;
}

std::string CircularLinkedList::toString() const
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

CircularLinkedList& CircularLinkedList::operator=(const CircularLinkedList& other)
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

std::ostream& operator<<(std::ostream& os, CircularLinkedList& list)
{
    os << list.toString();
    return os;
}

std::istream& operator>>(std::istream& is, CircularLinkedList& list)

{
    int value;
    while (is >> value) {
        list.add(value);
    }
    return is;
}


CircularLinkedList::CircularLinkedList(CircularLinkedList&& other) noexcept : head(other.head), tail(other.tail)
{
    other.head = other.tail = nullptr;
}


CircularLinkedList& CircularLinkedList::operator=(CircularLinkedList&& other) noexcept
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