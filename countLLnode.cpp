#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the length of the linked list
int getLength(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

int main() {
    // Example 1: 1->2->3->4->5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    cout << getLength(head1) << endl; // Output: 5

    // Example 2: 2->4->6->7->5->1->0
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);
    head2->next->next->next = new ListNode(7);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(1);
    head2->next->next->next->next->next->next = new ListNode(0);
    cout << getLength(head2) << endl; // Output: 7

    // Clean up memory (optional, but good practice)
    ListNode* current = head1;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    current = head2;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
