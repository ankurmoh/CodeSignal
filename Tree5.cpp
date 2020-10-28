//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
int preord = 0;
int search(vector<int>& arr,int start, int end, int find)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i]==find)
            return i;
    }
    return -1;
}
Tree<int>* build(vector<int>& inorder, vector<int>& preorder,int start,int end, unordered_map<int,int>& pos)
{
    if(start>end)
        return NULL;
    Tree<int>* t = new Tree(preorder[preord]);
    preord++;
    if(start == end)
        return t;
    int index = pos[t->value];
    //int index = search(inorder,start,end,t->value);
    t->left = build(inorder,preorder,start,index-1,pos);
    t->right = build(inorder,preorder,index+1,end,pos);
    return t;
}
Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    int n = inorder.size();
    if(n==0)
        return NULL;
    if(n!=preorder.size())
        return NULL;
    unordered_map<int,int>pos;
    for(int i=0;i<n;i++)
        pos[inorder[i]]=i;
return build(inorder,preorder,0,n-1,pos);
}
