class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivot = -1;
      
        //Find the pivot
        for(int i=n-2; i>=0 ;i--){
            if(A[i]<A[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(A.begin(),A.end());
            return;
        }

       //swap the pivot with highest number
       for(int i=n-1; i>pivot ;i--){
        if(A[i]>A[pivot]){
            swap(A[i],A[pivot]);
            break;
        }
       }
       
       //reverse the last elements
       reverse(A.begin() + pivot + 1,A.end());

    }
};