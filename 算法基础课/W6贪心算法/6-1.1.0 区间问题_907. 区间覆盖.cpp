#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
struct Range{
    int l, r;
    bool operator < (const Range &W) const{
        return l < W.l;
    }
}ranges[N];
int main(){
    int st, ed, n; scanf("%d%d%d", &st, &ed, &n);
    for(int i=0; i<n; ++i){
        int l, r; scanf("%d%d", &l, &r);
        ranges[i] = {l,r};
    }
    sort(ranges, ranges + n);
    int res =0; 
    bool success = false;
    for(int i=0; i<n; ++i){
        int j=i, r=-2e9;
        while(j<n && ranges[j].l<=st){
            r=max(r,ranges[j].r);
            ++j;
        }
        if(r<st){
            res=-1;
            break;
        }
        ++res;
        if(r>=ed){
            success = true;
            break;
        }
        st = r;
        i = j-1;
    }
    if(!success) res = -1;
    printf("%d\n", res);
    return 0;
}
