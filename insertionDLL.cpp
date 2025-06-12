#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Create doubly linked list from array
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node();
    head->data = arr[0];
    head->prev = NULL;
    Node* curr = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node();
        temp->data = arr[i];
        temp->prev = curr;
        curr->next = temp;
        curr = temp;
    }
    curr->next = NULL;

    return head;
}

// Insert x after pth node (0-based indexing)
Node* insertAtPosition(Node* head, int p, int x) {
    Node* temp = head;
    int count = 0;

    // Traverse to the pth node
    while (count < p && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return head; // Position out of bounds

    // Create new node
    Node* newNode = new Node();
    newNode->data = x;

    // Insert newNode after temp
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// Utility to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << "<->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    Node* head = createList(arr, 4);

    cout << "Original list:\n";
    printList(head);

    int position = 2; // Insert after 2nd node (0-based)
    int value = 99;

    head = insertAtPosition(head, position, value);

    cout << "\nAfter insertion:\n";
    printList(head);

    return 0;
}
