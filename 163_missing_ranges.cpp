class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int start = lower;
        int end = upper;
        vector<string> ret;
        for (int i=0; i<nums.size();i++){
            if (start < nums[i]){
                if (start==nums[i]-1) ret.push_back(to_string(start));
                else ret.push_back(to_string(start)+"->"+to_string(nums[i]-1));
            }
            // be careful about the INT_MAX
            if (nums[i]==INT_MAX) return ret;
            start = nums[i] + 1;
        }
        if (start==upper) {
            ret.push_back(to_string(start));
            return ret;
        }
        else if (start < upper){
            ret.push_back(to_string(start)+"->"+to_string(upper));
            return ret;
        }
        else return ret;
    }
};
