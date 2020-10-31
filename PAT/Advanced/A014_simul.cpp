#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int NMAX = 20;

struct Customer{
    int id, process, end;
    Customer(int id, int p, int e=0): id(id), process(p), end(e){}
};

int N, M, K, Q;
vector<queue<Customer> > c(NMAX + 2);
int window_cur[NMAX + 2] = {0};
queue<Customer> waiting;
map<int, int> res;

string format(int num){
    int hour = num / 60 + 8;
    int min = num % 60;
    string s = "";
    if(hour < 10)
        s += "0" + to_string(hour) + ":";
    else
        s += to_string(hour) + ":";

    if(min < 10)
        s += "0" + to_string(min);
    else
        s += to_string(min);
    
    return s;
}

int main()
{
    cin >> N >> M >> K >> Q;
    
    int tempk = K;
    int p;
    int count = 1;
    for(int j = 1; j <= M; ++j){
        for(int i = 1; i <= N; ++i){
            if(count > K)
                break;
            cin >> p;
            c[i].push(Customer(count++, p));
        }
        if(count > K)
            break;
    }

    if(K > N*M){
        K -= N*M;
        while(K--){
            cin >> p;
            waiting.push(Customer(count++, p));
        }
    }

    // for(int i = 1; i <= N; i++)
    //     for(auto x: c[i])
    //         cout << x.id << " " << x.process << endl;

    while(tempk--){
        int min = INT_MAX;
        int u = -1;
        for(int i = 1; i <= N; i++){
            if(!c[i].empty()){
                Customer top = c[i].front();
                if(window_cur[i] + top.process < min){
                    min = window_cur[i] + top.process;
                    u = i;
                }
            }
        }

        if(u != -1){
            Customer finish = c[u].front();
            c[u].pop();
            if(window_cur[u] < 540){
                res[finish.id] = window_cur[u] + finish.process;
            }else{
                res[finish.id] = -1;
            }
            window_cur[u] += finish.process;
            if(!waiting.empty()){
                c[u].push(waiting.front());
                waiting.pop();
            }
        }   
    }

    while(Q--){
        int ID;
        cin >> ID;
        if(res[ID] == -1)
            cout << "Sorry" << endl;
        else
            cout << format(res[ID]) << endl;
    }

    return 0;
}