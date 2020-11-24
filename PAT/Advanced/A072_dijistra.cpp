#include <iostream>
#include <vector>
using namespace std;

const int L = 1e3+15;

struct Node{
    int end, dis;
    Node(int e, int d): end(e), dis(d){}
};
vector<vector<Node> > graph(L);
int dist[L];
bool mark[L];

int N, M, K, D;
int minIndex=-1;
double minDis=-1, minAvg=INT_MAX*1.0;

int getIndex(string s){
    if(s[0]=='G')
        return stoi(s.substr(1))+N;
    else
        return stoi(s);
}

bool dijistra(){
    for(int i = 1; i <= N+M; i++){
        int u = -1, min = INT_MAX;
        for(int j = 1; j <= N+M; j++){
            if(!mark[j] && dist[j] < min){
                u = j;
                min = dist[j];
            }
        }
        if(u == -1)
            return false;
        if(u <= N && min > D)
            return false;
        mark[u] = true;
        for(auto v: graph[u]){
            if(!mark[v.end] && dist[v.end] > dist[u] + v.dis){
                dist[v.end] = dist[u] + v.dis;
            }
        }
    }
    return true;
}

int main(){
    cin >> N >> M >> K >> D;

    while(K--){
        string a, b;
        int c;
        cin >> a >> b >> c;
        int m = getIndex(a);
        int n = getIndex(b);
        graph[m].push_back(Node(n, c));
        graph[n].push_back(Node(m, c));
    }

    for(int i = 1; i <= M; i++){
        fill(dist, dist+N+M+1, INT_MAX);
        fill(mark, mark+N+M+1, false);
        int g = i+N;
        dist[g] = 0;
        if(dijistra()){
            double avg = 0.0;
            double min = INT_MAX*1.0;
            for(int j = 1; j <= N; j++){
                avg += dist[j]*1.0;
                if(dist[j] < min)
                    min = dist[j]*1.0;
            }
            avg /= N;
            if(min > minDis || (min == minDis && avg < minAvg)){
                minAvg = avg;
                minDis = min;
                minIndex = i;
            }
        }
    }

    if(minIndex == -1)
        printf("No Solution");
    else{
        printf("G%d\n", minIndex);
        printf("%.1lf %.1lf", minDis, minAvg);
    }
    return 0;
}