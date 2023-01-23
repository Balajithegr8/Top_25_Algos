#include <bits/stdc++.h>                                    //for adjacency matrix
using namespace std;

#define V 5                                                 //there are 5 vertices in the graph

int minKey(int key[], bool mstSet[]){                       //gets the min value key 
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min){
			min = key[v], min_index = v;}
	return min_index;
}

void printMST(int parent[], int graph[V][V])                // printing the data of mst in the form of edge and weight
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])                               //mst maker
{

	int parent[V];                                          // parent is the mst itself  

	int key[V];                                             //Key values used to pick minimum weight edge in cut

	bool mstSet[V];                                         // to make sure if the vertices are traversed or not

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;                //initialising all the key value as infinte and marking all the vertices unvisited

	key[0] = 0;
	parent[0] = -1;                                         // First node is always root of MST

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);

		mstSet[u] = true;                                   //mark the picked vertice as visited 

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent
			// vertices of m mstSet[v] is false for vertices
			// not yet included in MST Update the key only
			// if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 }
    };

	primMST(graph);

	return 0;
}