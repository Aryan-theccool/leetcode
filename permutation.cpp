class Solution {
public:

    void solve(vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& res, vector<int>& used)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i] == 1) continue;

            used[i] = 1;
            temp.push_back(nums[i]);

            solve(nums, temp, res, used);

            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> used(nums.size(), 0);

        solve(nums, temp, res, used);

        return res;
    }
};