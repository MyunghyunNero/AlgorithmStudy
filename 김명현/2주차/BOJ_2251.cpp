/*
    일단 중복을 생각했음
    첫번째로 set을 생각해서 set위주로만 생각한거 같음
    처음에는 a가 0 이고 c일때 set에 넣고 값이 이미 있으면 탈출하는 식으로 했는데 런타임 에러가 나옴 .. 이유는 찾아보는중..
    아마 생각하기에는 똑같은 값이 반복문이 돌아가는듯 a=3,b=2,c=3인 값이 이미 계산이 되었음에도 불구하고 계속 찾아감
    확실히 방문체크할때는 정확하게 해야하는듯 
    두 번째로 생각한 중복 문제는 그냥 a,b,c 값을 다 저장해서 중복을 제거함
    다른 사람들은 배열로 풀었던데 나는 생각의 흐름이 set으로 풀고 있어서 그런지 string으로 중복 제거했네요 ㅋㅋ
    그리고 dfs로 풀었더니 풀렸네요
*/
#include <iostream>
#include <set>
using namespace std;
set<int> st;
set<string> mul;
int v[3];
void dfs(int a,int b,int c){
    string str=to_string(a)+to_string(b)+to_string(c);
    if(mul.find(str)==mul.end()){
        mul.insert(str);
    }else{
        return ;
    }
    if(a==0){
        if(st.find(c)==st.end()){
            st.insert(c);
        }else{
            return;
        }
    }
    if(a!=0){      //a가 다른 통에 줄때 
        if(a+b<=v[1]){
            dfs(0,a+b,c);
        }else{
            dfs(a-(v[1]-b),v[1],c);
        }
        if(a+c<=v[2]){
            dfs(0,b,a+c);
        }else{
            dfs(a-(v[2]-c),b,v[2]);
        }
    }
    if(b!=0){   //b가 다른 통에 줄때 
        if(b+a<=v[0]){
            dfs(a+b,0,c);
        }else{
            dfs(v[0],b-(v[0]-a),c);
        }
        if(b+c<=v[2]){
            dfs(a,0,b+c);
        }else{
            dfs(a-(v[2]-c),b,v[2]);
        }
    }
    if(c!=0){   //c가 다른 통에 줄때
        if(c+a<=v[0]){
            dfs(c+a,b,0);
        }else{
            dfs(v[0],b,c-(v[0]-a));
        }
        if(b+c<=v[1]){
            dfs(a,c+b,0);
        }else{
            dfs(a,v[1],c-(v[1]-b));
        }
    }
}
int main(){
    for(int i=0;i<3;i++){
        cin>>v[i];
    }
    dfs(0,0,v[2]);
    for(auto iter=st.begin();iter!=st.end();iter++){
        cout<<*iter<<" ";
    }
}