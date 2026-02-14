class Solution {
public:
       bool finds( unordered_map<char,int>ransom,   unordered_map<char,int>mag){
        for(auto i:ransom){
            char c=i.first;
            int fransom=i.second;
            int fmag=mag[c];
            if(fmag<fransom){
                return false;
            }
        
        }
            return true;
       }


    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ransom;
                unordered_map<char,int>mag;

        for(int i=0;i<ransomNote.size();i++){
            ransom[ransomNote[i]]++;
        }
        
        for(int i=0;i<magazine.size();i++){
mag[magazine[i]]++;
        }
        return finds(ransom,mag);
    }
};