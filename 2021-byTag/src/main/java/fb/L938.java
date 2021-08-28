package fb;

/**
 * @author lei
 * @date 08/28/2021 6:15 PM
 *
 * 938
 */
// Definition for a binary tree node.
class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
}

public class L938 {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        if (root.val < low) return rangeSumBST(root.right, low, high); //
        if (root.val > high) return rangeSumBST(root.left, low, high);
        return root.val + rangeSumBST(root.right, low, high) + rangeSumBST(root.left, low, high);
    }
}
