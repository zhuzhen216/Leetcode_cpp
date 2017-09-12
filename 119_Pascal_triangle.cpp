class Solution {
public:
    // need pay attention to the zeroth row [1]
    vector<int> getRow(int rowIndex) {
        vector<int> cur(1);
        cur[0]=1;
        for (int i=1;i<=rowIndex;i++){
            vector<int> next(i+1);
            next[0]=1;
            for (int j=1;j<i;j++){
                next[j]=cur[j]+cur[j-1];
            }
            next[i]=1;
            cur = next;
        }
        return cur;
    }
};
