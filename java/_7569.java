import java.io.*;
import java.util.*;

public class _7569 {

    static class Tuple {
        int z;
        int y;
        int x;

        public Tuple(int z, int y, int x) {
            this.z = z;
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, H;
    public static int[][][] arr = new int[102][102][102];
    public static int[][][] visited = new int[102][102][102];
    public static int[] dz = new int[]{0, 0, 0, 0, -1, 1};
    public static int[] dy = new int[]{-1, 0, 0, 1, 0, 0};
    public static int[] dx = new int[]{0, -1, 1, 0, 0, 0};
    public static Queue<Tuple> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        M = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);
        H = Integer.parseInt(input[2]);

        for(int i=1; i<=H; i++){
            for(int j=1; j<=N; j++){
                input = br.readLine().split(" ");
                for(int k=1; k<=M; k++){
                    arr[i][j][k] = Integer.parseInt(input[k-1]);
                    if(arr[i][j][k] == 1){
                        q.add(new Tuple(i,j,k));
                        visited[i][j][k] = 1;
                    }
                }
            }
        }

        System.out.println(bfs());
    }

    private static int bfs(){
        int answer = 0;

        while(!q.isEmpty()){
            if(isRipe()){
                return answer;
            }

            int size = q.size();

            while(size-- > 0){
                Tuple t = q.poll();

                int z = t.z;
                int y = t.y;
                int x = t.x;

                for(int i=0; i<6; i++){
                    int ddz = z + dz[i];
                    int ddy = y + dy[i];
                    int ddx = x + dx[i];

                    boolean cd1 = 1<=ddz&&ddz<=H && 1<=ddy&&ddy<=N && 1<=ddx&&ddx<=M;
                    boolean cd2 = visited[ddz][ddy][ddx] == 0 && arr[ddz][ddy][ddx] == 0;

                    if(cd1 && cd2){
                        q.add(new Tuple(ddz, ddy, ddx));
                        visited[ddz][ddy][ddx] = 1;
                    }
                }
            }

            answer++;
        }

        if(isRipe()){
            return answer;
        }
        return -1;
    }

    private static boolean isRipe(){
        for(int i=1; i<=H; i++){
            for(int j=1; j<=N; j++){
                for(int k=1; k<=M; k++){
                    if(arr[i][j][k] == 0)
                        if(visited[i][j][k] == 0) {
                            return false;
                        }
                }
            }
        }
        return true;
    }
}