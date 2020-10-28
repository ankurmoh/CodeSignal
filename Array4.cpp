bool sudoku2(std::vector<std::vector<char>> grid) {
    int i,j,starti,startj;
    for(i=0;i<=6;i=i+3)
    {
        for(j=0;j<=6;j=j+3)
        {
            unordered_map<char,int>mp;
            for(starti = i; starti <i+3;starti++)
            {
                for(startj = j; startj<j+3; startj++)
                {
                    if(grid[starti][startj] == '.')
                        continue;
                    if(mp.find(grid[starti][startj])!= mp.end())
                    {
                        return false;
                    }
                    mp[grid[starti][startj]]=1;
                }
            }
        }
    }
    for(i=0;i<9;i++)
    {
        unordered_map<char,int>mp;
        for(j=0;j<9;j++)
        {
           if(grid[i][j] == '.')
                continue;
           if(mp.find(grid[i][j])!= mp.end())
                return false;
            mp[grid[i][j]]=1;
        }
    }
    for(j=0;j<9;j++)
    {
        unordered_map<char,int>mp;
        for(i=0;i<9;i++)
        {
            if(grid[i][j] == '.')
                continue;
           if(mp.find(grid[i][j])!= mp.end())
                return false;
            mp[grid[i][j]]=1;
        }
    }
    return true;
}
