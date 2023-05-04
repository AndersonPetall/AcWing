#include <iostream>
using namespace std;
const int N = 110;
int v[N][N], w[N][N], f[N], s[N];
int main() {
    int n, m; scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf ("%d", &s[i]);
        for (int j=1; j<=s[i]; ++j) scanf ("%d%d", &v[i][j], &w[i][j]);
    }
    for(int i=1; i<=n; ++i) for(int j=m; j>=1; --j) for(int k=1; k<=s[i]; ++k) 
        if(v[i][k]<=j) f[j] = max(f[j], f[j-v[i][k]] + w[i][k]);
    printf("%d\n", f[m]);
    return 0;
}
