public class Solution {
    public int[][] MatrixBlockSum(int[][] mat, int k) {
        int row = mat.Length, col = mat[0].Length;
        
        int[][] answer = new int[row][];
        
        for(int i = 0; i < row; i++)
        {
            answer[i] = new int[col];
        }
        
        for(int i = 0; i < row; i++) 
        {
            for(int j = 0; j < col; j++)
            {
                int x1 = Math.Max(0, i - k), x2 = Math.Min(row - 1, i + k);
                int y1 = Math.Max(0, j - k), y2 = Math.Min(col - 1, j + k);
                
                answer[i][j] = Enumerable.Range(x1, x2 - x1 + 1)
                                .SelectMany(rowIdx => Enumerable.Range(y1, y2 - y1 + 1)
                                .Select(colIdx => mat[rowIdx][colIdx]))
                                .Sum();
            }
        }
        
        return answer;
    }
}
