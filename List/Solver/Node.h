template <typename T>
class Node
{
public:
    T data;
    Node* next = nullptr;

    Node(T value) : data(value), next(nullptr) {}
};