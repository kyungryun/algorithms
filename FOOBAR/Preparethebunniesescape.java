import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static class Point {
        int r;
        int c;
        int wall;
        int dist;

        public Point(int r, int c, int wall, int dist){
            this.r = r;
            this.c = c;
            this.wall = wall;
            this.dist = dist;
        }
    }
    public static int solution(int[][] map) {
        // Your code here
        int ans = bfs(map);
        return ans;
    }

    public static int bfs(int[][] map){
        Queue<Point> q = new LinkedList<>();

        int h = map.length;
        int w = map[0].length;
        q.add(new Point(0,0,0,1));
        int ans = Integer.MAX_VALUE;
        int[][] visited = new int[h][w];
        for(int i=0 ; i<h ; i++) {
            for (int j = 0; j < w; j++) visited[i][j] = Integer.MAX_VALUE;
        }

        visited[0][0] = 0;
        while(!q.isEmpty()){
            Point cur = q.poll();
            int r = cur.r;
            int c = cur.c;
            if(r == h-1 && c == w-1){
                ans = Math.min(ans, cur.dist);
                continue;
            }

            for(int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if(nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc] <= cur.wall) continue;

                if(map[nr][nc] == 0){
                    visited[nr][nc] = cur.wall;
                    q.add(new Point(nr, nc, cur.wall, cur.dist + 1));
                }else{
                    if(cur.wall == 0){
                        visited[nr][nc] = cur.wall+1;
                        q.add(new Point(nr, nc, cur.wall+1, cur.dist+1));
                    }
                }
            }
        }
        return ans;
    }
}
