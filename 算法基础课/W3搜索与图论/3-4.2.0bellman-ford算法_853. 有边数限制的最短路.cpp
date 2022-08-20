#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510, M = 1e4 + 10;
struct Edge{
    int a, b, c;
}edges[M];
int n, m, k;
int dis[N], last[N];
void bellman_ford(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0; 
    for(int i = 0; i < k; ++i){
        memcpy(last, dis, sizeof dis);
        for(int j = 0; j < m; ++j){
            auto e= edges[j];
            dis[e.b] = min(dis[e.b], last[e.a] + e.c);
        }
    }
    if(dis[n] > 0x3f3f3f3f /2) puts("impossible");
    else printf("%d\n", dis[n]);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; ++i){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    bellman_ford();
    return 0;
}
