//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool traverse(Tree<int>* r, int s)
{
    if(r == NULL)
        return false;
    if((r->left == NULL) && (r->right == NULL))
    {
        if(r->value == s)
            return true;
        return false;
    }
    return (traverse(r->left, s-r->value) || traverse(r->right, s-r->value));
}
bool hasPathWithGivenSum(Tree<int> * t, int s) {
if(t==NULL)
    return false;
if((t->left == NULL) && (t->right == NULL))
{
    if(t->value == s)
        return true;
    else
        return false;
}
return traverse(t,s);
}
