#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete a node (not the last node) given only access to that node
void deleteNode(ListNode* node) {
    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    // delete nextNode; // Uncomment if you want to free memory (not usually needed in practice for this problem)
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example: 4 -> 5 -> 1 -> 9
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node1 = new ListNode(1);
    ListNode* node9 = new ListNode(9);
    node4->next = node5;
    node5->next = node1;
    node1->next = node9;

    // Let's delete node with value 5 (i.e., node5)
    deleteNode(node5);

    // Print the modified list
    printList(node4); // Output: 4 1 9

    // Clean up memory (optional, but good practice)
    ListNode* current = node4;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
