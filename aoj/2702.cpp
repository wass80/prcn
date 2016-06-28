#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

const int d4x[] = {0, 1, 0, -1};
const int d4y[] = {1, 0, -1, 0};

int h, w, r, c;
void d4p(int y, int x, vector<vector<int>>& exc,
         deque<tuple<int,int>>& q){
  exc[y][x] = 1;
  REP(d, 4){
    int ny = y + d4y[d], nx = x + d4x[d];
    if(ny < 0 || nx < 0 || ny > h+1 || nx > w+1 ){
      continue;
    }
    if(exc[ny][nx] == 0){
      if(!(ny <= 0 || nx <= 0 || ny >= h+1 || nx >= w+1 )){
        q.push_back(make_tuple(ny,nx));
      }
    }
  }
}
void sss(const vector<vector<int>>& hv, const vector<vector<int>>& wv,
         const vector<vector<int>>& e,int ay ,int ax){
  for(int y = 1; y <= h; y++){
    for(int x = 1; x <= w; x++){
      
      if (y==ay && x==ax) cout << "x" ;
      else if(e[y][x]==0)cout << "." ;
      else cout << "*" ;
    }cout << endl;
  }
}
int main(){
  while(cin >> h >> w >> r >> c, h != 0){
    vector<vector<int>> hv(h, vector<int>(w+1));
    vector<vector<int>> wv(h+1, vector<int>(w));
    REP(i, w){
      cin >> wv[0][i];
    }
    REP(i,h){
      REP(j,w+1){
        cin >> hv[i][j];
      }
      REP(j,w){
        cin >> wv[i+1][j];
      }
    }
    vector<vector<int>> exc(h+2, vector<int>(w+2));
    deque<tuple<int,int>> q;
    REP(y, h+2){
      d4p(y,0, exc, q);
      d4p(y,w+1, exc, q);
    }
    REP(x, w+2){
      d4p(0,x, exc, q);
      d4p(h+1,x, exc, q);
    }
    while(!q.empty()){
      int y, x; tie(y, x) = q.front();
      q.pop_front();
      if(exc[y][x] == 1) continue;
      bool res = true;
      REP(wl,2){
        bool out = false;
        if(hv[y-1][x-1] == wl && exc[y][x-1] == 1){
          out = true;
        }
        if(hv[y-1][x] == wl && exc[y][x+1] == 1){
          out = true;
        }
        if(wv[y-1][x-1] == wl && exc[y-1][x] == 1){
          out = true;
        }
        if(wv[y][x-1] == wl && exc[y+1][x] == 1){
          out = true;
        }
        res = res && out;
      }
      if(res){
        d4p(y,x, exc, q);
      }
    }
    
    bool eee = false;
    if(hv[r-1][c-1] == 0 && exc[r][c-1] == 1){
      eee = true;
    }
    if(hv[r-1][c] == 0 && exc[r][c+1] == 1){
      eee = true;
    }
    if(wv[r-1][c-1] == 0 && exc[r-1][c] == 1){
      eee = true;
    }
    if(wv[r][c-1] == 0 && exc[r+1][c] == 1){
      eee = true;
    }
    if(eee){
      cout << "Yes" << endl;
    } else if(exc[r][c] == 1){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
