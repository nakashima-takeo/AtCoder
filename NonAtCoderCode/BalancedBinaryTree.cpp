#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};
std::pair <int,bool> dfs(Node<int>* tree){
    if (tree == nullptr){
        return std::pair(0, true);
    }
    std::pair left = dfs(tree->left);
    if(left.second == false) return left;
    std::pair right = dfs(tree->right);
    if(right.second == false) return right;
    int maxValue = std::max(left.first, right.first);
    if(std::abs(left.first - right.first) >= 2) return std::pair(maxValue, false);
    return std::pair(maxValue + 1, true);
}
// 解答だと、返り値にintを用いて、-1をfalseの代わりに用いていた。

bool is_balanced(Node<int>* tree) {
    return dfs(tree).second;
}

// this function builds a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    bool res = is_balanced(tree);
    std::cout << std::boolalpha << res << '\n';
}
