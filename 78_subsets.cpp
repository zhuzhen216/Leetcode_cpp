class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> cur;
        cur.push_back(vector<int>());
        for (int i=0;i<nums.size();i++){
            vector<vector<int>> next;
            for (int j=0;j<cur.size();j++){
                next.push_back(cur[j]);
                cur[j].push_back(nums[i]);
                next.push_back(cur[j]);
            }
            cur = next;
        }
        return cur;
    }
};
