class Solution {
public:
int fun(int n,vector<int>& nums,vector<int> & ans){
if(n==0)return nums[n];
if(n<0)return 0;
if(ans[n]!=-1)return ans[n];

int pick=nums[n]+fun(n-2,nums,ans);
int notpick=0+fun(n-1,nums,ans);
ans[n] = max(pick,notpick);
return ans[n];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        return fun(n-1,nums,ans);
    }
};
