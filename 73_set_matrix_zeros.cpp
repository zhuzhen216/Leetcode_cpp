class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // two pass possible
        // first pass record all the column and row number that contain 0
        // second pass, convert all the rows and columns
        set<int> rows;
        set<int> columns;
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (set<int>::const_iterator iter=rows.begin();iter!=rows.end();iter++){
            int row = *iter;
            for (int j=0;j<matrix[row].size();j++){
                matrix[row][j]=0;
            }
        }
        for (set<int>::const_iterator iter=columns.begin();iter!=columns.end();iter++){
            int column = *iter;
            for (int j=0;j<matrix.size();j++){
                matrix[j][column]=0;
            }
        }
        
    }
};
