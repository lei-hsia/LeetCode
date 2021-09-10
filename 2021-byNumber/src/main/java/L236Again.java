/**
 * @author lei
 * @date 09/10/2021 5:08 PM
 *
 * return type: whether Node, or int, or void(which means a traversal)
 */
public class L236Again {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == q || root == p) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) return root;
        return left != null ? left : right;
    }
}
