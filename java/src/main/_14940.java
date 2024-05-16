import java.io.*;
import java.util.*;

public class _14940 {

    static class Pair {
        int a;
        int b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int n, m, srcY, srcX;
    public static int[][] arr = new int[1001][1001];
    public static int[][] dist = new int[1001][1001];
    public static int[][] visited = new int[1001][1001];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dist[i][j] = -1;
            }
        }

        for(int i=0; i<n; i++){

            input = br.readLine().split(" ");

            for(int j=0; j<m; j++){
                arr[i+1][j+1] = Integer.parseInt(input[j]);
                if(arr[i+1][j+1] == 2){
                    srcY = i+1;
                    srcX = j+1;
                }
                if(arr[i+1][j+1] == 0){
                    dist[i+1][j+1] = 0;
                }
                if(arr[i+1][j+1] == 1){
                    dist[i+1][j+1] = -1;
                }
            }
        }

        bfs();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                sb.append(dist[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    private static void bfs(){
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(srcY, srcX));
        visited[srcY][srcX] = 1;

        int cnt = 0 ;
        while(!q.isEmpty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                Pair now = q.poll();

                int y = now.a;
                int x = now.b;

                dist[y][x] = cnt;

                for(int j=0; j<4; j++){
                    int ddy = y + dy[j];
                    int ddx = x + dx[j];

                    if(1<=ddy&&ddy<=n&&1<=ddx&&ddx<=m&&visited[ddy][ddx]==0&&arr[ddy][ddx]==1){
                        visited[ddy][ddx] = 1;
                        q.add(new Pair(ddy,ddx));
                    }
                }
            }

            cnt++;
        }
    }

}
