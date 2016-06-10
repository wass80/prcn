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
    vector<vector<int>> p(n);
    for(int range(i,0,n)){
      int m;
      cin >> m;
      p[i] = vector<int>(m);
      for(int range(j,0,m)){
        cin >> p[i][j];
      }
      sort(all(p[i]));
    }
    int k;
    cin >> k;
    vector<int> l(k);
    for(int range(j, 0, k)){
      cin >> l[j];
    }
    sort(all(l));
    int id = -2;

    for(int range(i,0,n)){

      if(includes(all(p[i]), all(l))){
        if(id==-2){
          id = i;
        }else{
          id = -3;
        }
      }
    }
    cout << max(-1ll, id+1) << endl;
  }
}
