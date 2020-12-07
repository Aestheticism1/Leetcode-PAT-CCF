#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> postorder;
void traversal(vector<int>& in, vector<int>& pre, int root, int left, int right){
    if(left > right)
        return;
    int i = find(in.begin(), in.end(), pre[root]) - in.begin();
    traversal(in, pre, root+1, left, i-1);
    traversal(in, pre, root+1+i-left, i+1, right);
    postorder.push_back(pre[root]);
}
int main()
{
    int N;
    cin >> N;
    stack<int> s;
    vector<int> in, pre;
    for(int i = 0; i < N*2; ++i){
        string opt;
        int a;
        cin >> opt;
        if(opt == "Push"){
            cin >> a;
            s.push(a);
            pre.push_back(a);
        }else{
            in.push_back(s.top());
            s.pop();
        }
    }
    traversal(in, pre, 0, 0, N-1);
    for(int i = 0; i < postorder.size(); ++i){
        if(i != 0)
            cout << " ";
        cout << postorder[i];
    }
    return 0;
}