#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int n) {
        data = n;
        next = nullptr;
    }
};

class List {
private:
    Node* head;

public:
        List() {
        head = nullptr;
    }

    void append(int n) {
        Node* newNode = new Node(n);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* var = head;
        while (var->next != nullptr) {
            var = var->next;
        }
        var->next = newNode;
    }

   
    void insertAtBeginning(int n) {
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    
    bool search(int key) {
        Node* var = head;
        
        while (var != nullptr) {
            if (var->data == key)
                return true;
            var = var->next;
        }
        return false;
    }

    void deleteNode(int n) {
        if (head == nullptr)
            return;
        
        if (head->data == n) {
            Node* var = head;
            head = head->next;
            delete var;
            return;
        }

        Node* var = head;
        while (var->next != nullptr && var->next->data != n) {
            var = var->next;
        }

        if (var->next == nullptr)
            return;

        Node* nodeDelete = var->next;
        var->next = var->next->next;
        delete nodeDelete;
    }

    void reverse() {
        Node* last = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        head = last;
    }

    void display() {
        Node* var = head;
        while (var != nullptr) {
            cout << var->data << " -> ";
            var = var->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
        List list;
    
    list.append(10);
    list.append(30);
    list.append(50);
    
    cout << "List after appending: ";
    list.display();
    
    list.insertAtBeginning(5);
    cout << "Inserting at beginning: ";
    list.display();
    
    cout << "Searching 30: " << (list.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching 100: " << (list.search(100) ? "Found" : "Not Found") << endl;
    
    list.deleteNode(30);
    cout << "After deleting 30: ";
    list.display();
    
    list.reverse();
    cout << "List Reversed : ";
    list.display();
    
    return 0;
}