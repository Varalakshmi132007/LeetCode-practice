class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i,j,k;
        int sum;
        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for(i = 0 ; i < nums.size() - 2 ; i++){
            for(j = i+1 ; j < nums.size() - 1 ; j++){
                 k = j+1;
                 while(k < nums.size()){
                 sum = nums[i] + nums[j] + nums[k];
                 if(abs(sum - target) < abs(closest - target) ){
                    closest  = sum;
                 }
            k++;
        }
        }
    }
        return closest;
    }
};
