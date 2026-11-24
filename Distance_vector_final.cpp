
#include <iostream>
using namespace std;

const int INF = 999;

int main() {
    int n;
    int cost[10][10], dist[10][10];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter cost matrix (999 for no connection):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
        }
    }

    bool updated = true;

    while (updated) {
        updated = false;

        int oldDist[10][10];

        // Copy previous distance table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                oldDist[i][j] = dist[i][j];
            }
        }

        // Check routes through neighbours
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {

                if (i != k && cost[i][k] != INF) {

                    for (int j = 0; j < n; j++) {

                        if (oldDist[k][j] != INF &&
                            cost[i][k] + oldDist[k][j] < dist[i][j]) {

                            dist[i][j] = cost[i][k] + oldDist[k][j];
                            updated = true;
                        }
                    }
                }
            }
        }
    }

    cout << "\nFinal Distance Vector Tables:\n";
    

    for (int i = 0; i < n; i++) {
        cout << "Router " << i << ": ";

        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}
