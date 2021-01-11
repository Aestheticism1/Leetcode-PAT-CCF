// 大顶堆
class Solution {
public:
    void downAdjust(vector<int>& nums, int low, int high){
        int i = low, j = low*2+1;
        while(j <= high){
            if(j + 1 <= high && nums[j+1] > nums[j])
                j = j + 1;
            if(nums[j] > nums[i]){
                swap(nums[i], nums[j]);
                i = j;
                j = j*2+1;
            }else
                break;
        }
    }

    void buildMaxHeap(vector<int>& nums, int heapSize){
        for(int i = heapSize / 2; i >= 0; --i)
            downAdjust(nums, i, heapSize - 1);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();        
        buildMaxHeap(nums, heapSize);
        for(int i = heapSize - 1; i >= heapSize - k + 1; --i){
            swap(nums[0], nums[i]);
            downAdjust(nums, 0, i-1);
        }
        return nums[0];
    }
};

// 快排(更快)
class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int i = l - 1;
        for(int j = l; j < r; j++){
            if(nums[j] <= pivot){
                i += 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }

    int random_partition(vector<int>& nums, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    int find(vector<int>& nums, int l, int r, int index){
        int p = random_partition(nums, l, r);
        if(p == index)
            return nums[p];
        else
            return p < index ? find(nums, p+1, r, index) : find(nums, l, p-1, index);
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned)time(NULL));        
        int res = find(nums, 0, (int)nums.size() - 1, (int)nums.size() - k);
        return res;
    }
};

