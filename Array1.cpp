int firstDuplicate(std::vector<int> a) {
unordered_map<int,int>mp;
int i,n=a.size(),res=-1,ans;
for(i=0;i<n;i++)
{
    if(mp.find(a[i])!=mp.end())
    {
        res = a[i];
        break;
        // if((res == -1) || (res>mp[a[i]]))
        // {
        //     res = mp[a[i]];
        //     ans = a[i];
        //     break;
        // }
    }
    mp[a[i]]=i;
}
return res;
}
