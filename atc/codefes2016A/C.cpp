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
  string s; cin >> s;
  string res(s);
  int n; cin >> n;
  int rn = n;
  rep(i, s.size()){
    if (s[i] != 'a' && s[i] + rn > 'z'){
      res[i] = 'a';
      rn -= 'z' - s[i] + 1;
    }
  }
  res[s.size()-1] = (res[s.size()-1] + rn - 'a') % ('z' - 'a' + 1) + 'a';
  cout << res << endl;
  
}
