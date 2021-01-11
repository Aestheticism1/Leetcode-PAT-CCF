// 大顶堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};

// 快排(更快)
class Solution {
public:
    int partition(vector<int>& arr, int l, int r){
        int pivot = arr[r];
        int i = l - 1;
        for(int j = l; j < r; j++){
            if(arr[j] <= pivot){
                i = i + 1;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[r]);
        return i+1;
    }

    int random_partition(vector<int>& arr, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(arr[i], arr[r]);
        return partition(arr, l, r);
    }

    void randomized_selected(vector<int>& arr, int l, int r, int k){
        if(l >= r)
            return;
        int p = random_partition(arr, l, r);
        int num = p - l + 1;
        if(num == k)
            return;
        else if(num < k)
            randomized_selected(arr, p+1, r, k-num);
        else
            randomized_selected(arr, l, p-1, k);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, (int)arr.size()-1, k);
        vector<int> res(arr.begin(), arr.begin()+k);
        return res;
    }
};