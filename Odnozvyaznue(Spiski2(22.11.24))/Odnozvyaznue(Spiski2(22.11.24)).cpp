#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this;
        clear();
        if (other.head == nullptr) {
            head = nullptr;
        }
        else {
            head = new Node(other.head->data);
            Node* current = head;
            Node* otherCurrent = other.head->next;
            while (otherCurrent != nullptr) {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
        return *this;
    }
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    setlocale(0, "ru");
    LinkedList list1;
    list1.push(3);
    list1.push(2);
    list1.push(1);

    std::cout << "Список 1: ";
    list1.print();

    LinkedList list2;
    list2.push(6);
    list2.push(5);
    list2.push(4);

    std::cout << "Список 2 до копиювання: ";
    list2.print();
    list2 = list1;
    std::cout << "Список 2 після копиювання з Списку 1: ";
    list2.print();
    list1.push(0);
    std::cout << "Список 1 після змини: ";
    list1.print();
    std::cout << "Список 2 після змини Списку 1: ";
    list2.print();

    return 0;
}

// 1 ЗАДАНИЕ
//#include <iostream>
//
//struct Node {
//    int data;      
//    Node* next;     
//    Node(int value) : data(value), next(nullptr) {}
//};
//
//class LinkedList {
//private:
//    Node* head;    
//
//public:
//    
//    LinkedList() : head(nullptr) {}
//    ~LinkedList() {
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    void push(int value) {
//        Node* newNode = new Node(value);
//        newNode->next = head;
//        head = newNode;
//    }
//
//    LinkedList(const LinkedList& other) : head(nullptr) {
//        if (other.head == nullptr) return;
//
//        head = new Node(other.head->data);
//
//        Node* current = head;
//        Node* otherCurrent = other.head->next;
//        while (otherCurrent != nullptr) {
//            current->next = new Node(otherCurrent->data);
//            current = current->next;
//            otherCurrent = otherCurrent->next;
//        }
//    }
//    LinkedList& operator=(const LinkedList& other) {
//        if (this == &other) return *this; 
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        if (other.head == nullptr) {
//            head = nullptr;
//        }
//        else {
//            head = new Node(other.head->data);
//
//            Node* current = head;
//            Node* otherCurrent = other.head->next;
//            while (otherCurrent != nullptr) {
//                current->next = new Node(otherCurrent->data);
//                current = current->next;
//                otherCurrent = otherCurrent->next;
//            }
//        }
//        return *this;
//    }
//
//
//
//    void print() const {
//        Node* current = head;
//        while (current != nullptr) {
//            std::cout << current->data << " -> ";
//            current = current->next;
//        }
//        std::cout << "nullptr" << std::endl;
//    }
//};
//
//int main() {
//    setlocale(0, "ru");
//    LinkedList list;
//    list.push(3);
//    list.push(2);
//    list.push(1);
//
//    std::cout << "Оригинальний список: ";
//    list.print();
//
//    LinkedList copiedList(list);
//    std::cout << "Копия списку: ";
//    copiedList.print();
//
//    list.push(0);
//    std::cout << "Зминений оригинальний список: ";
//    list.print();
//    std::cout << "Копия посля змини оригиналу: ";
//    copiedList.print();
//
//    return 0;
//}
