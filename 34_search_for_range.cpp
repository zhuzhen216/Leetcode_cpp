class Solution {
    // really need to be careful about the len==1 case
    int found(vector<int>& nums, int target){
        if (nums.empty()) return -1;
        if (nums.size()==1){
            if (nums[0]==target) return 0;
            else return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        // int mid = (left+right)/2;
        while (left < right){
            int mid = (left+right)/2;
            if (nums[left]==target) return left;
            if (nums[right]==target) return right;
            if (nums[mid]==target) return mid;
            if (nums[mid]<target) left=mid+1;
            else right=mid;
            
        }
        return -1;
    }
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        //cout << ret[0] << " " << ret[1];
        int found_index = found(nums,target);
        cout << found_index;
        if (found_index==-1) return ret;
        else{
            int left = found_index-1;
            int right = found_index+1;
            while (left>0 && nums[left]==target) left--;
            ret[0]=++left;
            while (right<nums.size()&&nums[right]==target) right++;
            ret[1]=--right;
            return ret;
        }
    }
};
