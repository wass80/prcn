#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

signed main(){
  int n;
  while(cin >> n, n != 0){
    vector<int> p(n), j(n-1);
    int ps = 0;
    for(int range(i,0,n)){
      cin >> p[i];
      ps += p[i];
    }
    for(int range(i,0,n-1)){
      cin >> j[i];
    }
    sort(all(j));
    int res = ps * n;
    int js = 0;
    for(int i = n; i >= 2; i--){
      res = max(res, (ps + js)*i);
      js += j[i-2];
    }
    res = max(res, (ps + js));
    cout << res << endl;
  }
}

/*
1 2 3 4 5
 4 3 2 1

1,1->6,1->12,1
        ->9,2
   ->3,2->9,2
        ->6,3

(S + a + b) * m

(S + a + j + b)* m-1

1 1 1 3*3
5 * 2
*/
