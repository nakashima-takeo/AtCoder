#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int h, w;
  cin >> h >> w;

  auto experimentalGrid = vector<vector<int>>(h, vector<int>(w, 1));
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){

      if(s[j] == '#'){
        experimentalGrid[i][j] = -1;
        if(i != h-1) experimentalGrid[i+1][j] = 0;
        if(i != 0) experimentalGrid[i-1][j] = 0;
        if(j != w-1) experimentalGrid[i][j+1] = 0;
        if(j != 0) experimentalGrid[i][j-1] = 0;
      }
    }
  }

  int result = 0;
  rep(i, h)rep(j, w){
    int max_mas = 0;
    if(experimentalGrid[i][j] == -1) continue;
    stack<pair<pair<int,int>, int>> next_survey;
    next_survey.push(make_pair(make_pair(i,j), experimentalGrid[i][j]));
    while(!next_survey.empty()){
      max_mas += 1;
      if(experimentalGrid[i][j] == 0)  continue;
      auto nextP = next_survey.top(); next_survey.pop();
      int pi = nextP.first.first;
      int pj = nextP.first.second;
      experimentalGrid[pi][pj] = -1;
      if(pi != h-1){
        if(experimentalGrid[pi+1][pj] != -1){
          experimentalGrid[pi+1][pj] = nextP.second + 1;
          next_survey.push(make_pair(make_pair(pi+1,pj),nextP.second + 1));
        }
      }
      if(pi != 0){
        if(experimentalGrid[pi-1][pj] != -1){
          experimentalGrid[pi-1][pj] = nextP.second + 1;
          next_survey.push(make_pair(make_pair(pi-1,pj),nextP.second + 1));
        }
      }
      if(pj != w-1){
        if(experimentalGrid[pi][pj+1] != -1){
          experimentalGrid[pi][pj+1] = nextP.second + 1;
          next_survey.push(make_pair(make_pair(pi,pj+1),nextP.second + 1));
        }
      }
      if(pj != 0){
        if(experimentalGrid[pi][pj-1] != -1){
          experimentalGrid[pi][pj-1] = nextP.second + 1;
          next_survey.push(make_pair(make_pair(pi,pj-1),nextP.second + 1));
        }
      }
    }
    result = max(max_mas, result);
  }

  cout << result << endl;

  // ここまで
  return 0;
}
