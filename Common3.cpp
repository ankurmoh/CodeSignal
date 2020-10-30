int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    int i,j,n=nums.size(),sz=queries.size(),res=0,start,end;
vector<int>prefix(n+1,0);
for(i=1;i<=n;i++)
{
    prefix[i]=prefix[i-1] + nums[i-1];
}
for(i=0;i<sz;i++)
{
    start = queries[i][0];
    end = queries[i][1];
    res=(res + (prefix[end+1] - prefix[start]))%1000000007;
    //res = res % 1000000007;
}
if(res<0)
    res=res+1000000007;
return res;
}
