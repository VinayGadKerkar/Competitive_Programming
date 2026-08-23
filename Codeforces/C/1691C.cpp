#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long n,k; scanf("%lld %lld",&n,&k);
        char buf[100005]; scanf("%s",buf);
        string s(buf);
        long long S=0, L=-1, R=-1;
        for(int i=0;i<n;i++)
         if(s[i]=='1'){ 
            if(L<0) L=i; R=i; S++;
         }
        if(S==0){ 
            printf("0\n"); continue;
        }
        long long costEnd = n-1-R;
        long long costStart = L;
        long long bonus = 0;
        if(k>=costEnd) bonus=max(bonus,10LL);
        if(k>=costStart) bonus=max(bonus,1LL);
        if(S>=2 && k>=costStart+costEnd) bonus=max(bonus,11LL);
        printf("%lld\n", 11*S - bonus);
    }
}