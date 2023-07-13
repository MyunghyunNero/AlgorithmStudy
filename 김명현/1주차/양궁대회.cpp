/*
    이 문제를 읽고난후 시간복잡도 신경쓸 필요 없고 그리디 쪽으로 풀 수 있는지 생각을 해봤다.
    그리디로는 답이 없다고 느꼈고  브루트포스로 접근할 생각을 했다.
    그러기 위해 DFS를 구현해야했고 라이언이 몇발을 쐈는지 저장하는 값을 재귀돌때마다 넘겨야했다.
    그걸 배열로 할지 String으로 할지 고민을 했는데 배열보다는 String이 편할 거 같아서 String 선택
    그러다가 자꾸 틀렸는데 
    알고 보니 가장 큰 점수 차이를 구하는 거..
    나는 라이언이 가장 큰 점수 내는 것을 구하고 있엇다...
    문제를 잘 읽자
*/



#include <string>
#include <vector>
#include <iostream>

using namespace std;
string anstring=""; // 과녁별 화살 수를 저장하는 String 배열 
vector<int> in;  // 어피치가 쏜 화살을 전역함수로 빼줌 -> dfs함수에 바로 적용할 수 있게 
int ans=0;
int apeach=0;
void dfs(int idx,int cnt,int score,int apechscore,string s){ //idx 몇번째 과녁인지 , cnt는 남은 화살 갯수 , Score 라이언 점수, apechscore 어피치 점수 , s는 라이언이 쏜 과녁별 화살 갯수
    if(idx>10){  //과녁 체크 다했으면
        if(apechscore<score && ans<score-apechscore){     // 이 부분도 나중에 알았는데 라이언은 남은 화살을 마지막에 털어 넣는 느낌이였다. 그래서 추가
            if(cnt>0){
                s[10]=(char)(s[10]+cnt);   //남은 화살 마지막에 넣기  여기서-> 화살 갯수가 10을 넘어가면 String을 못쓰네? 생각했다가 화살 갯수 범위가 10이라 다행..
            }
            ans=score-apechscore;  // 점수차 최대이면 갱신
            anstring=s;   // 화살 수 도 갱신
        }else if(!anstring.empty() && ans==score-apechscore &&apechscore<score ){ //점수차가 같고 가장 낮은 점수 여러개 맞춘게 정답이 되야함
            for(int i=10;i>=0;i--){
                if(anstring[i]<s[i]){   //가장 낮은 점수가 많이 맞췃으면
                    if(cnt>0){
                        s[10]=(char)(s[10]+cnt);
                    }
                    anstring=s;  //갱신하고 탈출
                    break;
                }else if(anstring[i]==s[i]){
                    continue;
                }else{
                    break;
                }
            }
        }
        return;
    }
    if(cnt>in[idx] && in[idx]!=0){      //남은 갯수가 어피치가 쏜 갯수보다 크고 어피치가 쏜갯수가 0이 아니면 -> 어피치가 졌기에 어피치 점수 갱신
        dfs(idx+1,cnt-(in[idx]+1),score+(10-idx),apechscore-(10-idx),s+to_string(in[idx]+1));
    }else if(cnt>in[idx] && in[idx]==0){      // 남은 갯수가 어피치가 쏜 갯수 보다 크고 어피치가 안쐇으면 -> 어피치 점수 갱신 필요 없음
        dfs(idx+1,cnt-(in[idx]+1),score+(10-idx),apechscore,s+to_string(in[idx]+1));
    }
    // 그냥 0발 쏘고 넘어감 
    dfs(idx+1,cnt,score,apechscore,s+to_string(0));
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    for(int i=0;i<info.size();i++){
        in.push_back(info[i]);
        if(info[i]>0){
            apeach+=(10-i);       // 어피치 점수 더하기
        }
    }
    dfs(0,n,0,apeach,"");
    for(int i=0;i<anstring.size();i++){
        answer.push_back(anstring[i]-'0');
    }
    if(ans==0){
        answer.push_back(-1);
    }
    return answer;
}
