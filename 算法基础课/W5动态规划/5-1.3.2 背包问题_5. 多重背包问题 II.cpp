#include<iostream>
using namespace std;
const int N = 12010, M = 2010;  // N = 1000 * log2(2000) => 12000
int v[N], w[N], f[M];
int main(){
    int n,m, cnt=0; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        int a, b, s, k=1; scanf("%d%d%d", &a, &b, &s);
        while(k<=s){
            v[++cnt] = a*k;
            w[cnt] = b*k;
            s-=k;
            k*=2;
        }
        if(s>0){
            v[++cnt] = a*s;
            w[cnt] = b*s;
        }
    }
    n = cnt;
    for(int i=1; i<=n; ++i) for(int j=m; j>=v[i]; --j) f[j] = max(f[j], f[j-v[i]]+w[i]);
    printf("%d\n", f[m]);
    return 0;
}
