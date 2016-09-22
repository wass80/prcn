#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> r(n, vector<int>(n));
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    r[x-1][y-1] = 1;
  }
  int res = 0;
  for(int i = 1; i < (1 << n); i++){
    bool ok = true;
    for(int j = 0; j < n; j++){
      if((i & (1 << j)) == 0) continue;
      for(int k = j + 1; k < n; k++){
        if((i & (1 << k)) == 0) continue;
        if(r[j][k] != 1) { ok = false; break; }
      }
      if(!ok) break;
    }
    if(ok){
      res = max(res, (int)__builtin_popcount(i));
    }
  }
  cout << res << endl;
}
