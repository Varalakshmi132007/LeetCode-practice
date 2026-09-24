class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for(int i = 0 ; i <piles.size() ; i++){
            right = max(right , piles[i]);
        }

        int speed = right;
        while(left<=right){
            int mid = left + (right - left)/2;
            long long totalHr = 0;
            for(int i = 0 ; i < piles.size() ; i++){
                totalHr += (piles[i] + mid - 1)/mid;
            }
            if(totalHr <= h){
                speed = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
      return speed;
    }
};