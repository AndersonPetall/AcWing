#include<iostream>
using namespace std;
const int N = 1e5 + 6;
int n, m, x, A[N], B[N];
int main(){
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
    for(int i = 0; i < m; ++i) scanf("%d", &B[i]);
    for(int i = 0, j = m - 1; i < n; ++i){
        while(j >= 0 && A[i] + B[j] > x) --j;
        if(A[i] + B[j] == x) cout << i << " " << j <<endl;
    }
    return 0;
}
