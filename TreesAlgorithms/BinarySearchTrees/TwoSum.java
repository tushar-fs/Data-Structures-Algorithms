package TreesAlgorithms.BinarySearchTrees;

public class TwoSum {
    public Boolean checkTwoSum(TreeNode root, int target) {
        BSTBidirectionalIterator bstIterator = new BSTBidirectionalIterator(root);
        while(bstIterator.hasNext() && bstIterator.hasPrev() ) {
            
        }
        return false;
    }

    private static TreeNode createStandardTree() {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(7);
        return root;
    }

    public void main(String[] args) {
        TreeNode root = createStandardTree();
        System.out.println(checkTwoSum(root, 9));
    }    
}
