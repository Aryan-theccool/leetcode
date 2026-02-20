class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> maxarray(10,-1);
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int maxval=0;
            while(temp>0){
                maxval=max(maxval,(temp%10));
                temp=temp/10;

            }
            if(maxarray[maxval]!=-1){
                ans=max(ans,nums[i]+maxarray[maxval]);
            }
            maxarray[maxval]=max( maxarray[maxval],nums[i]);
        }
        return ans;
    }
};