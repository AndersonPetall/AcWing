#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int son[N][26], count[N], idx, root = 0;
char str[N];
void insert(char *str){
    int p = root;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    ++count[p];
}
int query(char *str){
    int p = root;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return count[p];
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        char op[2]; scanf("%s%s", op, str);
        if(*op == 'I') insert(str);
        if(*op == 'Q') printf("%d\n", query(str));
    }
    return 0;
}
