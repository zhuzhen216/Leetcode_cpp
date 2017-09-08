class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dp[i][0] for smallest value ending in nums[i]
        // dp[i][1] for largest value ending in nums[i]
        vector<vector<int> > dp(nums.size(),vector<int>(2));
        // initialize min value
        dp[0][0]=nums[0];
        // initialize max value
        dp[0][1]=nums[0];
        int ret = dp[0][1];
        for (int i=1; i< nums.size();i++){
            if (nums[i]<0){
                dp[i][0]=min(nums[i]*dp[i-1][1],nums[i]);
                dp[i][1]=max(nums[i]*dp[i-1][0],nums[i]);
                ret = max(ret,dp[i][1]);
            }
            else{
                dp[i][0]=min(nums[i]*dp[i-1][0],nums[i]);
                dp[i][1]=max(nums[i]*dp[i-1][1],nums[i]);
                ret = max(ret,dp[i][1]);
            }
        }
        return ret;
    }
};
