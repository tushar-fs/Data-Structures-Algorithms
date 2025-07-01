package TreesAlgorithms.BinarySearchTrees;

import java.util.ArrayDeque;
import java.util.Deque;

public class BSTIterator {
    private Deque<TreeNode> st;

    public BSTIterator(TreeNode root) {
        st = new ArrayDeque<>();
        pushLeftNodes(root);
    }

    public Boolean hasNext() {
       return !st.isEmpty();
    }

    public TreeNode getNext() {
        if(!hasNext()) return null;
        TreeNode curNode = st.pop();
        pushLeftNodes(curNode.right);
        return curNode;
    }

    public void pushLeftNodes(TreeNode root) {
        while(root!=null) {
            st.push(root);
            root = root.left;
        }
    }
}
