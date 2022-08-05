//理解版本
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
int e[N], ne[N], w[N], idx, h[N], dis[N];
int n, m;
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra(){
    memset(dis, 0x3f, sizeof dis); dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({dis[1], 1});
    while(heap.size()){
        auto t = heap.top(); heap.pop();
        int pointIdx = t.second, distance = t.first;
        if(st[pointIdx]) continue;
        st[pointIdx] = true;
        for(int i = h[pointIdx]; i != -1; i = ne[i]){
            int linkPointIdx = e[i];
            if(dis[linkPointIdx] > dis[pointIdx] + w[i]){
                dis[linkPointIdx] = dis[pointIdx] + w[i];
                heap.push({dis[linkPointIdx], linkPointIdx});
            }
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



//原版
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
int dis[N], h[N], e[N], ne[N], idx, w[N];
int n, m;
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[ver] + w[i]){
                dis[j] = dis[ver] + w[i];
                heap.push({dis[j],j});
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
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
