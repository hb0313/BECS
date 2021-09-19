/*
Basic Concepts, Storage representation, Adjacency matrix, adjacency list, adjacency multi list,
inverse adjacency list. Traversals-depth first and breadth first, Introduction to Greedy Strategy,
Minimum spanning Tree, Greedy algorithms for computing minimum spanning tree- Prims and Kruskal 
Algorithms, Dikjtra's Single source shortest path, Topological ordering.

Case study- Data structure used in Webgraph and Google map.
*/

#include <iostream>

using namespace std;

int n;
class graph {
    public:
        int cost[20][20], mincost;
    graph() {
        for (int i = 0; i <= 10; i++) {
            for (int j = 1; j <= 10; j++)

            {
                cost[i][j] = -1;
            }
        }
        mincost = 0;

    }
    void prims();
};
int main() {
    graph g;
    int c;

    char ans;
    do {
        cout << "Enter total no.of houses\n";
        cin >> n;
        cout << "Enter -1 if no.edge exist\n";
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cout << "Enter cost between house no.\t" << i << "and house no.\t" << j;
                cin >> c;
                g.cost[i][j] = g.cost[j][i] = c;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cout << "\n" << g.cost[i][j];
            }
        }
        g.prims();

        cout << "\nwant to continue?";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');
    return 0;
}
void graph::prims() {
    int min, row, col, visit[20], path[20], z;
    for (int i = 2; i <= n; i++) {
        visit[i] = 0;
    }
    visit[1] = 1;
    z = 1;
    path[z++] = 1;
    cout << "\nInitial cost is:" << mincost;
    for (int k = 1; k <= n - 1; k++) {
        min = 999;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visit[i] == 1 && visit[j] == 0) {
                    if (cost[i][j] != -1 && min > cost[i][j]) {
                        min = cost[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        cout << "\nmin" << min;
        mincost = mincost + min;
        visit[col] = 1;
        path[z++] = col;
        cost[row][col] = -1;
        cost[col][row] = -1;
    }
    cout << "\nTotal min cost" << mincost;
    cout << "Shorted path is";
    for (int i = 1; i <= n; i++)
        cout << path[i];

}
