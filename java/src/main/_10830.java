package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _10830 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static long B;
    public static long[][] matrix = new long[5][5];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        B = Long.parseLong(input[1]);

        for(int i=0;i<N;i++){
            input = br.readLine().split(" ");
            for(int j=0;j<N;j++){
                matrix[i][j] = Long.parseLong(input[j]);
            }
        }

        long[][] result = pow(matrix, B);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                System.out.print(result[i][j] % 1000 + " ");
            }
            System.out.println();
        }
    }

    public static long[][] pow(long[][] mat, long B){
        if(B <= 1){
            return mat;
        }

        long[][] half = pow(mat, B/2);

        if(B%2 == 0){
            return multiply(half, half);
        } else {
            return multiply(multiply(half, half), mat);
        }
    }

    public static long[][] multiply(long[][] a, long[][] b){
        long[][] result = new long[5][5];

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    result[i][j] += (a[i][k] * b[k][j]) % 1000L;
                    result[i][j] %= 1000L;
                }
            }
        }

        return result;
    }
}

