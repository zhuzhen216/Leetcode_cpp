class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // whether there are duplicate numbers?
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        for (int i=0;i<nums.size()-2;i++){
            if (nums[i]+nums[i+1]+nums[i+2]>=target) return ret;
            int left = i+1;
            int right = nums.size()-1;
            while (left < right){
                while (left<right && nums[left]+nums[right]>=target-nums[i]){
                    right--;
                }
                ret+=right-left;
                left++;
            }
        }
        return ret;
    }
};
