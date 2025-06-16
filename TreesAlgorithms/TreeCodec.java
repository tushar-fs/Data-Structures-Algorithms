package TreesAlgorithms;
import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    public final int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    public int getVal() { return this.val; }
}

public class TreeCodec {
    public TreeCodec() {};

    public String serialize(TreeNode root) {
        StringBuilder str = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            TreeNode cur = q.poll();
            if(cur == null) str.append("#,");
            else {
                str.append(cur.val).append(",");
                q.add(cur.left);
                q.add(cur.right);
            }
        }
        return str.toString();
    }

    public TreeNode deserialize(String str) {
        if(str == null || str.isEmpty() || str.equals("#,")) return null;
        String[] values = str.split(",");
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int i = 1;
        while(!q.isEmpty()) {
            TreeNode cur = q.poll();
            if(i < values.length) {
                if(!values[i].equals("#")) {
                    TreeNode leftNode = new TreeNode(Integer.parseInt(values[i]));
                    cur.left = leftNode;
                    q.add(leftNode);
                }
                i++;
            }
            
            if(i < values.length) {
                if(!values[i].equals("#")) {
                    TreeNode rightNode = new TreeNode(Integer.parseInt(values[i]));
                    cur.right = rightNode;
                    q.add(rightNode);
                }
                i++;
            }
        }
        return root;
    }

    public void printInorder(TreeNode root) {
        if (root == null) {
            return;
        }
        printInorder(root.left);
        System.out.print(root.val + " ");
        printInorder(root.right);
    }

    public static void main(String[] args) {
        // 1. Create a sample tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(5);

        // 2. Create a Codec instance
        TreeCodec codec = new TreeCodec();

        // 3. Serialize the tree
        String serializedData = codec.serialize(root);
        System.out.println("Serialized Tree: " + serializedData);
        // Expected output: 1,2,3,#,#,4,5,#,#,#,#,

        // 4. Deserialize the string back to a tree
        TreeNode deserializedRoot = codec.deserialize(serializedData);

        // 5. Verify the result
        System.out.print("Inorder traversal of deserialized tree: ");
        codec.printInorder(deserializedRoot); // Should be 2 1 4 3 5
        System.out.println();
    }
};