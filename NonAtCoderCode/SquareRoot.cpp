#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int square_root(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    return 0;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = square_root(n);
    std::cout << res << '\n';
}
