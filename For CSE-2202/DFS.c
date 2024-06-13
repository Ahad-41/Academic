#include<stdio.h>

#define N 100
int graph[N][N];
int discovered[N],finished[N];
int color[N],predecessor[N];

int vertex, edge, time;

void DFS(int u) {
    time++;
    discovered[u] = time;
    color[u] = 1;
    
    for (int i = 1; i <= vertex; i++) {
        if (graph[u][i] == 1 && color[i] == 0) {
            predecessor[i] = u;
            DFS(i);
        }
    }

    time++;
    finished[u] = time;
}

int main()
{
    scanf("%d %d",&vertex, &edge);

    int start,end;
    for (int i = 1; i <= edge; i++) {
        scanf("%d %d", &start, &end);
        graph[start][end] = 1;
    }

    for(int i = 1; i <= vertex; i++) {
        if(color[i] == 0) DFS(i);
    }

    printf("\nDiscovered:\n");
    for(int i = 1; i <= vertex; i++) printf("%d ",discovered[i]);
    printf("\n");

    printf("\nfinished:\n");
    for(int i = 1; i <= vertex; i++) printf("%d ",finished[i]);
    printf("\n");

    printf("\npredecessor:\n");
    for(int i = 1; i <= vertex; i++) printf("%d ",predecessor[i]);
    printf("\n");
}

