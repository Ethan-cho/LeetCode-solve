class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dir = [[-1, 0], [0, 1], [1, 0], [0, -1]] 
        x = y = 0 
        idx = 0 
        for i in instructions: 
            if i == "L":
                idx = (idx + 3) % 4 
            elif i == "R": 
                idx = (idx + 1) % 4 
            else: 
                x += dir[idx][0] 
                y += dir[idx][1] 
        if y == 0 and x == 0: 
            return True 
        elif idx != 0: 
            return True 
        else: return False