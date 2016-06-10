#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

int n;
bool hs(const string& str, const vector<int>& phi){
  //cout << "[" << str[n] <<"]" << endl;
  if(str[n] == '('){
    n++;
    bool l = hs(str, phi);
    bool r;
    switch(str[n]){
      case '*':
        n++;
        r = hs(str, phi);
        assert(str[n] == ')'); n++;
        return l && r;
      case '+':
        n++;
        r = hs(str, phi);
        assert(str[n] == ')'); n++;
        return l || r;
      case '-':
        n++; assert(str[n]=='>'); n++;
        r = hs(str, phi);
        assert(str[n] == ')'); n++;
        return (!l) || r;
    }
    cout << "(" << endl;
    assert(false);
  }else if(str[n] == '-'){
    n++;
    bool p = hs(str, phi);
    return !p;
  }else if(str[n] == 'T'){
    n++; return 1;
  }else if(str[n] == 'F'){
    n++; return 0;
  }else if('a'<=str[n] && str[n]<='k'){
    //cout << str[n]  << endl;
    bool p = phi[str[n] - 'a'];
    n++;
    return p;
  }
  cout << "hs" << endl;
  assert(false);
}
bool parse(const string& str, const vector<int>& phi){
  n = 0;
  bool pl = hs(str, phi);
  assert(str[n] == '=');
  n++;
  bool pr = hs(str, phi);
  return pl == pr;
}
bool tryp(const string& str, const vector<int>& phi){
  if(phi.size() == 11){
    return parse(str, phi);
  }
  vector<int> t(phi), f(phi);
  t.push_back(1);
  f.push_back(0);
  bool pt = tryp(str,t);
  bool pf = tryp(str,f);
  return pt && pf;
}
bool solve(const string& str){
  return tryp(str, vector<int>());
}
signed main(){
  string str;
  while(cin >> str, str != "#"){
    if(solve(str)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
