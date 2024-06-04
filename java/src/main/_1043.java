package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class _1043 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, answer;
    public static int[] parent = new int[51];
    public static List<List<Integer>> partyList = new ArrayList<>();
    public static Set<Integer> policeSet = new HashSet<>();

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        for(int i=1; i<=N; i++){
            parent[i] = i;
        }

        input = br.readLine().split(" ");
        int policeCnt = Integer.parseInt(input[0]);
        for(int i = 1; i <= policeCnt; i++) {
            policeSet.add(Integer.parseInt(input[i]));
        }

        for(int i=1; i<=M; i++){
            input = br.readLine().split(" ");
            int memberCnt = Integer.parseInt(input[0]);

            List<Integer> party = new ArrayList<>();
            for(int j = 1; j <= memberCnt; j++) {
                party.add(Integer.parseInt(input[j]));
            }

            for(int j = 0; j < party.size() - 1; j++) {
                for(int k = j+1; k < party.size(); k++){

                    int a = party.get(j), b = party.get(k);

                    if(policeSet.contains(getParent(a))){
                        parent[getParent(b)] = getParent(a);
                    } else {
                        parent[getParent(a)] = getParent(b);
                    }
                }
            }

            partyList.add(party);
        }



        for (int i=0; i<partyList.size(); i++) {
            boolean possible = true;

            List<Integer> party = partyList.get(i);

            for(int j=0; j<party.size() && possible; j++) {
                if(policeSet.contains(getParent(party.get(j))) || policeSet.contains(party.get(j))) {
                    possible = false;
                }
            }

            if(possible) {
                answer++;
            }
        }

        System.out.println(answer);
    }

    private static int getParent(int i){
        return parent[i] != i ? parent[i] = getParent(parent[i]) : i;
    }
}

