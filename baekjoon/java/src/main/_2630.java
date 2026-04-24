import java.io.*;
import java.util.*;

public class _2630 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, blue, white;
    public static int[][] arr = new int[129][129];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            String[] input = br.readLine().split(" ");

            for(int j=1; j<=N; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);
            }
        }

        fun(1, 1, N, N);
        System.out.println(white + "\n" + blue);
    }

    private static void fun(int sy, int sx, int dy, int dx){
        int blueCnt = 0;
        int whiteCnt = 0;

        for(int i=sy; i<=dy; i++){
            for(int j=sx; j<=dx; j++){
                if(arr[i][j] == 1){
                    blueCnt++;
                } else {
                    whiteCnt++;
                }
            }
        }

        int total = (dy-sy + 1) * (dx-sx + 1);
        if(blueCnt == total){
            blue++;
            return;
        }
        if(whiteCnt == total){
            white++;
            return;
        }

        fun(sy, sx, (sy + dy)/2, (dx + sx)/2);
        fun(sy, (sx + dx)/2 + 1, (sy + dy)/2, dx);
        fun((dy + sy) / 2 + 1, sx, dy, (dx + sx)/2);
        fun((dy + sy) / 2 + 1, (sx + dx)/2 + 1, dy, dx);
    }
}