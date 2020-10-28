std::vector<int> nextLarger(std::vector<int> a) {
stack<int>s;
int i,n=a.size();
vector<int>res(n,-1);
for(i=0;i<n;i++)
{
    while((!s.empty()) && (a[i]>a[s.top()]))
    {
        res[s.top()] = a[i];
        s.pop();
    }
    s.push(i);
}
return res;
}
