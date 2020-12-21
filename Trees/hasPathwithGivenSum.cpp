//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool godown(Tree<int>* t, int val, int s) {
    if (t->left == NULL && t->right == NULL && t->value + val == s)
        return true;

    if (t->left && godown(t->left, t->value + val, s))
        return true;
    if (t->right && godown(t->right, t->value + val, s))
        return true;
    return false;
}

bool hasPathWithGivenSum(Tree<int> * t, int s) {
    if (!t)
        return false;
    return (godown(t, 0, s));
}
