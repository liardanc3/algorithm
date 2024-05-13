import java.io.*;
import java.util.*;

public class _10026 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, count1, count2;
    public static int[][] arr = new int[101][101];
    public static int[][] visited1 = new int[101][101];
    public static int[][] visited2 = new int[101][101];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            String input = br.readLine();

            for(int j=1; j<=N; j++){
                if(input.charAt(j-1) == 'R'){
                    arr[i][j] = 1;
                } else if(input.charAt(j-1) == 'B'){
                    arr[i][j] = 2;
                } else {
                    arr[i][j] = 3;
                }
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(visited1[i][j] == 0){
                    count1++;
                    dfs1(i, j, arr[i][j]);
                }
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(visited1[i][j] == 0){
                    count2++;
                    dfs2(i, j, arr[i][j]);
                }
            }
        }

        System.out.println(count1 + " " + count2);
    }

    private static void dfs1(int y, int x, int color){
        visited1[y][x] = 1;

        for(int i=0; i<4; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if(1<=ddy&&ddy<=N&&1<=ddx&&ddx<=N&&arr[ddy][ddx]==color&&visited1[ddy][ddx]==0)
                dfs1(ddy,ddx, color);
        }
    }

    private static void dfs2(int y, int x, int color){
        visited2[y][x] = 1;

        for(int i=0; i<4; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if(1<=ddy&&ddy<=N&&1<=ddx&&ddx<=N&&arr[ddy][ddx]%2==color&&visited1[ddy][ddx]==0)
                dfs2(ddy,ddx, color);
        }
    }


}