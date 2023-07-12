import java.util.*;

class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            sb.append(n % k);
            n /= k;
        }
        String num = sb.reverse().toString();
        StringTokenizer st = new StringTokenizer(num, "0");
        while (st.hasMoreTokens()) {
            Long decimal = Long.parseLong(st.nextToken());
            if (isPrime(decimal)) answer++;
        }
        return answer;
    }
    public boolean isPrime(Long n) {
        if(n <= 1) return false;
        else if(n == 2) return true;
        for(int i = 2; i <= Math.sqrt(n); i++)
            if(n % i == 0) 
                return false;
        return true;
    }
}