void backtrack(vector<vector<int>>& res,vector<int>& ans,int k,int n)
{
    if(n<0)
        return;
    if(n == 0)
    {
        res.push_back(ans);
        return;
    }
    int i;
    for(i=1;((i<=k) && (i<=n));i++)
    {
        ans.push_back(i);
        backtrack(res,ans,k,n-i);
        ans.pop_back();
    }
}


std::vector<std::vector<int>> climbingStaircase(int n, int k) {
vector<vector<int>>res;
vector<int>ans;
if((k == 0) || (n==0))
{
    res.push_back(vector<int>());
    return res;
}
backtrack(res,ans,k,n);
return res;
}
