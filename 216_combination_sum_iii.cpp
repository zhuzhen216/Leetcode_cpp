class Solution {
    vector<vector<int>> ret;
    void helper(int k, int n, vector<int> path, int index){
        if (k==0 && n==0){
            ret.push_back(path);
            return;
        }
        if (k==0) return;
        if (n<index) return;
        for (int i=index;i<11-k;i++){
            path.push_back(i);
            helper(k-1,n-i,path,i+1);
            path.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(k,n,vector<int>(),1);
        return ret;
    }
};
