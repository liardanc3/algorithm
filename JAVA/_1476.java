import java.io.*;
import java.util.StringTokenizer;

public class _1476 {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] input = bf.readLine().split(" ");
        int E = Integer.parseInt(input[0]);
        int S = Integer.parseInt(input[1]);
        int M = Integer.parseInt(input[2]);
        int ret = 1;

        for(int e=1, s=1, m=1; E!=e||S!=s||M!=m; e++,s++,m++){
            ret++;
            if(e==15) e=0;
            if(s==28) s=0;
            if(m==19) m=0;
        }

        System.out.println(ret);

        bf.close();
    }
}
