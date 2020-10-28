pair<int,int> bfs(vector<vector<int>>& graph,int src,int n)
{
    vector<int>dist(n+1,-1);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    int i,j,con,fron,sz,neigh,maxdist = 0, point=src;
    while(!q.empty())
    {
        con = q.size();
        for(i=0;i<con;i++)
        {
            fron = q.front();
            q.pop();
            sz = graph[fron].size();
            for(j=0;j<sz;j++)
            {
                neigh = graph[fron][j];
                if(dist[neigh] == -1)
                {
                    dist[neigh]=dist[fron]+1;
                    q.push(neigh);
                }
                if(dist[neigh]>maxdist)
                {
                    maxdist = dist[neigh];
                    point = neigh;
                }
            }
        }
    }
    return make_pair(point, maxdist);
}


int treeDiameter(int n, std::vector<std::vector<int>> tree) {
vector<vector<int>>graph(n);
int i,sz = tree.size(),from,to;
for(i=0;i<sz;i++)
{
    to = tree[i][1];
    from = tree[i][0];
    graph[from].push_back(to);
    graph[to].push_back(from);
}
int x = bfs(graph,0,n).first;
return bfs(graph,x,n).second;
}
