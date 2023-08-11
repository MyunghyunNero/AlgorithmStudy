#include <iostream>
#include <vector>
using namespace std;
int n;
bool arr[500001];
vector<int> v[500001];
int ans;
void dfs(int start,int cnt){

    bool check=false;
    for(int i=0;i<v[start].size();i++){
        if(!arr[v[start][i]]){
            check=true;
            arr[v[start][i]]=true;
            dfs(v[start][i],cnt+1);
            arr[v[start][i]]=false;
        }
    }
    if(!check){
        ans+=cnt;
    }
}
int main(){
    cin>>n;
    arr[1]=true;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    if(ans%2==0){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
}