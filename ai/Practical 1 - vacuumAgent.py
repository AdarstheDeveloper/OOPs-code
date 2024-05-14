# -*- coding: utf-8 -*-
"""
Python program to implement
PEAS algorithm for vacuum cleaner
@author: Siddhartha
"""

import random


# Global Variables
STATES = [0, 1]                                     # 0 = Clean, 1 = Dirty
ROOMS = ['A', 'B']
SCORE = 0


class Room:
    '''
    Returns an object with the specified name
    and a random state i.e. clean / dirty
    '''
    def __init__(self, name):
        self.name = name
        self.state = random.choice(STATES)


A = Room('A')
B = Room('B')
print(f'A: {A.state}, B: {B.state}')                # Initial State of Rooms

vacuumLocation = random.choice(ROOMS)               # Random Starting Room
print(f'Vacuum is randomly placed at location {vacuumLocation}')

if vacuumLocation == 'A':
    if A.state == 1:                                # [A, Dirty] -> Suck
        print('Location A is dirty.')
        A.state = 0
        SCORE += 1
        print('Location A has been cleaned.')       # [A, Clean] -> Right
        print('Moving to location B')
        # vacuumLocation = 'B'
        SCORE -= 1
        if B.state == 1:                            # [B, Dirty] -> Suck
            print('Location B is dirty.')
            B.state = 0
            SCORE += 1
            print('Location B has been cleaned.')   # Both Clean
    else:                                           # [A, Clean] -> Right
        # vacuumLocation = 'B'
        print('Moving to location B')
        SCORE -= 1
        if B.state == 1:                            # [B, Dirty] -> Suck
            print('Location B is dirty.')
            B.state = 0
            SCORE += 1
            print('Location B has been cleaned.')   # Both Clean
else:
    if B.state == 1:                                # [B, Dirty] -> Suck
        print('Location B is dirty.')
        B.state = 0
        SCORE += 1
        print('Location B has been cleaned.')       # [B, Clean] -> Left
        print('Moving to location A')
        # vacuumLocation = 'A'
        SCORE -= 1
        if A.state == 1:                            # [A, Dirty] -> Suck
            print('Location A is dirty.')
            A.state = 0
            SCORE += 1
            print('Location A has been cleaned.')
    else:                                           # [B, Clean] -> Left
        # vacuumLocation = 'A'
        print('Moving to location A')
        SCORE -= 1
        if A.state == 1:                            # [A, Dirty] -> Suck
            print('Location A is dirty')
            A.state = 0
            SCORE += 1
            print('Location A has been cleaned.')

print(f'A: {A.state}, B: {B.state}')                # Final State of Rooms
print(f'Performance Measurement: {SCORE}')
