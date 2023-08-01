#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
string arr[251];
bool visited[251][251];
int r,c;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int sheep,wolf;
void bfs(int startx,int starty){
    queue<pair<int,int>> q;
    int sp=0;
    int wf=0;
    q.push({startx,starty});
    visited[startx][starty]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(arr[x][y]=='o'){
            sp++;
        }else if(arr[x][y]=='v'){
            wf++;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if( arr[nx][ny] == '#') continue;
            if(!visited[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    if(sp>wf){
        wolf-=wf;
    }else{
        sheep-=sp;
    }
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string s;
        cin>>s;
        arr[i]=s;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]=='v'){
                wolf++;
            }
            if(arr[i][j]=='c'){
                sheep++;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!visited[i][j] && arr[i][j]!='#'){
                bfs(i,j);
            }
        }
    }
    cout<<sheep<<' '<<wolf;

}