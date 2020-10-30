bool containsDuplicates(std::vector<int> a) {
unordered_map<int,int>mp;
int i,sz=a.size();
if(sz == 0)
    return false;
for(i=0;i<sz;i++)
{
    mp[a[i]]++;
    if(mp[a[i]]>1)
        return true;
}
return false;
}
