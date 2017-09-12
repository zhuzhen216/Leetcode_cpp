class Solution {
    vector<vector<int>> ret;
    void helper(vector<int> path,int target,int index,const vector<int>& candidates){
        if (target<0){
            return;
        }
        if (target==0){
            ret.push_back(path);
        }
        for (int i=index;i<candidates.size();i++){
            if (target < candidates[index]){
                return;
            }
            path.push_back(candidates[i]);
            helper(path,target-candidates[i],i,candidates);
            path.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;  
        helper(path,target,0,candidates);
        return ret;
    }
};
