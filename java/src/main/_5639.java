package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _5639 {

    public static class Node {
        int number;
        Node left, right;

        public Node(int number) {
            this.number = number;
            this.left = null;
            this.right = null;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static String input;
    public static Node root;

    public static void main(String[] args) throws IOException {
        input = br.readLine();
        root = new Node(Integer.parseInt(input));
        
        while((input = br.readLine()) != null){
            addNode(root, Integer.parseInt(input));
        }

        postOrder(root);
        System.out.println(sb);
    }

    private static void postOrder(Node root) {
        if(root.left != null){
            postOrder(root.left);
        }
        if(root.right != null){
            postOrder(root.right);
        }
        sb.append(root.number).append('\n');
    }

    private static void addNode(Node now, int newNumber){
        if(newNumber < now.number){
            if(now.left == null){
                now.left = new Node(newNumber);
            } else {
                addNode(now.left, newNumber);
            }
        }
        if(now.number < newNumber){
            if(now.right == null){
                now.right = new Node(newNumber);
            } else {
                addNode(now.right, newNumber);
            }
        }
    }
}

