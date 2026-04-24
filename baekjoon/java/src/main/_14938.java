import java.io.*;
import java.util.*;

public class _14938 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[][] dist = new int[101][101];
    public static int n, m, r, answer;
    public static int[] item = new int[101];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        n = Integer.parseInt(input[0]);
        for(int i=1; i<=n; i++){
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            dist[i][i] = 0;
        }
        m = Integer.parseInt(input[1]);
        r = Integer.parseInt(input[2]);

        input = br.readLine().split(" ");
        for(int i=1; i<=n; i++){
            item[i] = Integer.parseInt(input[i-1]);
        }

        for(int i=0; i<r; i++){
            input = br.readLine().split(" ");

            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int c = Integer.parseInt(input[2]);

            dist[a][b] = Math.min(dist[a][b], c);
            dist[b][a] = Math.min(dist[b][a], c);
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE){
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for(int i=1; i<=n; i++){
            int tmp = 0;
            for(int j=1; j<=n; j++){
                if(dist[i][j] <= m){
                    tmp += item[j];
                }
            }
            answer = Math.max(answer, tmp);
        }

        System.out.println(answer);

    }
}