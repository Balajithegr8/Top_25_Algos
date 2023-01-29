#include <bits/stdc++.h>
using namespace std;

int n=7;
int parent[7];
int rankk[7];

void makeset(){
    for(int i =0 ;i<=n;i++){
        parent[i]=i;
        rankk[i]=0;
    }
}

int findpar(int node){
    if(node == parent[node]){
        return node;
    }

    return parent[node]=findpar(parent[node]);
}

void union1(int u,int v){
    u=findpar(u);
    v=findpar(v);

    if(rankk[u]<rankk[v]){
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rankk[u]++;
    }
}

int main(){
    makeset();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        union1(u,v);
    }
}