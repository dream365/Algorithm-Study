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
 
int ansPerDigit[4] = {1,3,6,10};
 
int getDigits(int num) {
    int temp = num;
    int digit = 1;
    
    while(temp / 10 != 0) {
        temp /= 10;
        digit++;
    }
 
    return digit;
}
 
int getFirstNum(int num) {
    char charNum = to_string(num).c_str()[0];
    return charNum - '0';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
 
    for(int i = 0; i < N; i++) {
        int boring;
        cin >> boring;
        int ans = 0;
        int firstNum = getFirstNum(boring);
        ans += (firstNum - 1) * 10;
        ans += ansPerDigit[getDigits(boring)-1];
        cout << ans << endl;
    }
 
    return 0;
}
