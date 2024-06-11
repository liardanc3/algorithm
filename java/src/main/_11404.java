package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class _11404 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, a, b, c;
    public static long[][] dist = new long[101][101];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            Arrays.fill(dist[i], Long.MAX_VALUE);
        }

        for(int i=0; i<M; i++){
            String[] input = br.readLine().split(" ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);

            dist[a][b] = Math.min(c, dist[a][b]);
        }

        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                if(i==k) continue;
                for(int j=1; j<=N; j++){
                    if(j==k || j==i) continue;
                    if(dist[i][k] != Long.MAX_VALUE && dist[k][j] != Long.MAX_VALUE){
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                sb.append(dist[i][j] == Long.MAX_VALUE ? 0 : dist[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);

    }
}

