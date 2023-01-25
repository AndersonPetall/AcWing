#include<iostream>
using namespace std;
const int N = 1e3+10;
int n,m,v[N],w[N],f[N][N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[i][j]= j < v[i] ? f[i-1][j] :max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
    printf("%d\n",f[n][m]);
    return 0;
}




#include<iostream>
using namespace std;
const int N = 1e3+10;
int n,m,v[N],w[N],f[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    for(int i=1;i<=n;++i)for(int j=m;j>=v[i];--j)f[j]=max(f[j],f[j-v[i]]+w[i]);
    printf("%d\n",f[m]);
    return 0;
}
