//EDITION 1
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N], count[N];
int find(int idx){
    if(idx != p[idx]) p[idx] = find(p[idx]);
    return p[idx];
}
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        p[i] = i;
        count[i] = 1;
    }
    while(m--){
        string op;int a, b; cin >> op;
        if(op == "C"){
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            if(a != b){
                p[a] = b;
                count[b] += count[a];
            }
        }
        if(op == "Q1"){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        if(op == "Q2"){
            scanf("%d", &a);
            printf("%d\n", count[find(a)]);
        }
    }
    return 0;
}





//EDITION 2
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N], count[N];
int find(int idx){
    if(idx != p[idx]) p[idx] = find(p[idx]);
    return p[idx];
}
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        p[i] = i;
        count[i] = 1;
    }
    while(m--){
        string op;int a, b; cin >> op;
        if(op == "C"){
            scanf("%d%d", &a, &b);
            if(find(a) != find(b)){
            count[find(b)] += count[find(a)];
            p[find(a)] = find(b);
            }
        }
        if(op == "Q1"){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        if(op == "Q2"){
            scanf("%d", &a);
            printf("%d\n", count[find(a)]);
        }
    }
    return 0;
}
