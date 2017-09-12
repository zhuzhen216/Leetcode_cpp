class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int left = 0;
        int right = nums.size()-1;
        if (nums[left]>target) return 0;
        if (nums[right]<target) return nums.size();
        while (left < right){
            int mid = (left+right)/2;
            if (target==nums[mid]) return mid;
            else if (target < nums[mid]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
