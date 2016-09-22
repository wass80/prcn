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
  vector<int> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  sort(all(a));reverse(all(a));
  sort(all(b));reverse(all(b));
  bool ok = true;
  if (m > n) {
    cout << "YES" << endl;
    return 0;
  }
  rep(i, m){
    if(a[i] < b[i]) ok = false;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
