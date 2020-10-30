int productExceptSelf(std::vector<int> nums, int m) {
int i,n = nums.size(),sum=0;
if(n == 0)
    return 0;
vector<int>forward(n),backward(n);
forward[0]=nums[0];
for(i=1;i<n;i++)
{
    forward[i]=(forward[i-1]*nums[i])%m;
}
backward[n-1]=nums[n-1];
for(i=n-2;i>=0;i--)
    backward[i]=(backward[i+1]*nums[i])%m;
sum = (backward[1] + forward[n-2])%m;
for(i=1;i<=n-2;i++)
{
    sum =sum+ (forward[i-1]*backward[i+1])%m;
    sum = sum%m;
   // cout<<sum<<endl;
}
return sum%m;
}
