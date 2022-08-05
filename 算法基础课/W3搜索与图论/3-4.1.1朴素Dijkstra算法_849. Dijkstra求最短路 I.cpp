// EDITION 1 二维数组储存边
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 510;
int g[N][N], dis[N];
int n, m;
bool st[N];
int dijkstra(){
    memset(dis, 0x3f, sizeof dis); dis[1] = 0;
    for(int i = 0; i < n; ++i){
        int pointIdx = -1; // t = 0;
        for(int j = 1; j <= n; ++j)
            if(!st[j] && (pointIdx == -1 || dis[j] < dis[pointIdx])) pointIdx = j;   //!st[j] && (pointIdx == 0 || dis[pointIdx] > dis[j])
        st[pointIdx] = true;
        for(int j = 1; j <= n; ++j)
            dis[j] = min(dis[j], dis[pointIdx] + g[pointIdx][j]);
    }
    return dis[n] == 0x3f3f3f3f ? -1 : dis[n];
}
int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    printf("%d\n", dijkstra());
    return 0;
}



//EDITION 2 邻接表储存边
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510, M = 1e5 + 10;
int e[M], ne[M], w[M], idx, h[N], dis[N];
int n, m;
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra(){
    memset(dis, 0x3f, sizeof dis); dis[1] = 0;
    for(int i = 0; i < n; ++i){
        int pointIdx = -1;
        for(int j = 1; j <= n; ++j)
            if(!st[j] &&(pointIdx == -1 || dis[j] < dis[pointIdx])) pointIdx = j;
        st[pointIdx] = true;
        for(int j = h[t]; j != -1 ; j = ne[j]){
            int linkPointIdx = e[j];
            dis[linkPointIdx] = min(dis[linkPointIdx], dis[pointIdx] + w[j]);
        }
    }
    return dis[n] == 0x3f3f3f3f ? -1 : dis[n];
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", dijkstra());
    return 0;
}
