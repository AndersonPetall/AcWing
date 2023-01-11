#include<iostream>
using namespace std;
const int N = 1e3+10;
int n,m,v[N],w[N],f[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    for(int i=1;i<=n;++i)for(int j=v[i];j<=m;++j)f[j]=max(f[j],f[j-v[i]]+w[i]);
    printf("%d\n",f[m]);
    return 0;
}
