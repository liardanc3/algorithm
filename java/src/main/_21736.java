import java.io.*;
import java.util.*;

public class _21736 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N,M, srcY, srcX, cnt;
    public static int[][] arr = new int[601][601];
    public static int[][] visited = new int[601][601];
    public static int[] dy = new int[]{-1,0,0,1};
    public static int[] dx = new int[]{0,-1,1,0};

    public static void main(String[] args) throws IOException { 
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++){
            String line = br.readLine();
            for(int j=1; j<=M; j++){
                char now = line.charAt(j-1);

                if(now == 'P'){
                    arr[i][j] = 1;
                }
                if(now == 'X'){
                    arr[i][j] = -1;
                }
                if(now == 'I'){
                    srcY = i;
                    srcX = j;
                }
            }
        }

        dfs(srcY, srcX);
        System.out.println(cnt > 0 ? cnt : "TT");
    }

    private static void dfs(int y, int x){
        visited[y][x] = 1;

        if(arr[y][x] == 1){
            cnt++;
        }

        for(int i=0; i<4; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if(1<=ddy&&ddy<=N &&1<=ddx&&ddx<=M&&visited[ddy][ddx]==0&&arr[ddy][ddx]!=-1){
                dfs(ddy,ddx);
            }
        }
    }
}