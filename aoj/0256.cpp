#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

signed main(){
  int res = 0;
  for(int range(i,0,10)){
    int s; cin >> s;
    res += s;
  }
  cout << res << endl;
}
