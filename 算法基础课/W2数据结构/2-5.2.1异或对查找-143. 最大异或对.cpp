//EDITION1  精简
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 30*1e5 + 10;
int a[N], son[M][2], idx, root = 0;
void insert(int x){
    int p = root;
    for(int i = 30; ~i; --i){
        int &s = son[p][x >> i & 1];
        if(!s) s = ++idx;
        p = s;
    }
}
int query(int x){
    int p = root, res = 0;
    for(int i = 30; ~i;--i){
        int s = x >> i & 1;
        if(son[p][!s]){
            res += 1 <<i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]); insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; ++i) res =max(res, query(a[i]));
    printf("%d", res);
    return 0;
}



//EDITION 2   理解
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 30 * 1e5 + 10;
int a[N], son[M][2], idx, root = 0;
void insert(int x){
    int p = root;
    for(int i = 30; i >= 0; --i){
        int &s = son[p][x >> i & 1];
        if(!s) s = ++idx;
        p = s;
    }
}
int query(int x){
    int p = root, res = 0;
    for(int i = 30; i >= 0; --i){
        int s = x >> i & 1;
        if(son[p][!s]){
            res += 1 << i;
            p = son[p][!s];
        }
        else{
            res += 0 << i;
            p = son[p][s];
        } 
    }
    return res;
}
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]); insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; ++i) res = max(res, query(a[i]));
    printf("%d", res);
    return 0;
}
