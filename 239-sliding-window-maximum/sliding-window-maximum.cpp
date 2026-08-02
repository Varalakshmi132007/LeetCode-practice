class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        //first window
        for(int i=0 ; i<k ; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
              dq.push_back(i); 
            }
        
        //store maximum of first window
        res.push_back(nums[dq.front()]);
        //remaining windows
        for(int i=k ; i<nums.size() ; i++){
         
         //remove not part of curr window
         while(dq.size()>0 && dq.front() <= i-k ){
            dq.pop_front();
         }  

        while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
              dq.push_back(i);
        
              res.push_back(nums[dq.front()]);
         }
         return res;
    }
};