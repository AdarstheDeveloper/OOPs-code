# -*- coding: utf-8 -*-
"""
Python program to implement
the Hangman Game
@author: Siddhartha
"""


# Sub-states of Hangman Game
STATES = [['-----'],
          ['-----', '  |  '],
          ['-----', '  |  ', '  O  '],
          ['-----', '  |  ', '  O  ', '  |  ', '  |  '],
          ['-----', '  |  ', '  O  ', ' \\|  ', '  |  '],
          ['-----', '  |  ', '  O  ', ' \\|/ ', '  |  '],
          ['-----', '  |  ', '  O  ', ' \\|/ ', '  |  ', ' /  '],
          ['-----', '  |  ', '  O  ', ' \\|/ ', '  |  ', ' / \\']]
WORD = 'hangman'
guessed = list('_' * len(WORD))
guesses = list()
current = 0

# Play Hangman Game
while (current < len(STATES)-1):
    # Format Output
    print()
    print(*STATES[current], sep='\n', end='\n\n')
    print('Word:', ' '.join(guessed))
    print('Guessed:', ' '.join(sorted(guesses)))
    guess = input("Enter guess: ").strip()

    # Input Sanity Check
    if len(guess) > 1:
        print('Only one letter at a time!')
        continue
    elif len(guess) < 1:
        print('Guess a letter!')
        continue
    if guess in guesses:
        print('You have already guessed this letter!')
        continue

    # Hangman Game Logic
    guesses.append(guess)
    if guess in WORD:
        print('Good guess!')
        for i in range(len(WORD)):
            if WORD[i] == guess:
                guessed[i] = WORD[i]
    else:
        print('Oops!')
        current += 1
        continue

    # Exit Condition
    if '_' not in guessed:
        break

# Result
if current == len(STATES) - 1:
    print()
    print(*STATES[current], sep='\n')
    print('You lose!\nThe word was:', WORD)
else:
    print('\nCongratulations!!\nWord:', WORD)
