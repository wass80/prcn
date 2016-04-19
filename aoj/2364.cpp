#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define lim(x,r,l) (r<=x&&x<l)
#define all(x) begin(x),end(x)
typedef long long ll;
typedef long double ld;
using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

const vector<int> d4x({1, 0, -1, 0});
const vector<int> d4y({0, -1, 0, 1});

signed main(){
  int w, h; cin>>w>>h;
  vector<string> b(h);
  UnionFind u(w*h);
  for(int range(i,0,h)){
    cin >> b[i];
  }
  int gx, gy;
  for(int range(x,0,w)){
    for(int range(y,0,h)){
      if(b[y][x]=='t'){
        gy = y; gx = x;
        b[y][x]='.';
      }
      for(int range(d,0,4)){
        int dx=x+d4x[d], dy=y+d4y[d];
        if(lim(dx,0,w)&&lim(dy,0,h)){
          if(b[y][x] == '.' && b[dy][dx] == '.'){
            u.unionSet(x*h+y,dx*h+dy);
          }
        }
      }
    }
  }
  
  int n;cin>>n;
  int gt = -1;
  int t=0;
  for(range(t,0,n)){
    if(u.findSet(0, gx*h+gy)){
      gt = t;
      break;
    }
    int x, y; cin >> x >> y;
    b[y][x] = '.';
    for(int range(d,0,4)){
      int dx=x+d4x[d], dy=y+d4y[d];
      if(lim(dx,0,w)&&lim(dy,0,h)){
        if(b[dy][dx] == '.'){
          u.unionSet(x*h+y,dx*h+dy);
        }
      }
    }
  }
    if(u.findSet(0, gx*h+gy)){
      gt = t;
    }
  cout << gt << endl;
}
