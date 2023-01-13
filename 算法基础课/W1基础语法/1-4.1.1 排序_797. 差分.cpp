#include<iostream>
const int N = 1e5 + 10;
int n, m, q[N], s[N] = {0}, l, r, c;
void insert(int s[], int l, int r, int c){
    s[l] += c;
    s[r + 1] -= c;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &q[i]);
    for(int i = 1; i <= n; ++i) insert(s, i, i, q[i]);
    while(m--){
        scanf("%d%d%d", &l, &r, &c);
        insert(s, l, r, c);
    }
    for(int i = 1; i <= n; ++i) s[i] += s[i - 1];
    for(int i = 1; i <= n; ++i) printf("%d ", s[i]);
    return 0;
}


#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m, q[N], s[N];
void insert(int s[], int l, int r, int c){
    s[l] += c;
    s[r + 1] -= c;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &q[i]);
    int l, r, c;
    while(m--){
        scanf("%d%d%d", &l, &r, &c);
        insert(s, l, r, c);
    }
    for(int i = 1; i <= n; ++i) s[i] += s[i - 1];
    for(int i = 1; i <= n; ++i) q[i] += s[i];
    for(int i = 1; i <= n; ++i) printf("%d ", q[i]);
    return 0;
}
