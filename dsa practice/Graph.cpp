#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addedgesonbetween_Nodes(int u, int v, bool direction)
    {
        // undirected -> 0;
        // directedgraph -> 1 ;

        // create a edge from u to v
        adj[u].push_back(v);

        // if undirected graph we have to create from v to u too
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
        }
    }
};
int main(){
    int n ;
    cout<<"enter the no. of nodes" ;
    cin>> n ;

    int m ;
    cout<<"enter the no. of edges" ;
    cin>> m;

    graph g; 
    for(int i =0 ; i<m ; i++){
        int u , v ;
        cin>>u>>v ; 

        //creating a unordered graph
        g.addedgesonbetween_Nodes(u,v,0) ;
    } 

    g.printadjlist() ;

}

// output is here
// enter the corresponding values 
// n = 5 ,m = 6
// 0 1
// 1 2
// 2 3 
// 3 1
// 3 4 
// 0 4

// 4->3 ,0 
// 0->1 ,4 
// 1->0 ,2 ,3 
// 2->1 ,3 
// 3->2 ,1 ,4 