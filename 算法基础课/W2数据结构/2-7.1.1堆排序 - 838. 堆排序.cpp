//EDITION 1  :  根节点从1开始计算
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, m, cnt, h[N];
void down(int u){
    int t = u;
    if(2*u <= cnt && h[2*u] < h[t]) t = u * 2;
    if(2*u + 1 <= cnt && h[2*u + 1] < h[t]) t = 2*u + 1;
    if(u != t){
        swap(h[u], h[t]);
        down(t);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)scanf("%d", &h[i]);
    cnt = n;
    for(int i = n / 2; i ; --i) down(i);
    while(m--){
        printf("%d ", h[1]);
        h[1] = h[cnt --];
        down(1);
    }
    return 0;
}


//EDITION 2  :  根节点从0开始计算
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, m, h[N], cnt;
void down(int idx){
    int t = idx, leftnode = 1, rightnode = 2;
    if(idx != 0) leftnode = idx*2, rightnode = idx*2 + 1;
    if(leftnode <= cnt && h[leftnode] <= h[t]) t = leftnode;
    if(rightnode <= cnt && h[rightnode] <= h[t]) t = rightnode;
    if(t != idx){
        swap(h[t], h[idx]);
        down(t);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", &h[i]);
    cnt = n - 1;
    for(int i = n/2 - 1; i >= 0 ; --i) down(i);
    while(m--){
        printf("%d ", h[0]);
        h[0] = h[cnt--]; 
        down(0);
    }
    return 0;
}
