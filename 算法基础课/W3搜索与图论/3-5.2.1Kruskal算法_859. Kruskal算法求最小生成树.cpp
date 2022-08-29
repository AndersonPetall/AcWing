//EDITION 1   
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m, tree[N];
struct Edge{
    int a, b, w;
    bool operator<(const Edge &W)const{
        return w < W.w;
    }
}edges[M];
int find(int x){
    if(tree[x] != x) tree[x] = find(tree[x]);
    return tree[x];
}
int kruskal(){
    int res = 0, cnt = 0;
    for(int i = 1; i <= m; ++i){
        int a = find(edges[i].a), b = find(edges[i].b);
        if(a != b){
            tree[a] = b;
            res += edges[i].w;
            ++cnt;
        }
    }
    if(cnt == n -1 )return res;
    return INF;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    sort(edges + 1, edges + m + 1);
    for(int i = 1; i <= n; ++i) tree[i] = i;
    int t = kruskal();
    t == INF ? puts("impossible") : printf("%d\n", t);
    return 0;
}








//EDITION 2
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m, p[N];
struct Edge{
    int a, b, w;
    bool operator<(const Edge &W)const{
        return w < W.w;
    }
}edges[M];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int kruskal(){
    sort(edges, edges + m);
    for(int i = 1; i <= n; ++i) p[i] = i;
    int res = 0, cnt = 0;
    for(int i = 0; i < m; ++i){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            ++cnt;
        }
    }
    if(cnt < n - 1) return INF;
    return res;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int t = kruskal();
    t == INF ? puts("impossible") : printf("%d\n", t);
    return 0;
}
