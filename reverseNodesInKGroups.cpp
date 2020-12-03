//
// Created by peerdb on 02-12-20.
//

// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

ListNode<int>* reverseNodesInKGroups(ListNode<int>* l, int k) {
        ListNode<int>* dummy = new ListNode(-1), *prev(dummy), *cur(dummy), *OGnext;
        dummy->next = l;
        int num = 0;
        while ((cur = cur->next))
            ++num;
        while (num >= k) {
            cur = prev->next;
            for (int i = 0; i < k - 1; ++i) {
                OGnext = cur->next;
                cur->next = OGnext->next;
                OGnext->next = prev->next;
                prev->next = OGnext;
            }
            prev = cur;
            num -= k;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
}
