//EDITION self
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N=1e2+10;
int f[N];
set<int> S;
int sg(int x){
    if(f[x]!=-1) return f[x];
    for(int i=0;i<x;++i)for(int j=0;j<=i;++j)S.insert(sg(i)^sg(j));
    for(int i=0;;++i)if(!S.count(i))return f[x]=i;
}
int main(){
    memset(f,-1,sizeof f);
    int n; cin>>n;
    int res =0;
    while(n--){
        int x;cin>>x;
        res ^=sg(x);
    }
    res ? puts("Yes") : puts("No");
    return 0;
}


//EDITION　ACwing
#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
const int N=1e2+10;
int n, f[N];
unordered_set<int> S;
int sg(int x){
    if(f[x]!=-1) return f[x];
    for(int i=0;i<x;++i)for(int j=0;j<=i;++j)S.insert(sg(i)^sg(j));
    for(int i=0;;++i)if(!S.count(i))return f[x]=i;
}
int main(){
    memset(f,-1,sizeof f);
    cin>>n;
    int res =0;
    while(n--){
        int x;cin>>x;
        res ^=sg(x);
    }
    res ? puts("Yes") : puts("No");
    return 0;
}
