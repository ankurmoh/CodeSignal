//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
std::vector<int> traverseTree(Tree<int> * t) {
vector<int>res;
int i,con;
if(t == NULL)
    return res;
queue<Tree<int>*>q;
q.push(t);
Tree<int>* fron;
while(!q.empty())
{
    con = q.size();
    for(i=0;i<con;i++)
    {
        fron = q.front();
        q.pop();
        res.push_back(fron->value);
        if(fron->left)
            q.push(fron->left);
        if(fron->right)
            q.push(fron->right);
    }
}
return res;
}
