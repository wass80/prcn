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
  int n; cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  int mx = 1;
  int res = 0;
  rep(i, n){
    res += (x[i] - 1) / mx;
    if(mx == 1 || x[i] == mx){
      mx ++;
    }
  }
  cout << res << endl;
}
