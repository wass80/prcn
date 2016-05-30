#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

int p(int n){
  int res = 0;
  while(n!=0){
    if(n%2==1){
      res++;
    }
    n >>= 1;
  }
  return res;
}
tuple<int,int> maxp(int l, int r, int a, int b){
  //cout << "[" << l << "," << r << ") <- [" << a << "," << b << ")" << endl;
  if(b <= l || r <= a) {return make_tuple(0,-1);}
  if(l <= a && b <= r) {return make_tuple(p(b-1),-(b-1));}
  int mid = (a + b) / 2;
  return max(maxp(l, r, a, mid), maxp(l, r, mid, b));
}
signed main(){
  int n;
  cin >> n;
  for(int range(i,0,n)){
    int l, r;
    cin >> l >> r;
    cout << -get<1>(maxp(l, r+1,0,1ll<<62)) << endl;
  }
}

/*

00000
00001
00010
00011
00100
00101
00110
00111
01000
0100
..
01111
10000
10001
*/

