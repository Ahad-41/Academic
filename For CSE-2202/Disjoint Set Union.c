#include<stdio.h>
int node = 6, parent[100], Size[100];

void Initialization() {
    int i;
    for (i = 0; i <= node; i++) {
        parent[i] = i;
        Size[i] = 1;
    }
}

int Find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u != v) {
        if (Size[u] < Size[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        parent[v] = u;
        Size[u] += Size[v];
    }
}
int main() {

}
