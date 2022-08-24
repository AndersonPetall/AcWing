#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dis[N];
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa(){
    memset(dis, 0x3f, sizeof dis); dis[1] = 0;
    queue<int> q; 
    q.push(1); st[1] = true;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dis[n];
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if(spfa() == 0x3f3f3f3f) puts("impossible");
    else printf("%d\n", spfa());
    return 0;
}
