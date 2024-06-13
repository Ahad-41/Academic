#include <stdio.h>
const int MX = 1000000000;
int dist[505][505];

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void floydWarshall(int v) {
    int i, j, k;
    for (k = 1; k <= v; k++) {
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != MX && dist[i][k] != MX)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int i, j, c, s, q, cnt = 1;
    while (scanf("%d %d %d", &c, &s, &q) == 3) {
        if (!c && !s && !q) break;
        if (cnt > 1) printf("\n");

        for (i = 1; i <= c; i++) {
            for (j = 1; j <= c; j++) dist[i][j] = MX;
        }
        for (i = 1; i <= c; i++) dist[i][i] = 0;

        while (s--) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            dist[a][b] = dist[b][a] = min(dist[a][b], c);
        }
        floydWarshall(c);

        printf("Case #%d\n", cnt++);
        while (q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (dist[a][b] == MX) printf("no path\n");
            else printf("%d\n", dist[a][b]);
        }
    }
}
