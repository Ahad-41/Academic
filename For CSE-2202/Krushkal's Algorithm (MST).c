#include<stdio.h>
#define MX 10000
int graph[MX][MX];
int visited[MX][MX];
int parent[MX];

int Find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = Find(parent[v]);
}

int Union(int u, int v) {
    if (u == v) return 0;
    parent[v] = u;
    return 1;
}

int main()
{
    int vertex, edge;
    scanf("%d %d",&vertex, &edge);

    int i, j;
    for (i = 1; i <= vertex; i++) {
        for (j = 1; j <= vertex; j++) {
            graph[i][j] = 1000001;
            visited[i][j] = false;
        }
    }
    
    int start, end, weight;
    for (i = 1; i <= edge; i++) {
        scanf("%d %d %d",&start, &end, &weight);
        graph[start][end] = graph[end][start] = weight;
    }

    for (i = 1; i <= vertex; i++) parent[i] = i;

    int mstEdge = 1;
    int u, v;
    int minCost = 0, minEdge;

    while (mstEdge < vertex) {
        for (i = 1, minEdge = MX; i <= vertex; i++) {
            for (j = 1; j <= vertex; j++) {
                if (visited[i][j] == 0 and graph[i][j] < minEdge) {
                    minEdge = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int parent_of_u = Find(u); 
        int parent_of_v = Find(v);

        if (parent_of_u != parent_of_v) {
            Union(u, v);
            mstEdge++;
            minCost += minEdge;
        }
        visited[u][v] = visited[v][u] = 1;
    }

    printf("%d",minCost);
}
