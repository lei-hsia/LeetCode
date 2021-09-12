/**
 * @author lei
 * @date 09/11/2021 5:19 PM
 *
 * version: didn't enhance characteristics of a BST. Just a BT
 */
public class L235_LCA_BSTv1 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null  && right != null) return root;
        return left != null ? left : right;
    }
}
