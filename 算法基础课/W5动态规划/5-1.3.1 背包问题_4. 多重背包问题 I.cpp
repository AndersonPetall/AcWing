#include<iostream>
using namespace std;
const int N = 110;
int v[N],w[N],s[N],f[N][N];
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d%d", &v[i],&w[i],&s[i]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            for(int k=0; k<=s[i]&&k*v[i]<=j; ++k) f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i]);
    printf("%d\n", f[n][m]);
    return 0;
}
//是f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i])  而非 f[i][j] = max(f[i-1][j], f[i-1][j-k*v[i]]+k*w[i])的原因
//当k=0时, f[i-1][j-k*v[i]]+k*w[i] = f[i-1][j]
//在k这层循环中, 会与f[i-1]比较一次, 之后每次都是对于这个点进行更新，与自身f[i][j]进行比较(储存最大值)



//拆分
/*
si = 1, 相当于01背包中的一件物品
s2 > 1, 相当于01背包中的多个一件物品
*/
#include<iostream>
using namespace std;
const int N = 1e4+10;
int a[N], b[N], f[N];
int main(){
    int n, m, v, w, s, t=0; scanf("%d%d", &n, &m);
    while(n--){
        scanf("%d%d%d", &v, &w, &s);
        while(s--){   // 背包拆分
            a[++t] = v;
            b[t] = w;  
        }
    }
    for(int i=1; i<=t; ++i)
        for(int j=m; j>=a[i]; --j) f[j] = max(f[j], f[j-a[i]]+b[i]);
    printf("%d\n", f[m]);
    return 0;
}

//优化
#include<iostream>
using namespace std;
int f[10010];
int main(){
    int n, m, v, w, s; scanf("%d%d", &n, &m);
    while(n--){
        scanf("%d%d%d", &v, &w, &s);
        while(s--) for(int j=m; j>=v; --j) f[j] = max(f[j], f[j-v]+w);
    }
    printf("%d\n", f[m]);
    return 0;
}
