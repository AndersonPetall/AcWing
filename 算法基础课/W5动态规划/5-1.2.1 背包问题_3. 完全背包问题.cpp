//朴素版本
#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int v[N],w[N],f[N][N];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            for(int k=0; k*v[i]<=j;++k) f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}



//优化版本
#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int v[N],w[N],f[N][N];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            f[i][j] = f[i-1][j];  //赋初值  必要
            if(j-v[i]>=0)f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);  //与01背包不同, 物品重复使用,所以不用i-1而是用i
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}





#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int v[N],w[N],f[N];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    for(int i=1; i<=n; ++i){
        for(int j=v[i]; j<=m; ++j){  //正序  和01背包不一样
            f[j] = max(f[j], f[j-v[i]]+w[i]);  //物品i的选取由此轮(i)的f值进行计算,所以使用正序
        }
    }
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
    for(int i=1; i<=n; ++i){
        int v, w; scanf("%d%d", &v, &w);
        for(int j=v; j<=m; ++j) f[j] = max(f[j], f[j-v]+w);
    }
    printf("%d\n", f[m]);
    return 0;
}
