#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

typedef int Weight;
typedef int Flow;

#define REP(i,n) for(int i = 0; i < n; i++)
const int INF = 1e8;

struct Edge {
  int src, dest, rev;
  Flow cap;
  Weight cost;
  bool operator < (const Edge &rhs) const {
    return cost > rhs.cost;
  }
  Edge(int s, int d) : src(s), dest(d) { ; }
  Edge(int s, int d, int c) : src(s), dest(d), cost(c) { ; }
  Edge(int s, int d, int r, Flow cp, Weight cst) : src(s), dest(d), rev(r), cap(cp), cost(cst) { ; }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

typedef int Weight;
typedef int Flow;

void add_edge(Graph &g, int src, int dest, Flow cap) {
  g[src].push_back((Edge) { src, dest, (int)g[dest].size(), cap, 0 });
  g[dest].push_back((Edge) { dest, src, (int)g[src].size() - 1, 0, 0 });
}

Flow dfs(Graph &g, vector<bool> &used, int v, int t, Flow f) {
  if (v == t) return f;
  used[v] = true;
  for (Edge &e : g[v]) {
    if (!used[e.dest] && e.cap > 0) {
      Flow d = dfs(g, used, e.dest, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.dest][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

Flow ford_fulkerson(Graph &g, int s, int t) {
  Flow flow = 0;
  for (;;) {
    vector<bool> used(g.size(), false);
    Flow f = dfs(g, used, s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

vector<vector<int>> road;


bool reachable(int from, int to, int time){
  return road[from][to] <= time;
}
signed main(){
  int n,m,l;
  while(cin >> n >> m >> l, n != 0){
    road = vector<vector<int>>(n,vector<int>(n,INF));
    for(int range(i,0,n)){
      road[i][i] = 0;
    }
    for(int range(i,0,m)){
      int u, v, d;
      cin >> u >> v >> d;
      road[u][v] = road[v][u] = d;
    }

    vector<tuple<int,int>> req;
    for(int range(i,0,l)){
      int p,t;
      cin >> p >> t;
      req.emplace_back(t,p);
    }
    sort(all(req));

    for(int range(k,0,n)){
      for(int range(i,0,n)){
        for(int range(j,0,n)){
          road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
        }
      }
    }


    const int s_id = 0;
    const int t_id = 1;
    const int g_size = 2 + l + l;
    Graph g(g_size, Edges());
    for(int range(i,0,l)){
      for(int range(j,i+1,l)){
        int pt, pp, nt, np;
        tie(pt, pp) = req[i];
        tie(nt, np) = req[j];
        if(road[pp][np] <= nt - pt){
          add_edge(g, 2 + i, 2 + l + j, 1);
        }
      }
    }
    for(int range(i,0,l)){
      add_edge(g, s_id, 2 + i, 1);
      add_edge(g, 2 + l + i, t_id, 1);
    }
    int ff = ford_fulkerson(g, s_id, t_id);

    cout << l - ff << endl;
  }
}
