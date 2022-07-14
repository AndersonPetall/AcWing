#include<iostream>
using namespace std;
const int N = 5e5 + 10;
int p[N], d[N];
int find(int idx){
    if(idx != p[idx]){
        int temp = find(p[idx]);
        d[idx] += d[p[idx]];
        p[idx] = temp;
    }
    return p[idx];
}
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) p[i] = i;
    int lie = 0;
    while(m--){
        int type, x, y; scanf("%d%d%d", &type, &x, &y);
        if(x > n || y > n) ++lie;
        else{
            int rootx = find(x), rooty = find(y);
            if(type == 1){
                if(rootx == rooty){
                    if((d[x] - d[y])%3 != 0) {++lie;}
                }
                else{
                    p[rootx] = rooty;
                    d[rootx] = d[y] - d[x];
                }
            }
            if(type == 2){
                if(rootx == rooty){
                    if((d[x] - d[y] - 1)%3 != 0) {++lie;}
                }
                else{
                    p[rootx] = rooty;
                    d[rootx] = d[y] - d[x] + 1;
                }
            }
        }
    }
    printf("%d", lie);
    return 0;
}
