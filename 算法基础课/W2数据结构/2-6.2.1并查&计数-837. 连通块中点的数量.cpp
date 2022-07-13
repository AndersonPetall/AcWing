//EDITION 1
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m, p[N], count[N];
int find(int x){  //初始化,也可以从0开始
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d", &n , &m);
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        count[i] = 1;
    }
    while(m--){
        string op; cin >> op;
        int a, b;
        if(op == "C"){
            scanf("%d%d", &a, &b);
            if(find(a) != find(b)){
                count[find(b)] += count[find(a)];  //先加后合并,否则root会多计一次
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
            cout << count[find(a)] <<endl;
        }
    }
    return 0;
}




//EDITION 2
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m, p[N], count[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d", &n , &m);
    for(int i = 0; i < n; ++i){
        p[i] = i;
        count[i] = 1;
    }
    while(m--){
        string op; cin >> op;
        int a, b;
        if(op == "C"){
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            if(find(a) != find(b)){
		p[a] = b;   //加 和合并的顺序不重要,  a特指a所在的树,b特指b所在的树,root不会重复计数
                count[b] += count[a];
                //p[a] = b;
            }
        }
        if(op == "Q1"){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        if(op == "Q2"){
            scanf("%d", &a);
            cout << count[find(a)] <<endl;
        }
    }
    return 0;
}
