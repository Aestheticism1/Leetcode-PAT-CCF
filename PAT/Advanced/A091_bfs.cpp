#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int x, y, z;
    Node(int xx, int yy, int zz): x(xx), y(yy), z(zz){}
};
int M, N, L, T;
int res = 0;
int direct[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
bool graph[1300][130][80];
int BFS(Node p){
    queue<Node> q;
    q.push(p);
    graph[p.x][p.y][p.z] = false;
    int cnt = 0;
    while(!q.empty()){
        p = q.front();
        q.pop();
        cnt++;
        int tx, ty, tz;
        for(int i = 0; i < 6; ++i){
            tx = p.x + direct[i][0];
            ty = p.y + direct[i][1];
            tz = p.z + direct[i][2];
            if(tx >= 0 && tx < M && ty >= 0 && ty < N && tz >= 0 && tz < L && graph[tx][ty][tz]){
                graph[tx][ty][tz] = false;
                q.push(Node(tx, ty, tz));
            }
        }
    }
    return cnt;
}
int main()
{
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for(int k = 0; k < L; ++k)
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                scanf("%d", &graph[i][j][k]);

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < L; ++k){
                if(graph[i][j][k]){
                    int tmp = BFS(Node(i, j, k));
                    if(tmp >= T)
                        res += tmp;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}