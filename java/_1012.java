import java.io.*;
import java.util.*;

public class _1012 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[][] arr = new int[51][51];
    public static int[][] visited = new int[51][51];
    public static int[] dy = new int[]{-1,0,0,1};
    public static int[] dx = new int[]{0,-1,1,0};
    public static int T, N, M, K, Y, X, cnt;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            String[] input = br.readLine().split(" ");
            M = Integer.parseInt(input[0]);
            N = Integer.parseInt(input[1]);
            K = Integer.parseInt(input[2]);

            for(int i=0; i<K; i++){
                input = br.readLine().split(" ");
                int x = Integer.parseInt(input[0]);
                int y = Integer.parseInt(input[1]);

                arr[y+1][x+1] = 1;
            }

            for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                    if(visited[i][j] == 0 && arr[i][j] == 1){
                        dfs(i, j);
                        cnt++;
                    }
                }
            }

            sb.append(cnt).append("\n");
            init();
        }

        System.out.println(sb.toString());
    }

    private static void dfs(int y, int x){
        visited[y][x] = 1;

        for(int i=0; i<4; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if(inArr(ddy,ddx) && arr[ddy][ddx] == 1 && visited[ddy][ddx] == 0){
                dfs(ddy, ddx);
            }
        }
    }

    private static boolean inArr(int y, int x){
        return 1<=y && y<=N && 1<=x && x<=M;
    }

    private static void init(){
        cnt = 0;
        for(int i=1; i<=50; i++){
            for(int j=1; j<=50; j++){
                arr[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
}