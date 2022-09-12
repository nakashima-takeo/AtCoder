#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int binary_search(std::vector<int> arr, int target) {
    int index = arr.size() / 2;
    while (arr.size() != 0)
    {
        std::vector<int> brr;
        if (arr[index] == target) return index;
        else if (arr[index] > target)
        {
            brr.assign(&arr[0],&arr[index]);
            return binary_search(brr, target);
        }
        else if (arr[index] < target)
        {
            brr.assign(&arr[index + 1], &arr[arr.size()]);
            return binary_search(brr, target) + (index + 1);
        }
    }
    return -1;
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
