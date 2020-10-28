std::vector<int> graphDistances(std::vector<std::vector<int>> g, int s) {
    int i,j,n=g.size(),current_dist,current_node,neigh,sz,weight;
vector<vector<pair<int,int>>>adj(n);
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if((j==i) || (g[i][j]==-1))
            continue;
        adj[i].push_back(make_pair(j,g[i][j]));
    }
}
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
pq.push(make_pair(0,s));
vector<int>dist(n,INT_MAX);
dist[s]=0;
while(!pq.empty())
{
    pair<int,int> fron = pq.top();
    pq.pop();
    current_dist = fron.first;
    current_node = fron.second;
    sz = adj[current_node].size();
    for(i=0;i<sz;i++)
    {
        neigh = adj[current_node][i].first;
        weight = adj[current_node][i].second;
        if((dist[neigh] == INT_MAX) || (dist[neigh]>weight + current_dist))
        {
            dist[neigh] = weight + current_dist;
            pq.push(make_pair(dist[neigh],neigh));
        }
    }
}
return dist;
}
