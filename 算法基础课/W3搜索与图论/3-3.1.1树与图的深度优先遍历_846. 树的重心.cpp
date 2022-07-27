//EDITION1  状态数组为int型    sum = 1(当前结点计入结点总数)
#include<iostream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx, st[N];
int n, ans = N;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u){
    st[u] = 1;
    int size = 0, sum = 1;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s = dfs(j);
            size = max(size, s);
            sum += s;
        }
    }
    size = max(size, n - sum);
    ans = min(ans, size);
    return sum;
}
int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; ++i){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}



//EDITION2  状态数组为int型    sum = 0(当前结点不计入结点总数)
#include<iostream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx, st[N];
int n, ans = N;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u){
    st[u] = 1;
    int size = 0, sum = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s = dfs(j);
            size = max(size, s);
            sum += s;
        }
    }
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}
int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; ++i){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}



//EDITION3  状态数组为bool型    sum = 1(当前结点计入结点总数)
#include<iostream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int n, ans = N;
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u){
    st[u] = true;
    int size = 0, sum = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s = dfs(j);
            size = max(size, s);
            sum += s;
        }
    }
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}
int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; ++i){
        int a, b; scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
