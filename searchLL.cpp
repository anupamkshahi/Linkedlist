#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isKeyPresent(ListNode* head, int key) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == key)
            return true;
        current = current->next;
    }
    return false;
}

int main() {
    // Example: 1->2->3->4, key = 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    int key = 3;
    cout << boolalpha << isKeyPresent(head, key) << endl; // Output: true

    // Clean up memory
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
