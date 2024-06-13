#include<stdio.h>

int color[100], distance[100], predecessor[100];
int graph[100][100];

void PrintPath(int s, int v) {
    if (v == s) printf("%d ",s);
    else if(predecessor[v] == 1000) printf("No path from %d to %d exists.",s,v);
    else {
        PrintPath(s, predecessor[v]);
        printf("%d ", v);
    }
}

int main()
{
    int i,j;
    int count;

    int vertex, edge;
    scanf("%d %d",&vertex, &edge);

    for (int i = 1; i <= edge; i++) {
        int start,end;
        scanf("%d %d",&start, &end);
        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    int source,destination;
    scanf("%d %d",&source,&destination);

    for(int i = 1; i <= vertex; i++) {
        color[i] = 0;
        distance[i] = 1000;
        predecessor[i] = -1;
    }

    int Queue[100], head = 1, tail = 1;
    color[source] = 1;
    distance[source] = 0;
    predecessor[source] = 1000;

    Queue[head++] = source;

    while (head != tail) {
        int u = Queue[tail++];
        printf("%d ", u);
        for(int i = 1; i <= vertex; i++) {
            if (graph[u][i] == 1 && color[i] == 0) {
                color[i] = 1;
                distance[i] = distance[u] + 1;
                predecessor[i] = u;
                Queue[head++] = i;
            }
        }
    }
    printf("\n");

    printf("\nDistance:\n");
    for (int i = 1; i <= vertex; i++) printf("%d ", distance[i]);
    printf("\n");

    printf("\npredecessor:\n");
    for (int i = 1; i <= vertex; i++) printf("%d ",predecessor[i]);
    printf("\n");

    PrintPath(source,destination);
}