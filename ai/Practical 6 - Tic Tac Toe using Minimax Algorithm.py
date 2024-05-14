# -*- coding: utf-8 -*-
"""
Python program to implement
the tic-tac-toe game using
the Minimax algorithm
"""


from math import inf

# Global Declarations
AI = +1                                             # AI is MAX Player
AI_MOVE = 'X'
HUMAN = -1                                          # Human is MIN Player
HUMAN_MOVE = 'O'


def getEmptyCells(state):
    '''
    Checks for empty cells on the board.
    :param state: Instance of 3x3 tic-tac-toe board.
    :return: List of tuples (row, col) indicating empty positions.
    '''
    empty_cells = []
    for row in range(3):
        for col in range(3):
            if state[row][col] == ' ':
                empty_cells.append((row, col))
    return empty_cells


def checkWin(state, player):
    '''
    Checks if the player has won the game instance.
    :param state: Instance of 3x3 tic-tac-toe board.
    :param player: AI or HUMAN global variables.
    :return: True if winning condition satisified else False.
    '''
    if player == AI:
        symbol = AI_MOVE
    else:
        symbol = HUMAN_MOVE

    # Check Rows
    if state[0][0] == state[0][1] == state[0][2] == symbol:
        return True
    if state[1][0] == state[1][1] == state[1][2] == symbol:
        return True
    if state[2][0] == state[2][1] == state[2][2] == symbol:
        return True

    # Check Columns
    if state[0][0] == state[1][0] == state[2][0] == symbol:
        return True
    if state[0][1] == state[1][1] == state[2][1] == symbol:
        return True
    if state[0][2] == state[1][2] == state[2][2] == symbol:
        return True

    # Check Diagonals
    if state[0][0] == state[1][1] == state[2][2] == symbol:
        return True
    if state[0][2] == state[1][1] == state[2][0] == symbol:
        return True
    return False


def evaluateScore(state):
    '''
    Evaluates score of state for Minimax Algorithm.
    :param state: Instance of 3x3 tic-tac-toe board.
    :return: 1 if AI wins, -1 is HUMAN wins, 0 if draw.
    '''
    if checkWin(state, AI):
        return AI
    elif checkWin(state, HUMAN):
        return HUMAN
    else:
        return 0


def minimaxAlgo(state, depth, player):
    '''
    Computes the best move using Minimax Algorithm.
    :param state: Instance of 3x3 tic-tac-toe board.
    :param depth: Depth in game tree representing number of possible moves.
    :param player: AI or HUMAN global variables indicating turn for move.
    :return: Dictionary of {row, col, score} for best move at state.
    '''
    if player == AI:
        best_move = {'row': -1, 'col': -1, 'score': -inf}
        symbol = AI_MOVE
    else:
        best_move = {'row': -1, 'col': -1, 'score': +inf}
        symbol = HUMAN_MOVE

    if depth == 0 or checkWin(state, AI) or checkWin(state, HUMAN):
        score = evaluateScore(state)
        return {'row': -1, 'col': -1, 'score': score}

    for row, col in getEmptyCells(state):
        # Attempting Move
        state[row][col] = symbol
        move = minimaxAlgo(state, depth-1, -player)
        state[row][col] = ' '

        # Check If Move Made was Better
        move['row'] = row
        move['col'] = col
        if player == AI:                            # Maximizing
            if move['score'] > best_move['score']:
                best_move = move
        else:                                       # Minimizing
            if move['score'] < best_move['score']:
                best_move = move
    return best_move


def print_board(board):
    '''
    Outputs board values in tic-tac-toe board format.
    :param board: Instance of 3x3 tic-tac-toe board.
    '''
    print(' {} | {} | {} '.format(board[0][0], board[0][1], board[0][2]))
    print('-'*11)
    print(' {} | {} | {} '.format(board[1][0], board[1][1], board[1][2]))
    print('-'*11)
    print(' {} | {} | {} '.format(board[2][0], board[2][1], board[2][2]))
    print()


# Driver Code
if __name__ == '__main__':
    BOARD = [[' ' for _ in range(3)] for _ in range(3)]
    print('Tic-Tac-Toe Game using Minimax Algorithm')
    print(f'Human:{HUMAN_MOVE}, AI:{AI_MOVE}')
    print_board(BOARD)

    while(True):
        x, y = map(int, input("Human Plays: ").split(' '))
        BOARD[x][y] = HUMAN_MOVE
        print_board(BOARD)
        empty_cells = getEmptyCells(BOARD)
        if len(empty_cells) == 0 or checkWin(BOARD, HUMAN):
            break

        AI_response = minimaxAlgo(BOARD, len(empty_cells), AI)
        print("AI Plays:", AI_response['row'], AI_response['col'])
        BOARD[AI_response['row']][AI_response['col']] = AI_MOVE
        print_board(BOARD)
        if len(empty_cells) == 0 or checkWin(BOARD, AI):
            break

    print('\nFinal Board')
    print_board(BOARD)
    if checkWin(BOARD, AI):
        print('AI Wins!')
    elif checkWin(BOARD, HUMAN):
        print('Human Wins!')
    else:
        print('Draw!')
