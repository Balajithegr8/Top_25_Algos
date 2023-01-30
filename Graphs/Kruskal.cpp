#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int >&a,vector<int>&b){
    return a[2]<b[2];
}

void makeset(vector<int> &parent,vector<int> &rankk,int n ){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rankk[i]=0;
    }
}

int findparent(vector<int> &parent ,int node){
    if(node==parent[node]){
        return node;
    }
    else{
        return parent[node]= findparent(parent,parent[node]);
    }
}

void unionset(int u,int v,vector<int> &parent,vector<int>&rankk){
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rankk[u]<rankk[v]){
        parent[u]=v;
    }
    else if(rankk[v]<rankk[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rankk[u]++;
    }
}

int minimumspanningtree(vector<vector<int>>& edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int > parent(n);
    vector<int > rankk(n);
    makeset(parent,rankk,n);

    int minweight=0;

    for(int i=0;i<edges.size();i++){
        int u=findparent(parent,edges[i][0]);
        int v=findparent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            minweight=minweight + wt;
            unionset(u,v,parent,rankk);
        }
    }
    return minweight;
}

int main()
{
    int n=4;    //vertices
    int m=4;    //edges
    vector<vector<int>> edges={{0,1,3},{0, 3, 5},{1, 2, 1},{2,3,8}};
    int k=minimumspanningtree(edges,n);
    cout<<k;
    return 0;
}