#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int head, e[N], ne[N], idx;
void init(){
    head = -1, idx = 0;
}
void add_to_head(int x){
    e[idx] = x, ne[idx] = head, head = idx++;
}
void add(int k, int x){
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
void remove(int k){
    ne[k] = ne[ne[k]];
}
int main(){
    int M; cin >> M ;
    init();
    while(M--){
        int k,x; char m;
        cin >> m;
        if(m =='H'){
            cin >> x;
            add_to_head(x);
        }
        else if(m == 'I'){
            cin >> k >> x;
            add(k-1, x);
        }
        else{
            cin >> k ;
            if(!k) head = ne[head];
            else remove(k -1);
        }
    }
    for(int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
    return 0;
}
