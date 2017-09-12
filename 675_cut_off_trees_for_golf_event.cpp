class Solution {
    static bool compare(vector<int> x,vector<int> y){
        return x[0]<y[0];
    }
    
    int helper(vector<vector<int>>& forest, vector<int> start, vector<int> end){
        queue<vector<int>> position;
        position.push(start);
        int count = 0;
        set<vector<int> > seen;
        while (!position.empty()){
            int cur_len = position.size();
            for (int i=0; i<cur_len;i++){
                vector<int> cur_tree = position.front();
                position.pop();
                seen.insert(cur_tree);
                if (cur_tree==end){
                    return count;
                }
                if (cur_tree[0]!=0 && forest[cur_tree[0]-1][cur_tree[1]]!=0 && seen.find({cur_tree[0]-1,cur_tree[1]})==seen.end()){
                    position.push({cur_tree[0]-1,cur_tree[1]});
                }
                if (cur_tree[0]!=forest.size()-1 && forest[cur_tree[0]+1][cur_tree[1]]!=0 && seen.find({cur_tree[0]+1,cur_tree[1]})==seen.end()){
                    position.push({cur_tree[0]+1,cur_tree[1]});
            }
                if (cur_tree[1]!=0 && forest[cur_tree[0]][cur_tree[1]-1]!=0 && seen.find({cur_tree[0],cur_tree[1]-1})==seen.end()){
                    position.push({cur_tree[0],cur_tree[1]-1});
                }
                if (cur_tree[1]!=forest[0].size()-1 && forest[cur_tree[0]][cur_tree[1]+1]!=0 && seen.find({cur_tree[0],cur_tree[1]+1})==seen.end()){
                    position.push({cur_tree[0],cur_tree[1]+1});
            }
        }
            count+=1;
    }
        return -1;
    }
        
    
    public:
    int cutOffTree(vector<vector<int>>& forest) {
        int ret=0;
        // first search trees need to be cutted
        // and then order them
        vector<vector<int> > trees;
        trees.push_back({0,0,0});
        for (int i=0;i<forest.size();i++){
            for (int j=0;j<forest[0].size();j++){
                if (forest[i][j]>1){
                    trees.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(trees.begin(),trees.end(),compare);
        for (int i=0; i<trees.size()-1;i++){
            int count = helper(forest,{trees[i][1],trees[i][2]},{trees[i+1][1],trees[i+1][2]});
            if (count==-1) return -1;
            ret += count;
        }
        return ret;
        
    }
};
