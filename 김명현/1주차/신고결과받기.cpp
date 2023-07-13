/*
    단순 구현 문제
    map을 이용하면 편하고 빠르게 구현가능 
    사간복잡도 21*200000 정도 
*/


#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
map<string,set<string>> m;   // set을 이용해 중복 제거 
map<string,int> sig;    // 유저가 신고당한 횟수를 저장하는 곳 
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    /*
        report에 주어진 양식에 맞춰 신고자 , 피신고자를 구분지어 map에 저장 
        한 유저가 동일한 유저에 대한 신고들을 1회 처리하기 이해 value 값을 set으로 지정 
    */
    for(string s : report){
        string tmp;
        vector<string> str;
        for(int i=0;i<s.size();i++){     // 신고자, 피신고자 분류 
            if(s[i]==' '){
                str.push_back(tmp);
                tmp="";
            }else{
                tmp+=s[i];
            }
        }
        str.push_back(tmp);
        m[str[0]].insert(str[1]);   // 신고자가 누구를 신고했는지 저장 
    }
    for(int i=0;i<id_list.size();i++){
        for(string s: m[id_list[i]]){
            sig[s]++;         // 유저 별로 신고당한 횟수 증가 
        }
    }
    for(int i=0;i<id_list.size();i++){   // 첫 유저부터 반복문을 돌린다. -> answer에 차례대로 담기 위함
        int cnt=0;
        for(string s: m[id_list[i]]){    // 유저가 신고한 유저가 k번을 넘어 정지 당했는지 체크 
            if(sig[s]>=k) cnt++;      //정지면 인원수 추가
        }
        answer.push_back(cnt);
    }
    return answer;
}