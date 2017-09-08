class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()){
            return false;
        }
        map<int,int> counter;
        for (int num:nums){
            counter[num]++;
        }
        for (map<int,int>::const_iterator iter=counter.begin();iter!=counter.end();iter++){
            if (iter->second>1){
                return true;
            }
        }
        return false;
    }
};
