#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_first_occurrence(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right)
    {
        int mid = (right + left) / 2;
        if (arr[mid] == target)
        {
            if (arr[mid - 1] == target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
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
    int res = find_first_occurrence(arr, target);
    std::cout << res << '\n';
}
