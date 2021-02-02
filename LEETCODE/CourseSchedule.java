class CourseSchedule {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        int []arr = new int[numCourses];
        
        for(int []pArr : prerequisites){
            arr[pArr[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0 ; i<arr.length ; i++){
            if(arr[i] == 0) q.add(i);
        }
        
        int cnt = 0;
        
        while(!q.isEmpty()){
            int cur = q.poll();
            
            for(int[] pArr : prerequisites){
                if(pArr[1] == cur){
                    arr[pArr[0]]--;
                    if(arr[pArr[0]] == 0) q.add(pArr[0]);
                }
            }
            cnt++;            
        }
        
        return cnt == numCourses;
    }
}
