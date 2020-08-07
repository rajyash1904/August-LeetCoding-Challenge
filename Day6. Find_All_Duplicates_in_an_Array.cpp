/*

Find All Duplicates in an Array


Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> sol;
        for(auto x: nums)
        {
            int idx = abs(x) -1;
            if(nums[idx]<0)
                sol.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        
        return sol;
    }
};