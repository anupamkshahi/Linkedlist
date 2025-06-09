#include <iostream>
using namespace std;

// Node structure for singly linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a value at the end of the linked list
ListNode* insertAtEnd(ListNode* head, int x) {
    ListNode* newNode = new ListNode(x);
    
    // If the list is empty, make the new node the head
    if (head == nullptr) {
        return newNode;
    }
    
    // Traverse to the last node
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    // Insert the new node at the end
    current->next = newNode;
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example 1: Insert into an existing list
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Before insertion: ";
    printLinkedList(head1); // Typo corrected: should be printLinkedList(head1)
    head1 = insertAtEnd(head1, 6);
    cout << "After insertion: ";
    printLinkedList(head1); // Prints: 1->2->3->4->5->6

    // Example 2: Insert into a list with two elements
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(4);

    cout << "\nBefore insertion: ";
    printLinkedList(head2);
    head2 = insertAtEnd(head2, 1);
    cout << "After insertion: ";
    printLinkedList(head2); // Typo corrected: should be printLinkedList(head2)
    // Corrected code below:
    printLinkedList(head2); // Prints: 5->4->1

    return 0;
}
