#include<iostream>
using namespace std;
int lowbit(int x){
    return x&(-x); // return x & (~x + 1);
}
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int x,res=0;scanf("%d",&x);
        while(x) x-=lowbit(x),res++;
        printf("%d ",res);
    }
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int x,res=0;scanf("%d",&x);
        for(int i=x;x;x-=x&-x)res++;
        printf("%d ",res);
    }
    return 0;
}
