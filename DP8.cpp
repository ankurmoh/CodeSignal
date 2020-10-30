int longestIncreasingSubsequence(std::vector<int> sequence) {
int i,n=sequence.size(),j,maxres=1;
if(n==0)
    return 0;
vector<int>dp(n,1);
for(i=1;i<n;i++)
{
    for(j=0;j<i;j++)
    {
        if(sequence[i]>sequence[j])
        {
            if(dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
            maxres = max(maxres,dp[i]);
        }
    }
}
return maxres;
}
