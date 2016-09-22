#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define rep(i,n) for(int i=0,i##_len=n;i<i##_len;i++)
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

signed main(){
  int n, m; cin >> n >> m;
  vector<int> x(m);
  rep(i, m) cin >> x[i];
  int l = 0;
  int r = 2 * n;
  rep(i, 100){
    int t = (l + r) / 2;
    int v = 0;
    bool out = false;
    rep(j, m){
      int back = x[j] - v - 1;
      if (back > 0) {
        if (back > t){
          out = true;
          break;
        } else {
          v = max(x[j], x[j] + max(t - 2 * back, (t - back) / 2));
        }
      } else {
        v = x[j] + t;
      }
    }
    if (out || v < n) l = t;
    else r = t;
  }
  cout << r << endl;
}
