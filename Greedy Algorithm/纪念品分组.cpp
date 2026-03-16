#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,n,res_1,res_2=0,j=0;
    cin>>w>>n;
    vector<int> a(n),b;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        if(j==(n-i-1)||j==(n-i-2))
        {
            if(j==(n-2-i)&&(a[j]+a[n-i-1])>w)
            {
                res_2+=2;
                break;
            }
            else
            {
                res_2+=1;
                break;
            }
        }
        res_1=0;
        res_1+=(a[j]+a[n-i-1]);
        if(res_1>w)
        {
            res_2+=1;
        }
        else
        {
            res_2+=1;
            j++;
        }
    }
    cout<<res_2;
}

