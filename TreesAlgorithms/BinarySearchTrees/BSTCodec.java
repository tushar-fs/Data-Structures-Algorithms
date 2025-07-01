package TreesAlgorithms.BinarySearchTrees;

import java.util.ArrayDeque;
import java.util.Deque;

public class BSTCodec {
    // Encodes a tree to a single string.

    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeUtil(root, sb);
        return sb.toString();
    }

    private void serializeUtil(TreeNode root, StringBuilder sb) {
        if (root == null)
            return;
        sb.append(root.val).append(",");
        serializeUtil(root.left, sb);
        serializeUtil(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.isEmpty())
            return null;
        String[] values = data.split(",");
        int rootVal = Integer.parseInt(values[0]);
        TreeNode root = new TreeNode(rootVal);
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.push(root);
        int i = 1;
        while (!dq.isEmpty() && i < values.length) {
            int curVal = Integer.parseInt(values[i++]);
            TreeNode curNode = new TreeNode(curVal);
            TreeNode lastRemovedNode = null;
            while (!dq.isEmpty() && curVal > dq.peek().val) {
                lastRemovedNode = dq.pop();
            }
            if (lastRemovedNode != null) {
                lastRemovedNode.right = curNode;
            } else {
                dq.peek().left = curNode;
            }
            dq.push(curNode);
        }
        return root;
    }
}
