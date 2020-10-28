//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
long long sum = 0;
void traverse(Tree<int>* t, string val)
{
    if(t == NULL)
        return;
    if((t->left == NULL) && (t->right == NULL))
    {
        sum=sum+stol(val);
        return;
    }
    if(t->left)
        traverse(t->left, val + to_string(t->left->value));
    if(t->right)
        traverse(t->right, val + to_string(t->right->value));
}
long long digitTreeSum(Tree<int> * t) {
if(t == NULL)
    return 0;
traverse(t, to_string(t->value));
return sum;
}
