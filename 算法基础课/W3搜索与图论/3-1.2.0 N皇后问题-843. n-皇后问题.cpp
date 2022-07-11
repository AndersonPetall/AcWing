//EDITION 1   Time Complexity = O(n!)
#include<iostream>
using namespace std;
const int N = 1e1;
char q[N][N];
bool diagonal[N*2], back_diagonal[N*2], column[N];
int n;
void dfs(int row){
    if(row == n){
        for(int i = 0; i < n; ++i)puts(q[i]);
        puts("");
        return ;
    }
    for(int i = 0; i < n; ++i){
        if(!(column[i]||diagonal[i+row]||back_diagonal[n-i+row])){
            q[row][i] = 'Q';
            column[i] = diagonal[i+row]=back_diagonal[n-i+row] = 1;
            dfs(row+1);
            column[i] = diagonal[i+row]=back_diagonal[n-i+row] = 0;
            q[row][i] = '.';
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) q[i][j] = '.';
    dfs(0);
    return 0;
}



//EDITION 1   Time Complexity = O(2^(n^2))
#include<iostream>
using namespace std;
const int N = 1e1;
char q[N][N];
bool diagonal[N*2], back_diagonal[N*2], Column[N], Row[N];
int n;
void dfs(int row, int col, int nQ){
    if(col == n) col = 0, ++row;
    if(row == n){
        if(nQ == n){
            for(int i = 0; i < n; ++i) puts(q[i]);
            puts("");
        }
        return;
    }
    q[row][col] = '.';
    dfs(row, col + 1, nQ);
    if(!(Row[row]||Column[col]||diagonal[row+col]||back_diagonal[n-col+row])){
        q[row][col] = 'Q';
        Row[row] = Column[col] = diagonal[row+col] = back_diagonal[n-col+row] = 1;
        dfs(row,col+1,nQ+1);
         Row[row] = Column[col] = diagonal[row+col] = back_diagonal[n-col+row] = 0;
        q[row][col] = '.';
    }
}
int main(){
    scanf("%d", &n);
    dfs(0, 0, 0);
    return 0;
}
