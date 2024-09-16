#include <stdio.h>
#include <string.h>

#define INF 100000000
#define N 4

int adjacencyMatrix[N][N];
int dist[N];
int color[N];
int edges[N * N][3];
int edge_count;
int updatedMatrix[N][N];
int updatedWeight[N + 1];

int Min_Distance() {
    int min = INF, min_index;
    for (int v = 0; v < N; ++v) {
        if (!color[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Dijkstra_Algorithm(int source) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        color[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < N - 1; ++count) {
        int u = Min_Distance();
        color[u] = 1;

        for (int v = 0; v < N; ++v) {
            if (!color[v] && adjacencyMatrix[u][v] != 0 && dist[u] != INF && dist[u] + updatedMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + updatedMatrix[u][v];
            }
        }
    }

    printf("Shortest Distance from vertex %d:\n", source);
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) printf("Vertex %d: INF\n", i);
        else printf("Vertex %d: %d\n", i, dist[i]);
    }
}

void BellmanFord_Algorithm() {
    for (int i = 0; i <= N; i++) updatedWeight[i] = INF;
    updatedWeight[N] = 0;

    int edges_with_extra[edge_count + N][3];
    memcpy(edges_with_extra, edges, edge_count * 3 * sizeof(int));

    for (int i = 0; i < N; ++i) {
        edges_with_extra[edge_count + i][0] = N;
        edges_with_extra[edge_count + i][1] = i;
        edges_with_extra[edge_count + i][2] = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < edge_count + N; ++j) {
            int u = edges_with_extra[j][0];
            int v = edges_with_extra[j][1];
            int weight = edges_with_extra[j][2];

            if (updatedWeight[u] != INF && updatedWeight[u] + weight < updatedWeight[v]) {
                updatedWeight[v] = updatedWeight[u] + weight;
            }
        }
    }
}

void JohnsonAlgorithm() {
    BellmanFord_Algorithm();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                updatedMatrix[i][j] = adjacencyMatrix[i][j] + updatedWeight[i] - updatedWeight[j];
            }
        }
    }

    for (int source = 0; source < N; ++source) {
        Dijkstra_Algorithm(source);
    }
}

int main() {
    freopen("APSP.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int vertex, edge;
    scanf("%d %d", &vertex, &edge);

    edge_count = 0;
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edge; ++i) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        adjacencyMatrix[start][end] = weight;
        adjacencyMatrix[end][start] = weight;

        edges[edge_count][0] = start;
        edges[edge_count][1] = end;
        edges[edge_count][2] = weight;
        edge_count++;
    }

    JohnsonAlgorithm();
    printf("\n");
    printf("\n");
}


/*
4 5
0 1 -5
0 2 2
0 3 3
1 2 4
2 3 1
*/
