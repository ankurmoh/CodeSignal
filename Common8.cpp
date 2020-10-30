std::vector<std::string> repeatedDNASequences(std::string s) {
unordered_map<string,int>mp;
set<string>st;
string temp;
int i,j,len=s.length();
for(i=0;i<=len-10;i++)
{
    temp = s.substr(i,10);
    mp[temp]++;
    if(mp[temp]>1)
        st.insert(temp);
}
vector<string>res(st.begin(),st.end());
return res;
}
