import java.io.*;
import java.util.*;

public class _2667 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, cnt, tmp;
    public static List<Integer> list = new ArrayList<>();
    public static int[][] arr = new int[26][26];
    public static int[][] visited = new int[26][26];
    public static int[] dy = new int[]{-1,0,0,1};
    public static int[] dx = new int[]{0,-1,1,0};

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=0; i<N; i++){
            String input = br.readLine();

            for(int j=0; j<N; j++){
                char ch = input.charAt(j);

                if(ch == '1'){
                    arr[i+1][j+1] = 1;
                }
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(visited[i][j] == 0 && arr[i][j] == 1){
                    tmp = 0;
                    dfs(i, j);
                    list.add(tmp);
                    cnt++;
                }
            }
        }

        list.sort((a,b) -> {
            return a > b ? 1 : -1;
        });

        System.out.println(cnt);
        list.forEach(i -> System.out.println(i));
    }

    private static void dfs(int y, int x){
        tmp++;
        visited[y][x] = 1;

        for(int i=0; i<4; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if(1<=ddy&&ddy<=N&&1<=ddx&&ddx<=N&&arr[ddy][ddx]==1&&visited[ddy][ddx]==0){
                dfs(ddy,ddx);
            }
        }
    }
}