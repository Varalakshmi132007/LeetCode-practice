class Solution {
public:
    void solve(vector<int>& candidates, int target, int start,
               vector<int>& current, vector<vector<int>>& ans) {

        // Base case
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // If current number is greater than target, skip it
            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // i, not i+1 because we can reuse the same element
            solve(candidates, target - candidates[i], i,
                  current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};