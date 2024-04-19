#include <bits/stdc++.h>
using namespace std;
using long long ll;
using unsigned long long ull;
using long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n), end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  string s;
  cin >> s;

  map<int, int> count_map;
  vector<char> used_char;
  for (auto &&ch : s)
  {
    int count = 0;
    if (find(ALL(used_char), ch) != used_char.end())
      continue;
    for (auto &&ch_searched : s)
    {
      if (ch == ch_searched)
      {
        count++;
      }
    }
    count_map[count]++;
    used_char.push_back(ch);
  }

  for (auto &&i : count_map)
  {
    if (i.second != 2)
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  // ここまで
  return 0;
}
