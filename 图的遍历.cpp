#include <bits/stdc++.h>
using namespace std;

class Map {
public:
    int Matrix[20][20];
    int Visit[101];
    int Vnum;
    void showMatrix();
    void DFS(int v);
    void Initial();
    void BFS(int v);
};

void Map::Initial() {
    cin >> Vnum;
    for (int i = 0; i < Vnum; i++) {
        Visit[i] = 0;
        for (int j = 0; j < Vnum; j++) {
            Matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < Vnum; i++) {
        for (int j = 0; j < Vnum; j++) {
            cin >> Matrix[i][j];
        }
    }
}

void Map::showMatrix() {
    for (int i = 0; i < Vnum; i++) {
        for (int j = 0; j < Vnum; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::DFS(int v) {
    Visit[v] = 1;
    cout << v << " ";
    int *Object = new int[20];
    for (int i = 0; i < 20; i++) {
        Object[i] = -1;
    }
    int j = 0;
    for (int i = 0; i < Vnum; i++) {
        if (Matrix[v][i] == 1) {
            Object[j] = i;
            j++;
        }
    }
    int k = 0;
    int w = 0;
    do {
        w = Object[k];
        if (w == -1) break;
        if (Visit[w] == 0) {
            DFS(w);
        }
        k++;
    } while (w != -1);
}

void Map::BFS(int v) {
    queue<int> q;
    int *Object = new int[20];
    for (int i = 0; i < Vnum; i++) {
        Object[i] = 0;
    }
    for (int u = 0; u < Vnum; u++) {
        if (Visit[u] == 0) {
            q.push(u);
            cout << u << " ";
            Visit[u] = 1;
            while (!q.empty()) {
                int p = q.front();
                q.pop();
                int k = 0;
                for (int j = 0; j < Vnum; j++) {
                    if (Matrix[p][j] == 1) {
                        Object[k] = j;
                        k++;
                    }
                }
                int w = 0;
                for (w = 0; w < k; w++) {
                    if (Visit[Object[w]] == 0) {
                        Visit[Object[w]] = 1;
                        cout << Object[w] << " ";
                        q.push(Object[w]);
                    }
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Map myMap;
        myMap.Initial();
        // myMap.showMatrix();
        // myMap.DFS(0);
        myMap.BFS(0);
        cout << endl;
    }
}