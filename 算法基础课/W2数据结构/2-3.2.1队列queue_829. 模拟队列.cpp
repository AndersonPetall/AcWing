//情况一: head = 0, tail = -1, head <= tail not empty  插入为stk[++tt] = x;
#include <iostream> ;
using namespace std;
const int N = 1e5 + 10;
int m, q[N], head =0,  tail = -1;
int main(){
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            q[++tail] = x;
        }
        if(s == "pop"){
            ++head;
        }
        if(s == "empty"){
            cout << (head <= tail ? "NO": "YES") << endl;
        }
        if(s == "query"){
            cout << q[head] <<endl;;
        }
    }
    return 0;
}


//情况二:head = 0, tail = 0,  head < tail not empty  插入为stk[tt++] = x;
#include <iostream> ;
using namespace std;
const int N = 1e5 + 10;
int m, q[N], head = 0,  tail = 0;
int main(){
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            q[tail++] = x;
        }
        if(s == "pop"){
            ++head;
        }
        if(s == "empty"){
            cout << (head < tail ? "NO": "YES") << endl;
        }
        if(s == "query"){
            cout << q[head] <<endl;;
        }
    }
    return 0;
}
