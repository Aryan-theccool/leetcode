class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
                    int   n=nums.size()-1;
        int result=0;
        int d=INT_MAX;

        for(int i=0;i<n-1;i++){
            
        int left=i+1;

        int right=n;
        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            int diff=abs(target-sum);
            if(diff<d){
                d=diff;
                result=sum;
            }
            if(sum==target){
                return result;
            }
            if(sum>target)
            {
                right--;
            }else{
                left++;
            }

        }
        }
        return result;
    }
};