#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string ans="";
    int x=0;
    while (n>0)
    {
        if(x==25)
        break;
        if(n&1){
          ans+=('a'+x);
        }
        n/=2;
        x++;
    }
    cout<<ans<<endl;
}