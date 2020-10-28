bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
long long int i,n = solution.size(),len,j,sum=0,sum1=0;
string temp;
unordered_map<char,char>mp;
for(i=0;i<n;i++)
{
    mp[solution[i][0]] = solution[i][1];
}
for(i=0;i<3;i++)
{
    temp = "";
    len = crypt[i].length();
    if(len == 0)
        continue;
    for(j=0;j<len;j++)
    {
        if(mp.find(crypt[i][j]) == mp.end())
            return false;
        temp = temp + mp[crypt[i][j]];
    }
    if((len>=2) && (temp[0] == '0'))
        return false;
    if(i<=1)
        sum = sum + stoll(temp);
    else if(i==2)
        sum1=stoll(temp);
}
return (sum==sum1);
}
