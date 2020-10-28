bool dfs(int src,vector<int>& color,vector<vector<int>>& graph)
{
    color[src]=1;
    int i,sz=graph[src].size(),neigh;
    for(i=0;i<sz;i++)
    {
        neigh = graph[src][i];
        if(color[neigh] == 1)
            return true;
        if((color[neigh] == 0) && dfs(neigh,color,graph))
            return true;
    }
    color[src]=2;
    return false;
}

bool hasDeadlock(std::vector<std::vector<int>> connections) {
int i,sz=connections.size(),n=sz-1,j,sz1;
vector<int>visited(n+10,0), color(n+10,0);
vector<vector<int>>graph(n+10);
for(i=0;i<sz;i++)
{
   sz1=connections[i].size();
   for(j=0;j<sz1;j++)
   {
       graph[i].push_back(connections[i][j]);
   }
}
for(i=0;i<=n;i++)
{
    if(color[i]==0)
    {
        if(dfs(i,color,graph))
            return true;
    }
}
return false;
}
