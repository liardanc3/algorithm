package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class _15449 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static List<Integer> list = new ArrayList<>();
    public static int answer;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        for (String s : input) {
            Integer num = Integer.parseInt(s);
            list.add(num);
        }

        list.sort(Comparator.naturalOrder());

        for (int i = 0; i < list.size() - 2; i++) {
            for (int j = i + 1; j < list.size() - 1; j++) {
                for (int k = j + 1; k < list.size(); k++) {
                    int a = list.get(i);
                    int b = list.get(j);
                    int c = list.get(k);

                    if(a<b+c && b<c+a && c<a+b){
                        answer++;
                    }
                }
            }
        }

        System.out.println(answer);
    }
}

