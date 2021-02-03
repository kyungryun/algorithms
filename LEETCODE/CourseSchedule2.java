class CourseSchedule2 {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int []arr = new int[numCourses];
        int []ans = new int[numCourses];
        for(int []pArr : prerequisites){
            arr[pArr[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0 ; i<arr.length ; i++){
            if(arr[i] == 0) q.add(i);
        }
        
        int cnt = 0;
        int idx = 0;
        while(!q.isEmpty()){
            int cur = q.poll();
            ans[idx++] = cur;
            for(int[] pArr : prerequisites){
                if(pArr[1] == cur){
                    arr[pArr[0]]--;
                    if(arr[pArr[0]] == 0) q.add(pArr[0]);
                }
            }
            cnt++;            
        }
        
        return idx == numCourses ? ans : new int[0];
    }
}
