import java.io.*;
import java.util.*;

public class _1337 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        List<Integer> list = new ArrayList<>();
        while(N-- > 0){
            int number = Integer.parseInt(br.readLine());
            list.add(number);
        }
        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 < o2 ? -1 : 1;
            }
        });

        int ret = 5;
        for(int i=0; i<list.size(); i++){
            int start = list.get(i);
            int end = Arrays.binarySearch(list.toArray(),start+4);

            ret = Math.min(ret, end < 0 ? 5-(-(end+1)-i) : 5-(end-i+1));
        }

        bw.write(Integer.toString(ret));
        bw.flush();
        bw.close();
        br.close();
    }
}
