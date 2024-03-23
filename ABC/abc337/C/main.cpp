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

  vector<int> a(n);
  REP(i, n) cin >> a[i];

  vector<int> result;

  map<int, int> map;

  REP(i, n){
    map[a[i]] = i+1;
  }

  int number = -1;
  while (true)
  {
    auto it = map.find(number);
    if(it == map.end()) break;
    number = it -> second;
    result.push_back(number);
  }

  REP(i, n){
    cout << result[i] << " ";
  }

  // ここまで
  return 0;
}
