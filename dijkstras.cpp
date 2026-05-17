#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n = 4;

    vector<vector<int>> graph = {
        {0, 1, 4, 0},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {0, 6, 3, 0}
    };

    vector<int> dist(n, 9999);

    vector<int> vis(n, 0);

    dist[0] = 0;

    for(int i = 0; i < n - 1; i++){

        int minDist = 9999;
        int u;

        for(int j = 0; j < n; j++){

            if(!vis[j] && dist[j] < minDist){

                minDist = dist[j];
                u = j;
            }
        }

        vis[u] = 1;

        for(int v = 0; v < n; v++){

            if(graph[u][v] &&
               !vis[v] &&
               dist[u] + graph[u][v] < dist[v]){

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from node 0:\n";

    for(int i = 0; i < n; i++){

        cout << i << " -> " << dist[i] << endl;
    }

    return 0;
}