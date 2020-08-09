/*

Rotting Oranges

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.

*/

class Solution {
public:
    int x[4]={1,0,-1,0};
    int y[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        
        int count=0;
        while(!q.empty())
        {
            auto t= q.front();
            int k=t.first;
            q.pop();
            count=max(count,k);
            int rx= t.second.first;
            int ry= t.second.second;
            cout<<rx<<" "<<ry<<" "<<k<<endl;
            for(int l=0;l<4;l++)
            {
                int dx=x[l]+rx;
                int dy=y[l]+ry;
                if(dx<0 || dx>=n || dy<0 || dy>=m || vis[dx][dy] || grid[dx][dy]==0)
                    continue;
                else 
                {
                    vis[dx][dy]=true;
                    q.push({k+1,{dx,dy}});
                } 
                
                   
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==false && grid[i][j]==1) return -1;
            }
        }
        
       return count==0 ? 0:count; 
    }
};