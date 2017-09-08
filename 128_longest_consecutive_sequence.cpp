class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // careful: 1. duplicated number
        // naive method with sort
        // need to use set
        // but can not deal with duplicated numbers
        unordered_map<int,int> map_len;
        //int num;
        //
        int maxArrayLen = 0;
        for(int i=0;i<nums.size();i++){
            //cout << i;
            //num = nums[i];
            //cout << nums[i];
            if (map_len.find(nums[i])!=map_len.end()){
                continue;
            }
            // map_len[nums[i]-1] seems donot work if nums[i]-1 not in map_len;
            int left = map_len.find(nums[i]-1)!=map_len.end()?map_len[nums[i]-1]:0;
            int right = map_len.find(nums[i]+1)!=map_len.end()?map_len[nums[i]+1]:0;
            map_len[nums[i]]=left+right+1;
            if (left!=0) map_len[nums[i]-left]=left+right+1;
            if (right!=0) map_len[nums[i]+right]=left+right+1;
            maxArrayLen = max(maxArrayLen,left+right+1);
        }
        return maxArrayLen;
    }
};
