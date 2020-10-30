void combination(vector<int>& arr,int num,vector<vector<int>>& res,vector<int>& ans,int begin)
{
    if(num<0)
        return;
    if(num == 0)
    {
        //sort(ans.begin(),ans.end());
        res.push_back(ans);
        return;
    }
    int i,sz=arr.size();
    for(i=begin;i<sz;i++)
    {
        if(arr[i]<=num)
        {
            if((i==begin) || (arr[i]!=arr[i-1]))
            {
            ans.push_back(arr[i]);
            combination(arr,num-arr[i],res,ans,i+1);
            ans.pop_back();
            }
        }
    }
}

std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num) {
vector<vector<int>>res;
vector<int>ans;
combination(arr,num,res,ans,0);
return res;
}
