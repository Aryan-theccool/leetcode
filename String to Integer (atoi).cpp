// class Solution {
// public:
//     int myAtoi(string s) {
//         int n=s.size();
//        vector<int> vc(n);
//        vector<int>temp(n);
//        for(int i=0;i<s.size();i++){
//         if(s[i]==''){
//             continue;
//         }
//         if(s[i]=='+' || s[i]=='-'){
//             vc[i]=s[i];

//         }
//         if(s[i]=='0' && !temp.empty()){
//             temp[i]=s[i];
//         }
//         if(s[i]=='0'){
//             vc[i]=s[i];
//         }
        
//        } 
//        return vc;
//     }
// };
class Solution {
public:
    int myAtoi(string s) {
        
        long num = 0;
        int sign = 1;
        bool started = false;

        for(int i = 0; i < s.size(); i++)
        {
            if(!started && s[i] == ' ')
                continue;

            if(!started && (s[i] == '+' || s[i] == '-'))
            {
                sign = (s[i] == '-') ? -1 : 1;
                started = true;
                continue;
            }

            if(isdigit(s[i]))
            {
                started = true;
                num = num * 10 + (s[i] - '0');

                if(sign * num > INT_MAX)
                    return INT_MAX;

                if(sign * num < INT_MIN)
                    return INT_MIN;
            }
            else
                break;
        }

        return sign * num;
    }
};