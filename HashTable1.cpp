std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
int i,n = dishes.size(),j,sz;
vector<string>temp;
unordered_map<string, vector<string>>mp;
for(i=0;i<n;i++)
{
    temp = dishes[i];
    sz = temp.size();
    for(j=1;j<sz;j++)
    {
        mp[temp[j]].push_back(temp[0]);
    }
}
vector<vector<string>>res;
for(auto it=mp.begin();it!=mp.end();it++)
{
    if(it->second.size()<2)
        continue;
    temp.clear();
    sort(it->second.begin(),it->second.end());
    temp.push_back(it->first);
    sz = it->second.size();
    for(i=0;i<sz;i++)
        temp.push_back(it->second[i]);
    res.push_back(temp);
}
sort(res.begin(),res.end());
return res;
}
