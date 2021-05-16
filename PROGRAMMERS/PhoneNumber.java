
class PhoneNumber {
    public String solution(String phone_number) {
        StringBuilder sb = new StringBuilder();
        int i=0;
        for( ; i<phone_number.length()-4 ; i++){
            sb.append('*');
        }
        for( ; i<phone_number.length() ; i++){
            sb.append(phone_number.charAt(i));
        }
        return sb.toString();
    }
}
