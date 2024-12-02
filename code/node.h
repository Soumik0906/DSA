#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* node) : data(val), next(node) {}
};

// Namespace for utility functions
namespace LinkedListUtils {

    // Create Linked List from Vector
    Node* createFromVector(const std::vector<int>& arr) {
        if (arr.empty()) {
            return nullptr;
        }

        Node* head = new Node(arr[0]);
        Node* temp = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }

        return head;
    }

    // Print Linked List
    void printList(Node* head) {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data;
            if (temp->next) {
                std::cout << " -> ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Delete Head Node
    Node* deleteHead(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Delete Entire List
    void deleteList(Node*& head) {
        while (head) {
            head = deleteHead(head);
        }
    }
}

#endif // NODE_H
