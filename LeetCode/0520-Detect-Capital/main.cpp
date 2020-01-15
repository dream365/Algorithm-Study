#include <iostream>
#include <string>
using namespace std;

bool checkCapital(char a);
bool detectCapitalUse(string word);

int main() {
    string str;

    cin >> str;
    cout << detectCapitalUse(str);

    return 0;
}

bool checkCapital(char a) {
    if (a >= 'A' && a <= 'Z')
        return true;
    return false;
}

bool detectCapitalUse(string word) {
    bool isAllCap = true;
    bool isAllLow = true;
    bool is1stCap = false;
    bool is1st = true;
    for (size_t i = 0; i < word.length(); i++){
        if (checkCapital(word[i])) {
            isAllLow = false;
            if (is1st)
                is1stCap = true;
            else
                is1stCap = false;
        }
        else
            isAllCap = false;
        if (is1st)
            is1st = false;
    }

    if (!is1stCap && !isAllCap && !isAllLow)
        return false;
    return true;
}