import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class _18111 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M, B, left = Integer.MAX_VALUE, right = Integer.MIN_VALUE, cost = Integer.MAX_VALUE, h = -1;
    public static int[][] arr = new int[501][501];

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        B = Integer.parseInt(input[2]);

        for(int i=0; i<N; i++){
            String[] height = br.readLine().split(" ");

            for(int j=0; j<M; j++){
                arr[i+1][j+1] = Integer.parseInt(height[j]);
                left = Math.min(left, Integer.parseInt(height[j]));
                right = Math.max(right, Integer.parseInt(height[j]));
            }
        }

        for(int i=right; i>=left; i--){

            int tmpCost = 0, tmpB = B;

            for(int r=1; r<=N; r++){
                for(int c=1; c<=M; c++){
                    if(arr[r][c] > i){
                        tmpB += (arr[r][c] - i);
                        tmpCost += 2 * (arr[r][c] - i);
                    } else if (arr[r][c] < i){
                        tmpB -= (i - arr[r][c]);
                        tmpCost += (i - arr[r][c]);
                    }
                }
            }

            if(tmpCost < cost && tmpB >= 0){
                cost = tmpCost;
                h = i;
            }
        }

        System.out.println(cost + " " + h);

    }
}
