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
        void add(const T& value);

        /**
        * @brief Добавляет элемент в конец списка (перемещение).
        * @param value Значение, которое нужно добавить.
        */
        void add(T&& value);

        /**
        * @brief Удаляет элемент со значением value из списка.
        * @param value Значение, которое нужно удалить.
        */
        void remove(const T& value);

        /**
        * @brief Вставляет элемент newValue после элемента с значением targetValue.
        * @param targetValue Значение элемента, после которого нужно вставить.
        * @param newValue Значение, которое нужно вставить.
        */
        void insertAfter(const T& targetValue, const T& newValue);

        /**
        * @brief Удаляет элемент, следующий за элементом с значением targetValue.
        * @param targetValue Значение элемента, после которого нужно удалить.
        */
        void removeAfter(const T& targetValue);

        /**
        * @brief Проверяет наличие элемента со значением value в списке.
        * @param value Значение, которое нужно найти.
        * @return true, если элемент найден, иначе false.
        */
        bool find(const T& value) const;

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
        if (nullptr != other.tail)
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
    CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& other)
    {
        CircularLinkedList temp(other);
        std::swap(this->tail, temp.tail);
        std::swap(this->head, temp.head);
        return *this;
    }

    template <typename T>
    CircularLinkedList<T>::~CircularLinkedList() {
        if (head) {
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
    CircularLinkedList<T>& CircularLinkedList<T>::operator=(CircularLinkedList<T>&& other) noexcept
    {
        if (this != &other)
        {
            std::swap(this->head, other.head);
            std::swap(this->tail, other.tail);
        }
        return *this;
    }

    template<typename T>
    void CircularLinkedList<T>::add(const T& value)
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

    template<typename T>
    void CircularLinkedList<T>::add(T&& value)
    {
        Node<T>* newNode = new Node<T>(std::move(value));
        if (isEmpty()) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    template<typename T>
    void CircularLinkedList<T>::remove(const T& value)
    {
        if (isEmpty()) {
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        do {
            if (current->data == value) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                }
                else if (current == head) {
                    tail->next = head->next;
                    head = head->next;
                }
                else if (current == tail) {
                    previous->next = head;
                    tail = previous;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }

    template<typename T>
    void CircularLinkedList<T>::insertAfter(const T& targetValue, const T& newValue) {
        if (isEmpty()) {
            return;
        }

        Node<T>* current = head;
        do {
            if (current->data == targetValue)
            {
                Node<T>* newNode = new Node<T>(newValue);
                newNode->next = current->next;
                current->next = newNode;
                if (current == tail) {
                    tail = newNode;
                }
                return;
            }
            current = current->next;
        } while (current != head);
    }

    template<typename T>
    void CircularLinkedList<T>::removeAfter(const T& targetValue) {
        if (isEmpty()) {
            return;
        }

        Node<T>* current = head;
        do {
            if (current->data == targetValue)
            {
                if (current->next == head) {
                    tail = current;
                }
                Node<T>* toRemove = current->next;
                current->next = toRemove->next;
                delete toRemove;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    template<typename T>
    bool CircularLinkedList<T>::find(const T& value) const
    {
        if (isEmpty()) {
            return false;
        }
        Node<T>* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
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
}