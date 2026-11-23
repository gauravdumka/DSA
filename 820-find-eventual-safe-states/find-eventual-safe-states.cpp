class Solution {
private:
    bool dfs(int node, int vis[],int pvis[], int ans[],vector<vector<int>>& graph){
        vis[node]=1;
        pvis[node]=1;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pvis,ans,graph)){
                    return true;
                }
            }else if(vis[it] && pvis[it]){
                return true;
            }
        }
        ans[node]=1;
        pvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int v=graph.size();
        int* vis = new int[v]();
        int* pvis = new int[v]();
        int* ans = new int[v]();
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,pvis,ans,graph);
            }
        }
        vector<int>res;
        for(int i=0;i<v;i++){
            if(ans[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};