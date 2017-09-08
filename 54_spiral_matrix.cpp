class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()){
            return vector<int>();
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ret(row*col);
        int k=0, up = 0, down = row-1, left = 0, right = col-1;
        while (true){
            for (int i=left; i<=right; i++){
                ret[k]=matrix[up][i];
                k++;
            }
            if (++up>down){break;}
            for (int i=up;i<=down;i++){
                ret[k]=matrix[i][right];
                k++;
            }
            if (--right<left) break;
            for (int i=right;i>=left;i--){
                ret[k]=matrix[down][i];
                k++;
            }
            if (--down<up) break;
            for (int i=down;i>=up;i--){
                ret[k]=matrix[i][left];
                k++;
            }
            if (++left>right) break;
        }
        return ret;
    }
};
