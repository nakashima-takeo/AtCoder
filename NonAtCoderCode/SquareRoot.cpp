#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <cmath>
using namespace std;

int square_root(int n) {
    int right = n;
    int left = 0;
    int mid = 0;
    int square = 0;
    while (right >= left)
    {
        mid = (left + right) / 2;
        square = pow(mid, 2);
        if(square == n)
        {
            return mid;
        }
        else if (square > n)
        {
            right = mid - 1;
        }
        else
        {
            if(pow((mid + 1), 2) > n)
            {
                return mid;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
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
