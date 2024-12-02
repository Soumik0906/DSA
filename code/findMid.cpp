#include "node.h"

Node* findMiddle(Node* head) {
    // if nodes <= 1, return immediately
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next; 
    }

    return slow;
}

int main() {
    Node* head = LinkedListUtils::createFromVector({1, 2, 3, 4, 5});

    Node* mid = findMiddle(head);
    
    std::cout << mid->data << std::endl;

    return 0;
}
