class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for (int i=1; i<triangle.size();i++){
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            dp[i][dp[i].size()-1]=dp[i-1][dp[i-1].size()-1]+triangle[i][triangle[i].size()-1];
            for (int j=1;j<dp[i].size()-1;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        int ret=dp[dp.size()-1][0];
        for (int i=1;i<dp[dp.size()-1].size();i++){
            ret = min(ret,dp[dp.size()-1][i]);
        }
        return ret;
    }
};
