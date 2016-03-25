/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> current = new ArrayList<Integer>();
        pathSum(root, sum, current, result);
        return result;
    }
    
    private void pathSum(TreeNode root, int sum, List<Integer> currentResult,
        List<List<Integer>> result){
        if(root == null) return;
        currentResult.add(root.val);
        if(root.left == null && root.right == null && sum == root.val){
            result.add(new ArrayList(currentResult));
            currentResult.remove(currentResult.size()-1);
            return;
        }else{
            pathSum(root.left, sum - root.val, currentResult, result);
            pathSum(root.right, sum - root.val, currentResult, result);
        }
        currentResult.remove(currentResult.size() - 1);//remove leaf node which is not target node.
    }
    
}