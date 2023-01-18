import java.io.*;
import java.util.*;

public class _2167 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[][] arr = new String[301][301];
        int prefixSum[][] = new int[301][301];
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        for(int i=1; i<=N; i++)
            arr[i] = br.readLine().split(" ");

        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++)
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] +
                        Integer.parseInt(arr[i][j-1]);
        }

        int K = Integer.parseInt(br.readLine());
        while(K-- > 0){
            String[] point = br.readLine().split(" ");
            int x1 = Integer.parseInt(point[0]);
            int y1 = Integer.parseInt(point[1]);
            int x2 = Integer.parseInt(point[2]);
            int y2 = Integer.parseInt(point[3]);

            int sum = prefixSum[x2][y2]
                    - prefixSum[x1-1][y2] - prefixSum[x2][y1-1]
                    + prefixSum[x1-1][y1-1];
            bw.write(Integer.toString(sum) + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
