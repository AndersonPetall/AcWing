//EDITION 1  DFS self
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, h[N], e[M], ne[M], idx;
int color[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int pointIdx, int colorType){
    color[pointIdx] = colorType;
    for(int i = h[pointIdx]; i != -1; i = ne[i]){
        int nextPointIdx = e[i];
        if(!color[nextPointIdx] && !dfs(nextPointIdx, 3- colorType)) return false;
        else if(color[nextPointIdx] == colorType) return false;
    }
    return true;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if(!color[i] && !dfs(i, 1)){
            flag = false;
            break;
        }
    }
    flag ? puts("Yes") : puts("No");
    return 0;
}


//EDITION 2  DFS ACwing
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int c){
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, 3-c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }
    flag == true ? puts("Yes") : puts("No");
    return 0;
}



//EDITION 3  BFS self
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool bfs(int pointIdx){
    color[pointIdx] = 1;
    queue<int> q; q.push(pointIdx);
    while(q.size()){
        int headPoint = q.front(); q.pop();
        for(int i = h[headPoint]; i != -1; i = ne[i]){
            int linkedPoint = e[i];
            if(!color[linkedPoint]) color[linkedPoint] = 3 - color[headPoint], q.push(linkedPoint);
            else if(color[linkedPoint] == color[headPoint]) return false;
        }
    }
    return true;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if(!color[i] && !bfs(i)){
            flag = false;
            break;
        }
    }
    flag ? puts("Yes") : puts("No");
    return 0;
}
