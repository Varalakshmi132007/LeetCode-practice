class Solution {
public:
    string reverseWords(string s) {
       int n = s.length();
       string ans = "";

       reverse(s.begin(),s.end()); //reverse the string

       //Reverse the individual characters
       for(int i=0 ; i<n ; i++){
         string word = "";
         while(i<n && s[i] != ' '){
            word += s[i];
            i++;
         }

         reverse(word.begin(),word.end());
         //Adding the strings
         if(word.length() > 0){
            ans += " " + word;
         }
       } 
       return ans.substr(1);
    }
};