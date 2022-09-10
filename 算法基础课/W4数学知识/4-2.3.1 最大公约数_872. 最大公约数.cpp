//EDITION 1  self
#include<iostream>
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
int main(){
    int n; cin >> n;
    while(n--){
        int a, b; scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}


//EDITION 2  STL自带的求最大公约数的函数__gcd(a,b)
#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main() {
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << __gcd(a,b) << endl;
    }
    return 0;
}
