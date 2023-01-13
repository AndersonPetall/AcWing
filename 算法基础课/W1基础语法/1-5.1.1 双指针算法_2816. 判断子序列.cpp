#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m, A[N], B[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
    for(int i = 0; i < m; ++i) scanf("%d", &B[i]);
    int j = 0;
    for(int i = 0; i < m; ++i){
        if(A[j] == B[i]) ++j;
        if(j == n){puts("Yes");break;}
    }
    if (j != n) {puts("No");}
    return 0;
}
