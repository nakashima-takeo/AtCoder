#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;

  vector<pair<int,int>> xy(n);
  REP(i, n) cin >> xy[i].first >> xy[i].second;

  vector<int> result(n);

  REP(i, n){
    int max_distance = 0;
    int max_distance_index = 1;
    REP(j, n){
      int distance = pow(xy[i].first - xy[j].first, 2) + pow(xy[i].second - xy[j].second, 2);
      if(distance > max_distance) max_distance_index = j+1;
      max_distance = max(max_distance, distance);
    }
    result[i] = max_distance_index;
  }

  REP(i, n) cout << result[i] << endl;

  // ここまで
  return 0;
}
