char firstNotRepeatingCharacter(std::string s) {
unordered_map<char,int>mp;
int i,len=s.length();
for(i=0;i<len;i++)
    mp[s[i]]++;
for(i=0;i<len;i++)
{
    if(mp[s[i]]==1)
        return s[i];
}
return '_';
}
