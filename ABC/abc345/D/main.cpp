#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

vector<vector<vector<bool>>> putTile(vector<vector<bool>> space, pair<int,int> tile, int row_count, int column_count){
  vector<vector<vector<bool>>> result;
  REP(a, row_count){
    REP(b, column_count){
      bool ok_flag = !space[a][b];
      REP(i, tile.first){
        if(a+i >= row_count - 1) break;
        if(!ok_flag) break;
        REP(j, tile.second){
          if(b+j >= column_count -1) break;
          if(space[a+i][b+j]){
            ok_flag = false;
            break;
          }
          if(i == tile.first -1 && j == tile.second -1){
            vector<vector<bool>> result1 = space;
            REP(k,tile.first){
              REP(l, tile.second){
                result1[a+i][b+j] = true;
              }
            }
            result.push_back(result1);
          }
        }
      }
    }
  }
  return result;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, h, w;
  cin >> n >> h >> w;

  vector<pair<int, int>> tiles(n);
  REP(i, n){
    cin >> tiles[i].first >> tiles[i].second;
  }

  vector<vector<bool>> space(h, vector<bool>(w, false));
  vector<vector<vector<bool>>> s;
  s.push_back(space);
  REP(i, n){
    REP(j, s.size()){
      auto new_s = putTile(s[j], tiles[i], h, w);
      REP(k, new_s.size()){
        s.push_back(new_s[k]);
      }
    }
    REP(l, s.size()){
      bool ok_flag = true;
      REP(a, h){
        if(!ok_flag) break;
        REP(b, w){
          if(!ok_flag) break;
          if(s[l][a][b] == false){
            ok_flag = false;
            break;
          }
          if(a == h-1 && b == w-1){
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
