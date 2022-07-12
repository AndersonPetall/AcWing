//EDITION 1 





//EDITION 
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n, m, path[N][N], map[N][N];
int vectorX[4] = {-1,0,1,0}, vectorY[4] = {0,1,0,-1};
int bfs(){
    queue<PII> q; q.push({1,1});
    while(q.size()){
        auto point = q.front(); q.pop();
        map[point.first][point.second] = 1;
        for(int i = 0; i < 4; ++i){
            int x = point.first + vectorX[i], y = point.second + vectorY[i];
            if(map[x][y] == 0){
                map[x][y] = 1;
                path[x][y] = path[point.first][point.second] + 1;
                q.push({x,y});
            }
        }
    }
    return path[n][m];
}
int main(){
    memset(map, 1, sizeof map);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) scanf("%d", &map[i][j]);
    cout << bfs() << endl;
    return 0;
}
