#include <iostream>

using namespace std;

int main()
{
    int M;
    cin >> M;
    string id, sign_in, sign_out;
    cin >> id >> sign_in >> sign_out;
    string unlock_id = id;
    string lock_id = id;
    string unlock = sign_in;
    string lock = sign_out;
    M--;
    while(M--){
        cin >> id >> sign_in >> sign_out;
        if(sign_in < unlock){
            unlock = sign_in;
            unlock_id = id;
        }
        if(sign_out > lock){
            lock = sign_out;
            lock_id = id;
        }
    }
    cout << unlock_id << " " << lock_id;
    return 0;
}