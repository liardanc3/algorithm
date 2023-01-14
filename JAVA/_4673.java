import java.io.*;
import java.util.*;

public class _4673 {

    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] count = new int[10001];
        for(int i=1; i<=10000; i++){
            int sum=i;
            int now=i;
            while(now>0){
                sum += now%10;
                now/=10;
            }
            if(sum<=10000)
                count[sum]++;
        }

        for(int i=1; i<=10000; i++){
            if(count[i]==0)
                bw.write(Integer.toString(i)+'\n');
        }

        bw.flush();
        bw.close();
        bf.close();
    }
}
