package programmers.week1;

import java.util.*;

public class Question2 {
    Long index=1L;
    Long P = 0L;

    public int solution(int n, int k) {
        List<Long> queue = new ArrayList<>();
        while(n!=0){
            int remain = n%k;
            n/=k;
            //remain이 0이 아닐때
            if(remain!=0){
                P+=remain*index;
                index*=10;
            }
            //0일때 P가 0이 아닐때 즉 값이 종료됐을때
            else if(P!=0){
                queue.add(P);
                P=0L;
                index=1L;
            }
        }
        //다 종료된다음에 0으로 끝나지 않을때 마지막을 더해준다.
        if(P!=0){
            queue.add(P);
        }

        int count = 0;
        //queue 사이즈만큼 돌면서 소수인지 확인한다
        for(int i=0;i<queue.size();i++){
            Long data = queue.get(i);
            if(data==1){
                continue;
            }

            boolean isPrime = true;
            for(Long j=2L;j*j<=data;j++){
                if(data%j==0) {
                    isPrime=false;
                    break;
                }
            }
            if(isPrime){
                count++;
            }
        }

        return count;
    }
}