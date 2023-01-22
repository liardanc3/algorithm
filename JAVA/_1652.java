import java.io.*;
import java.util.*;

public class _1652 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int answer1 = 0, answer2 = 0;
        String[] arr1 = new String[100];
        int N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; i++){
            arr1[i] = br.readLine();
            int cnt = 0;
            for(int j=0; j<N; j++){
                if(arr1[i].charAt(j) == '.')
                    cnt++;
                else
                    cnt = 0;
                if(cnt == 2){
                    answer1++;
                    while(j<N && arr1[i].charAt(j) == '.')
                        j++;
                    cnt = 0;
                }
            }
        }
        String[] arr2 = new String[100];
        for(int i=0; i<N; i++){
            arr2[i] = "";
            for(int j=0; j<N; j++)
                arr2[i] += arr1[j].charAt(i);
            int cnt = 0;
            for(int j=0; j<N; j++){
                if(arr2[i].charAt(j) == '.')
                    cnt++;
                else
                    cnt = 0;
                if(cnt == 2){
                    answer2++;
                    while(j<N && arr2[i].charAt(j) == '.')
                        j++;
                    cnt = 0;
                }
            }
        }

        bw.write(Integer.toString(answer1) + ' ' + Integer.toString(answer2));

        bw.flush();
        bw.close();
        br.close();
    }
}
