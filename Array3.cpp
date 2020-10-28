std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
int i,j,n=a.size(),temp;
for(i=0;i<n;i++)
{
    for(j=i;j<n;j++)
    {
        //swap(a[i][j],a[j][i]);
        temp = a[i][j];
        a[i][j] = a[j][i];
        a[j][i] = temp;
    }
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
}
for(i=0;i<n;i++)
{
    reverse(a[i].begin(),a[i].end());
}
return a;
}
