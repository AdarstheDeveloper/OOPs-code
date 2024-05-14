# -*- coding: utf-8 -*-
"""
Python program to develop
puzzle for the water jug problem
@author: Siddhartha
"""


class WaterJugProblem:
    def __init__(self):
        self.x = 0  # 4 Litre Jug
        self.y = 0  # 3 Litre Jug

    def rule1(self):
        ''' Fill 4 litre jug completely '''
        if self.x < 4:
            self.x = 4
            return True
        return False

    def rule2(self):
        ''' Fill 3 litre jug completely '''
        if self.y < 3:
            self.y = 3
            return True
        return False

    def rule3(self, d):
        ''' Pour some water out of 4 litre jug '''
        if self.x > 0 and d <= self.x:
            self.x -= d
            return True
        return False

    def rule4(self, d):
        ''' Pour some water out of 3 litre jug '''
        if self.y > 0 and d <= self.y:
            self.y -= d
            return True
        return False

    def rule5(self):
        ''' Empty 4 litre jug '''
        if self.x >= 0:
            self.x = 0
            return True
        return False

    def rule6(self):
        ''' Empty 3 litre jug '''
        if self.y >= 0:
            self.y = 0
            return True
        return False

    def rule7(self):
        ''' Fill 4 litre jug using 3 litre jug '''
        if self.x + self.y >= 4:
            self.y -= (4 - self.x)
            self.x = 4
            return True
        return False

    def rule8(self):
        ''' Fill 3 litre jug using 4 litre jug '''
        if self.x + self.y >= 3:
            self.x -= (3 - self.y)
            self.y = 3
            return True
        return False

    def rule9(self):
        ''' Pour all water from 3 litre jug into 4 litre jug '''
        if self.x + self.y <= 4:
            self.x += self.y
            self.y = 0
            return True
        return False

    def rule10(self):
        ''' Pour all water from 4 litre jug into 3 litre jug '''
        if self.x + self.y <= 3:
            self.y += self.x
            self.x = 0
            return True
        return False


# Driver Code
if __name__ == '__main__':
    obj = WaterJugProblem()
    print(f'Initial State: ({obj.x}, {obj.y})')
    while(obj.x != 2):
        inp = int(input("Enter Rule: #"))
        if inp == 0:
            break
        elif inp == 1:
            res = obj.rule1()
        elif inp == 2:
            res = obj.rule2()
        elif inp == 3:
            res = obj.rule3(int(input("Enter value of d: ")))
        elif inp == 4:
            res = obj.rule4(int(input("Enter value of d: ")))
        elif inp == 5:
            res = obj.rule5()
        elif inp == 6:
            res = obj.rule6()
        elif inp == 7:
            res = obj.rule7()
        elif inp == 8:
            res = obj.rule8()
        elif inp == 9:
            res = obj.rule9()
        elif inp == 10:
            res = obj.rule10()
        else:
            print('Invalid Rule #')
            continue

        if not res:
            print('Rule cannot be applied!')
        print(f'State: ({obj.x}, {obj.y})')
