class Solution {
public:
    int maxArea(vector<int>& height) {
        int right =height.size()-1;
        int left=0;
        int maxii=0;
        int ans=0;
        while(right>left){
         ans= (min(height[left],height[right])*(right-left));
                    maxii=max(ans,maxii);
         if(height[right]<height[left]){
            --right;
         }else{
        ++left;
         }
        }
        return maxii;
    }
};