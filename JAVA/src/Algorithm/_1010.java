package Algorithm;

import java.io.*;

public class _1010 {

    static int[][] C = new int[30][30];
    public static void init(){
        C[1][0]=1; C[1][1]=1;
        for(int i=2; i<=29; i++){
            C[i][0]=1;
            for(int j=1; j<=i; j++)
                C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        init();

        int TC = Integer.parseInt(bf.readLine());
        while(TC-->0){
            String[] str = bf.readLine().split(" ");
            int N = Integer.parseInt(str[0]);
            int M = Integer.parseInt(str[1]);

            System.out.println(C[M][N]);
        }

        bf.close();
    }
}