import java.io.*;
import java.util.StringTokenizer;

public class _1789 {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long S = Long.parseLong(bf.readLine());

        long sum = 0, ret=0;
        for(ret=1;; ret++){
            sum+=ret;
            if(sum+ret+1>S)
                break;
        }
        bw.write(Long.toString(ret));
        bw.flush();
        bw.close();
    }
}
