#include<iostream>
using namespace std;
int main(){
    int n, res=0;cin>>n;
    while(n--){
        int x; scanf("%d",&x);
        res ^=x;
    }
    res ? puts("Yes") : puts("No");
    return 0;
}
