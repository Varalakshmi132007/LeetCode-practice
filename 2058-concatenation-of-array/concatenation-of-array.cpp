class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size1 = nums.size();
        vector<int> ans(2*size1);

        for(int i = 0 ; i  < size1 ; i++){
            ans[i] = nums[i];
            ans[size1 + i] = nums[i];
        }
        return ans;
    }
};