#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
struct Range
{
    int l, r;
    bool operator< (const Range &W)const{
        return r < W.r;
    }
}ranges[N];
int main(){
    int n;scanf("%d", &n);
    for (int i=0; i<n; ++i) scanf("%d%d", &ranges[i].l, &ranges[i].r);
    sort(ranges, ranges+n);
    int res=0, ed=-2e9;
    for(int i=0; i<n; ++i)if(ed<ranges[i].l){
        ++res;
        ed = ranges[i].r;
    }
    printf("%d\n", res);
    return 0;
}
