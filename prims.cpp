#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n = 4;

    vector<vector<int>> cost = {
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 0},
        {6, 8, 0, 0}
    };

    vector<int> vis(n, 0);

    vis[0] = 1;

    int edges = 0;

    int minCost = 0;

    while(edges < n - 1){

        int min = 9999;
        int x, y;

        for(int i = 0; i < n; i++){

            if(vis[i]){

                for(int j = 0; j < n; j++){

                    if(!vis[j] &&
                       cost[i][j] &&
                       cost[i][j] < min){

                        min = cost[i][j];

                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << min << endl;

        minCost += min;

        vis[y] = 1;

        edges++;
    }

    cout << "Minimum Cost = " << minCost;

    return 0;
}