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

  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a.at(i);

  vector<int> node;
  set<int> node_set;
  int last_node;

  node.push_back(1);
  node_set.insert(1);
  REP(i, 1001001000){
    int current_node = node.at(i) - 1;
    int next_node = a.at(current_node);
    node.push_back(next_node);
    if (node_set.find(next_node) != node_set.end()){
      last_node = next_node;
      break;
    }
    node_set.insert(next_node);
  }

  int first_node_number;
  vector<int> answer_vector;
  REP(i, 1001001000){
    if (node.at(i) == last_node){
      first_node_number = i;
      break;
    }
  }

  FOR(i, first_node_number, node.size() - 1){
    answer_vector.emplace_back(node.at(i));
  }
  cout << answer_vector.size() << endl;
  for (const auto& item : answer_vector) {
      cout << item;
      if (&item != &answer_vector.back()) {
          cout << " ";
      }
  }
  cout << endl;
  return 0;
}
