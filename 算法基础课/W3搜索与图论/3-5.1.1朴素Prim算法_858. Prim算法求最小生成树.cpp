#include<iostream>
#include<cstring>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dis[N];
bool st[N];
int prim(){
    memset(dis, 0x3f, sizeof dis);
    int res = 0;
    for(int i = 0; i < n; ++i){
        int pointIdx = -1;
        for(int j = 1; j <= n; ++j)
            if(!st[j] &&(pointIdx == -1 || dis[pointIdx] > dis[j])) pointIdx = j;
        if(i && dis[pointIdx] == INF) return INF; //不是第一个点且距离为正无穷: 无法构建成树
        if(i) res += dis[pointIdx];
        st[pointIdx] = true;
        for(int j = 1; j <= n; ++j)dis[j] = min(dis[j], g[pointIdx][j]);
    }
    return res;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    } 
    int t = prim();
    t == INF ? puts("impossible") :printf("%d\n", t);
    return 0;
}
