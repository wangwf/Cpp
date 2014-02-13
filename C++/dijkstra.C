// Dijkstra's shortest path

#include <stdio.h>
#include <limits.h>

// number of vertices in the graph
#define V 9

/**********************

Dijkstra pseudo code

initial-single_source (Graph g, Node s)
   for each vertex v in vertics(g)
       dist[v] = INT_MAX
       pi[v] = NULL


for(int i=0; i<V; i++){
  
}
*************************/


int minDistance(int dist[], bool visited[]){

  //initialize
  int min = INT_MAX, min_index;

  for(int v=0; v<V; v++){
    if(visited[v] == false &&dist[v] <=min){
      min = dist[v];
      min_index=v;
    }}
  return min_index;
}

//
int printSolution(int dist[], int n){
  printf("Vertext Distance from Souce\n");
  for(int i=0; i<V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

//Function that implements Dijkstra's single source shortest parth algorithm
// adjacency matrix representation for graph

void dijkstra(int graph[V][V], int src){
  int dist[V]; //the output array , dist[i] hold the shortest distance from src to i
  bool visited[V]; // true if vertex i included in shortest path tree

  for(int i=0; i<V; i++){
    dist[i] = INT_MAX;
    visited[i] = false;
  }
  
  //Distance of source vertex from i
  dist[src]=0;

  //find shortest path for all vertices
  for(int count=0; count<V-1; count++){
    //min-distance from the set not yet processed
    int v= minDistance(dist, visited);
    visited[v] =true;
    
    for(int w=0; w<V; w++){
      if(!visited[w] && graph[v][w] && dist[v]!= INT_MAX
	 && dist[v]+graph[v][w] < dist[w])
	dist[w]=dist[v]+graph[v][w];
    }
    printSolution(dist, V);
  }
}

// driver program to test above function
int main()
{
  /* Let us create the example graph discussed above */
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
		     {4, 0, 8, 0, 0, 0, 0, 11, 0},
		     {0, 8, 0, 7, 0, 4, 0, 0, 2},
		     {0, 0, 7, 0, 9, 14, 0, 0, 0},
		     {0, 0, 0, 9, 0, 10, 0, 0, 0},
		     {0, 0, 4, 0, 10, 0, 2, 0, 0},
		     {0, 0, 0, 14, 0, 2, 0, 1, 6},
		     {8, 11, 0, 0, 0, 0, 1, 0, 7},
		     {0, 0, 2, 0, 0, 0, 6, 7, 0}
  };
  
  dijkstra(graph, 0);
  
  return 0;
}
