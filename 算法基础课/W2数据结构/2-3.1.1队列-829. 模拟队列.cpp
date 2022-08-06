//EDITION 1   一个index
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int m, stack[N], idx = -1;
int main(){
    scanf("%d", &m);
    while(m--){
        string s; cin >> s;
        if(s == "push"){
            int a; cin >> a;
            stack[++idx] = a;
        }
        if(s == "pop") --idx;
        if(s == "query")  printf("%d\n", stack[0]);
        if(s == "empty") cout << (idx == -1 ? "YES" : "NO") << endl;
        
    }
    return 0;
}
