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

  vector<pair<int,int>> beans(n);
  REP(i, n) cin >> beans[i].second >> beans[i].first;

  map<int, int> color_value;
  int ans = 0;

  REP(i, n){
    auto it = color_value.find(beans[i].first);
    if(it == color_value.end()){
      color_value[beans[i].first] = beans[i].second;
    }else{
      int min_value = min(it->second, beans[i].second);
      color_value[beans[i].first] = min_value;
    }
  }

  for (auto &&i : color_value)
  {
    ans = max(ans, i.second);
  }

  cout << ans << endl;

  // ここまで
  return 0;
}
