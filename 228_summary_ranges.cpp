class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int start = 0;
        while (start < nums.size()){
            int end = start + 1;
            while (end < nums.size() && nums[end]==nums[end-1]+1){
                end++;
            }
            if (end==start+1){
                ret.push_back(to_string(nums[start]));
            }
            else {
                ret.push_back(to_string(nums[start])+"->"+to_string(nums[end-1]));
            }
            start = end;
        }
        return ret;
    }
};
