// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int low = 0;
//         int high = s.length() - 1;

//         while (low < high) {

//             if (!isalnum(s[low])) {
//                 low++;
//                 continue;
//             }

//             if (!isalnum(s[high])) {
//                 high--;
//                 continue;
//             }

//             if (tolower(s[low]) != tolower(s[high]))
//                 return false;

//             low++;
//             high--;
//         }

//         return true;
//     }
// };
class Solution {
public:

    bool fun(string &s, int low, int high) {
        if (low >= high)
            return true;

        if (s[low] != s[high])
            return false;

        return fun(s, low + 1, high - 1);
    }

    bool isPalindrome(string s) {
        
        // Step 1: Clean the string
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {              // keep letters & numbers
                temp += tolower(s[i]);        // convert to lowercase
            }
        }

        // Step 2: Check palindrome
        return fun(temp, 0, temp.length() - 1);
    }
};