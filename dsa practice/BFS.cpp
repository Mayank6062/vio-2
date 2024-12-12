#include <iostream>
#include <unordered_map>
#include <list>
#include<queue> 
#include<set>
using namespace std;

void prepareAdjlist(unordered_map<int ,set<int>> &Adjlist , vector<pair<int, int>> &edges){
    for(int i = 0; i<edges.size() ; i++){
        int u = edges[i].first ;
        int v = edges[i].second ;

        Adjlist[u].insert[v] ; 
        Adjlist[v].insert[u] ;

    }
}
void bfs(unordered_map<int,set<int>> &Adjlist , unordered_map<int,bool> &visited ,vector<int> &ans, int node){
    queue<int>q ;
    q.push(node) ;
    visited[node] = 1;
    while(!q.empty()){
        int frontnode = q.front() ;
        q.pop() ;

        //store frontnode into ans
        ans.push_back(frontnode) ;

        //traverse all the neighbours of frontnode

        for(auto i : Adjlist[frontnode]){
            if(!visited[i]) {
                q.push(i) ;
                visited[i] = 1 ;
            }
        }
    }
      
}

vector<int> BFS(int vertex , vector<pair<int ,int>>edges){
    unordered_map<int,set<int>> Adjlist ;
    vector<int> ans ;

    prepareAdjlist(Adjlist , edges) ;
        //printadj(adjlist) 
        //traverse all the component of a graph 

    for(int i = 0 ; i<vertex ; i++){
        if(! visited[i]){
            bfs(Adjlist , visited , ans , i) ;
        }
    }
    return ans ;
}