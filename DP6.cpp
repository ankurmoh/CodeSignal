int maximalSquare(std::vector<std::vector<char>> matrix) {
int i,j,sz1=matrix.size(),sz2,res=0;
if(sz1==0)
    return 0;
sz2 = matrix[0].size();
vector<vector<int>>dp(sz1+1,vector<int>(sz2+1));
for(i=0;i<sz1;i++)
{
    dp[i][0]=matrix[i][0]-'0';
    if(dp[i][0] == 1)
        res=1;
}
for(i=0;i<sz2;i++)
{
    dp[0][i]=matrix[0][i]-'0';
    if(dp[0][i] == 1)
        res = 1;
}
for(i=1;i<sz1;i++)
{
    for(j=1;j<sz2;j++)
    {
        if(matrix[i][j]=='0')
        {
            dp[i][j]=0;
        }
        else
        {
            dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
        res = max(res,dp[i][j]);
    }
}
return res*res;
}
