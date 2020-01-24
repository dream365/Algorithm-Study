class Solution {
public:
    int getDigits(int num) {
        int digits = 0;
        int curNum = num;
        
        while(curNum != 0) {
            curNum /= 10;
            digits++;
        }
        
        return digits;
    }
    
    int getSeqNum(int startNum, int digits) {
        int seqNum = 0;
        int multiplyNum = 1;
        
        for(int i = startNum + digits - 1; startNum <= i; i--) {
            seqNum += i * multiplyNum;
            multiplyNum *= 10;
        }
        
        return seqNum;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int fromDigit = getDigits(low);
        int toDigit = getDigits(high);
        
        for(int digit = fromDigit; digit <= toDigit; digit++) {
            for(int i = 1; i <= 10 - digit; i++) {
                int curSeqNum = getSeqNum(i, digit);
                
                if(curSeqNum < low)
                    continue;
                
                if(high < curSeqNum)
                    break;
                
                ans.push_back(curSeqNum);
            }
        }
        
        return ans;
    }
};
