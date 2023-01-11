#include<iostream>
using namespace std;
const int N = 110;
int n,m,v[N][N],w[N][N],s[N],f[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        for(int j=0;j<s[i];++j)cin>>v[i][j]>>w[i][j];
    }
    for(int i=1;i<=n;++i)
        for(int j=m;j>=0;--j)
            for(int k=0;k<s[i];++k)
                if(v[i][k]<=j)f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
    printf("%d\n",f[m]);
    return 0;
}
