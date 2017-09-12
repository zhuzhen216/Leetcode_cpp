class Solution {
public:
    bool canJump(vector<int>& nums) {
        // possible to store whether it is possible to reach
        // certain position
        //
        // something needed to be taken care of: when reaching an
        // element, making jumps could be out of boundary.
        //
        vector<int> possible(nums.size(),0);
        possible[0]=1;
        for (int i=0;i<nums.size();i++){
            if (possible[i]==0) continue;
            for (int j=0;j<nums[i];j++){
                if (i+j+1>=nums.size()){
                    return true;
                }
                possible[i+j+1]=1;
            }
        }
        if (possible[nums.size()-1]==1){
            return true;
        }
        else{
            return false;
        }
    }
};
