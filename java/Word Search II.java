class Solution {
    
    private static int[][] dirs = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    
    public List<String> findWords(char[][] board, String[] words) {
        if (board == null || board.length == 0 || board[0] == null || board[0].length == 0 || words == null || words.length == 0) return new ArrayList<>();
        List<String> res = new ArrayList<>();
        for (String word : words) {
            if (findWord(board, word)) res.add(word);
        }
        return res;
    }
    
    private boolean findWord(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (findWordBacktrack(board, word, visited, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    private boolean findWordBacktrack(char[][] board, String word, boolean[][] visited, int idx, int r, int c) {
        if (idx == word.length()) return true;
        if (r < 0 || r >= board.length ||
            c < 0 || c >= board[0].length ||
            visited[r][c] == true || board[r][c] != word.charAt(idx)) return false;
        visited[r][c] = true;
        for (int[] d : dirs) {
            int i = r + d[0];
            int j = c + d[1];
            if (findWordBacktrack(board, word, visited, idx+1, i, j)) {
                return true;
            }
        }
        visited[r][c] = false;
        return false;
    }
}