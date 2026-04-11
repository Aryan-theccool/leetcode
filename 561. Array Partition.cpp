
class Solution {
public:
int ans=0;
int fun(vector<int> &nums,int i){
ans += min(nums[i],nums[i+1]);
return ans;
}
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        for( i=0;i<nums.size()-1;i += 2){

ans=fun(nums,i)   ;
     }
     return ans;
    }
};