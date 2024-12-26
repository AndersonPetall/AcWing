#include<iostream>
using namespace std;
int const N = 1e6+10;
int main(){
    int n,res=0,q[N],s[N];
    scanf("%d", &n);
    for(int i=0,j=0;i<n;++i){
        scanf("%d",&q[i]);
        s[q[i]]++;
        while(j<i&&s[q[i]]>1)s[q[j++]]--; // --s[q[j++]]
        res = max(res, i-j+1);
    }
    printf("%d",res);
    return 0;
}
