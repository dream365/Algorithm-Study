class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                bool isFound = false;
                
                if(nums1[i] == nums2[j]) {
                    isFound = true;
                    int idx = ++j;
                    for(int k = j; k < nums2.size(); k++){
                        if(nums1[i] < nums2[k]) { 
                            ans[i] = nums2[k];
                            break;
                        }
                    }
                }
                
                if(isFound)
                    break;
            }
        }
        
        return ans;
    }
};
