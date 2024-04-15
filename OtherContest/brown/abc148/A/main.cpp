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

  vector<int> vec = {1, 2, 3};

  // AとBを入力
  int A, B;
  cin >> A >> B;

  // Aをベクターから削除
  vec.erase(remove(vec.begin(), vec.end(), A), vec.end());

  // Bをベクターから削除
  vec.erase(remove(vec.begin(), vec.end(), B), vec.end());

  // 残った値が答え
  cout << vec.front() << endl;

  return 0;
}
