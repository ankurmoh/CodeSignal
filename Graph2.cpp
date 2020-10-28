void dfs(int src,unordered_map<int,unordered_set<int>>& graph,vector<int>& visited)
{
    visited[src]=1;
    int i,neigh;
    for(auto it = graph[src].begin(); it!= graph[src].end(); it++)
    {
        neigh = *it;
        if(visited[neigh]==0)
            dfs(neigh,graph,visited);
    }
}

int singlePointOfFailure(std::vector<std::vector<int>> connections) {
int i,j,n=connections.size(),sz,to,from,con,res=0;
unordered_map<int,unordered_set<int>>graph;
vector<pair<int,int>>edges;
vector<int>visited(n);
for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(connections[i][j]==1)
        {
            graph[i].insert(j);
            graph[j].insert(i);
            edges.push_back(make_pair(i,j));
        }
    }
}
sz = edges.size();
for(i=0;i<sz;i++)
{
    to = edges[i].first;
    from = edges[i].second;
    graph[to].erase(from);
    graph[from].erase(to);
    for(j=0;j<n;j++)
        visited[j]=0;
    con = 0;
    for(j=0;j<n;j++)
    {
        if(visited[j]==0)
        {
            con++;
            dfs(j,graph,visited);
        }
    }
    if(con>1)
        res++;
    graph[to].insert(from);
    graph[from].insert(to);
}
return res;
}
