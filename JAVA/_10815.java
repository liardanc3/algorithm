import java.io.*;
import java.util.*;

public class _10815 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] list = new int[20000001];
        String[] card = br.readLine().split(" ");
        for(String str : card)
            list[Integer.parseInt(str)+10000000]++;

        int M = Integer.parseInt(br.readLine());
        String[] check = br.readLine().split(" ");
        for(String str : check){
            int number = Integer.parseInt(str) + 10000000;

            bw.write(list[number] > 0 ? "1 " : "0 ");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
