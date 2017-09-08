class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out({1});
        for (int i=1; i<nums.size();i++){
            int temp = out[out.size()-1];
            out.push_back(nums[i-1]*temp);
        }
        int back = nums[nums.size()-1];
        int index = out.size()-2;
        while (index>=0){
            out[index]=out[index]*back;
            back=back*nums[index];
            index--;
        }
        return out;
    }
};
