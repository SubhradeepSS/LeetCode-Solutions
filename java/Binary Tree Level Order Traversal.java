/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.Queue;
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null){
            return ans;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(q.size() != 0){
            Integer s=q.size();
            List<Integer> level = new ArrayList<>();
            while(s-- > 0){
                TreeNode t=q.remove();
                level.add(t.val);
                if(t.left != null){
                    q.add(t.left);
                }
                if(t.right != null){
                    q.add(t.right);
                }
            }
            ans.add(level);
        }
        return ans;
    }
}