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
 
int array_max(int arr[], int size) {
    int max = arr[0];
    for(int i=1; i<size; i++) if(arr[i]>max) max=arr[i];
    return max;
}
 
int isDominant(int arr[], int n) {
    int max = array_max(arr, n);
    bool isEdible = false;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(max == arr[i]) {
            if(0 <= i-1 && arr[i-1] < max) {
                idx = i;
                isEdible = true;
                break;
            }
            
            if(i+1 <= n-1 && arr[i+1] < max) {
                idx = i;
                isEdible = true;
                break;
            }
        }
    }
 
    return isEdible ? idx + 1 : -1;
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
        bool isAnyDominant = false;
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }
 
        cout << isDominant(arr, n) << endl;
    }
 
    return 0;
}
