#include <iostream>

using namespace std;

const int L = 1e5+5;

struct User{
    int id=0, scores[6]={-2,-2,-2,-2,-2,-2}, perfect=0, rank=1, total_score=0;
    bool flag = false;
};

User users[L];

bool cmp(User& a, User& b){
    if(a.total_score != b.total_score)
        return a.total_score > b.total_score;
    else if(a.perfect != b.perfect)
        return a.perfect > b.perfect;
    else
        return a.id < b.id;
}

int main()
{
    int N, K, M;
    int full_score[6];
    cin >> N >> K >> M;
    for(int i = 1; i <= K; ++i)
        cin >> full_score[i];
    
    for(int i = 0; i < M; ++i){
        int id, pid, score;
        cin >> id >> pid >> score;
        users[id].id = id;
        if(score > -1)
            users[id].flag = true;
        else if(score == -1)
            score = 0;
        
        users[id].scores[pid] = max(users[id].scores[pid], score);
    }

    for(int i = 1; i <= N; ++i){
        if(users[i].flag){
            for(int j = 1; j <= K; ++j){
                if(users[i].scores[j] == full_score[j])
                    users[i].perfect++;
                users[i].total_score += users[i].scores[j] < 0 ? 0 : users[i].scores[j];
            }
        }
    }
    sort(users+1, users+N+1, cmp);
    for(int i = 2; i <= N; ++i){
        users[i].rank = users[i].total_score == users[i-1].total_score ? users[i-1].rank : i;
    }
    for(int i = 1; i <= N; ++i){
        if(users[i].flag){
            printf("%d %05d %d", users[i].rank, users[i].id, users[i].total_score);
            for(int j = 1; j <= K; ++j)
                if(users[i].scores[j] != -2)
                    printf(" %d", users[i].scores[j]);
                else
                    printf(" -");
            printf("\n");
        }
    }
    return 0;
}