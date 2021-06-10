import java.util.*;
class OpenChat {
    public String[] solution(String[] record) {
        List<String> list = new ArrayList<>();
        Map<String, String> hm = new HashMap<>();
        
        for(String str : record){
            String[] com = str.split(" ");
            
            if(com[0].equals("Enter")){
                list.add(com[1] + "님이 들어왔습니다.");
                hm.put(com[1], com[2]);
            }else if(com[0].equals("Change")){
                hm.put(com[1],com[2]);
            }else{
                list.add(com[1] + "님이 나갔습니다.");
            }
        }
        String[] answer = new String[list.size()];
        for(int i=0 ; i<list.size() ; i++){
            int idx = list.get(i).indexOf("님");
            String id = list.get(i).substring(0, idx);
            String[] temp = list.get(i).split(" ");
            answer[i] = hm.get(id)+"님이 " + temp[1];
        }
        return answer;
    }
}
