class Solution {
public:
    void getAllCombin(vector<int>& arr, int idx, int tar,
                      vector<vector<int>>& ans, vector<int>& combin) {

        // Target achieved
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }

        // Invalid
        if (idx == arr.size() || tar < 0) {
            return;
        }

        // TAKE
        combin.push_back(arr[idx]);

        // Same index because we can reuse the number
        getAllCombin(arr, idx, tar - arr[idx], ans, combin);

        // Backtrack
        combin.pop_back();

        // SKIP
        getAllCombin(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombin(arr, 0, tar, ans, combin);

        return ans;
    }
};