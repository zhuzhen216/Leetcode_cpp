class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> index;
        heights.push_back(0);
        // it is important to initialize ret;
        int ret=0;
        for (int i=0;i<heights.size();i++){
            while (index.size()>0 && heights[index.back()]>=heights[i]){
                int h = heights[index.back()];
                index.pop_back();
                int left = index.size()!=0?index.back():-1;
                ret = max(ret,h*(i-left-1));
            }
            index.push_back(i);
        }
        return ret;
    }
};
