import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _14500 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, answer;
    public static int[][] arr = new int[501][501];
    public static int[][] dy = new int[][]{
            {0,0,0,0}, {0,1,2,3},
            {0,0,1,1},
            {0,1,2,2}, {0,1,2,2}, {0,0,1,2},  {0,0,1,2},  {0,1,1,1},  {0,1,1,1}, {0,0,0,1}, {0,0,0,1},
            {0,1,1,2}, {0,1,1,2}, {0,0,1,1},  {0,0,1,1},
            {0,0,0,1}, {0,1,1,1}, {0,1,1,2},  {0,1,1,2}
    };
    public static int[][] dx = new int[][]{
            {0,1,2,3}, {0,0,0,0},
            {0,1,0,1},
            {0,0,0,1}, {0,0,0,-1}, {0,1,0,0}, {-1,0,0,0}, {0,-2,-1,0},{0,0,1,2}, {-2,-1,0,0}, {0,1,2,0},
            {0,0,1,1}, {0,-1,0,-1},{0,1,-1,0},{0,1,1,2},
            {0,1,2,1}, {0,-1,0,1}, {0,-1,0,0},{0,0,1,0}
    };

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++) {
            input = br.readLine().split(" ");

            for(int j=1; j<=M; j++) {
                arr[i][j] = Integer.parseInt(input[j-1]);
            }
        }

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                fun(i, j);
            }
        }

        System.out.println(answer);
    }

    private static void fun(int y, int x) {
        for(int i=0; i<19; i++){
            int y1 = y + dy[i][0];
            int y2 = y + dy[i][1];
            int y3 = y + dy[i][2];
            int y4 = y + dy[i][3];
            int x1 = x + dx[i][0];
            int x2 = x + dx[i][1];
            int x3 = x + dx[i][2];
            int x4 = x + dx[i][3];

            boolean cd1 = 1<=y1&&y1<=N&&1<=y2&&y2<=N&&1<=y3&&y3<=N&&1<=y4&&y4<=N;
            boolean cd2 = 1<=x1&&x1<=M&&1<=x2&&x2<=M&&1<=x3&&x3<=M&&1<=x4&&x4<=M;

            if(cd1 && cd2){
                answer = Math.max(answer, arr[y1][x1] + arr[y2][x2] + arr[y3][x3] + arr[y4][x4]);
            }
        }
    }
}
