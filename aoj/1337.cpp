#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
typedef long long ll;
typedef long double ld;
using namespace std;

const vector<int> d4x({1, 0, -1, 0});
const vector<int> d4y({0, -1, 0, 1});

int dfs(vector<vector<int>>& m, int x, int y){
  if(0<=x&&0<=y&&x<m.size()&&y<m[0].size()&&m[x][y]==0){
    m[x][y] = 1;
    for(int range(i,0,4)){
      dfs(m,x+d4x[i],y+d4y[i]);
    }
    return 1;
  }
  return 0;
}
signed main(){
  int n;
  while(cin >> n, n != 0){
    vector<int> l(n), t(n), r(n), b(n);
    for(int range(i,0,n)){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
    }
    set<int> sx, sy;
    for(int range(i,0,n)){
      sx.insert(3*l[i]-1); sx.insert(3*l[i]); sx.insert(3*l[i]+1);
      sy.insert(3*t[i]-1); sy.insert(3*t[i]); sy.insert(3*t[i]+1);
      sx.insert(3*r[i]-1); sx.insert(3*r[i]); sx.insert(3*r[i]+1);
      sy.insert(3*b[i]-1); sy.insert(3*b[i]); sy.insert(3*b[i]+1);
    }

    vector<int> vx(all(sx)), vy(all(sy));
    vector<vector<int>> m(vx.size(), vector<int>(vy.size(), 0));
    
    for(int range(i,0,n)){
      const int ll = lower_bound(all(vx),3*l[i]) - vx.begin();
      const int tt = lower_bound(all(vy),3*t[i]) - vy.begin();
      const int rr = lower_bound(all(vx),3*r[i]) - vx.begin();
      const int bb = lower_bound(all(vy),3*b[i]) - vy.begin();

      for(int range(x,min(ll,rr),max(ll,rr)+1)){
        m[x][tt] = 1;
        m[x][bb] = 1;
      }
      for(int range(y,min(tt,bb),max(tt,bb)+1)){
        m[ll][y] = 1;
        m[rr][y] = 1;
      }
    }
/*     for(int range(x,0,vx.size())){
      for(int range(y,0,vy.size())){
        cout<<m[x][y];
      }
      cout<<endl;
    } */
    int res = 0;
    for(int range(x,0,vx.size())){
      for(int range(y,0,vy.size())){
        res += dfs(m, x, y);
      }
    }
    cout << res << endl;
  }
}
