//EDITION 1   queue
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx, d[N];
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs(){
    memset(d, -1, sizeof d); d[1] = 0;
    queue<int> q; q.push(1);
    while(q.size()){
        int t = q.front(); q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; ++i){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b);
    }
    printf("%d", bfs());
    return 0;
}




//EDITION 2   数组模拟queue
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx, d[N], q[N];
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs(){
    memset(d, -1, sizeof d); d[1] = 0;
    int hh = 0, tt = 0; q[0] = 1;
    while(hh <= tt){
        int t  = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[n];
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; ++i){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b);
    }
    printf("%d", bfs());
    return 0;
}
