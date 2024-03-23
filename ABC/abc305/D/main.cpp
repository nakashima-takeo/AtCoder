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
  vector<int> sleepHistory(n);
  REP(i, n) cin >> sleepHistory[i];
  int q;
  cin >> q;
  vector<pair<int, int>> lr(q);
  REP(i, q) cin >> lr[i].first >> lr[i].second;

  vector<int> totalSleepTime(n);
  int total = 0;
  for(int i = 2; i < n; i++){
    if(i % 2 == 0){
      total += sleepHistory[i] - sleepHistory[i-1];
    }
    totalSleepTime[i] = total;
  }

  vector<int> result(q);

  REP(i, q){
    int first_distance = 0;
    int second_distance = 0;
    auto it = lower_bound(ALL(sleepHistory), lr[i].first);
    int index = it - sleepHistory.begin();
    if(index % 2 == 0){
      first_distance += lr[i].first - *it;
    }
    first_distance += totalSleepTime[index];

    it = lower_bound(ALL(sleepHistory), lr[i].second);
    index = it - sleepHistory.begin();
    if(index % 2 == 0){
      second_distance += lr[i].second - *it;
    }
    second_distance += totalSleepTime[index];

    result[i] = second_distance - first_distance;
  }

  REP(i, q){
    cout << result[i] << endl;
  }

  // ここまで
  return 0;
}
