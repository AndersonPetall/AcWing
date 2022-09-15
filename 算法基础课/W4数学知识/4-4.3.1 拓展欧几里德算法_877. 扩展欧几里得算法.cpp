//EDITION    精简版
#include<iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);  //
    y -= a/b*x;
    return d;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, x, y; scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}



#include<iostream>
#include<algorithm>
using namespace std;
int exgcd(int a, int b, int &x, int &y){
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1, gcd;
    gcd = exgcd(b, a%b, x1, y1);
    x = y1, y = x1 - a/b*y1;
    return gcd;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, x, y;scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}



#include<iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int gcd = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return gcd;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, x=0, y=0;; scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}
