class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int min_subarray = INT_MAX;
        int i=0,j=0;
        while (j<nums.size()){
            sum+=nums[j++];
            while (sum>=s){
                min_subarray = min(min_subarray,j-i);
                sum-=nums[i++];
            }
        }
        return min_subarray==INT_MAX?0:min_subarray;
    }
};
