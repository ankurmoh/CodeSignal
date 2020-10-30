int missingNumber(std::vector<int> arr) {
int i,n= arr.size(),sum=0;
for(i=0;i<n;i++)
    sum=sum+arr[i];
return (n*(n+1))/2 - sum;
}
