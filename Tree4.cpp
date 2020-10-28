
bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if ((t1 == nullptr && t2 == nullptr) || t2 == nullptr) return true;
    return helper(t1, t2);
}

bool isSame(Tree<int>* t1, Tree<int>* t2) {
    if (t1 == nullptr || t2 == nullptr) return t1 == t2;
    if (t1->value != t2->value) return false;
    return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
}
bool helper(Tree<int> * t1, Tree<int> * t2) {
    if (t1 == nullptr) return false;
    if (isSame(t1, t2)) return true;
    return helper(t1->left, t2) || helper(t1->right, t2);
}
