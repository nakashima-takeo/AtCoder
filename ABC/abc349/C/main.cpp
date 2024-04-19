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

  string s, t;
  cin >> s >> t;

  // tを小文字に
  for (char &c : t)
  {
    c = std::tolower(static_cast<unsigned char>(c));
  }

  vector<int> place(2);
  place[0] = std::numeric_limits<int>::max() - 10;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == t[0])
    {
      place[0] = i;
      break;
    }
  }

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == t[2])
    {
      if (place[0] == i)
        continue;
      place[1] = i;
    }
  }

  for (int i = place[0] + 1; i < place[1]; i++)
  {
    if (s[i] == t[1])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (t[2] == 'x')
  {
    for (int i = place[0] + 1; i <= s.length(); i++)
    {
      if (s[i] == t[1])
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
