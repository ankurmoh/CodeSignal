vector<vector<int>>dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};

void bfs(std::vector<std::vector<char>>& skyMap,int i,int j, vector<vector<int>>& visited)
{
    visited[i][j]=1;
    queue<pair<int,int>>q;
    q.push(make_pair(i,j));
    pair<int,int>fron;
    int k,x,y;
    while(!q.empty())
    {
        fron = q.front();
        q.pop();
        for(k=0;k<4;k++)
        {
            x=fron.first + dir[k][0];
            y=fron.second + dir[k][1];
            if((x>=0)&&(x<skyMap.size())&&(y>=0)&&(y<skyMap[0].size())&&(skyMap[x][y]=='1')&&(visited[x][y]==0))
            {
                visited[x][y]=1;
                q.push(make_pair(x,y));
            }
        }
    }
}


int countClouds(std::vector<std::vector<char>> skyMap) {
queue<pair<int,int>>q;
int i,j,m=skyMap.size(),n,con=0;
if(m==0)
    return 0;
n=skyMap[0].size();
vector<vector<int>>visited(m,vector<int>(n,0));
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        if((skyMap[i][j]=='1') && (visited[i][j]==0))
        {
            con++;
            bfs(skyMap,i,j,visited);
        }
    }
}
return con;
}
