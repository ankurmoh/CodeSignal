bool containsCloseNums(std::vector<int> nums, int k) {
    unordered_map<int, vector<int>>mp;
    int i,n=nums.size();
    for(i=0;i<n;i++)
    {
        if(mp.find(nums[i])!=mp.end())
        {
            if(i-mp[nums[i]].back() <= k)
                return true;
        }
        mp[nums[i]].push_back(i);
    }
    return false;
