#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

//n을 k진수로 바꾼 "문자열"을 반환
string change(int n, int k) {
    string ret = "";
    while (n > 0) {
        ret += (n % k) + '0';
        n /= k;
    }
    //algorithm헤더에 존재
    reverse(ret.begin(), ret.end());
    return ret;
}

//'0'으로 토큰분리
vector<string> split (string input, char delimiter) {
    vector<string> ret;
    string tmp;
    stringstream ss(input);
    while(getline(ss, tmp, delimiter)) {
        ret.push_back(tmp);
    }
    return ret;
}

//n이 소수인지 판별
bool isprime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string k_num = change(n, k);
    vector<string> tokenized = split(k_num, '0');
    //각 토큰들에 대해 소수인지 판별하고 맞으면 카운트
    for (string token : tokenized) {
        if (token.size() == 0) continue;
        //3진수일 때 111...111 이면 100만을 넘기므로 int가 아니라 long long
        //stoi가 아니라 stol임에 주의
        long long num = stol(token);
        if (isprime(num)) answer++;
    }
    return answer;
}