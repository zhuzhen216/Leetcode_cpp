class Solution {

    int helper(vector<int>::const_iterator start,vector<int>::const_iterator end){
        if (end-start==0 || end-start==1) return 0;
        
        int ret = 0;
        int min_val = *start;
        for (int i=1;start+i<end;i++){
            if (*(start+i)<min_val){
                min_val = *(start+i);
            }
            else{ret = max(*(start+i)-min_val,ret);};
            }
        return ret;
    }
    public:
    int maxProfit(vector<int>& prices) {
        int ret=0;
        for (int i=0;i<prices.size();i++){
            ret = max(helper(prices.begin(),prices.begin()+i)+helper(prices.begin()+i,prices.end()),ret);
        }
    return ret;
    }
};
