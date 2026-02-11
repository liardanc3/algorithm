package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class _12851 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int a, b;
    public static Queue<Integer> q = new ArrayDeque<>();
    public static Queue<Integer> visitedQ = new ArrayDeque<>();
    public static int[] visited = new int[200001];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        a = Integer.parseInt(input[0]);
        b = Integer.parseInt(input[1]);

        if(a >= b){
            System.out.println(a-b);
            System.out.println(1);
        } else {
            fun(a);
        }

    }

    private static void fun(int now){
        q.add(now);
        visitedQ.add(now);

        int answer = 0;
        int aCnt = 0;

        while(!q.isEmpty()){
            int size = q.size();

            while(!visitedQ.isEmpty()){
                visited[visitedQ.poll()] = 1;
            }

            while(size-- > 0){
                int number = q.poll();

                if(number == b){
                    aCnt++;
                } else {
                    if(number-1 >= 0 && visited[number-1] == 0){
                        q.add(number-1);
                        visitedQ.add(number-1);
                    }
                    if(number+1 <= 200000 && visited[number+1] == 0){
                        q.add(number+1);
                        visitedQ.add(number+1);
                    }
                    if(number * 2 <= 200000 && visited[number * 2] == 0){
                        q.add(number*2);
                        visitedQ.add(number*2);
                    }
                }
            }
            if(aCnt != 0){
                break;
            }
            answer++;
        }

        System.out.println(answer);
        System.out.println(aCnt);
    }
}

