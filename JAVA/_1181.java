import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class _1181 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<String> list = new ArrayList<>();

        int N = Integer.parseInt(br.readLine());
        while(N-- > 0){
            String input = br.readLine();
            list.add(input);
        }
        list = list.stream().distinct().collect(Collectors.toList());
        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() < o2.length() ? -1 :
                        o1.length() > o2.length() ? 1 :
                                o1.compareTo(o2) < 0 ? -1 : 1;
            }
        });
        for(String str : list)
            bw.write(str + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}
