import java.util.*;
class StringSort {
    public String[] solution(String[] strings, int n) {
        String[] answer = {};
        Arrays.sort(strings, (a, b) -> (a.charAt(n) - b.charAt(n)) == 0 ? a.compareTo(b) : (a.charAt(n) - b.charAt(n)));
        return strings;
    }
}
