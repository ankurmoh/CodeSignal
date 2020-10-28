//
// Binary tdkmees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
Tree<int>* predess(Tree<int>* r)
{
    if (r->right == NULL)
        return r;
    while(r->right!=NULL)
        r=r->right;
    return r;
}
void deletefrom(Tree<int>*& t,int val)
{
    if(t == NULL)
        return;
    if(t->value>val)
        deletefrom(t->left, val);
    else if(t->value<val)
        deletefrom(t->right, val);
    else
    {
        if((t->left == NULL) && (t->right == NULL))
        {
            t = NULL;
            return;
        }
        else if(t->left!=NULL)
        {
            Tree<int>* pred = predess(t->left);
            t->value = pred->value;
            deletefrom(t->left, pred->value);
        }
        else if(t->left==NULL)
        {
            t = t->right;
        }
    }
}
Tree<int> * deleteFromBST(Tree<int> * t, std::vector<int> queries) {
if(t == NULL)
    return NULL;
int i,n = queries.size();
for(i=0;i<n;i++)
{
    deletefrom(t,queries[i]);
}
return t;
}
