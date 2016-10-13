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
  int w, h; cin >> w >> h;
  vector<int> cx(w), cy(h);
  vector<tuple<int,int>> cxy(w+h);
  rep(i,w){
    cin >> cx[i];
    cxy[i] = make_tuple(cx[i], 0);
  }
  rep(i,h){
    cin >> cy[i];
    cxy[w+i] = make_tuple(cy[i], 1);
  }

  sort(all(cxy));

  int mx = 0, my = 0;

  int res = 0;
  rep(i,w+h){
    int cs, d; tie(cs, d) = cxy[i];
    if(d == 0){
      res += cs * (h + 1 - my);
      mx++;
    }else{
      res += cs * (w + 1 - mx);
      my++;
    }
  }
  cout << res << endl;
}
