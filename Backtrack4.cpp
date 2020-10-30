vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
bool dfs(string temp,int pos,int len,vector<vector<char>>& board,int i,int j,int sz1,int sz2)
{
    if(pos == len)
        return true;
    if((i<0)||(i>=sz1)||(j<0)||(j>=sz2)||(board[i][j]!=temp[pos]))
        return false;
    int k,x,y;
    char ch = board[i][j];
    board[i][j]='*';
    bool res = false;
    for(k=0;k<8;k++)
    {
        x = i + dir[k][0];
        y = j + dir[k][1];
        res = res || dfs(temp,pos+1,len,board,x,y,sz1,sz2);
    }
    board[i][j]=ch;
    return res;
}
bool valid(string temp,int len,vector<vector<char>>& board,int sz1,int sz2)
{
    int i,j;
    for(i=0;i<sz1;i++)
    {
        for(j=0;j<sz2;j++)
        {
            if(board[i][j] == temp[0])
            {
                if(dfs(temp,0,len,board,i,j,sz1,sz2))
                    return true;
            }
        }
    }
    return false;
}
std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
int i,sz1=words.size(),sz2 = board.size(),sz3,len;
vector<string>res;
string temp;
if((sz1 == 0) || (sz2 == 0))
    return res;
sz3 = board[0].size();
sort(words.begin(),words.end());
for(i=0;i<sz1;i++)
{
    temp = words[i];
    len = temp.length();
    if(valid(temp,len,board,sz2,sz3))
    {
        res.push_back(temp);
    }
}
return res;
    }
