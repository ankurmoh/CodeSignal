int kthLargestElement(std::vector<int> nums, int k) {
priority_queue<int, vector<int>, greater<int>>pq;
int i,n=nums.size();
for(i=0;i<n;i++)
{
    if(pq.size()<k)
        pq.push(nums[i]);
    else if(pq.size() == k)
    {
        if(pq.top()<nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
}
return pq.top();
}
