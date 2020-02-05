class Solution {
public:
    static bool compare(vector<int>& point1, vector<int>& point2)
    {
        int a = pow(point1[0],2) + pow(point1[1],2);
        int b = pow(point2[0],2) + pow(point2[1],2);
        if(a < b)
            return true;
        else
            return false;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> answer;
        sort(points.begin(),points.end(),compare);
        for(int i = 0; i < K; i++)
        {
            answer.push_back(points[i]);
        }
        return answer;
    
    }
};