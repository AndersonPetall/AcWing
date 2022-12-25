#include<iostream>
using namespace std;
const int N =2e3+10, mod=1e9+7;
int c[N][N];
int main(){
    int n; cin>>n;
    for(int i=0;i<N;++i)for(int j=0;j<=i;++j) !j ? c[i][j]=1 : c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",c[a][b]);
    }
    return 0;
}
