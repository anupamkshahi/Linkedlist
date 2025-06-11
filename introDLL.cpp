#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* constructDLL(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node();
    head->data = arr[0];
    head->prev = nullptr;
    head->next = nullptr;
    Node* current = head;

    for (int i = 1; i < n; ++i) {
        Node* newNode = new Node();
        newNode->data = arr[i];
        newNode->prev = current;
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
    }
    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = constructDLL(arr, n);
    printDLL(head);

    // Optional: Clean up memory (not shown in production if list is used beyond this scope)
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
