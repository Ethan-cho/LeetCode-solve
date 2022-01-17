class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        string_s = s.split(' ') 
        
        answer = True
        
        check_dict = {} 
        for p, s in zip(pattern, string_s): 
            if p not in check_dict.keys(): 
                check_dict[p] = s 
            else:
                if check_dict[p] != s:
                    answer = False 
                    break 
                    
        if (len(set(check_dict.keys())) != len(set(check_dict.values()))) or (len(pattern) != len(string_s)): 
            answer = False
        return answer
