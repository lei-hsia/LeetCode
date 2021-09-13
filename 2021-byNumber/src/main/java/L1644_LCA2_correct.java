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

    private TreeNode LCA(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null; // traverse the entire tree 放在递归前面的是terminal condition

        TreeNode left = LCA(root.left, p, q);
        TreeNode right = LCA(root.right, p, q);

        if (root == p || root == q) { // 金comment：放在递归后面的，是递归全部完成之后执行的
            count++;
            return root;
        }

        return right == null ? left : left == null ? right : root;
    }
}
