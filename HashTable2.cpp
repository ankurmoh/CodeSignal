bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {
unordered_map<string,string>mp,mp1;
int i,n=patterns.size();
for(i=0;i<n;i++)
{
  if(mp.find(strings[i])!=mp.end())
  {
      if(mp[strings[i]]!=patterns[i])
        return false;
  }
  if(mp1.find(patterns[i])!=mp1.end())
  {
      if(mp1[patterns[i]]!=strings[i])
        return false;
  }
  mp[strings[i]]=patterns[i];
  mp1[patterns[i]] = strings[i];
}
return true;
}
