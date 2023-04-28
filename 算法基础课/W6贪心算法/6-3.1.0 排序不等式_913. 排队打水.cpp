#include<iostream>
#include<algorithm>
using namespace std;
using LL = long long ;
const int N = 1e5+10;
int n, t[N];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; ++i)scanf("%d", &t[i]);
    sort(t, t+n);
    reverse(t, t+n);
    LL res = 0;
    for(int i=0; i<n; ++i) res += t[i]*i;
    printf("%lld\n", res);
    return 0;
}
