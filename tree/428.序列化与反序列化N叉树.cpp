/*
序列化与反序列化N叉树
1.  preorder recursive traversal

2. add number of children after root val, in order to know when to terminate 

1 3 3 2 5 0 6 0 2 0 4 0 
*/


 /*
 2 // Definition for a Node.
 3 class Node {
 4     public int val;
 5     public List<Node> children;
 6 
 7     public Node() {}
 8 
 9     public Node(int _val,List<Node> _children) {
10         val = _val;
11         children = _children;
12     }
13 };
14 */
15 class Codec {
16  // Encodes a tree to a single string.
17     public String serialize(Node root) {
18         List<String> list = new LinkedList<>();
19         buildString(root, list);
20         return String.join(",", list);
21     }
22 
23     private void buildString(Node root, List<String> list) {
24         if (root == null) return;
25 
26         list.add(String.valueOf(root.val));
27         list.add(String.valueOf(root.children.size()));
28         for (Node child : root.children) {
29             buildString(child, list);
30         }
31 
32     }
33 
34     // Decodes your encoded data to tree.
35     public Node deserialize(String data) {
36         if (data.length() == 0) return null;
37         String[] strArr = data.split(",");
38         Queue<String> queue = new LinkedList<>();
39         Collections.addAll(queue, strArr);
40         return buildTree(queue);
41     }
42 
43     private Node buildTree(Queue<String> queue) {
44         // match the given constructor form
45         Node root = new Node();
46         root.val = Integer.parseInt(queue.poll());
47         int size = Integer.parseInt(queue.poll());
48         root.children = new ArrayList<>(size);
49         for (int i = 0; i < size; i++) {
50             root.children.add(buildTree(queue));
51         }
52         return root;
53     }
54 }
55 
56 
57 // Your Codec object will be instantiated and called as such:
58 // Codec codec = new Codec();
59 // codec.deserialize(codec.serialize(root));