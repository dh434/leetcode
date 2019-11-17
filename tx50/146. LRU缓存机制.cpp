/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3

*/

//为了插入O（1）, 使用双向队列
//为了查找O(1)， 使用map



class LRUCache {
private:
    class node{
        public:
        int key;
        int val;
        node* pre;
        node* next;

        node(){}
        node(int key, int value){
            this->key = key;
            this->val = value;
        }
    };
    int size = 0;
    int capacity = 0;
    node* dummyHead = new node();
    node* dummyTail = new node();
    unordered_map<int,node*> search_map;

    void add(node* target){
        node* temp = dummyHead->next;
        
        dummyHead->next = target;
        target->pre = dummyHead;
        
        target->next = temp;
        temp->pre = target;
    }
    
    void del(node* target){
        node* preNode = target->pre;
        node* nextNode = target->next;
        
        preNode->next = nextNode;
        nextNode->pre = preNode;
        
        target->pre = NULL;
        target->next = NULL;
    }
    
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dummyHead->next = dummyTail;
        dummyHead->pre = NULL;
        dummyTail->next = NULL;
        dummyTail->pre = dummyHead;
    }
    
    int get(int key) {
         if(search_map.count(key) != 0){
             node* target = search_map[key];
             del(target);
             add(target);
             return target->val;
         }  
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(search_map.count(key) != 0){
            node* target = search_map[key];
            target->val = value;
            del(target);
            add(target);
        }else{ 
            if(size < capacity){
                size++;    
            }else{
                node* tmp = dummyTail->pre;
                del(tmp);
                search_map.erase(tmp->key);
            }
            node* target = new node(key, value);
            search_map[key] = target;
            add(target);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */