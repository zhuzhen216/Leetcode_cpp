class Solution {
    vector<vector<int> > ret;
    void helper(vector<int>& candidates, vector<int>& path, int index, int target){
        if (target == 0) {
            ret.push_back(path);
            return;
        }
        if (target < 0 || index==candidates.size()) {
            return;
        }
        for (int i=index; i<candidates.size();i++){
            // be careful about i> index condition.
           if(i!=0&&candidates[i]==candidates[i-1]&&i>index){continue;}
            path.push_back(candidates[i]);
            helper(candidates,path,i+1,target-candidates[i]);
            path.pop_back();
        }
        
    }
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return vector<vector<int> >();
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        helper(candidates,path,0,target);
        return ret;
    }
};
