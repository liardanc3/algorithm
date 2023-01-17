import java.io.*;
import java.util.*;

public class _1436 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        List<Integer> list = new ArrayList<>();
        for(int i=0; i<=9999; i++){
            String now = "";
            if(i<10) now += "0";
            if(i<100) now += "0";
            if(i<1000) now += "0";
            now += Integer.toString(i);

            for(int idx=0; idx<5; idx++){
                int number = Integer.parseInt(
                        now.substring(0,idx)
                        + "666"
                        + now.substring(idx,4));
                if(!list.contains(number))
                    list.add(number);
            }
        }
        Collections.sort(list);

        bw.write(Integer.toString(list.get(N-1)));
        bw.flush();
        bw.close();
        br.close();
    }
}
