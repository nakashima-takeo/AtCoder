#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

template <typename T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, a, b;
  cin >> n >> a >> b;

  vector<int> d(n);
  REP(i, n) cin >> d[i];

  vector<int> d1Distance(n-1);
  for(int i=1; i <n; i++) d1Distance[i-1] = (d[i] - d[0]) % (a+b);
  int min_value = 0;
  int max_value = 0;
  REP(i, d1Distance.size()){
    if(a+b % 2)d1Distance[i] = d1Distance[i] - ((a+b) / 2);
    else d1Distance[i] = d1Distance[i] - ((a+b+1) /2);
  }

  REP(i, d1Distance.size()){
    max_value = max(max_value, d1Distance[i]);
    min_value = min(min_value, d1Distance[i]);
  }

  if(max_value - min_value < a) cout << "Yes" << endl;
  else cout <<"No" << endl;


  // ここまで
  return 0;
}
