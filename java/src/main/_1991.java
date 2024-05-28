import java.io.*;
import java.util.*;

public class _1991 {
    static class Node {
        char ch;
        Node left;
        Node right;

        public Node(char ch, Node left, Node right) {
            this.ch = ch;
            this.left = left;
            this.right = right;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static Map<Character, Node> m = new HashMap<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        Node root = new Node('A', null, null);
        m.put('A', root);

        for(int i=0; i<N; i++){
            String[] input = br.readLine().split(" ");

            char a = input[0].charAt(0);
            char b = input[1].charAt(0);
            char c = input[2].charAt(0);

            Node aNode = null;
            Node bNode = null;
            Node cNode = null;

            if(m.containsKey(a)){
                aNode = m.get(a);
            } else {
                aNode = new Node(a, null, null);
                m.put(a, aNode);
            }
            if(b != '.'){
                if(m.containsKey(b)){
                    bNode = m.get(b);
                } else {
                    bNode = new Node(b, null, null);
                    m.put(b, bNode);
                }
            }
            if(c != '.'){
                if(m.containsKey(c)){
                    cNode = m.get(c);
                } else {
                    cNode = new Node(c, null, null);
                    m.put(c, cNode);
                }
            }

            aNode.left = bNode;
            aNode.right = cNode;

        }

        preorder(m.get('A'));
        sb.append("\n");
        inorder(m.get('A'));
        sb.append("\n");
        postorder(m.get('A'));

        System.out.println(sb);
    }

    private static void preorder(Node n){
        sb.append(n.ch);
        if(n.left != null){
            preorder(n.left);
        }
        if(n.right != null){
            preorder(n.right);
        }
    }

    private static void inorder(Node n){
        if(n.left != null){
            inorder(n.left);
        }
        sb.append(n.ch);
        if(n.right != null){
            inorder(n.right);
        }
    }

    private static void postorder(Node n){
        if(n.left != null){
            postorder(n.left);
        }
        if(n.right != null){
            postorder(n.right);
        }
        sb.append(n.ch);
    }
}