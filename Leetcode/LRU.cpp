#include<bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    Node* prev , *next;
    Node(){
        prev = nullptr;
        next = nullptr;
    }
};

class LRU {
    private:
        unordered_map<int , Node*> keys;
        Node* head;
        int len;
        int curLen = 0;
    public:
        LRU(int length) {
            len = length;
            head = new Node();
        }

        int get(int key){
            if(!keys.count(key)) return -1;
            Node* node = keys[key];
            node -> next = head -> next;
            head -> next = node;
            node -> next -> prev = node;
            head -> next -> prev = head;
            return node -> value;
        }

        void set(int key , int value){
            
        }
};