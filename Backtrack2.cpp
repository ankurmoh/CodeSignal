void addsolution(vector<vector<int>>& board, vector<vector<int>>& res, int n)
{
    int i,j;
    vector<int>temp;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(board[i][j]==1)
            {
                temp.push_back(i+1);
                break;
            }
        }
    }
    res.push_back(temp);
}


bool safe(int row,int col, vector<vector<int>>& board,int n)
{
    int i,j;
    for(j=0;j<col;j++)
    {
        if(board[row][j]==1)
            return false;
    }
    for(i=row,j=col;(i>=0 && j>=0);i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(i=row,j=col;(i<n && j>=0);i++,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}

bool solveNQ(vector<vector<int>>& board,int n,int col,vector<vector<int>>& res)
{
    if(col == n)
    {
        addsolution(board,res,n);
        return true;
    }
    bool result = false;
    int i;
    for(i=0;i<n;i++)
    {
        if(safe(i,col,board,n))
        {
            board[i][col]=1;
            result = solveNQ(board,n,col+1,res) || result;
            board[i][col]=0;
        }
    }
    return result;
}

std::vector<std::vector<int>> nQueens(int n) {
vector<vector<int>>res;
if(n==0)
    return res;
vector<vector<int>>board(n, vector<int>(n,0));
if(solveNQ(board,n,0,res))
    return res;
return res;
}
