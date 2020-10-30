int mini(int a,int b,int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        else
            return c;
    }
    else if(b<=a)
    {
        if(b<c)
            return b;
        return c;
    }
    return -1;
}

int paintHouses(std::vector<std::vector<int>> cost) {
int i,j,n=cost.size();
vector<int>red(n),blue(n),green(n);
red[0]=cost[0][0];
blue[0]=cost[0][1];
green[0]=cost[0][2];
for(i=1;i<n;i++)
{
    red[i] = cost[i][0] + min(blue[i-1],green[i-1]);
    blue[i] = cost[i][1] + min(green[i-1],red[i-1]);
    green[i] = cost[i][2] + min(blue[i-1],red[i-1]);
}
return mini(red[n-1],green[n-1],blue[n-1]);
}
