#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> words;
    for(int i = 0 ; i < n ; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }
    vector<vector<int>> graph(26);
    vector<int> indegree(26 , 0);
    bool impossible = false;
    for(int i = 0 ; i < n - 1 ; i++){
        string &word1 = words[i];
        string &word2 = words[i + 1];

        int j = 0;
        while(j < word1.size() && j < word2.size() && word1[j] == word2[j])
            j++;
        if(j == word2.size() && word1.size() > word2.size()){
            impossible = true;
            break;
        }
        if(j < word1.size() && j < word2.size()){
            int a = word1[j] - 'a' , b = word2[j] - 'a';
            graph[a].push_back(b);
            indegree[b]++;
        }
    }
    if(impossible){
        cout << "Impossible\n";
        return 0;
    }

    queue<int> q;
    
    for(int i = 0 ; i < 26 ; i++)
        if(indegree[i] == 0)
            q.push(i);

    string answer;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        answer += char('a' + node);
        for(int next : graph[node]){
            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }
    if(answer.size() != 26){
        cout << "Impossible" << "\n";
        return 0;
    }
    cout << answer << "\n";
    return 0;
}