// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
unsigned long long power(int digits) {
    int i = 0, out = 1;
    while (i < digits) {
        out *= 10;
        digits -= 1;
    }
    return out;
}

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

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    ListNode<int>   *result = new ListNode<int>(0);
    ListNode<int>   *head = result;
    int carryover = 0;
    
    a = reverse(a);
    b = reverse(b);
    
    while (a || b) {
        if (a) {
            carryover += a->value;
            a = a->next;
        }
        if (b) {
            carryover += b->value;
            b = b->next;
        }
        head->next = new ListNode<int>(carryover % 10000);
        head = head->next;
        carryover /= 10000;
        
    }
    if (carryover >= 1)
        head->next = new ListNode<int>(carryover);
    
    return reverse(result->next);
}
