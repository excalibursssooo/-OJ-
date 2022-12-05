#include <iostream>
using namespace std;

int find(char a, char b, char tree[][3], int n, int generate) {
    for (int i = 0; i < n; i++) {
        if (tree[i][0] == a) {
            if (tree[i][1] == b || tree[i][2] == b)
                return generate + 1;
            else {
                generate++;
                if (tree[i][1] == '-')
                    return find(tree[i][2], b, tree, n, generate);
                else if (tree[i][2] == '-')
                    return find(tree[i][1], b, tree, n, generate);
                else
                    return max(find(tree[i][1], b, tree, n, generate), find(tree[i][2], b, tree, n, generate));
            }
        }
    }
    return 0;
}

int main() {
    int m, n;
    cin >> m >> n;
    char tree[101][3];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tree[i][j];
        }
    }
    while (n--) {
        char first, second;
        cin >> first >> second;
        if (find(first, second, tree, m, 0) >= find(second, first, tree, m, 0)) {
            int len = find(first, second, tree, m, 0);
            if (len == 0)
                cout << "-" << endl;
            else if (len == 1)
                cout << "child" << endl;
            else if (len == 2)
                cout << "grandchild" << endl;
            else {
                for (int i = 0; i < len - 2; i++) {
                    cout << "great-";
                }
                cout << "grandchild" << endl;
            }
        } else {
            int len = find(second, first, tree, m, 0);
            if (len == 0)
                cout << "-" << endl;
            else if (len == 1)
                cout << "parent" << endl;
            else if (len == 2)
                cout << "grandparent" << endl;
            else {
                for (int i = 0; i < len - 2; i++) {
                    cout << "great-";
                }
                cout << "grandparent" << endl;
            }
        }
    }
    int a, b;
    cin >> a >> b;
}