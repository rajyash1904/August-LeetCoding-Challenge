/*

Pascal's Triangle II

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int n) 
    {
        vector<int> prev;
        vector<int> sol;
        prev.push_back(1);
        if(n==0) return prev;
        for(int i=1;i<=n;i++)
        {
            sol.clear();
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i) sol.push_back(1);
                 else sol.push_back(prev[j] +prev[j-1]);
            }
            prev= sol;
        }
       
        return sol;
    }
};