class Solution {
public:
    bool isValid(vector<int>& nums, int k, long long maxSum) {
        int parts = 1;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            }
            else {
                parts++;
                sum = nums[i];
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long start = 0;
        long long end = 0;

        for (int i = 0; i < nums.size(); i++) {
            start = max(start, (long long)nums[i]);
            end += nums[i];
        }

        long long ans = end;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};