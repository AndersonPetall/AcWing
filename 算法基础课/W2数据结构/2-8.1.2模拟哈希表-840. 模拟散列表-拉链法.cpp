#include<iostream>
#include<cstring>
using namespace std;
const int N = 2e5 + 3, null = 0x3f3f3f3f;
int h[N], n;
int find(int x){
    int k = (x % N + N ) % N;
    while(h[k] != null && h[k] != x){
        ++k;
        if(k == N) k = 0;
    }
    return k;
}
int main(){
    memset(h, null, sizeof h);
    scanf("%d", &n);
    while(n--){
        char op[2]; int x; scanf("%s%d", op, &x);
        if(*op == 'I') h[find(x)] = x;
        if(*op == 'Q'){
            if(h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}
