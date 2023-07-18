/*
    보자마자 BFS가 떠올랐음 . 그냥 그래프 탐색임 
    심지어 아래 오른쪽밖에 못가서 쉬웠음 그냥 기초 BFS 설명할것도 딱히 없는듯
    시간복잡도는 n이 3인순간 신경도 안씀 
*/

#include <iostream>
#include <queue>
using namespace std;
int arr[3][3];
bool visited[3][3];
int n;
bool check=false;
void bfs(){
    visited[0][0]=true;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==n-1 && y==n-1){
            check=true;
            break;
        }
        int nx=x+arr[x][y];
        if(!visited[nx][y] && nx<n){
            visited[nx][y]=true;
            q.push({nx,y});
        }
        int ny=y+arr[x][y];
        if(!visited[x][ny] && ny<n){
            visited[x][ny]=true;
            q.push({x,ny});
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    bfs();
    if(check){
        cout<<"HaruHaru";
    }else{
        cout<<"Hing";
    }
}