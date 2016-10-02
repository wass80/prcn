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
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  int res = 0;
  rep(i, n){
    if(a[a[i]-1]-1 == i){
      res ++;
    }
  }
  cout << res/2 << endl;
}
