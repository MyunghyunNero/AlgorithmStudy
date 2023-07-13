/*
    소수를 보자마자 반사적으로 에라토스테네스 체가 떠오름
    -> 1000000의 값을 저장해도 문제 없겠다 생각이 들었음 -> 하지만 k진수로 바꾸면서 값 저장은 불가능 할 수 있다고 생각함 
    -> 그냥 소수인지 체크를 해야함 
    * 이 문제에서 자료형 값을 넘을지 안넘을지 고민을 많이 한 것같다. 시간복잡도 또한 확신이 없이 풀었다. String을 써야하나 고민좀 한듯..
    그러고 읽어보면 좀 복잡한 구현문제 
    원래는 k진수로 변환함수 구현 , 정답 구현 따로 하려했으나 귀찮아서 그냥 진행
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool arr[1000001];  //에라토스테네스의 체 쓰려던 흔적.. 
bool checkprime(long long n){           // 이 부분에서 시간복잡도가 헷갈렸다. 흠.. 10 -> 3진수로 바꾸면 대략 3^2 <10 인 느낌이니 대략 길이는 2배 증가? 
    if(n==1) return false;              // long long 으로 진행 했다. 그리고 i*i 면 대략 백만? 느낌이 든다.
    for(long long i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int change(int num,int k){
    long long s=0;
    vector<long long> v;
    long long idx=1;
    /*
        num을 k진수로 변환한다/
    */
    while(num){
        long long remain=num%k;
        num/=k;
        if(remain){           // 만약 0이 안나오면 계속 s에 추가해준다   (s는 0P0 ,p0 에서 P의 값을 나타냄)
            s+=remain*idx;
            idx*=10;  //idx는 자릿수 값 
        }else if(s!=0){     //remain == 0이 나왔는데 s가 0이 아니다.-> s의 값을 저장함 
            v.push_back(s);
            s=0;
            idx=1;       //s,idx 초기화
        }else{         //s,remain 둘다 0 이면 그냥 초기화 후 넘어감 굳이 안넣어도 되지만 가독성을 위함
            s=0;
            idx=1;
        }
    }
    if(s!=0){         //P0 으로 끝나는 경우 마지막 P를 저장하기 위함
        v.push_back(s);
    }
    int cnt=0;
    for(int i=0;i<v.size();i++){       // 저장된 값을 소수인지 체크하고 갯수 저장 
        if(checkprime(v[i])) {cnt++;}
    }
    return cnt;
}
int solution(int n, int k) {
    
    return change(n,k);
}