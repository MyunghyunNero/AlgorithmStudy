/*
    처음 든 생각은 그냥 피보나츠 수열처럼 계속 구하면 된다고 생각.
    메모리제이션으로 풀어도 되지만 난 그냥 3개의 배열을 갱신해가며 풀었음 
    long long은 문제에서 주어졋으니 생략 
*/

#include <iostream>
using namespace std;
long long n;
long long d[3];  
int main(){
    d[0]=1;
    d[1]=1;
    d[2]=2;
    cin>>n;
    if(n==1){
        cout<<4;
        return 0;
    }else if(n==2){
        cout<<6;
        return 0;
    }
    for(int i=3;i<n;i++){
        long long temp=d[2];
        long long temp2=d[1];
        d[2]=temp+temp2;
        d[1]=temp;
        d[0]=temp2;
    }
    cout<<4*d[2]+2*d[1];
}