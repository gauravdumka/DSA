// class Solution {
// private:
//     bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&path){
//         vis[node]=1;
//         path[node]=1;

//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 if(dfs(it,adj,vis,path)) return true;
//             }
//             else if(path[it]){
//                 return true;
//             }
//         }

//         path[node]=0;
//         return false;
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> adj[numCourses];

//         for(auto it:prerequisites){
//             adj[it[1]].push_back(it[0]);
//         }

//         vector<int> vis(numCourses,0);
//         vector<int> path(numCourses,0);

//         for(int i=0;i<numCourses;i++){
//             if(!vis[i]){
//                 if(dfs(i,adj,vis,path)) return false;
//             }
//         }

//         return true;
//     }
// };

 ///////////////////////////////  USING BFS   /////////////////////////////
//  => if toposort doesn't produce total n el then there is a cycle

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(topo.size()==numCourses)return true;
        return false;
    }
};