#include <iostream>
using namespace std;

int main()
{
    class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int count = 0;
            if (s.length() == 0)
                return true;
            for (int i = 0, j = 0; i < s.length(), j < t.length();)
            {
                if (s[i] != t[j])
                {
                    j++;
                }
                else
                {
                    i++;
                    j++;
                    count++;
                    if (count == s.length())
                        return true;
                }
            }
            return false;
        }
    };
}
