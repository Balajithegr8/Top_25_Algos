#include<bits/stdc++.h>    // graph using list 
using namespace std;

class graph{
        public:
        map<int,list<int>> adj;

        void edge(int u,int v,bool direction){          //direction =0 undirected      //direction =1 directed 
            adj[u].push_back(v);
            if(direction==0){
                adj[v].push_back(u);
            }
        }

        void print(){
            for(auto i:adj){                            // since adj is a map {key:values} {a:b,c,d}  i will take node "a" or key 
                cout<<i.first<<"->";
                for(auto j: i.second){                  // j will take  "b,c,d" and iterate over it 
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }
        
        void bfs(int src){                               //BFS
            map<int ,bool> visited;
            queue<int> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                int node=q.front();
                cout<<node<<" ";
                q.pop();
                for(int nbr:adj[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true; 
                    }
                }
                
            }
        }
};


int main(){

    int n;
    cout<<"Enter the number of nodes :";
    cin>>n;
    int m;
    cout<<"Enter the number of edges :";
    cin>>m;
    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;          // u, v are the nodes 
        g.edge(u,v,0);      // undirected graph 
    }
    cout<<endl<<"The adjacency list is :"<<endl;
    g.print();
    cout<<endl<<"The BFS traversal for the graph is :";
    g.bfs(0);
    cout<<endl<<endl;
    return 0;
}