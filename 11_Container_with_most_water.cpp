class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxWater = 0;
        while (start<end){
            if (height[start]<= height[end]){
                maxWater = max(maxWater,height[start]*(end-start));
                start++;
            }
            else{
                maxWater = max(maxWater,height[end]*(end-start));
                end--;
            }
            
        }
        return maxWater;
    }
};
