/**
 * @author lei
 * @date 09/11/2021 6:01 PM
 *
 *  very straightforward;
 *  even "if (root == null || root == q || root == p) return root;" is not needed; can be just line 12-14;
 *  but line 11 makes recursion faster
 */
public class L235V2 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == q || root == p) return root;
        if (root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
        if (root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
        return root;
    }
}
