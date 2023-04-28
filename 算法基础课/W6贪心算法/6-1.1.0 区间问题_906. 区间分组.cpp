#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
struct Range{
    int l, r;
    bool operator <(const Range &W) const{
        return l<W.l;
    }
}ranges[N];
int main(){
    int n; scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int l,r; scanf("%d%d", &l, &r);
        ranges[i] = {l,r};
    }
    sort(ranges, ranges + n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i=0; i<n; ++i){
        auto x = ranges[i];
        if(heap.empty() || heap.top() >=x.l) heap.push(x.r);
        else{
            heap.pop();
            heap.push(x.r);
        }
    }
    printf("%d\n", heap.size());
    return 0;
}









#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n, b[2*N], idx;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int l, r; scanf("%d%d", &l, &r);
        b[idx++] = l*2;
        b[idx++] = r*2 + 1;
    }
    sort(b, b+idx);
    int res=1, t=0;
    for(int i=0; i<idx; ++i){
        if(b[i]%2 == 0) ++t;
        else --t;
        res = max(res,t);
    }
    printf("%d\n", res);
    return 0;
}
