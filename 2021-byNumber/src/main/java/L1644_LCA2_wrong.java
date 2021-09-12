/**
 * @author lei
 * @date 09/12/2021 4:27 PM
 *
 * This is a wrong answer.
 *
 * if (left == null && right == null) return null; will not just return null when executes, cuz it
 * returns null after bottom layer ends executions: it then goes up a layer in recursion.
 *
 * U want this whole recursion to end, THEN: if (left == null && right == null) return null, not inside
 * somewhere during the recursion.
 *
 * As a result, leave the original LCA intact as it was, then making a judgment after recursion ends (see
 * file LCA2_correct)
 */
public class L1644_LCA2_wrong {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == q || root == p) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) return root;
        if (left == null && right == null) return null;
        return left != null ? left : right;
    }
}
