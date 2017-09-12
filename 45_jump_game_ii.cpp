class Solution {
public:
    int jump(vector<int>& nums) {
        int edge=0;
        int min_step =0;
        int max_reach = nums[0];
        for (int i=1;i<nums.size();i++){
            if (edge<i) {
                min_step++;
                edge = max_reach;
                if (edge >= nums.size()-1) return min_step;
            }
            max_reach = max(max_reach,i+nums[i]);
            if (max_reach==i) return -1;
        }
        return min_step;
        /*
        // NAIVE METHOD: ETL
        // dp problem
        //
        vector<int> dp(nums.size(),INT_MAX);
        dp[0]=0;
        for (int i=0;i<nums.size()-1;i++){
            if (dp[i]==INT_MAX) continue;
            if (nums[i]+i>=nums.size()-1){
                dp[nums.size()-1]=min(dp[nums.size()-1],dp[i]+1);
                continue;
            }
            else{
                for (int j=1;j<=nums[i];j++){
                    dp[i+j]=min(dp[i+j],dp[i]+1);
                }
            }
        }
        // cout<< dp[0] << " " << dp[1];
        return dp[nums.size()-1]; */
    }
};
