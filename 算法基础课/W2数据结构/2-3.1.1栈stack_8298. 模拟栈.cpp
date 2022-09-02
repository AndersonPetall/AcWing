//EDITION 1   top = 0
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int m, stack[N], top;
int main(){
    scanf("%d", &m);
    while(m--){
        string s; cin >> s;
        if(s == "push"){
            int a; cin >> a;
            stack[top++] = a;
        }
        if(s == "pop") --top;
        if(s == "empty") cout << (top == 0 ? "YES" : "NO") << endl;
        if(s == "query") printf("%d\n", stack[top - 1]);
    }
    return 0;
}


//EDITION 2   top = -1
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int m, stack[N], top = -1;
int main(){
    scanf("%d", &m);
    while(m--){
        string s; cin >> s;
        if(s == "push"){
            int a; cin >> a;
            stack[++top] = a;
        }
        if(s == "pop") --top;
        if(s == "empty") cout << (top == -1 ? "YES" : "NO") << endl;
        if(s == "query") printf("%d\n", stack[top]);
    }
    return 0;
}
