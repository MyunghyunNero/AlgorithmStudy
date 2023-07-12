#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, vector<string> > m;
map<string, int> cnt;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string tmp;
    while(getline(ss, tmp, delimiter)) {
        answer.push_back(tmp);
    }
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (string report1 : report) {
        //info[1] = 신고 당한 사람, info[0] = 신고한 사람
        vector<string> info = split(report1, ' ');
        if (m.find(info[1]) != m.end()) {
            if (find(m[info[1]].begin(), m[info[1]].end(), info[0]) == m[info[1]].end())
                m[info[1]].push_back(info[0]);
        }
        else {
            vector<string> tmp;
            tmp.push_back(info[0]);
            m[info[1]] = tmp;
        }
    }
    for (auto it : m) {
        if (it.second.size() >= k) {
            for (string alarmed : it.second) {
                cnt[alarmed]++;
            }
        }
    }
    for (string id : id_list) {
        if (cnt.find(id) != cnt.end()) answer.push_back(cnt[id]);
        else answer.push_back(0);
    }
    return answer;
}