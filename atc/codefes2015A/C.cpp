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
  int n, t; cin >> n >> t;
  vector<int> a(n), b(n);
  vector<int> c(n);
  int sum = 0;
  rep(i, n) {
    cin >> a[i] >> b[i];
    c[i] = a[i] - b[i];
    sum += a[i];
  }
  sort(all(c)); reverse(all(c));
  int i;
  for(i = 0; i < c.size() && sum > t; i++){
    sum -= c[i];
  }
  if (sum > t) cout << -1 << endl;
  else cout << i << endl;
} 
