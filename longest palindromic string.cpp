// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.size()==0 || s=nullptr ){
//             return "";
//         }
//         int left=0;
//         int right=0;
//         for(int i=0;i<s.size();i++){
//             int len1=check(s,i,i);
//             int len2=check(s,i,i+1);
//             int len=max(len1,len2)

//             if(l)
//         }
//     }
// };
class Solution {
public:
    
    // Helper function to expand from center
    int expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;   // length of palindrome
    }
    
    string longestPalindrome(string s) {
        
        if (s.length() <= 1) return s;
        
        int start = 0, end = 0;
        
        for (int i = 0; i < s.length(); i++) {
            
            int len1 = expand(s, i, i);       // odd length
            int len2 = expand(s, i, i + 1);   // even length
            
            int len = max(len1, len2);
            
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end   = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};