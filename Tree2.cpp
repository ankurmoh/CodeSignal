//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool sym(Tree<int>* t1, Tree<int>* t2)
{
    if((t1 == NULL) && (t2 == NULL))
        return true;
    if((t1 == NULL) || (t2 == NULL))
        return false;
    if(t1->value != t2->value)
        return false;
    return (sym(t1->left,t2->right) && sym(t1->right,t2->left));
}
bool isTreeSymmetric(Tree<int> * t) {
  if(t == NULL)
    return true;
return sym(t,t);
}
