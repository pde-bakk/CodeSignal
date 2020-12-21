//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool    isMirror(Tree<int>* a, Tree<int>* b) {
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    return (a->value == b->value
        && isMirror(a->left, b->right)
        && isMirror(a->right, b->left));
}

bool isTreeSymmetric(Tree<int> * t) {
    if (!t)
        return true;
    return isMirror(t->left, t->right);

}
