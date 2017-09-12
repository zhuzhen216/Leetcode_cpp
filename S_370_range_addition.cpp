class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret(length+1,0);
        for (int i=0;i<updates.size();i++){
            ret[updates[i][0]]+=updates[i][2];
            ret[updates[i][1]+1]-=updates[i][2];
            }
        // range sum
        for (int i=1;i<length;i++){
            ret[i]+=ret[i-1];
        }
        ret.pop_back();
        return ret;
    }
};
