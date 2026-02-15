class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int res=0;
        bool odd=false;
        for(auto i:mpp){
            int value =i.second;
            if(value%2==0){
                res +=value;
            }else{
                odd=true;
            }
        }
        if(odd==false){
            return res;
        }
        for(auto i:mpp){
            int value=i.second;
            if(value%2==1){
                res +=value-1;
            }
        }
        return res+1;
    }
};