class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // check from the tail
        int end = nums.size()-1;
        // need to be nums[end]<=nums[end-1] for the cases of equal nums
        while (end>0 && nums[end]<=nums[end-1]){
            end--;
        }
        
        // if (5,4,3,2,1) -> (1,2,3,4,5)
        
        if (end==0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        end--;
        
        // switch the smallest with current
        int forward = end+1;
        while (forward < nums.size() && nums[forward]>nums[end]){
            forward++;
        }
        int temp = nums[end];
        nums[end]=nums[forward-1];
        nums[forward-1]=temp;
        reverse(nums.begin()+end+1,nums.end());
        
    }
};
