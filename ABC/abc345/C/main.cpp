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

  string s;
  cin >> s;

  sort(ALL(s));
  vector<ll> count;
  ll total_count = s.length();

  int tmp_count = 1;
  for(int i=1;i < s.length(); i++){
    if (s[i-1] == s[i]){
      tmp_count++;
      if(i == s.length() - 1){
        count.push_back(tmp_count);
      }
    } else{
      count.push_back(tmp_count);
      tmp_count = 1;
    }
  }

  bool all_one = true;
  REP(i, count.size()){
    if(count[i] != 1){
      all_one = false;
    }
  }

  ull result = 1;
  if(total_count == tmp_count){
    cout << result << endl;
  } else {
    result += total_count * (total_count - 1) / 2;
    REP(i, count.size()){
      result -= count[i] * (count[i] - 1) / 2;
    }
    if(all_one) result--;
    cout << result << endl;
  }

  // ここまで
  return 0;
}
