import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1987 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int R, C, mx;
    public static int[] visited = new int[91];
    public static int[][] arr = new int[21][21];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        R = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);

        for(int i=1; i<=R; i++){
            String line = br.readLine();

            for(int j=1; j<=C; j++){
                arr[i][j] = line.charAt(j-1);
            }
        }

        visited[arr[1][1]] = 1;
        dfs(1, 1, 1);
        System.out.println(mx);
    }

    private static void dfs(int y, int x, int cnt){
        mx = Math.max(mx, cnt);

        for(int i=0; i<4; i++){
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if(1<=ddy&&ddy<=R&&1<=ddx&&ddx<=C&&visited[arr[ddy][ddx]]==0){
                visited[arr[ddy][ddx]]=1;
                dfs(ddy, ddx, cnt+1);
                visited[arr[ddy][ddx]]=0;
            }
        }
    }
}

