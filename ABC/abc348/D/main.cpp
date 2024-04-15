#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<vector<int>> Graph;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  Graph graph;

  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid_info(h, vector<int>(w));
  REP(i, h) REP(j, w) cin >> grid_info[i][j];

  REP(i, h){
    REP(j, w){
      if(grid_info[i][j] != '#'){
        if(i != 0 && grid_info[i-1][j] != '#'){
          graph[i,j].push_back());
          graph[(i-1)*w+j].push_back(i*w+j);
        }
        if(j != 0 && grid_info[i][j-1] != '#'){
          graph[i*w+j].push_back(i*w+j-1);
          graph[i*w+j-1].push_back(i*w+j);
        }
        if(i != h-1 && grid_info[i+1][j] != '#'){
          graph[i*w+j].push_back((i+1)*w+j);
          graph[(i+1)*w+j].push_back(i*w+j);
        }
        if(j != w-1 && grid_info[i][j+1] != '#'){
          graph[i*w+j].push_back(i*w+j+1);
          graph[i*w+j+1].push_back(i*w+j);
        }
      }
    }
  }

  int n;
  cin >> n;
  vector<tuple<pair<int,int>, int, bool>> drags(n);
  REP(i, n){
    cin >> get<0>(drags[i]).first >> get<0>(drags[i]).second >> get<1>(drags[i]);
    get<2>(drags[i]) = false;
  }
  REP(i, n){
    get<0>(drags[i]).first = get<0>(drags[i]).first - 1;
    get<0>(drags[i]).second = get<0>(drags[i]).second - 1;
  }

  pair<int, int> current_position = {0, 0};
  REP(i, h){
    REP(j, w){
      if(grid_info[i][j] == 'S'){
        current_position = {i, j};
        break;
      }
    }
  }

  queue<pair<pair<int,int>, int>> unused_drags;
  REP(i, n){
    if(current_position.first = get<0>(drags[i]).first && current_position.second = get<0>(drags[i]).second){
      get<2>(drags[i]) = true;
      pair<pair<int,int>, int> drag = make_pair(get<0>(drags[i]), get<1>(drags[i]));
      unused_drags.push(drag);
    }
  }


  while(!unused_drags.empty()){
    pair<pair<int,int>, int> drag = unused_drags.front();
    unused_drags.pop();
    current_position = drag.first;
    int drag_energy = drag.second;

    
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
