#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

signed main(){
  int n; cin >> n;
  for(int range(i,0,n)){
    string l; cin >> l;
    deque<vector<int>> s;
    s.push_back(vector<int>());
    for(int range(k,0,l.size())){
      int res = 0;
      vector<int> ls;
        //cout << "@" << l[k] << endl;
        //cout << "l"  << s.size() << endl;
      switch(l[k]){
        case '[':
          s.push_back(vector<int>());
          break;
        case ']':
          res = 0;
          ls = s.back();
          s.pop_back();
          sort(all(ls));
          for(int range(u,0,(ls.size()+1)/2)){
            res += ls[u];
          }
          s.back().push_back(res);
          //cout << "<- " << res << endl;
          break;
        default:
          res = l[k] - '0';
          k++;
          while(k < l.size() && isdigit(l[k])){
            res = res * 10 + (l[k] - '0');
            k++;
          }
          res = (res + 1) / 2;
          k--;
          //cout << "d " << res << endl;
          s.back().push_back(res);
      }
    }
    cout << s[0][0] << endl;
  }
}
