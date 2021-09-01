/**
 * @author lei
 * @date 08/29/2021 5:28 PM
 */

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
/*
*   if (left != null && right != null): why can we use this as a benchmark?
*
*   ALWAYS PAY ATTENTION TO TERMINAL CONDITION:
*           if (root == null || root == q || root == p) return root;
*
*   So it's going to be a null, or p/q node.
*   If not null: meaning a p/q would be in this subtree;
*   If neither are null, then p and q must be in 2 subtrees, meaning current node is the LCA
*   If one side goes to null, then p & q would be both in the other side subtree.
*
*   (update) 01.Sept.2021:
*       1. if not a BST, >/<: value comparison never shows
*       2. just a BT: just recursion
*       3. recursive function: returns a Node(like this problem), or a value(e.g. rangeSum), or void (traversal)
*
* */
public class L236LCA {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == q || root == p) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) return root;
        return left == null ? right : left;
    }
}
