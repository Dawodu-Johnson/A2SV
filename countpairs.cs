public class Solution {
    public int CountPairs(IList<IList<int>> coordinates, int k) {
   
        long answer = 0;
        
        Dictionary<(int, int), long> data = new Dictionary<(int, int), long>();
        
        foreach (List<int> coordinate in coordinates) {
            int x = coordinate[0];
            int y = coordinate[1];
            var key = (x, y);

            if (data.ContainsKey(key)) {
                data[key] += 1;
            }
            else {
                data[key] = 1;
            }
        }
        
        foreach (List<int> coordinate in coordinates) {
            int x1 = coordinate[0], y1 = coordinate[1], x2, y2;
             
            for (int i = 0; i <= k; i++) {
                x2 = i ^ x1; y2 = (k - i) ^ y1;
                var key = (x2, y2);
                
                if (data.ContainsKey(key)) {
                    answer += data[key];
                }

                if (x2 == x1 && y2 == y1) {
                    answer -= 1;
                }
            }
         }
        
        return (int)(answer / 2);
    }
}
