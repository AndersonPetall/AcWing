#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n;
struct Range{
    int l, r;
    bool operator< (const Range &W)const{  //成员函数, 只读
        return r < W.r;
    }
} range[N];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; ++i)scanf("%d%d", &range[i].l, &range[i].r);
    sort(range,range+n);
    int res=0, ed=-2e9;
    for(int i=0; i<n; ++i)
        if(ed < range[i].l){  //若选点未能被区间包含, 则将区间右端点选为下一个点
            ++res;
            ed = range[i].r;  
        }
    printf("%d\n", res);
    return 0;
}
