#include<bits/stdc++.h>
using namespace std;

int fibb(int n){
    if(n <= 1) return n;

    int last = fibb(n-1);
    int slast = fibb(n-2);

    return last + slast;
}

int main(){
    int n = 5;
    int ans = fibb(n);

    cout<<ans<<endl;

    return 0;
}