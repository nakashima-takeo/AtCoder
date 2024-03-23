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
  int n;
  cin >> n;
  vector<pair<char, char>> hands(n);
  REP(i, n){
    pair<char, char> p;
    cin >> p.first >> p.second;
    hands[i] = p;
  }

  int result = 0;

  REP(i, n){
    if (hands[i].first == 'P' && hands[i].second == 'G') result++;
    if (hands[i].first == 'C' && hands[i].second == 'P') result++;
    if (hands[i].first == 'G' && hands[i].second == 'C') result++;
  }

  cout << result << endl;

  return 0;
}
