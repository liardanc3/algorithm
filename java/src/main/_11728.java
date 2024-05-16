import java.io.*;
import java.util.*;

public class _11728 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        List<Integer> list = new ArrayList<>();
        br.readLine();
        String[] input = br.readLine().split(" ");
        for(String s : input)
            list.add(Integer.parseInt(s));
        input = br.readLine().split(" ");
        for(String s : input)
            list.add(Integer.parseInt(s));
        Collections.sort(list);

        for(Integer i : list)
            bw.write(Integer.toString(i)+ " ");
        bw.flush();
        bw.close();
        br.close();
    }
}
