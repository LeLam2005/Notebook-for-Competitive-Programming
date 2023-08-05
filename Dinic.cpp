struct edge{
  int u, v;
  ll cap, flow;
} e[N];
//non-scaling O(V^2, E), Scaling=VElog(U) with higher constant
int n, m, s, t, timer, level[N], ptr[N], LIM; bool SCALING=1;
vector<int> g[N];

void add_edge(int u, int v, ll c, bool isUndir=true){
  g[u].push_back(timer); e[timer]={u, v, c, 0}; ++timer;
  g[v].push_back(timer); e[timer]={v, u, (isUndir?c:0), 0}; ++timer;
}

bool bfs(){
  queue<int> q({s});
  fill(level+1, level+1+n, -1); level[s]=0;
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(auto id:g[u]){
      if(level[e[id].v]==-1 and e[id].flow<e[id].cap and (e[id].cap-e[id].flow>=LIM)){
        q.push(e[id].v);
        level[e[id].v]=level[u]+1;
      }
    }
  }
  return level[t]!=-1;
}

ll dfs(int u, ll cur_flow){
  if(u==t) return cur_flow;
  for(int& x=ptr[u]; x<g[u].size(); ++x){
    int id=g[u][x];
    if(level[e[id].v]!=(level[u]+1) or (e[id].cap<=e[id].flow)) continue;
    if(ll pushed=dfs(e[id].v, min(cur_flow, e[id].cap-e[id].flow))){
      e[id].flow+=pushed;
      e[id^1].flow-=pushed;
      return pushed;
    }
  }
  return 0;
}

ll FLOW(){
  ll ans=0;
  for(; LIM>0; LIM>>=1){
    while(bfs()){
      fill(ptr+1, ptr+1+n, 0);
      while(ll pushed=dfs(s, INF64)) ans+=pushed;
    }
  }
  return ans;
}
