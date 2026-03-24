class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int lp = 0;
        int rp = height.size() - 1;

        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            int water = width * ht;

            ans = max(ans, water);  
            if (height[lp] < height[rp]) 
                lp++;
            else 
                rp--;
        }

        return ans;
    }
};