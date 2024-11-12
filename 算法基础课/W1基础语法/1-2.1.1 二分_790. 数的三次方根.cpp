#include<iostream>
using namespace std;
int main(){
    double x;scanf("%lf", &x);
    double l=-100, r=100;
    while(r-l>1e-8){
        double mid = (l+r)/2;  // double类型所以不能用 l+r>>1
        if(mid*mid*mid>=x)r=mid;else l=mid;  //    mid*mid*mid>=x  或者 mid*mid*mid>x都可以
    }
    printf("%.6lf\n", l);
    return 0;
}


//这里使用 1e10-8，是因为题目要求保留小数点后6位，如果使用1e10-7, 那么这个因为四舍五入第八位到第七位，已经产生误差，输出六位时候误差会积累。
//如果使用-8，那么四舍五入第九位到第八位，取前六位时候，第七位会被truncate掉，但是第七位是准确值。
