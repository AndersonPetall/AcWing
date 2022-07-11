//EDITION 1
#include<iostream>
using namespace std;
const int N = 10;
int path[N], state[N], n;
void dfs(int x){
    if(x > n){
        for(int i = 1; i <= n; ++i) printf("%d ", path[i]);
        puts("");
        return ;
    }
    for(int i = 1; i <= n; ++i){
        if(!state[i]){
            path[x] = i;
            state[i] = 1;
            dfs(x+1);
            state[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}



//EDITION 2
#include<iostream>
using namespace std;
const int N = 10;
int n, path[N];
void dfs(int x, int state){
    if(x == n){
        for(int i = 0; i < n; ++i)printf("%d ", path[i]);
        puts("");
        return ;
    }
    for(int i = 0; i < n; ++i){
        if(!(state >> i & 1)){
            path[x] = i + 1;
            dfs(x + 1, state + (1<<i));
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(0, 0);
    return 0;
}



//EDITION 3
#include<iostream>
using namespace std;
const int N = 10;
int n, path[N];
void dfs(int x, int state){
    if(x > n){
        for(int i = 1; i <= n; ++i)printf("%d ", path[i]);
        puts("");
        return ;
    }
    for(int i = 1; i <= n; ++i){
        if(!(state >> i & 1)){
            path[x] = i;
            dfs(x + 1, state + (1<<i));
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(1, 0);
    return 0;
}
