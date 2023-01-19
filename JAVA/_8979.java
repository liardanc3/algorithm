import java.io.*;
import java.util.*;

public class _8979 {

    public static void main(String[] args) throws IOException{
        class Country{
            private int number, gold, silver, bronze;

            public Country(int number, int gold, int silver, int bronze) {
                this.number = number;
                this.gold = gold;
                this.silver = silver;
                this.bronze = bronze;
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Country> list = new ArrayList<>();
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        Country origin = null;
        for(int i=0; i<N; i++){
            String[] info = br.readLine().split(" ");
            if(Integer.parseInt(info[0])==K) {
                origin = new Country(Integer.parseInt(info[0]),
                        Integer.parseInt(info[1]), Integer.parseInt(info[2]),
                        Integer.parseInt(info[3]));
            }
            else {
                list.add(new Country(Integer.parseInt(info[0]),
                        Integer.parseInt(info[1]), Integer.parseInt(info[2]),
                        Integer.parseInt(info[3])));
            }
        }
        int rank = 1;
        for(int i=0; i<N-1; i++){
            if(origin.gold < list.get(i).gold){
                rank++;
                continue;
            }
            if(origin.gold == list.get(i).gold){
                if(origin.silver < list.get(i).silver){
                    rank++;
                    continue;
                }
                if(origin.silver==list.get(i).silver){
                    if(origin.bronze < list.get(i).bronze)
                        rank++;
                }
            }
        }

        bw.write(Integer.toString(rank));
        bw.flush();
        bw.close();
        br.close();
    }
}
