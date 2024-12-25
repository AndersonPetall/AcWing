#include<iostream>
using namespace std;
int const N = 1e6+10;
int n,m,q[N];
int sl(int q[], int l, int r, int x){
    while(l<r){//左边<=， 右边>
        int mid=l+r>>1;
        q[mid]>=x? r=mid : l=mid+1;
    }
    return q[l]==x? l:-1;
}
int sr(int q[], int l, int r, int x){
    while(l<r){//左边<， 右边>=
        int mid=l+r+1>>1;
        x>=q[mid]? l=mid:r=mid-1;
    }
    return q[r]==x? r:-1;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;++i)scanf("%d", &q[i]);
    while(m--){
        int x;scanf("%d", &x);
        printf("%d %d\n", sl(q,0,n-1,x),sr(q,0,n-1,x));
    }
    return 0;
}




#include<iostream>
using namespace std;
int const N = 1e6+10;
int n,m,q[N];
int sl(int q[], int l, int r, int x){
    while(l+1<r){//左边<， 右边>=
        int mid=l+r>>1; q[mid] >= x ? r=mid: l=mid;
    }
    return q[r]==x? r:-1;
}
int sr(int q[], int l, int r, int x){
    while(l+1<r){//左边<=， 右边>
        int mid=l+r>>1; q[mid] <= x ? l=mid : r=mid;
    }
    return q[l]==x? l:-1;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;++i)scanf("%d", &q[i]);
    while(m--){
        int x;scanf("%d", &x);
        printf("%d %d\n", sl(q,-1,n-1,x),sr(q,0,n,x));
    }
    return 0;
}


//思路
//https://www.bilibili.com/video/BV1d54y1q7k7/?spm_id_from=333.1391.0.0
#include<iostream>
using namespace std;
int const N = 1e6+10;
int n,m,k,q[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);
    while(m--){
        scanf("%d",&k);
        int l=-1,r=n;
        while(l+1<r){
            int mid=l+r>>1;
            q[mid]<k?l=mid:r=mid;
        }
        if(q[r]!=k)printf("%d %d\n", -1,-1);
        else{
            printf("%d ",r);
            int l=-1,r=n;
            while(l+1<r){
                int mid=l+r>>1;
                q[mid]<=k?l=mid:r=mid;
            }
            printf("%d\n",l);
        }
    }
    return 0;
}
