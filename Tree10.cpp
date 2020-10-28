int prims(vector<vector<pair<int,int>>>& graph,vector<bool>& MST,int n,int src)
{
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);
    int fron,sz,i,neigh,weight,con=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        fron = pq.top().second;
        pq.pop();
        if(MST[fron]==true)
            continue;
        con = con + pq.top().first;
        MST[fron]=true;
        sz = graph[fron].size();
        for(i=0;i<sz;i++)
        {
            neigh = graph[fron][i].first;
            weight = graph[fron][i].second;
            if(((dist[neigh] == INT_MAX) || (dist[neigh] > weight)) && (MST[neigh] == false))
            {
                dist[neigh]=weight;
                pq.push(make_pair(weight,neigh));
                parent[neigh]=fron;
            }
        }
    }
    return con;
}
int networkWires(int n, std::vector<std::vector<int>> wires) {
int i,sz=wires.size(),to,from,con=0;
vector<vector<pair<int,int>>>adjacency(n);
for(i=0;i<sz;i++)
{
    from = wires[i][0];
    to = wires[i][1];
    adjacency[from].push_back(make_pair(to,wires[i][2]));
    adjacency[to].push_back(make_pair(from,wires[i][2]));
}
vector<bool>MST(n+1,false);
for(i=0;i<n;i++)
{
    if(MST[i]==false)
        con = con + prims(adjacency,MST,n,i);
}
return con;
}
