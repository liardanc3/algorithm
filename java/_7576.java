import java.io.*;
import java.util.*;

public class _7576 {

    static class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N,M, cnt;
    public static int[][] arr = new int[1001][1001];
    public static int[][] visited = new int[1001][1001];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};
    public static Queue<Pair> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException { 
        String[] input = br.readLine().split(" ");

        M = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++){
            input = br.readLine().split(" ");

            for(int j=1; j<=M; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);

                if(arr[i][j] == 0){
                    cnt++;
                }
                if(arr[i][j] == 1){
                    q.add(new Pair(i, j));
                    visited[i][j] = 1;
                }
            }
        }

        System.out.println(cnt == 0 ? 0 : bfs());
    }

    private static int bfs(){
        int answer = 1;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                Pair p = q.poll();

                int y = p.y;
                int x = p.x;

                for(int i=0; i<4; i++){
                    int ddy = y + dy[i];
                    int ddx = x + dx[i];

                    if(1<=ddy&&ddy<=N&&1<=ddx&&ddx<=M&&visited[ddy][ddx]==0&&arr[ddy][ddx]==0){
                        cnt--;
                        visited[ddy][ddx] = 1;
                        q.add(new Pair(ddy,ddx));
                    }
                }
            }

            if(cnt==0){
                return answer;
            }
            answer++;
        }
        return -1;
    }
}