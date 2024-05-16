import java.awt.*;
import java.io.*;
import java.util.*;

public class _2178 {
    static class Pair {
        int y;
        int x;

        Pair(int y, int x){
            this.y=y;
            this.x=x;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static int[][] arr = new int[101][101];
    public static int[][] visited = new int[101][101];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0,-1,1,0};

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=0; i<N; i++){
            String line = br.readLine();

            for(int j=0; j<M; j++){
                char ch = line.charAt(j);

                if(ch == '1'){
                    arr[i+1][j+1] = 1;
                } else {
                    arr[i+1][j+1] = 0;
                }
            }
        }

        System.out.println(bfs() + 1);
    }

    private static int bfs(){
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(1, 1));
        visited[1][1] = 1;
        int answer = 0;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                Pair now = q.poll();

                int y = now.y;
                int x = now.x;
                if(y == N && x == M){
                    return answer;
                }

                for(int i=0; i<4; i++){
                    int ddy = y + dy[i];
                    int ddx = x + dx[i];

                    if(1<=ddy&&ddy<=N && 1<=ddx&&ddx<=M && visited[ddy][ddx]==0 && arr[ddy][ddx]==1){
                        visited[ddy][ddx]=1;
                        q.add(new Pair(ddy,ddx));
                    }
                }
            }

            answer++;
        }

        return answer;
    }

}