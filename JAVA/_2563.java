import java.io.*;
import java.util.*;

public class _2563 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[][] arr = new int[101][101];
        int N = Integer.parseInt(br.readLine());
        while(N-- > 0){
            String[] point = br.readLine().split(" ");
            int y = Integer.parseInt(point[0]);
            int x = Integer.parseInt(point[1]);

            for(int i=y; i<y+10 && i<=100; i++){
                for(int j=x; j<x+10 && j<=100; j++)
                    arr[i][j]=1;
            }
        }
        int area = 0;
        for(int i=1; i<=100; i++){
            for(int j=1; j<=100; j++){
                if(arr[i][j]==1)
                    area++;
            }
        }
        bw.write(Integer.toString(area));

        bw.flush();
        bw.close();
        br.close();
    }
}
