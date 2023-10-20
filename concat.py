class Node:
    def __init__(self):
        self.links = [None] * 26
        self.flag = False

    def containsKey(self, character):
        return self.links[ord(character) - ord('a')] is not None

    def put(self, character):
        self.links[ord(character) - ord('a')] = Node()

    def next(self, character):
        return self.links[ord(character) - ord('a')]

    def setEnd(self):
        self.flag = True

    def end(self):
        return self.flag

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        transverse = self.root
        for character in word:
            if not transverse.containsKey(character):
                transverse.put(character)
            transverse = transverse.next(character)
        transverse.setEnd()

    def search(self, word):
        transverse = self.root
        for ch in word:
            if transverse.containsKey(ch):
                transverse = transverse.next(ch)
            else:
                return False
        return transverse.end()

    def startsWith(self, prefix):
        transverse = self.root
        for character in prefix:
            if not transverse.containsKey(character):
                return False
            transverse = transverse.next(character)
        return True

class Solution:
    def findAllConcatenatedWordsInADict(self, words):
    
        trie = Trie()
        answer = []

        def can_be_concatenated(word, start, trie, depth, memo):
            if start == len(word):
                return depth >= 2
            
            if start in memo:
                return memo[start]
            
            transverse = trie.root
            for i in range(start, len(word)):
                if not transverse.containsKey(word[i]):
                    memo[start] = False
                    return False
                transverse = transverse.next(word[i])
                if transverse.end() and can_be_concatenated(word, i + 1, trie, depth + 1, memo):
                    memo[start] = True
                    return True

            memo[start] = False
            return False

       
        for word in words:
            trie.insert(word)

       
        for word in words:
            if can_be_concatenated(word, 0, trie, 0, {}):
                answer.append(word)

        return answer
