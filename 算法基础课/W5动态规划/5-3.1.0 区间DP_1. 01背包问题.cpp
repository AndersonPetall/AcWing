#include<iostream>
#include<cstring>
using namespace std;
const int N = 307;
int a[N], s[N], f[N][N];
int main(){
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        s[i] += s[i-1] + a[i];
    }
    memset(f,0x3f,sizeof f);
    for(int len=1; len<=n; ++len){
        for(int i=1,j ; (j = i+len-1)<=n; ++i){
            //j = i+len-1;
            if(len == 1){
                f[i][j] = 0;
                continue;
            }
            for(int k=i; k<=j-1; ++k)f[i][j]=min(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}


//倒着枚举
#include<iostream>
using namespace std;
const int N = 307;
int s[N], f[N][N];
int main(){
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&s[i]);
        s[i] += s[i-1];
    }
    for(int i=n; i>=1; --i){
        for(int j=i; j<=n; ++j){
            if(j==i){
                f[i][j] = 0;
                continue;
            }
            f[i][j] = 1e9;
            for(int k=i; k<j; ++k)f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}

//记忆搜索
#include<iostream>
#include<cstring>
using namespace std;
const int N = 307;
int a[N], s[N], f[N][N];
int dp(int i, int j){
    if(i == j)return 0;
    int &v = f[i][j];
    if(v != -1)return v;
    v = 1e8;
    for(int k=i; k <=j-1; ++k) v = min(v, dp(i,k) + dp(k+1, j) + s[j] - s[i-1]);
    return v;
}
int main(){
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        s[i] += s[i-1] + a[i];
    }
    memset(f, -1, sizeof f);
    printf("%d\n",dp(1,n));
    return 0;
}
