import javax.print.attribute.HashAttributeSet;
import java.io.*;
import java.util.*;

public class _7785 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        TreeSet<String> treeSet = new TreeSet<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.compareTo(o1);
            }
        });
        while(N-- > 0){
            String[] log = br.readLine().split(" ");
            String name = log[0];
            String act = log[1];

            if(act.equals("enter"))
                treeSet.add(name);
            else
                treeSet.remove(name);
        }
        for(String s : treeSet)
            bw.write(s + '\n');

        bw.flush();
        bw.close();
        br.close();
    }
}
