class SkillTree {
    public int solution(String skill, String[] skill_trees) {
        int answer = skill_trees.length;
        int before = 0;
        int cur = 0;
        for(int i=0 ; i<skill_trees.length ; i++){
            before = skill_trees[i].indexOf(skill.charAt(0));
            
            for(int j=1 ; j<skill.length() ; j++){
                cur = skill_trees[i].indexOf(skill.charAt(j));
                if((before > cur && cur != -1) || (before == -1 && cur != -1)){
                    answer--;
                    break;
                }
                before = cur;
            }   
        }
        return answer;
    }
}
