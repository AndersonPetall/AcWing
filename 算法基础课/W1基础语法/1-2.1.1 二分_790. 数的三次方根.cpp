#include<iostream>
using namespace std;

double a;

int main(){
    double x;
    cin >> x;
    
    double l = 0; r = x;
    while(r - l > 10e-7){//保留5位小数
        double mid = (l + r)/2;
        if(x <= double*double) r = mid;
        else l = mid;
    }
    print("%lf\n", l);
    
    return 0;
}
