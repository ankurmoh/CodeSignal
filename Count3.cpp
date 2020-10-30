int primesSum2(int n) {
int MOD = 1000000007,i,j,sum=0;
vector<int>sieve(n+1,1);
sieve[0]=0;
sieve[1]=0;
for(i=2;i*i<=n;i++)
{
    if(sieve[i]==1)
    {
        for(j=i*i;j<=n;j=j+i)
            sieve[j]=0;
    }
}
for(i=2;i<=n;i++)
{
    if(sieve[i]==1)
    {
        sum = (sum + i) % MOD;
    }
}
return sum%MOD;
}
