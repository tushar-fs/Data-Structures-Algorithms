package TreesAlgorithms.BinarySearchTrees;

import java.util.ArrayDeque;
import java.util.Deque;

public class BSTBidirectionalIterator {
    private Deque<TreeNode> nextStack;
    private Deque<TreeNode> prevStack;

    public BSTBidirectionalIterator(TreeNode root) {
        this.nextStack = new ArrayDeque<>();
        this.prevStack = new ArrayDeque<>();
        pushLeftChilds(root);
        pushRightChilds(root);
    }

    public Boolean hasNext() {
        return !nextStack.isEmpty();
    }

    public Boolean hasPrev() {
        return !prevStack.isEmpty();
    }

    public int getNext() {
        if(!hasNext()) return -1;
        TreeNode nextElement = nextStack.pop();
        prevStack.push(nextElement);
        pushLeftChilds(nextElement.right);
        return nextElement.val;
    }

    public int getPrev() {
        if(!hasPrev()) return -1;
        TreeNode prevElement = prevStack.pop();
        nextStack.push(prevElement);
        pushRightChilds(prevElement.left);
        return prevElement.val;
    }

    public void pushLeftChilds(TreeNode root) {
        while(root != null) {
            nextStack.push(root);
            root = root.left;
        }
    }

    public void pushRightChilds(TreeNode root) {
        while(root != null) {
            prevStack.push(root);
            root = root.right;
        }
    }
}
