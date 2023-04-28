#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n, res, a[N];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; ++i)scanf("%d", &a[i]);
    sort(a, a+n);
    for(int i=0; i<n; ++i) res += abs(a[i]-a[n>>1]);
    printf("%d\n", res);
    return 0;
}
