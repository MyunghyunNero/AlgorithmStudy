/*
    후.. 이 문제를 보고 처음 든생각은 상당히 귀찮은 처리 들이 많다는 점이다.
    String 안에 너무 많은 데이터가 들어있음 , 시간을 정수형 변환이 필요 등등
    그래도 구현을 제외하고 시간복잡도 생각은 딱히 안해도 되는 범위이다.
    생각
    1. 시간 별로 record 값이 주어져서 정렬할 필요는 없음 (그래도 편하게 해주네요 ㅎㅎ)
    2. 시간 정수 변환 매우 귀찮지만 해야죠..
    3. map으로 시간 값들 저장 -> 어차피 시간별로 들어오고 IN,OUT 순서대로 들어오기에 신경안써도 됨 (이런건 편하게 주어지네요)
    4. map이 알아서 정렬 된 구조이기에 차량번호 신경안써도 됨
    5. 시간 구현만 하면 되는 문제
*/



#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std; 
map<string,vector<string>> m;    // 차량번호 들어오는 값들 저장
/*
    시간 분 -> 총합 분으로 변환 시킴
*/
int counttime(string a,string b){
    int bidx=b.find(':');
    int bhour=stoi(b.substr(0,bidx));
    int bmin=stoi(b.substr(bidx+1));
    int aidx=a.find(':');
    int ahour=stoi(a.substr(0,aidx));
    int amin=stoi(a.substr(aidx+1));
    int ans=0;
    if(bmin<amin){                               //빼야하는 분이 더 크면 시간에서 1뺴줌
        ans=(bhour-1-ahour)*60+(60+bmin-amin);
    }else{
        ans=(bhour-ahour)*60+(bmin-amin);     //빼야하는 분이 더 작으면 정상 진행
    }
    return ans;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    /*
        신고결과 받기에서 했던 거처럼 String을 구분지어서 분류함 IN,OUT은 순서대로 주어지기에 신경안씀 
    */
    for(string s:records){
        vector<string> str;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                str.push_back(tmp);
                tmp="";
            }else{
                tmp+=s[i];
            }
        }
        str.push_back(tmp);
        m[str[1]].push_back(str[0]);  //차량번호에 들어오고 나가는 시간들 쭉 젖장
    }

    /*
        차량 번호 순서대로 요금 정산
    */
    for(auto it=m.begin();it!=m.end();it++){
        vector<string> tmp=it->second;
        int cnt=0;
        int ans=fees[1]; 
        if(tmp.size()%2==0){                     //들어오고 나가는게 다 찍혀있으면 그냥 계싼
            for(int i=1;i<tmp.size();i+=2){
                cnt+=counttime(tmp[i-1],tmp[i]);
            }
        }else{
            for(int i=1;i<tmp.size()-1;i+=2){        //마지막에 들어오고 나가는게 없으면 23:59을 나가는걸로 계산 
                cnt+=counttime(tmp[i-1],tmp[i]);
            }
            cnt+=counttime(tmp[tmp.size()-1],"23:59");
        }

        // 기본요금 넘어가면 추가 정산 
        if(cnt>fees[0]){
            if((cnt-fees[0])%fees[2]==0){               // 요금 정확하게 떨어지는지 
                ans+=((cnt-fees[0])/fees[2])*fees[3];
            }else{                                        //올림을 해야하는지 구분 
                ans+=((cnt-fees[0])/fees[2]+1)*fees[3];
            }
        }
        answer.push_back(ans);
    }
    return answer;
}