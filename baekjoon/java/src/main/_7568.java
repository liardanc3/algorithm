import java.io.*;
import java.util.*;

public class _7568 {

    public static void main(String[] args) throws IOException{
        class Human{
            int weight, height, idx;
            public Human(int weight, int height, int idx) {
                this.weight = weight;
                this.height = height;
                this.idx = idx;
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        List<Human> list = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; i++){
            String[] info = br.readLine().split(" ");
            Human human = new Human(Integer.parseInt(info[0]),Integer.parseInt(info[1]), 1);
            list.add(human);
        }
        for(int i=0; i<N; i++){
            Human h1 = list.get(i);
            for(int j=0; j<N; j++){
                if(i==j) continue;
                Human h2 = list.get(j);
                if(h1.height < h2.height && h1.weight < h2.weight)
                    h1.idx++;
            }
        }
        for(Human h : list)
            bw.write(Integer.toString(h.idx)+ ' ');

        bw.flush();
        bw.close();
        br.close();
    }


}
