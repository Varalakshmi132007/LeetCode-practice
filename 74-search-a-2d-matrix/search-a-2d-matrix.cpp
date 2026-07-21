class Solution {
public:
    bool searchInMatrix(vector<vector<int>>& mat, int target , int row){
           int n = mat[0].size();
           int st = 0 , er = n-1;

           while(st<=er){
            int midRow = st + (er-st)/2;
            if(target == mat[row][midRow]){
                return true;
            }else if(mat[row][midRow] < target){
                st = midRow +1;
            } else{
                er = midRow - 1;
            }
         }
           return false;
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int startRow = 0 , endRow = m-1;

        while(startRow<=endRow){
            int mid = startRow + (endRow - startRow)/2;
            if(target >= mat[mid][0] && target <= mat[mid][n-1]){
                return searchInMatrix(mat, target, mid);
            }
            else if(target > mat[mid][n-1]){
              startRow = mid + 1;
            }else{
              endRow = mid-1;
            }
        }
         return false;
     }
    
};