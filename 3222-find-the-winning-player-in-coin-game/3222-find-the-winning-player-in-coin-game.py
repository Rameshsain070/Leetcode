class Solution(object):
    def winningPlayer(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: str
        """
        cnt = 0
        while x > 0 and y > 3:
            x -= 1
            y -= 4
            cnt += 1

        if cnt % 2 == 0:
            return "Bob"
        else:
            return "Alice"        
        