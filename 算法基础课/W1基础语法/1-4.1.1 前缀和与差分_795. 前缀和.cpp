#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m, q[N], s[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &q[i]);
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + q[i];
    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l -1]);
    }
    return 0;
}
