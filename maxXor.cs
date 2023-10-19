public class Node
{
    public Node[] child { get; } = new Node[2];

    public bool contains(int bit) => child[bit] != null;

    public Node next(int bit) => child[bit];

    public void put(int bit) => child[bit] = new Node();
}


public class Trie{
    public Node _root {get;} = new Node();
    
    public void insert(int val)
    {
        Node recurse = _root;
        
        for(int i = 31; i >= 0; i--) 
        {
            int bit = (val >> i) & 1;
            if(!recurse.contains(bit)) {
                recurse.put(bit);
            }
            recurse = recurse.next(bit);
        }
    }
    
    public int findMax(int val) 
    {
        Node recurse = _root;
        int answer = 0;
        for(int i = 31; i >=0; i--)
        {
            int complement = 1 ^ ((val >> i) & 1);
            
            if(recurse.contains(complement)) {
                answer += (1 << i);
                recurse = recurse.next(complement);
            }
            else recurse = recurse.next(1^complement);
        }
        
        return answer;
    }
}
public class Solution {
    
    public int FindMaximumXOR(int[] nums) {
        // by observation, it's optimal to choose opposing bits per position
        Trie trie = new Trie();
        int answer = 0;
        for(int i = 0; i < nums.Length; i++)
        {
            trie.insert(nums[i]);
        }
        
        for(int i = 0; i < nums.Length; i++)
        {
            answer = Math.Max(answer, trie.findMax(nums[i]));
        }
        
        return answer;
    }
}
