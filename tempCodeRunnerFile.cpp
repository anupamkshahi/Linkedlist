#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* constructLinkedList(const vector<int>& arr) {
    if (arr.empty()){
        return nullptr;
    } 
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}


int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = constructLinkedList(arr1);
    printLinkedList(head1); // Output: 1->2->3->4->5

    vector<int> arr2 = {2, 4, 6, 7, 5, 1, 0};
    ListNode* head2 = constructLinkedList(arr2);
    printLinkedList(head2); // Output: 2->4->6->7->5->1->0

    // Remember to delete the linked list to avoid memory leaks!
    // (Deletion code is not shown here for brevity.)
    return 0;
}
