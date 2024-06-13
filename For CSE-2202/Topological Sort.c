#include<stdio.h>

int graph[100][100];
int inDegree[100];
int Queue[100];

int main()
{
    int vertex, edge;
    scanf("%d %d",&vertex, &edge);

    for (int i = 1; i <= edge; i++) {
        int start, end;
        scanf("%d %d",&start, &end);
        inDegree[end]++;
        graph[start][end] = 1;
    }

    printf("In Degree:\n");
    for(int i = 1; i <= vertex; i++) printf("%d ", inDegree[i]);
    printf("\n");
    printf("\n");

    int head = 0, tail=0;

    for (int i = 1; i <= vertex; i++) {
        if (inDegree[i] == 0) Queue[head++] = i;
    }

    while(head != tail) {
        int u = Queue[tail];
        printf("%d ",u);
        tail++;
        for (int i = 1; i <= vertex; i++) {
            if (graph[u][i] == 1) {
                graph[u][i] = 0;
                inDegree[i]--;
                if (inDegree[i] == 0) Queue[head++] = i;
            }
        }
    }
    printf("\n");
}