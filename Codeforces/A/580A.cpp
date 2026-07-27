#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin >> word;
    int upperCnt = 0;
    int lowerCnt = 0;
    for(char ch : word){
        if(isupper(ch))
            upperCnt++;
        else
            lowerCnt++;
    }
    if(upperCnt > lowerCnt)
        transform(word.begin() , word.end() , word.begin() , ::toupper);
    else if(lowerCnt > upperCnt)
        transform(word.begin() , word.end() , word.begin() , ::tolower);
    else
        transform(word.begin() , word.end() , word.begin() , ::tolower);
    

    cout << word << "\n";
}