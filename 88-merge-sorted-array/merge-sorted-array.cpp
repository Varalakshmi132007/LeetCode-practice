class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n)
     {
        int index = m+n-1;
         
        int i = m-1;
        int j =n-1;
       
        while(i>=0 && j>=0)
        {
            if (a[i]>b[j])
            {
             a[index]=a[i];
             i--;
             index--;
            }
            else
            {
                a[index]=b[j];
                j--;
                index--;
            }

        }
        while(j>=0)
        {
            a[index]= b[j];
            index--;
            j--;
        }
     }
};