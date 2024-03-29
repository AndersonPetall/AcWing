#include<algorithm>
using namespace std;
using PII = pair<int, int>;
const int N = 5e4+10;
PII cow[N];
int main(){
    int n; scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int s, w; scanf("%d%d", &w, &s);
        cow[i] = {w+s, w};
    }
    sort(cow, cow+n);
    int res=-2e9, sum=0;
    for(int i=0; i<n; ++i){
        int s=cow[i].first - cow[i].second, w=cow[i].second;
        res = max(res,sum-s);
        sum += w;
    }
    printf("%d\n", res);
    return 0;
}
