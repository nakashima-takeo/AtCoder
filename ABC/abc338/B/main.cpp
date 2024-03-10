#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(n) begin(n), end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  string s;
  cin >> s;

  sort(ALL(s));
  int max_numbers_of_chars = 0;
  int numbers_of_chars = 0;
  char max_frequent_char;
  max_frequent_char = s.at(0);

  if (s.length() == 1)
  {
    cout << max_frequent_char << endl;
    return 0;
  }

  REP(i, s.length() - 1)
  {
    char c = s.at(i);
    char next_c = s.at(i + 1);

    if (c == next_c)
    {
      numbers_of_chars++;
    }
    else
    {
      if (max_numbers_of_chars < numbers_of_chars)
      {
        max_frequent_char = c;
        max_numbers_of_chars = numbers_of_chars;
      }
      numbers_of_chars = 0;
    }
  }

  if (max_numbers_of_chars < numbers_of_chars)
  {
    max_frequent_char = s[s.length() - 1];
  }

  cout << max_frequent_char << endl;

  // ここまで
  return 0;
}
