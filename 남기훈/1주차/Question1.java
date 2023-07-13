import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int id_size = id_list.length; //이름의 수
        Map<String, Integer> nameToInt = new HashMap<>();
        Map<String, List<String>> map = new HashMap<>(); //유저가 신고를 받은 명단
        for(int i=0;i<id_size;i++){
            map.put(id_list[i], new ArrayList<>()); //각 map에 ArrayList 할당해준다
            nameToInt.put(id_list[i],i); //유저와 id_list의 index를 매핑해준다
        }
        for(int i=0;i<report.length;i++){ //report를 하나씩 돌면서
            String[] stringSplit = report[i].split(" "); //split해 신고자와 피신고자를 나눈다
            List<String> list = map.get(stringSplit[1]); //피신고자를 신고한 사람 목록을 가져와
            if(!list.contains(stringSplit[0])){ //신고자 이력이 없으면
                list.add(stringSplit[0]); //더한다
            }
        }
        int[] answer = new int[id_size];
        for(int i=0;i<id_size;i++){
            List<String> reportList = map.get(id_list[i]); //피신고자의 신고자 목록을 가지고와
            if(reportList.size()>=k){ //k가 넘으면
                for(int j=0;j<reportList.size();j++){ //신고자를 하나씩 돌면서
                    int index =nameToInt.get(reportList.get(j)); //answer해 해당 index를 찾아
                    answer[index]++; //1++한다
                }
            }
        }
        return answer;
    }

}

