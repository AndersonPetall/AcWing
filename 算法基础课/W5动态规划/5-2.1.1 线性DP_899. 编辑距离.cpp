#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 14, M = 1010;
int n, m, f[N][N];
char str[M][M];
int edit_distance(char a[], char b[]){
    int lena=strlen(a+1), lenb = strlen(b+1);
    for(int i = 0; i <= lena; ++i)f[i][0] = i;
    for(int i = 0; i <= lenb; ++i)f[0][i] = i;
    for(int i = 1; i <= lena; ++i){
        for(int j = 1; j <=lenb; ++j){
            f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
            f[i][j] = min(f[i][j], f[i-1][j-1] + (a[i] != b[j]));
        }
    }
    return f[lena][lenb];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n; ++i) scanf("%s", str[i] +1);
    while(m--){
        char s[N];
        int limit;
        scanf("%s%d", s+1, &limit);
        int res = 0; 
        for(int i=0; i < n; ++i) if(edit_distance(str[i],s) <= limit) ++res;
        printf("%d\n",res);
    }
    return 0;
}
