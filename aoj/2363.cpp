#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
typedef long long ll;
typedef long double ld;
using namespace std;

const ld eps = 0.0000001;

ld calc(){
  int n, m; cin >> n >> m;
  vector<int> v(m);
  vector<ld>  r(m);
  ld sum = 0;
  ld reroll = 1;
  for(int range(i,0,m)){
    cin >> v[i] >> r[i];
    sum += v[i] * r[i];
    reroll -= r[i];
  }
  return sum / (1 - reroll);
}

signed main(){
  int t; cin>>t;
  ld m = 0;
  for(int range(i,0,t)){
    m = max(m, calc());
  }
  ld han = calc();
  if(han + eps < m){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

/*
y = X
    p -> y
y = X + p y
y = X/(1 - p)
p : re-roll
 */
