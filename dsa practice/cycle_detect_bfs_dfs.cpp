// for bfs cycle detecion -> 
#include <unordered_map>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool iscyclebfs(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj) {
    unordered_map<int,int> parent ;
    parent[src] = -1 ;
    visited[src] = true ;
    queue<int> q ;
    q.push(src) ;

    while(!q.empty()){
        int front = q.front() ;
        q.pop() ;
        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true ;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front ;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // create adjacency list
    unordered_map<int, list<int>> adj ;
    for(int i = 0 ; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle the disconnected component of the graph
    unordered_map<int,bool> visited ;
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            bool ans = iscyclebfs(i, visited, adj) ;
            if(ans == true) {
                return "Yes";
            }
        }
    }
    return "No";
}


// cycle detection for dfs ->
// we just have to add an function for this ->
bool iscycledfs(int node, int parent , unordered_map<int,bool> &visited, unordered_map<int,list> & adj){
    visited[node] = true ;
    for(auto neighbour :adj[node]){
        if(!visited[neighbour]){
            bool cycledetected = iscyclebfs(neighbour,node,visited,adj) ;
            if(cycledetected){
                return true ;
            }
            else if(neighbour != parent){
                // cycle present
                return true ; 
            }
        }
    }
    return false; 
}