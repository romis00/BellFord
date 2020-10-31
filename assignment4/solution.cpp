//
//  main.cpp
//  assignment4
//
// Implementation of BellFord algorithm into c++
//
//  Created by Roman Tuzhilkin on 10/30/20.
//  Copyright © 2020 Roman Tuzhilkin. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX_EDGE_L = 1000;
const int UNUSSIGNED_EDGE = -1001;

void bellF(int**, int*, int, int, int);

int main(int argc, const char * argv[]) {

    int number_vertices = 0;
    int number_edges = 0;
    int source_vertex = 0;
    int *dist = new int[0];
    int **edge = new int*[0];

    int a = 0;
    int b = 0;

    //________________________________________Working with input begin

    //cout << "Enter number of vertices: ";
    cin >> number_vertices;
    number_vertices++;

    //cout << "Enter number of edges: ";
    cin >> number_edges;
    number_edges++;

    //cout << "Enter source vertex: ";
    cin >> source_vertex;

    dist = new int[number_vertices];
    edge = new int*[number_vertices];

    for (int i=1; i<number_vertices; i++)
    {
        edge[i] = new int[number_vertices];
        for (int j=0;j<number_vertices; j++)
        {
            edge[i][j] = UNUSSIGNED_EDGE;
        }
    }
    for (int i=1; i<number_edges; i++)
    {
        cin >> a;
        cin >> b;
        cin >> edge[b][a];
    }
    //________________________________________Working with input end
    
    bellF(edge, dist, number_vertices, number_edges, source_vertex);

    return 0;
}

void bellF(int** edge, int* dist, int number_vertices, int number_edges, int source_vertex)
{
    int prev[number_vertices];
    bool flag = false;
    
    //________________________________________Initializing dist, prev begin
    dist[source_vertex] = 0;
    prev[source_vertex] = 0;
    for (int i=0; i<number_vertices; i++)
    {
        if (source_vertex != i) {
            dist[i] = MAX_EDGE_L;
            prev[i] = MAX_EDGE_L;
        }
    }
    //________________________________________Initializing dist, prev end

    //________________________________________Filling in dist array begin
    for (int k = 1; k<(number_vertices/3)+1; k++)
    {
    
        for (int v = 1; v < number_vertices; v++)
        {
            for (int u = 1; u < number_vertices; u++)
            {
                
                if ((dist[u] > (dist[v] + edge[u][v])) && (dist[v] != MAX_EDGE_L) && (edge[u][v] != UNUSSIGNED_EDGE))
                {
                    dist[u] = dist[v] + edge[u][v];
                    prev[u] = dist[u];
                }
            }
        }
    }
    //________________________________________Filling in dist array end

    //________________________________________Additional iteration begin
    for (int v = 1; v < number_vertices; v++)
    {
        for (int u = 1; u < number_vertices; u++)
        {

            if ((dist[u] > (dist[v] + edge[u][v])) && (dist[v] != MAX_EDGE_L) && (edge[u][v] != UNUSSIGNED_EDGE))
            {
                dist[u] = dist[v] + edge[u][v];
            }
        }
    }
    //________________________________________Additional iteration end

    //________________________________________Check if extra iteration changed array begin
    for (int i=1; i<number_vertices; i++)
    {
        if ((prev[i] != dist[i])&&(!flag))
        {
            cout << "True";
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "False";
    }
    //________________________________________Check if extra iteration changed array end
}
