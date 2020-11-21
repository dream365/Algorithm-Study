#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
 
int getAns(int* arr, int n) {
    bool start = false;
    int num = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1)
            if(start) {
                sum += num;
                num = 0;
            } else {
                start = true;
            }
 
        if(arr[i] == 0 && start)
            num++;
    }
 
    return sum;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }
 
        cout << getAns(arr, n) << endl;
    }
 
    return 0;
}

