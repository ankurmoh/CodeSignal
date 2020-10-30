int arrayMaxConsecutiveSum2(std::vector<int> inputArray) {
int i,n=inputArray.size(),maxtot, maxsofar;
if(n==0)
    return 0;
else if(n==1)
    return inputArray[0];
maxsofar = inputArray[0];
maxtot = maxsofar;
for(i=1;i<n;i++)
{
    maxsofar = max(inputArray[i], maxsofar+inputArray[i]);
    maxtot = max(maxtot,maxsofar);
}
return maxtot;
}
