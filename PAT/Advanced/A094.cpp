#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int depth=1;    
    vector<int> children;
};
int main() 
{
    int N, M;
    cin >> N >> M;
    Node n[105];
    for(int i = 0; i < M; ++i){
        int id, num;
        cin >> id >> num;
        int tmp;
        while(num--){
            cin >> tmp;
            n[id].children.push_back(tmp);
        }
    }
    int res[105];
    fill(res, res + 105, 0);
    queue<Node> q;
    q.push(n[1]);
    while(!q.empty()){
        Node a = q.front();
        q.pop();
        res[a.depth]++;
        for(auto x: a.children){
            n[x].depth = a.depth + 1;
            q.push(n[x]);
        }
    }
    int largest_gen=1, level=1;
    for(int i = 0; i < 105; ++i){
        if(res[i] > largest_gen){
            largest_gen = res[i];
            level = i;
        }
    }
    cout << largest_gen << " " << level;
    return 0;
}