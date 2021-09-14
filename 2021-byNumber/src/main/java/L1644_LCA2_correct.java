/**
 * @author lei
 * @date 09/12/2021 5:17 PM
 *
 * One important tip:
 *
 *      xxxxx ....
 *      recursion_function(...)
 *      yyyyy ....
 *
 *      >>> in the above structure, xxxxx is the terminal condition, cuz it's been executed each time recurse happens;
 *      yyyyy is what u do after all recursion finishes. It's not executed each recursion, but executed after all finishes.
 */
public class L1644_LCA2_correct {
    private int count = 0;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode lca = LCA(root, p, q);
        return count == 2 ? lca : null;
    }

    public TreeNode LCA(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        TreeNode left = LCA(root.left, p, q);
        TreeNode right = LCA(root.right, p, q);

        if (root == q || root == p) {
            count++;
            return root;
        }

        return right == null ? left : left == null ? right : root;
    }
}
