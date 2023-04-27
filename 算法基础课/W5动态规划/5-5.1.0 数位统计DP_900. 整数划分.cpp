#include<iostream>
#include<vector>
using namespace std;
int base[10], f[10][10], g[10][10];
void init(){
    base[0] = 1;
    for(int i=1; i<=9; ++i) base[i] = base[i-1]*10;
    for(int i=0; i<=9; ++i) f[1][i] = 1;
    for(int i=2; i<=9; ++i) for(int j=0; j<=9; ++j) f[i][j] = f[i-1][j]*10 + base[i-1];
    for(int i=1; i<=9; ++i) g[1][i] = 1;
    for(int i=2; i<=9; ++i){
        g[i][0] = g[i-1][0] + f[i-1][0]*9;
        for(int j=1; j<=9; ++j) g[i][j] = g[i-1][j] + f[i-1][j]*9 + base[i-1];
    }
}
vector<int> dp(int n){
    vector<int> ans(10,0);
    if(n<=0) return ans;
    vector<int> nums;
    while(n) nums.push_back(n%10), n/=10;
    vector<int> last(10,0);
    for(int i=0; i<=9; ++i)ans[i] = g[nums.size()-1][i];
    for(int i=nums.size()-1; i>=0; --i){
        int x = nums[i];
        for(int j= (i==nums.size()-1); j<x; ++j){
            for(int k=0; k<=9; ++k) ans[k] += last[k] * base[i];
            ans[j] += base[i];
            for(int k=0; k<=9; ++k) ans[k] += f[i][k];
        }
        last[x] ++;
        if(!i) for(int k=0; k<=9; ++k) ans[k] += last[k];
    }
    return ans;
}
vector<int> ask(int a, int b){
    auto x = dp(b);
    auto y = dp(a-1);
    vector<int> ans;
    for(int i=0; i<=9; ++i)ans.push_back(x[i]-y[i]);
    return ans;
}
void print(vector<int> ans){
    for(auto x : ans) printf("%d ", x);
    puts("");
}
bool check(int x){
    auto t = ask(x,x);
    vector<int> cnt(10,0);
    while(x) cnt[x%10]++, x/= 10;
    for(int i=0; i<=9; ++i) if(cnt[i] != t[i]) return false;
    return true;
}
int main(){
    init();
    int a,b;
    while(cin>>a>>b, a||b){
        if(a>b) swap(a,b);
        auto t = ask(a,b);
        print(t);
    }
    return 0;
}








#include<iostream>
#include<cmath>
using namespace std;
int dgt(int n){
    int res = 0; 
    while(n) ++res, n/=10;
    return res;
}
int cnt(int n, int i){
    int res=0, d=dgt(n);
    for(int j=1; j<=d; ++j){
        int p = pow(10, j-1), l = n/p/10, r = n%p, dj = n/p%10;
        if(i) res += l*p;
        if(!i && l)res += (l-1)*p;
        if((dj>i) && (i||l)) res += p;
        if((dj==i) && (i||l)) res += r+1;
    }
    return res;
}
int main(){
    int a, b;
    while(cin>>a>>b, a){
        if(a>b) swap(a,b);
        for(int i=0; i<=9; ++i) printf("%d ", cnt(b,i) - cnt(a-1,i));
        cout << endl;
    }
    return 0;
}
