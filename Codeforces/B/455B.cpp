#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* children[26];
    bool win , lose;

    Node() {
        memset(children, 0, sizeof(children));
        win = false;
        lose = false;
    }   

    void put(char ch , Node* node){
        children[ch - 'a'] = node;
    }

    Node* get(char ch){
        return children[ch - 'a'];
    }

    bool contains(char ch){
        return children[ch - 'a'] != NULL;
    }
};

void insert(Node* root , string word){
    for(char &ch : word){
        if(!root -> contains(ch)){
            root -> put(ch , new Node());
        }
        root = root -> get(ch);
    }
}
void dfs(Node* node) {
    bool hasChild = false;

    for(int i = 0; i < 26; i++) {
        if(node->children[i]) {
            hasChild = true;

            dfs(node->children[i]);

            node->win |= !node->children[i]->win;
            node->lose |= !node->children[i]->lose;
        }
    }

    if(!hasChild) {
        node->win = false;
        node->lose = true;
    }
}

int main() {
    int n , k;
    cin >> n >> k;
    vector<string> strs;
    for(int i = 0; i < n ; i++){
        string s;
        cin >> s;
        strs.push_back(s);
    }
    Node* root = new Node();
    for(string &s : strs){
        insert(root , s);
    }
    dfs(root);

    if(!root->win){
        cout << "Second" << "\n";
    }else if(root -> lose){
        cout << "First" << "\n";
    }else if(k % 2 == 1){
        cout << "First" << "\n";
    }else
        cout << "Second" << "\n";

    return 0;
   

}