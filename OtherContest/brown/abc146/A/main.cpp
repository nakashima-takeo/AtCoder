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

  map<string, int> daysUntilSunday = {
    {"SUN", 7},
    {"MON", 6},
    {"TUE", 5},
    {"WED", 4},
    {"THU", 3},
    {"FRI", 2},
    {"SAT", 1}
  };

  string s;
  cin >> s;

  cout << daysUntilSunday[s] << endl;

  // ここまで
  return 0;
}
