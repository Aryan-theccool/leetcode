class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
//         class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         unordered_map<char,int> mpp;
//         for (char c : text) {
//             mpp[c]++;
//         }

//         int b = mpp['b'];
//         int a = mpp['a'];
//         int l = mpp['l'] / 2;
//         int o = mpp['o'] / 2;
//         int n = mpp['n'];

//         return min({b, a, l, o, n});
//     }
// };

                unordered_map<char,int>need;
                string neeed ="balloon";
                int count =0;

        for(int i=0;i<neeed.size();i++){
            need[neeed[i]]++;
        }
                for(int i=0;i<text.size();i++){
            mpp[text[i]]++;
        }
        int res=INT_MAX;
        for(auto i:need){
            char ch=i.first;
            int fneeed=i.second;
            int ftext=mpp[ch];
           int time =ftext/fneeed;
           res=min(res,time);



            }
        
return res;
    }
};