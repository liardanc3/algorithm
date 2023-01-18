import java.io.*;
import java.util.*;

public class _2740 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[][] arr1 = new int[101][101];
        int[][] arr2 = new int[101][101];
        int[][] matrix = new int[101][101];

        String[] NM = br.readLine().split(" ");
        for(int i=1; i<=Integer.parseInt(NM[0]); i++){
            String[] point = br.readLine().split(" ");
            for(int j=1; j <= Integer.parseInt(NM[1]); j++){
                arr1[i][j] = Integer.parseInt(point[j-1]);
            }
        }
        String[] MK = br.readLine().split(" ");
        for(int i=1; i<=Integer.parseInt(MK[0]); i++){
            String[] point = br.readLine().split(" ");
            for(int j=1; j <= Integer.parseInt(MK[1]); j++){
                arr2[i][j] = Integer.parseInt(point[j-1]);
            }
        }

        for(int i=1; i<=Integer.parseInt(NM[0]); i++){
            for(int k=1; k<=Integer.parseInt(MK[1]); k++){
                for(int j=1; j<=Integer.parseInt(MK[0]); j++){
                    matrix[i][k] += arr1[i][j]*arr2[j][k];
                }
            }
        }

        for(int i=1; i<=Integer.parseInt(NM[0]); i++){
            for(int j=1; j<=Integer.parseInt(MK[1]); j++){
                bw.write(Integer.toString(matrix[i][j]) + " ");
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
