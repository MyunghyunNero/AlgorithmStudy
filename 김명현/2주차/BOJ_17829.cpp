/*
    사실 이문제도 재귀의 기초 문제라 생각함
    재귀 귀초만 알면 매우 쉽게 풀수 있음 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[1025][1025];
int recur(int x,int y,int size){
    vector<int> v;
    if(size==2){
        v.push_back(arr[x][y]);
        v.push_back(arr[x+1][y]);
        v.push_back(arr[x][y+1]);
        v.push_back(arr[x+1][y+1]);
        sort(v.begin(),v.end());
        return v[1];
    }
    v.push_back(recur(x,y,size/2));
    v.push_back(recur(x+size/2,y,size/2));
    v.push_back(recur(x,y+size/2,size/2));
    v.push_back(recur(x+size/2,y+size/2,size/2));
    sort(v.begin(),v.end());
    return v[1];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<recur(0,0,n);
}