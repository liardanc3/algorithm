import java.io.*;
import java.util.*;

public class _1978 {

    public static int[] prime = new int[1001];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=2; i<=1000; i++){
            boolean isPrime = true;
            for(int j=2; j*j<=i && isPrime; j++){
                if(i%j==0)
                    isPrime = false;
            }
            if(isPrime)
                prime[i]=1;
        }

        br.readLine();
        int ret = 0;
        List<String> inputList = Arrays.asList(br.readLine().split(" "));
        for(String number : inputList){
            if(prime[Integer.parseInt(number)]==1)
                ret++;
        }

        bw.write(Integer.toString(ret));
        bw.flush();
        bw.close();
        br.close();
    }
}
