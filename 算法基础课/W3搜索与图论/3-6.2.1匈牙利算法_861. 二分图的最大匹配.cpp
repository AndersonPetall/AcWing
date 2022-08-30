#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =510, M = 1e5 + 10;
int n1, n2, m;
int h[N], e[M], ne[M], idx, match[N];
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int dyeing(){
    int res = 0;
    for(int i = 1; i <= n1; ++i){
        memset(st, false, sizeof st);
        if(find(i)) ++res;
    }
    return res;
}
int main(){
    scanf("%d%d%d", &n1, &n2, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b; scanf("%d%d", &a, &b); 
        add(a, b);
    }
    printf("%d\n", dyeing());
    return 0;
}
