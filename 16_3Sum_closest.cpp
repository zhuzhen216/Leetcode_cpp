class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()<3) return NULL;
        sort(nums.begin(),nums.end());
        int diff = nums[0]+nums[1]+nums[2]-target;
        for (int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while (left<right){
                int curDiff = nums[i]+nums[left]+nums[right]-target;
                diff = abs(diff)<abs(curDiff)?diff:curDiff;
                if (curDiff==0) return target;
                else if (curDiff<0) left++;
                else right--;
            }
        }
        return target+diff;
    }
};
