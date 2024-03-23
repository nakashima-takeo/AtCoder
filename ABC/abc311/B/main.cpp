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

  int n, d;
  cin >> n >> d;
  vector<string> s(n);
  REP(i, n) cin >> s.at(i);

  vector<bool> holiday(d);
  REP(i, d) holiday.at(i) = true;
  REP(i, n){
    REP(j, d){
      if(s.at(i).at(j) == 'x') holiday.at(j) = false;
    }
  }

  int max_holidays = 0;
  int one_holiday = 0;
  REP(i, d){
    if(holiday.at(i) == true){
      one_holiday++;
    } else {
      max_holidays = max(max_holidays, one_holiday);
      one_holiday = 0;
    }
  }

  max_holidays = max(max_holidays, one_holiday);

  cout << max_holidays << endl;

  // ここまで
  return 0;
}
