#include<stdio.h>

int main()
{
    int vertex, edge;
    scanf("%d %d",&vertex,&edge);

    int i, j;
    int graph[vertex+1][vertex+1];
    for (i = 1; i <= vertex; i++) {
        for (j = 1; j <= vertex; j++) {
            graph[i][j] = 1000;
        }
    }

    int start, end, weight;
    for (i = 1; i <= edge; i++) {
        for (j = 1; j <= edge; j++) {
            scanf("%d %d %d",&start, &end, &weight);
            graph[start][end] = graph[end][start] = weight;
        }
    }

    int visited[vertex+1];
    for (i = 1; i <= vertex; i++) visited[i] = 0;
    visited[1] = 1;

    int u, v;
    int mstEdge = 1, a, b, minCost = 0;
    while (mstEdge < vertex) {
        int minimumWeight = 1000;
        for (i = 1; i <= vertex; i++) {
            for (j = 1; j <= vertex; j++) {
                if (graph[i][j] < minimumWeight) {
                    if (visited[i] != 0) {
                        minimumWeight = graph[i][j];
                        u = a = i;
                        v = b = j;
                    }
                    if (visited[u] == 0 || visited[v] == 0) {
                        printf("\n Edge %d:(%d %d) cost:%d", mstEdge++, a, b, minimumWeight);
                        minCost += minimumWeight;
                        visited[b] = 1;
                    }
                }
            }
        }
        graph[a][b] = graph[b][a] = 1000;
    }

    printf("\nMinimum cost: %d\n", minCost);
}



-----------------------------------------------------------

int n;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}
