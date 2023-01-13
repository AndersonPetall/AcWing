#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int n, m, a, x1, y1, x2, y2, c, q[N][N], s[N][N];
void submatrixInsert(int s[][N], int x1, int y1, int x2, int y2, int c){
    s[x1][y1] += c;
    s[x2+1][y2+1] += c;
    s[x1][y2+1] -= c;
    s[x2+1][y1] -= c;
}
int main(){
    scanf("%d%d%d", &n, &m, &a);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &q[i][j]);
    while(a--){
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        submatrixInsert(s, x1, y1, x2, y2, c);
        
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j) printf("%d ", q[i][j] + s[i][j]);
        printf("\n");
    }
    return 0;
}




#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int n, m, a, x1, y1, x2, y2, c, q[N][N], s[N][N];
void submatrixInsert(int s[][N], int x1, int y1, int x2, int y2, int c){
    s[x1][y1] += c;
    s[x2+1][y2+1] += c;
    s[x1][y2+1] -= c;
    s[x2+1][y1] -= c;
}
int main(){
    scanf("%d%d%d", &n, &m, &a);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &q[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            s[i][j] = q[i][j] - q[i-1][j] - q[i][j-1] + q[i-1][j-1];
    while(a--){
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        submatrixInsert(s, x1, y1, x2, y2, c);
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j) printf("%d ", s[i][j]);
        printf("\n");
    }
    return 0;
}
