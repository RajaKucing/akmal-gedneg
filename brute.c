#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Fungsi untuk mencari rute terpendek menggunakan brute force
void bruteForce(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = i;
    }

    int minPath = INF;
    vector<int> minPathOrder;

    do {
        int currentPath = 0;
        bool validPath = true;

        // Menghitung panjang rute saat ini
        for (int i = 0; i < n - 1; ++i) {
            int u = nodes[i];
            int v = nodes[i + 1];
            if (graph[u][v] == 0) { // Menyaring jalur yang tidak valid
                validPath = false;
                break;
            }
            currentPath += graph[u][v];
        }

        // Kembali ke titik distribusi awal
        if (validPath && graph[nodes[n - 1]][nodes[0]] != 0) {
            currentPath += graph[nodes[n - 1]][nodes[0]];
            if (currentPath < minPath) {
                minPath = currentPath;
                minPathOrder = nodes;
            }
        }
    } while (next_permutation(nodes.begin() + 1, nodes.end())); // Menggunakan STL next_permutation untuk menghasilkan semua kemungkinan permutasi

    cout << "Rute terpendek: ";
    for (int node : minPathOrder) {
        cout << node << " ";
    }
    cout << minPathOrder[0] << endl; // Kembali ke titik distribusi awal

    cout << "Total jarak yang ditempuh: " << minPath << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0},
        {0, 0, 20, 15},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    bruteForce(graph);

    return 0;
}
