#include <cstdint>
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int>*    reverse(ListNode<int> *head) {
    ListNode<int>   *prev = NULL;
    ListNode<int>   *temp = NULL;
    while (head) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}


bool isListPalindrome(ListNode<int> * l) {
    ListNode<int>   *slow = l;
    ListNode<int>   *fast = l;
    while (fast && fast->next) { // When fast reaches the end of the list, slow reaches the middle!
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverse(slow); // We reverse the second part of the list
    while (slow) {
        if (l->value != slow->value) {
            return false;
        }
        l = l->next;
        slow = slow->next;
    }
    return true;
}
