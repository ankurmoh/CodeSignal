std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
int i,n = words.size(), m =parts.size(),j,start,len,k;
string curword, match,temp;
unordered_set<string>part(parts.begin(),parts.end());
vector<string>res;
for(i=0;i<n;i++)
{
    curword = words[i];
    match = "";
    start = -1;
    len = curword.length();
    for(j=5;j>=1;j--)
    {
        for(k=0;k<=len-j;k++)
        {
            if(part.count(curword.substr(k,j)))
            {
                match = curword.substr(k,j);
                start = k;
                break;
            }
        }
         if(match != "")
                break;
    }
    // for(j=0;j<m;j++)
    // {
    //     if(curword.find(parts[j]) != string::npos)
    //     {
    //         if((match == "") || (match.length() < parts[j].length()))
    //         {
    //             match = parts[j];
    //             start = curword.find(parts[j]);
    //         }
    //         else if(match.length() == parts[j].length())
    //         {
    //             if(start>curword.find(parts[j]))
    //             {
    //                 start = curword.find(parts[j]);
    //                 match = parts[j];
    //             }
    //         }
    //     }
    // }
    if(match == "")
    {
        res.push_back(curword);
        continue;
    }
    temp = "";
    for(j=0;j<start;j++)
        temp=temp+curword[j];
    temp=temp+"[";
    for(j=start;j<start+match.length();j++)
        temp=temp+curword[j];
    temp=temp+"]";
    for(j=start+match.length();j<len;j++)
        temp=temp+curword[j];
    res.push_back(temp);
}
return res;
}
