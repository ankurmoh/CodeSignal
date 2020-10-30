std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
unordered_map<int,int>mp;
int i,n=arr.size(),start,end,curr=0,longest = -1;
vector<int>res;
for(i=0;i<n;i++)
{
    curr=curr+arr[i];
    if(curr == s)
    {
        if(longest<i+1)
        {
            longest = i+1;
            start=1;
            end = i+1;
        }
    }
    if(mp.find(curr - s)!=mp.end())
    {
        if(longest<(i-mp[curr-s] + 1))
        {
            longest = i-mp[curr-s] + 1;
            start = mp[curr-s] + 1;
            end = i+1;
        }
    }
    if(mp.find(curr) == mp.end())
        mp[curr] = i+1;
}
if(longest == -1)
{
    res.push_back(-1);
}
else
{
    res.push_back(start);
    res.push_back(end);
}
return res;
}
