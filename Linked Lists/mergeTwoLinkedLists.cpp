// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int>* l1, ListNode<int>* l2) {
    if (!l1 || !l2)
        return (!l1 ? l2 : l1);

  ListNode<int>* mergedl = nullptr;
    if (l1->value <= l2->value) {
        mergedl = l1;
        l1 = l1->next;
    } else {
        mergedl = l2;
        l2 = l2->next;
    }

    ListNode<int>* mergedTail = mergedl;

    while (l1 && l2) {
        ListNode<int> * temp = nullptr;
        if (l1->value <= l2->value) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }

        mergedTail->next = temp;
        mergedTail = temp;
    }

    if (l1) {
        mergedTail->next = l1;
    } else if (l2) {
        mergedTail->next = l2;
    }

    return mergedl;
}
