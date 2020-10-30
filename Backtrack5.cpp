void backtrack(vector<int>& a,int sum,int begin,vector<string>& res,vector<int>& ans)
{
    if(sum<0)
        return;
    int i,sz=a.size(),sz1;
    if(sum == 0)
    {
        //sort(ans.begin(),ans.end());
        string temp1 = "(";
        sz1 = ans.size();
        for(i=0;i<sz1;i++)
        {
            temp1 = temp1 + char(ans[i]+'0');
            if(i!=sz1-1)
                temp1=temp1+" ";
        }
        temp1=temp1+")";
        res.push_back(temp1);
        return;
    }
    for(i=begin;i<sz;i++)
    {
        if(a[i]<=sum)
        {
            if((i == begin) || (a[i]!=a[i-1]))
            {
            ans.push_back(a[i]);
            backtrack(a,sum-a[i],i,res,ans);
            ans.pop_back();
            }
        }
    }
}

std::string combinationSum(std::vector<int> a, int sum) {
string temp="";
vector<int>ans;
vector<string>res;
sort(a.begin(),a.end());
backtrack(a,sum,0,res,ans);
//sort(res.begin(),res.end());
int i,sz = res.size();
for(i=0;i<sz;i++)
{
    temp=temp+res[i];
}
if(temp == "")
    return "Empty";
return temp;
}
