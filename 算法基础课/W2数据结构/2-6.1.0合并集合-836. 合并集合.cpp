#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);  //寻找树根 
    return p[x];
}
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; ++i) p[i] = i;  // 初始化
    while(m--){
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(*op == 'M') p[find(a)] = find(b); //树a的root的值由自身改为树b的root(子节点),此时路劲压缩  (树a的所有结点的索引都将改为树b的root) 
        if(*op == 'Q'){
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
