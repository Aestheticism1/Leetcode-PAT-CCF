#include <unordered_map>
struct DListNode{
    int key, val;
    DListNode *pre;
    DListNode *next;
    DListNode(int k, int v): key(k), val(v), pre(nullptr), next(nullptr){}
};
class Solution {
private:
    int size;
    DListNode *head;
    DListNode *tail;
    unordered_map<int, DListNode*> mp;
    
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        this->size = k;
        this->head = new DListNode(0, 0);
        this->tail = new DListNode(0, 0);
        this->head->next = tail;
        this->tail->pre = head;
        if(this->size < 1 || operators.size() == 0)
            return {};
        vector<int> res;
        
        for(vector<int> op: operators){
            if(op[0] == 1){
                set(op[1], op[2]);
            }else{
                int v = get(op[1]);
                res.push_back(v);
            }
        }
        return res;
    }
    
    void set(int key, int val){
        if(mp.find(key) != mp.end()){
            mp[key]->val = val;
            moveToFirst(mp[key]);
        }else{
            DListNode* node = new DListNode(key, val);
            mp[key] = node;
            if(this->size <= 0)
                removeLast();
            else
                this->size--;
            insertFirst(node);
        }
    }
    
    int get(int key){
        int val = -1;
        if(mp.find(key) != mp.end()){
            val = mp[key]->val;
            moveToFirst(mp[key]);
        }
        return val;   
    }
    
    void moveToFirst(DListNode *node){
        if(node->pre == this->head) return;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        insertFirst(node);
    }
    
    void insertFirst(DListNode *node){
        node->next = this->head->next;
        this->head->next->pre = node;
        this->head->next = node;
        node->pre = this->head;
    }
    
    void removeLast(){
        mp.erase(this->tail->pre->key);
        this->tail->pre->pre->next = this->tail;
        this->tail->pre = this->tail->pre->pre;
    }
};