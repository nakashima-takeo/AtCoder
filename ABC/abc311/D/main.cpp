#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i, n) cin >> s[i];

  // vectorに詰め替え
  vector<vector<bool>> ice_and_rock(n , vector<bool>(m));
  REP(i, n){
    REP(j, m){
      ice_and_rock[i][j] = s[i][j] == '.';
    }
  }

  vector<vector<bool>> result_ice_and_rock(n, vector<bool>(m, false)) ;
  set<pair<int,int>> reached_point_set;

  stack<pair<int, int>> point;
  point.push(pair(1, 1));
  result_ice_and_rock[1][1] = true;

  while(!point.empty()){
    pair<int, int> t = point.top();
    point.pop();

    pair<int,int> p;
    p = t;
    // 下方向
    while(true){
      pair<int,int> next_p = make_pair(p.first + 1, p.second);
      if(!ice_and_rock[next_p.first][next_p.second]){
        if(!reached_point_set.contains(p)){
          reached_point_set.insert(p);
          point.push(p);
        }
        break;
      }
      result_ice_and_rock[next_p.first][next_p.second] = true;
      p = next_p;
    }

    p = t;
    // 右方向
    while(true){
      pair<int,int> next_p = make_pair(p.first, p.second + 1);
      if(!ice_and_rock[next_p.first][next_p.second]){
        if(!reached_point_set.contains(p)){
          reached_point_set.insert(p);
          point.push(p);
        }
        break;
      }
      result_ice_and_rock[next_p.first][next_p.second] = true;
      p = next_p;
    }

    p = t;
    // 左方向
    while(true){
      pair<int,int> next_p = make_pair(p.first, p.second - 1);
      if(!ice_and_rock[next_p.first][next_p.second]){
        if(!reached_point_set.contains(p)){
          reached_point_set.insert(p);
          point.push(p);
        }
        break;
      }
      result_ice_and_rock[next_p.first][next_p.second] = true;
      p = next_p;
    }

    p = t;
    // 上方向
    while(true){
      pair<int,int> next_p = make_pair(p.first - 1, p.second);
      if(!ice_and_rock[next_p.first][next_p.second]){
        if(!reached_point_set.contains(p)){
          reached_point_set.insert(p);
          point.push(p);
        }
        break;
      }
      result_ice_and_rock[next_p.first][next_p.second] = true;
      p = next_p;
    }
  }


  int result = 0;
  for(const auto& row : result_ice_and_rock){
    for(const  auto& elem : row){
      if(elem) result++;
    }
  }

  cout << result << endl;

  // ここまで
  return 0;
}
