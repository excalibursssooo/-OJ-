#include <bits/stdc++.h>
using namespace std;

class Map {
private:
    int Matrix[101][101];
    int Vnum;

public:
    void SetMatrix();
    void dij(int v0);
};

void Map::SetMatrix() {
    cin >> Vnum;
    for (int i = 0; i < Vnum; i++) {
        for (int j = 0; j < Vnum; j++) {
            cin >> Matrix[i][j];
        }
    }
    for (int i = 0; i < Vnum; i++) {
        for (int j = 0; j < Vnum; j++) {
            if (Matrix[i][j] == 0) {
                Matrix[i][j] = 99999;
            }
        }
    }
}

void Map::dij(int v0) {
    int i, j, v, w, min;
    int dist[1001];
    int final[1001];
    int path[101][101];
    int len[101];
    for (i = 0; i < Vnum; i++) {
        final[i] = 0;
        dist[i] = Matrix[v0][i];
        for (j = 0; j < Vnum; j++) {
            path[i][j] = -1;
        }
    }
    for (j = 0; j < Vnum; j++) {
        path[j][0] = j;
    }
    final[v0] = 1;

    for (i = 1; i < Vnum; i++) {
        min = 9999;
        for (j = 0; j < Vnum; j++) {
            if (dist[j] < min && dist[j] != 99999 && final[j] == 0) {
                min = dist[j];
                v = j;
            }
        }
        final[v] = 1;
        for (j = 0; j < Vnum; j++) {
            if (dist[j] > dist[v] + Matrix[v][j] && final[j] == 0) {
                dist[j] = dist[v] + Matrix[v][j];
                for (w = 0; path[j][w] != -1; w++) {
                    path[j][w] = -1;
                }
                for (w = 0; path[v][w] != -1; w++) {
                    path[j][w] = path[v][w];
                }
                path[j][w] = j;
            }
        }
    }

    for (i = 0; i < Vnum; i++) {
        if (i != v0) {
            cout << v0 << "-" << i << "-" << dist[i] << "----";
            cout << "[" << v0 << " ";
            w = 0;
            while (path[i][w] != -1) {
                cout << path[i][w] << " ";
                w++;
            }
            cout << "]";
            cout << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Map myMap;
        myMap.SetMatrix();
        int v0;
        cin >> v0;
        myMap.dij(v0);
    }
}