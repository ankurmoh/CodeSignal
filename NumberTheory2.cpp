void permute(string& s,int begin,vector<string>& res)
{
    if(begin>s.length())
        return;
    if(begin == s.length())
    {
        res.push_back(s);
        return;
    }
    int i;
    for(i=begin;i<s.length();i++)
    {
        if((i == begin) || (s[i]!=s[i-1]))
        {
        swap(s[begin],s[i]);
        permute(s,begin+1,res);
        swap(s[begin],s[i]);
        }
    }
}

std::vector<std::string> stringPermutations(std::string s) {
sort(s.begin(),s.end());
vector<string>res;
permute(s,0,res);
sort(res.begin(),res.end());
return res;
}
