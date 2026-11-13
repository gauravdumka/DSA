class Solution {
private: 
    void bfs(int i, int j, int color,vector<vector<int>>& image,vector<vector<int>>&vis ){
        int curr=image[i][j];
        vis[i][j]=1;
        image[i][j]=color;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row-1>=0 && image[row-1][col]==curr && !vis[row-1][col]){
                vis[row-1][col]=1;
                image[row-1][col]=color;
                q.push({row-1,col});
            }
            if(row+1<image.size() && image[row+1][col]==curr && !vis[row+1][col]){
                vis[row+1][col]=1;
                image[row+1][col]=color;
                q.push({row+1,col});
            }
            if(col-1>=0 && image[row][col-1]==curr && !vis[row][col-1]){
                vis[row][col-1]=1;
                image[row][col-1]=color;
                q.push({row,col-1});
            }
             if(col+1<image[0].size() && image[row][col+1]==curr && !vis[row][col+1]){
                vis[row][col+1]=1;
                image[row][col+1]=color;
                q.push({row,col+1});
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m= image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(sr,sc,color,image,vis);
        return image;
    }
};