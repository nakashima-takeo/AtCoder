#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int binary_search(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) { // <= here because left and right could point to the same element, < would miss it
        int mid = left + (right - left) / 2; // use `(right - left) /2` to prevent `left + right` potential overflow
        // found target, return its index
        if (arr.at(mid) == target) return mid;
        if (arr.at(mid) < target) {
            // middle less than target, discard left half by making left search boundary `mid + 1`
            left = mid + 1;
        } else {
            // middle greater than target, discard right half by making right search boundary `mid - 1`
            right = mid - 1;
        }
    }
    return -1; // if we get here we didn't hit above return so we didn't find target
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = binary_search(arr, target);
    std::cout << res << '\n';
}