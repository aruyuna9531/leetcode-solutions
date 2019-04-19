/*
146.LRU缓存机制[Hard]（探索字节跳动——数据结构（2））

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

思路：

开辟缓存<key, value>，并设定缓存最大容量。
get操作，从缓存中查key，查到了返回value，同时把缓存中该条记录移到最后面。查不到返回-1，缓存不变。时间复杂度O(n)
put操作，先查key，查到了删除原数对，之后在缓存最后添加该数对，结束。查不到则将数对插入后面，检查是否溢出，如果溢出则删掉缓存中第一条数据。时间复杂度O(n)

*/

class LRUCache {
    vector<pair<int, int> > cache;
    const int maxSize;
public:
    LRUCache(int capacity): maxSize(capacity) {
        
    }
    
    int get(int key) {
        if(cache.size()==0)return -1;
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                int tkey = cache[i].first;
                int tval = cache[i].second;
                cache.erase(cache.begin()+i);
                pair<int, int> tmp(tkey, tval);
                cache.push_back(tmp);
                return tval;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                cache.erase(cache.begin()+i);
                pair<int, int> tmp(key, value);
                cache.push_back(tmp);
                return;
            }
        }
        //缓存中没找到key记录
        pair<int, int> tmp(key, value);
        cache.push_back(tmp);
        if(cache.size()>maxSize)cache.erase(cache.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
