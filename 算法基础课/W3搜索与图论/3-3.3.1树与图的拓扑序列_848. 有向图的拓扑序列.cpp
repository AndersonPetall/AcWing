//EDITION 1
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n, m, q[N], d[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void topsort(){
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; ++i){
        if(!d[i]) q[++tt] = i;
    }
    while(hh <= tt){
        int t = q[++hh];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0) q[++tt] = j;
        }
    }
    if(tt == n ){
        for(int i = 1; i <= n; ++i) printf("%d ", q[i]);
    }
    else{
        puts("-1");
    }
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; ++i){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b);
        ++d[b];
    }
    topsort();
    return 0;
}
