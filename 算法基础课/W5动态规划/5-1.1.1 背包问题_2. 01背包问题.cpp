//朴素版本
#include<iostream>
using namespace std;
const int N = 1e3+10;
int v[N],w[N],f[N][N];
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d", &v[i], &w[i]);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[i][j]= j < v[i] ? f[i-1][j] :max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
    printf("%d\n",f[n][m]);
    return 0;
}



//优化版本
#include<iostream>
using namespace std;
const int N = 1e3+10;
int v[N],w[N],f[N];
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d%d", &v[i], &w[i]);
    for(int i=1;i<=n;++i)for(int j=m;j>=v[i];--j)f[j]=max(f[j],f[j-v[i]]+w[i]);
    printf("%d\n",f[m]);
    return 0;
}



//进阶优化版本  边录入边计算
#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int f[N];
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i=1;i<=n;++i){
        int v,w; cin>>v>>w;
        for(int j=m;j>=v;--j) f[j] = max(f[j],f[j-v]+w);  
    }
    printf("%d\n",f[m]);
    return 0;
}
