#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,w,l;
vector<int> v;
queue<int> q;
int arr[1001];
int ans;
int main(){
    cin>>n>>w>>l;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int idx=0;
    int sum=0;
    int cnt=0;
    int start=0;
    while(idx<n){
        for(int i=start;i<idx;i++){
            arr[i]++;
            if(arr[i]>w){
                sum-=v[i];
                cnt--;
                start++;
            }
        }
        if(sum+v[idx]<=l && cnt<w){
            sum+=v[idx];
            arr[idx]=1;
            idx++;
            cnt++;
            
        }
        ans++;
    }
    cout<<ans+w;
    
}