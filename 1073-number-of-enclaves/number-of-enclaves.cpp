class Solution {
private:
    void dfs(int row, int col,vector<vector<int>>& board , vector<vector<int>>& vis){
        vis[row][col]=1;
        int m=board.size(); int n=board[0].size();
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<m && nrow>=0 && ncol>=0 && ncol<n && board[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0; i<n;i++){
            if(grid[0][i]==1 && vis[0][i]==0){
                dfs(0,i,grid,vis);
            }
            if(grid[m-1][i]==1  && vis[m-1][i]==0){
                dfs(m-1,i,grid,vis);
            }
        }
        for(int i=0; i<m;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][n-1]==1  && vis[i][n-1]==0){
                dfs(i,n-1,grid,vis);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};