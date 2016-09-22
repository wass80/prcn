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
  vector<int> a(m+1, 0);
  rep(i, n) {
    int aa; cin >> aa;
    a[aa] += 1;
  }
  int res = 0;
  rep(i, m+1){
    if (a[res] < a[i]){
      res = i;
    }
  }
  if (a[res] >= (n + 2) / 2) cout << res << endl;
  else cout << "?" << endl;
}
