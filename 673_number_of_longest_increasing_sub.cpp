class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ret = 0;
        vector<int> dp_len(nums.size(),1);
        vector<int> dp_count(nums.size(),1);
        for (int i=1;i<nums.size();i++){
            for (int j=0;j<i;j++){
                if (nums[i]>nums[j]){
                    if (dp_len[j]+1>dp_len[i]){
                        dp_len[i] = dp_len[j] +1;
                        dp_count[i] = dp_count[j];
                    }
                    else if (dp_len[j]+1==dp_len[i]){
                        dp_count[i]+=dp_count[j];
                    }
                }
            }
        }
        int max_len=*max_element(dp_len.begin(),dp_len.end());
        int ret_count=0;
        for (int i=0;i<nums.size();i++){
            if (dp_len[i]==max_len){
                ret_count+=dp_count[i];
            }
        }
        return ret_count;
    }
};
