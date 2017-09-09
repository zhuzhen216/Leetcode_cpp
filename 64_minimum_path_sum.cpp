class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==0){
            return 0;
        }
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (i==0 && j==0) continue;
                else if (i==0){grid[i][j]=grid[i][j-1]+grid[i][j];}
                else if (j==0){grid[i][j]=grid[i-1][j]+grid[i][j];}
                else{
                    int up = i==0?0:grid[i-1][j];
                    int left = j==0?0:grid[i][j-1];
                    grid[i][j]=grid[i][j]+min(up,left);
                }
            }   
        }
    return grid[grid.size()-1][grid[0].size()-1];
    }
};
