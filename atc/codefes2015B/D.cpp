#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define rep(i,n) for(int i=0,i##_len=n;i<i##_len;i++)
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long double ld;
using namespace std;

signed main(){
  int n; cin >> n;
  vector<int> x(n), c(n);
  rep(i, n) cin >> x[i] >> c[i];
  map<int,int> fills;
  rep(i, n){
    int xx = x[i];
    int cc = c[i];
    int l = xx; int r = -1;
    auto b = fills.lower_bound(xx+1);
    if (b != fills.begin()){
      b--;
      int pl, pr; tie(pl, pr) = *b;
      if (pr >= xx) {
        xx = pr;
        l = pl;
        fills.erase(b);
      }
    }
    while(cc > 0){
      auto nb = fills.lower_bound(xx+1);
      if (nb == fills.end()){
        xx = xx + cc - 1;
        cc = 0;
      } else {
        int nl, nr; tie(nl, nr) = *nb;
        if(nl > xx + cc) {
          xx = xx + cc - 1;
          cc = 0;
        }else if(nl == xx + cc){
          xx = xx + cc - 1;
          r = nr;
          cc = 0;
          fills.erase(nb);
        } else{
          cc = cc - ( nl - xx );
          xx = nr;
          fills.erase(nb);
        }
      }
    }
    fills.insert(make_pair(l, max(xx + 1, r)));
    cout << xx << endl;
  }
}
