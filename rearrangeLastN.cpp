// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

// ListNode<int>* rearrangeLastN(ListNode<int>* l, int n) {
//     if (n == 0) {
//         return (l);
//     }
//     ListNode<int>* head(l), *prev(l);
//     while (l->next) {
//         prev = l;
//         l = l->next;
//     }
//     prev->next = NULL;
//     l->next = head;
//     head = l;
//     return rearrangeLastN(head, n - 1);
// }

ListNode<int>* rearrangeLastN(ListNode<int>* l, int n) {
    if (!l || n <= 0) {
        return (l);
    }
    ListNode<int>* head(l), *prev(NULL), *tail(l);
    for (size_t i = 1; i < n; ++i)
        tail = tail->next;
    
    while (tail->next) {
        prev = head;
        head = head->next;
        tail = tail->next;
    }
    if (!prev)
        return (l);
    prev->next = NULL;
    tail->next = l;
    return head;
}
