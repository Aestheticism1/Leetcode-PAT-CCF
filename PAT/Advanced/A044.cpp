#include <iostream>
#include <vector>
using namespace std;

// 前缀和 + lower_bound
int others(){
    int N,M,maxSum=INT_MAX;
    scanf("%d%d",&N,&M);
    int A[N+1]={0}; //表示给定的一组数中第1个数到第i个数的和,A[0]=0
    vector<pair<int,int>>v;//存储加和最小且要大于M的一串数字的首尾位置
    for(int i=1;i<N+1;++i){
        scanf("%d",&A[i]);
        A[i]+=A[i-1];
    }
    for(int i=0;i<N;++i){//枚举左端点i
        int j=lower_bound(A,A+N,A[i]+M)-A;//c++标准库自带的返回容器某区间中第一个大于等于value的位置的函数
        if(A[j]-A[i]==M){//A[j]-A[i]==M，说明由i到j这段数组符合要求
            printf("%d-%d\n",i+1,j);//输出此时的左端点i+1和右端点j
            maxSum=-1;//置maxSum为-1，表示已经找到了总和等于M的一组数字
        }
        else if(A[j]-A[i]>M&&A[j]-A[i]<maxSum){//如果A[j]-A[i]>M&&A[j]-A[i]<maxSum
            v.clear();//清空vector
            maxSum=A[j]-A[i];//更新maxSum
            v.push_back({i+1,j});//将当前这一串数字的首尾位置加入vector中
        }else if(A[j]-A[i]>M&&A[j]-A[i]==maxSum)//如果A[j]-A[i]>M&&A[j]-A[i]==maxSum
            v.push_back({i+1,j});//将当前这一串数字的首尾位置加入vector中
    }
    if(maxSum!=-1)//maxSum不为-1，表示没有找到总和等于M的一组数字，输出vector中的数字
        for(int i=0;i<v.size();++i)
            printf("%d-%d\n",v[i].first,v[i].second);
    return 0;
}

// mine
int main()
{
    int N, M;
    cin >> N >> M;
    int a[N];
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    
    int min = INT_MAX;
    vector<pair<int, int>> res;
    for(int i = 0; i < N; ++i){
        int sum = 0;
        int j = i;
        while(j < N && sum < M){
            sum += a[j];
            j++;
        }
        if(sum < M)
            break;
        if(sum < min){
            res.clear();
            res.push_back({i+1, j});
            min = sum;
        }else if(sum == min){
            res.push_back({i+1, j});
        }
    }
    for(int i = 0; i < res.size(); ++i){
        if(i != res.size()-1)
            cout << res[i].first << '-' << res[i].second << endl;
        else
            cout << res[i].first << '-' << res[i].second;
    }
    return 0;
}