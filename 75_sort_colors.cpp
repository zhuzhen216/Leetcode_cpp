class Solution {
public:
    void sortColors(vector<int>& nums) {
        // three pointers
        // 
        int red_start = 0;
        int blue_end = nums.size()-1;
        int head = 0;
        while (red_start<nums.size()&&nums[red_start]==0){
            red_start++;
        }
        while (blue_end>red_start && nums[blue_end]==2){
            blue_end--;
        }
        head = red_start;
        while (head <= blue_end){
            // switch current element with either blue_end or red_start
            // the break condition is nums[head]==1 or head<=blue_end
            while (head<=blue_end && nums[head]!=1){
                if (nums[head]==2){
                int temp = nums[blue_end];
                nums[blue_end]=2;
                nums[head]=temp;
                // make sure blue_end is not blue
                while (nums[blue_end]==2){
                    blue_end--;}
                }
                if (nums[head]==0)
                {
                int temp = nums[red_start];
                nums[red_start]=0;
                nums[head]=temp;
                // make sure red_start is not red
                while (nums[red_start]==0){
                    red_start++;}
                }
                // red_start can be larger than head
                // then, we assign the value of red_start to head;
                if (red_start>head){
                    head = red_start;
                }
        }
        head++;
        }
    }
};
