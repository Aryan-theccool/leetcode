class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i = 0; i < n; i++) {
    vector<int> freqqq(26, 0);

    for(int j = i; j < n; j++) {
        freqqq[s[j] - 'a']++;

        int maxi = 0;
        int mini = INT_MAX;

        for(int k = 0; k < 26; k++) {
            if(freqqq[k] > 0) {
                maxi = max(maxi, freqqq[k]);
                mini = min(mini, freqqq[k]);
            }
        }

        ans += maxi - mini;
    }
}
return ans;
    }
};