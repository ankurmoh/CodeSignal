int leves(string a, string b)
{
    int i,j,len = a.length(),ans;
    vector<vector<int>>dp(len+1, vector<int>(len+1,0));
    for(i=1;i<=len;i++)
    {
        dp[0][i]=i;
        dp[i][0]=i;
    }
    for(i=1;i<=len;i++)
    {
        for(j=1;j<=len;j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+2));
        }
    }
    return dp[len][len];
}


bool kpalindrome(std::string s, int k) {
string temp = s;
reverse(temp.begin(),temp.end());
int edit = leves(s,temp);
if(edit <= 2*k)
    return true;
return false;
}
