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
stack<Tree<int>*>st;
Tree<int>* current = t;
while((!st.empty() || current!=NULL))
{
    while(current!=NULL)
    {
        st.push(current);
        current=current->left;
    }
    Tree<int>* temp = st.top();
    st.pop();
    k--;
    if(k == 0)
        return temp->value;
    //cout<<temp->value<<" ";
    if(temp->right)
        current = temp->right;
}
return -1;
}
