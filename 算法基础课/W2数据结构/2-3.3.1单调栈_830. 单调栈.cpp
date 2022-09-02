#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int stk[N], idx = 0, n;
int main(){
    cin >> n;
    while(n--){
        int x; scanf("%d", &x);
	//栈中元素大于当前的数字,则自栈顶弹出直到栈中元素小于当前数字
        while(idx && stk[idx] >= x) --idx;
        if(!idx) printf("-1 ");
        else printf("%d ", stk[idx]);
	// 若stk[idx++] = x 则会导致stk[1] = 0
        stk[++idx] = x; 
    }
    return 0;
}
