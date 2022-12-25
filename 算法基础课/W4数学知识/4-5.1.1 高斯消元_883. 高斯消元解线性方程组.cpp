#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 110;
const double eps = 1e-8;
double a[N][N];
int gauss(int n){
    int c,r;
    for(c=r=0;c<n;++c){
        int t = r;
        for(int i=r;i<n;++i)if(fabs(a[i][c])>fabs(a[t][c])) t=i;
        if(fabs(a[t][c])<eps) continue;
        for(int i=c;i<=n;++i) swap(a[t][i],a[r][i]);
        for(int i=n;i>=c;--i)a[r][i]/=a[r][c];
        for(int i=r+1;i<n;++i)if(fabs(a[i][c])>eps)for(int j=n;j>=c;--j)a[i][j]-=a[r][j]*a[i][c];
        ++r;
    }
    if(r<n){
        for(int i=r;i<n;++i)if(fabs(a[i][n])>eps)return 2;
        return 1;
    }
    for(int i=n-1;i>=0;--i)for(int j=i+1;j<n;++j)a[i][n]-=a[i][j]*a[j][n];
    return 0;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)for(int j=0;j<n+1;++j)scanf("%lf",&a[i][j]);
    int res = gauss(n);
    if(res == 0)for(int i=0;i<n;++i) fabs(a[i][n])<eps ? puts("0.00"):printf("%.2lf\n",a[i][n]);
    else res == 1 ? puts("Infinite group solutions"):puts("No solution");
    return 0;
}






#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-8;
const int N = 110;
double a[N][N];
int gauss(int n){
    int c,r;
    for(c=r=0;c<n;++c){
        int t = r;
        //寻找C列的最大值
        for(int i=r;i<n;++i)
            if(fabs(a[i][c])>fabs(a[t][c])) t=i;
        //如果最大值为0,则意味该列无解(方程系数为0)
        if(fabs(a[t][c])<eps) continue;
        //将当前列(列C)置换至未操作的方程组的最上层
        for(int i=c;i<=n;++i) swap(a[t][i],a[r][i]);
        //最大值所在的行  将最大值系数变为1
        for(int i=n;i>=c;--i)a[r][i]/=a[r][c];
        //利用最大值所在的行,将未操作的方程组的列C的系数变为0
        for(int i=r+1;i<n;++i)
            if(fabs(a[i][c])>eps)
                for(int j=n;j>=c;--j)a[i][j]-=a[r][j]*a[i][c];
        ++r;
    }
    //行数 < 列数(方程组中某几行方程系数为0)
    if(r<n){
        // 若存在 方程系数为0,但方程结果不为0
        for(int i=r;i<n;++i)
            //无解(0 = 非0 矛盾)
            if(fabs(a[i][n])>eps)return 2;
        //无穷解(0 = 0)
        return 1;
    }
    //唯一解
    for(int i=n-1;i>=0;--i)for(int j=i+1;j<n;++j)a[i][n]-=a[i][j]*a[j][n];
    return 0;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)for(int j=0;j<n+1;++j)scanf("%lf",&a[i][j]);
    int res = gauss(n);
    if(res == 0)for(int i=0;i<n;++i) fabs(a[i][n])<eps ? puts("0.00"):printf("%.2lf\n",a[i][n]);
    else res == 1 ? puts("Infinite group solutions"):puts("No solution");
    return 0;
}
