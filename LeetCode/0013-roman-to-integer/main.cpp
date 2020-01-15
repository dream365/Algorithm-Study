class Solution {
public:
    int getNum(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++)
        {

            if(getNum(s[i]) < getNum(s[i+1]))
            {
                sum += getNum(s[i+1]) - getNum(s[i]);
                i++;
            }
            else
                sum += getNum(s[i]);
        }
        return sum;
    }
};
