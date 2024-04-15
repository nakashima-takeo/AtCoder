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

  map<char,int> m;

  for (char c : s) {
    ++m[c]; // キーcの値をインクリメント。キーが存在しなければ自動的に追加され、値は0で初期化されるため、1になる。
  }

  for (auto &&i : m)
  {
    if(i.second != 2){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  // ここまで
  return 0;
}
