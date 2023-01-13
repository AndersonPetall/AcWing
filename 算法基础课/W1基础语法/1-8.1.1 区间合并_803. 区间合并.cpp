#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
int n, l, r;
void merge(vector<PII> &A){
    vector<PII> B;
    sort(A.begin(), A.end());
    int st = -(2e9 + 10), ed =-(2e9 + 10);
    for(auto item : A){
        if(ed < item.first) {
            if(ed != -2e9 - 10) B.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else ed = max(ed, item.second);
    }
    if(st != -2e9 - 10) B.push_back({st, ed});
    A = B;
}
int main(){
    scanf("%d", &n);
    vector<PII> segs;
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() <<endl;
    //printf("%d\n", segs.size());
    return 0;
}
