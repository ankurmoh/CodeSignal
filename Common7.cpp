std::string minSubstringWithAllChars(std::string s, std::string t) {
vector<int>freq1(26,0);
vector<int>freq2(26,0);
if((t=="") || (s==""))
    return "";
int i,len1=s.length(),len2=t.length(),right,left=0,formed=0,minlength=-1,start;
for(i=0;i<len2;i++)
    freq2[t[i]-'a']++;
for(right=0;right<len1;right++)
{
    freq1[s[right]-'a']++;
    if((freq1[s[right]-'a']==freq2[s[right]-'a']) && (freq2[s[right]-'a']>0))
        formed++;
    while((formed == len2) && (left<=right))
    {
        if((minlength == -1) || (minlength>right-left+1))
        {
            minlength = right-left+1;
            start = left;
        }
        freq1[s[left]-'a']--;
        if((freq1[s[left]-'a']<freq2[s[left]-'a'])) //&& (freq2[s[left]-'a']>0))
            formed--;
        left++;
    }
}
return s.substr(start,minlength);
}
