//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

int kthSmallestInBST(Tree<int> * t, int k) {
    set<int> MySet;
    stack<Tree<int>*> MyStack;
    Tree<int>* tmp = t;
    
    while (MySet.size() < k) {
        while (t != NULL) {
            MyStack.push(t);
            t = t->left;
        }
        Tree<int>* top = MyStack.top();
        MyStack.pop();
        MySet.insert(top->value);
        t = top->right;
    }
    return *(--MySet.end());
}
