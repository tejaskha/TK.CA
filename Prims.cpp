#include <iostream>
#include <climits>
using namespace std;

void prims(int n, int a[10][10], int source) {
    int s[10], u, v, k = 1, min, sum = 0, t = 0;

    for (int i = 0; i < n; i++)
        s[i] = 0;

    s[source] = 1;

    while (k <= n - 1) {
        min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (s[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (s[j] == 0 && a[i][j] < min && a[i][j] != 0) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << "(" << u << "," << v << ")=" << min << endl;
        sum += min;
        s[u] = s[v] = 1;
        k++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != 1)
            t = 1;
    }

    if (t == 0)
        cout << "Cost of minimum spanning tree is " << sum << endl;
    else
        cout << "Minimum spanning tree not possible" << endl;
}

int main() {
    int a[10][10], n, source;

    cout << "==========================================\n";
    cout << "Find minimum cost spanning tree using Prim's Algorithm\n";
    cout << "==========================================\n";

    cout << "\nEnter the number of vertices: ";
    cin >> n;

    cout << "(Enter the cost matrix: 0 for self-loop and 999 for no edge)\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter the source node: ";
    cin >> source;

    prims(n, a, source);

    return 0;
}
