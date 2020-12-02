// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    while (l && l->value == k)
        l = l->next;
        
    ListNode<int> *curr(l);
    while (curr && curr->next) {
        if (curr->next->value == k)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return l;
}
