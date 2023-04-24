#include<iostream>
using namespace std;
const int INF= 2e9, N = 2333;
int lena, lenb, f[N][N];
char a[N], b[N];
int main(){
    scanf("%d%s%d%s", &lena, a+1, &lenb, b+1);
    for(int i=1; i<=lena; ++i) for(int j=1; j<=lenb; ++j) f[i][j] = INF;
    for(int i=1; i<=lena; ++i)f[i][0]=i;
    for(int i=1; i<=lenb; ++i)f[0][i]=i;
    for(int i=1; i<=lena; ++i) {
        for(int j=1; j<=lenb; ++j){
            f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1);
            if(a[i]==b[j])f[i][j] = min(f[i][j], f[i-1][j-1]);
            else f[i][j] = min(f[i][j], f[i-1][j-1] + 1);
        }
    }
    printf("%d\n",f[lena][lenb]);
    return 0;
}
