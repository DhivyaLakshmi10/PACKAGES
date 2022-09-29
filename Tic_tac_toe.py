#positioning of the board
print("Positioning:")
print("1|2|3")
print("-+-+-+")
print("4|5|6")
print("-+-+-+")
print("7|8|9")
print(" ")

#the game board
print("1.Two player")
print("2.One player")
ip=int(input())
if(ip==1):
 print("THE BOARD:")
 Game_board = {'1': ' ' , '2': ' ' , '3': ' ' ,
            '4': ' ' , '5': ' ' , '6': ' ' ,
            '7': ' ' , '8': ' ' , '9': ' ' }

 key_board = []


 for key in Game_board:
    key_board.append(key)


 def printBoard(board):
    print(board['1'] + '|' + board['2'] + '|' + board['3'])
    print('-+-+-')
    print(board['4'] + '|' + board['5'] + '|' + board['6'])
    print('-+-+-')
    print(board['7'] + '|' + board['8'] + '|' + board['9'])

# the game function
 def game():

    turn = 'X'
    count = 0

    
    for i in range(10):
        printBoard(Game_board)
        print("Turn of player" + turn + ".Which position do you want to move to?")

        move = input()        

        if Game_board[move] == ' ':
            Game_board[move] = turn
            count += 1
        else:
            print("The position is aldready filled\nSelect another position")
            continue

        # checking if player X or O has wins!!,for every move after 5 moves. 
        if count >= 5:
            if Game_board['1'] == Game_board['2'] == Game_board['3'] != ' ': # across the top
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")                
                break
            elif Game_board['4'] == Game_board['5'] == Game_board['6'] != ' ': # across the middle
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break
            elif Game_board['7'] == Game_board['8'] == Game_board['9'] != ' ': # across the bottom
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break
            elif Game_board['1'] == Game_board['4'] == Game_board['7'] != ' ': # down the left side
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break
            elif Game_board['2'] == Game_board['5'] == Game_board['8'] != ' ': # down the middle
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break
            elif Game_board['3'] == Game_board['6'] == Game_board['9'] != ' ': # down the right side
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break 
            elif Game_board['7'] == Game_board['5'] == Game_board['3'] != ' ': # diagonal1
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break
            elif Game_board['1'] == Game_board['5'] == Game_board['9'] != ' ': # diagonal2
                printBoard(Game_board)
                print("\nGAME OVER!!!!.\n")                
                print(" **** " +turn + " wins!!. ****")
                break 

        # If neither X or O wins and the board is full, we declare the result as 'tie'.
        if count == 9:
            print("\nGAME OVER!!!!.\n")                
            print("IT'S A TIE!!")

        # changing the player after every move.
        if turn =='X':
            turn = 'O'
        else:
            turn = 'X'        
    
    # to repeat the game or not
    repeat = input("WANNA TRY AGAIN?(y/n)")
    if repeat == "y" or repeat == "Y":  
        for key in key_board:
            Game_board[key] = " "

        game()
    elif repeat=="n" or repeat=="N":
       print("THANK YOU!!PLAY SOON!")

 if __name__ == "__main__":
    game()
    
else:
 import random
 def printBoard(board):
   

    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |')

 def inputPlayerLetter():
    # Lets the player type which letter they want to be.
    letter = ''
    while not (letter == 'X' or letter == 'O'):
        print('Do you want to be X or O?')
        letter = input().upper()

    # the first element in the tuple is the player's letter, the second is the computer's letter.
    if letter == 'X':
        return ['X', 'O']
    else:
        return ['O', 'X']

 def whoGoesFirst():
    # Randomly choose the player who goes first.
    if random.randint(0, 1) == 0:
        return 'computer'
    else:
        return 'player'

 def playAgain():
    # This function returns True if the player wants to play again, otherwise it returns False.
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')

 def makeMove(board, letter, move):
    board[move] = letter

 def isWinner(bo, le):
    # Given a board and a player's letter, this function returns True if that player has won.
    return ((bo[7] == le and bo[8] == le and bo[9] == le) or # across the top
    (bo[4] == le and bo[5] == le and bo[6] == le) or # across the middle
    (bo[1] == le and bo[2] == le and bo[3] == le) or # across the bottom
    (bo[7] == le and bo[4] == le and bo[1] == le) or # down the left side
    (bo[8] == le and bo[5] == le and bo[2] == le) or # down the middle
    (bo[9] == le and bo[6] == le and bo[3] == le) or # down the right side
    (bo[7] == le and bo[5] == le and bo[3] == le) or # diagonal
    (bo[9] == le and bo[5] == le and bo[1] == le)) # diagonal

 def getBoardCopy(board):
    # Make a duplicate of the board list and return it the duplicate.
    dupeBoard = []

    for i in board:
        dupeBoard.append(i)

    return dupeBoard

 def isSpaceFree(board, move):
    # Return true if the passed move is free on the passed board.
    return board[move] == ' '

 def getPlayerMove(board):
    # Let the player type in his move.
    move = ' '
    while move not in '1 2 3 4 5 6 7 8 9'.split() or not isSpaceFree(board, int(move)):
        print('What is your next move? (1-9)')
        move = input()
    return int(move)

 def chooseRandomMoveFromList(board, movesList):
    possibleMoves = []
    for i in movesList:
        if isSpaceFree(board, i):
            possibleMoves.append(i)

    if len(possibleMoves) != 0:
        return random.choice(possibleMoves)
    else:
        return None

 def getComputerMove(board, computerLetter):
    # Given a board and the computer's letter, determine where to move and return that move.
    if computerLetter == 'X':
        playerLetter = 'O'
    else:
        playerLetter = 'X'

    # Here is our algorithm for our Tic Tac Toe AI:
   
    for i in range(1, 10):
        copy = getBoardCopy(board)
        if isSpaceFree(copy, i):
            makeMove(copy, computerLetter, i)
            if isWinner(copy, computerLetter):
                return i

   
    for i in range(1, 10):
        copy = getBoardCopy(board)
        if isSpaceFree(copy, i):
            makeMove(copy, playerLetter, i)
            if isWinner(copy, playerLetter):
                return i

    # Try to take one of the corners, if they are free.
    move = chooseRandomMoveFromList(board, [1, 3, 7, 9])
    if move != None:
        return move

    # Try to take the center, if it is free.
    if isSpaceFree(board, 5):
        return 5

    # Move on one of the sides.
    return chooseRandomMoveFromList(board, [2, 4, 6, 8])

 def isBoardFull(board):
    # Return True if every space on the board has been taken. Otherwise return False.
    for i in range(1, 10):
        if isSpaceFree(board, i):
            return False
    return True


 print('Welcome to Tic Tac Toe!')

 while True:
    # Reset the board
    theBoard = [' '] * 10
    playerLetter, computerLetter = inputPlayerLetter()
    turn = whoGoesFirst()
    print('The ' + turn + ' will go first.')
    gameIsPlaying = True

    while gameIsPlaying:
        if turn == 'player':
            # Player's turn.
            printBoard(theBoard)
            move = getPlayerMove(theBoard)
            makeMove(theBoard, playerLetter, move)

            if isWinner(theBoard, playerLetter):
                printBoard(theBoard)
                print('Hooray! You have won the game!')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    printBoard(theBoard)
                    print('The game is a tie!')
                    break
                else:
                    turn = 'computer'

        else:
            # Computer's turn.
            move = getComputerMove(theBoard, computerLetter)
            makeMove(theBoard, computerLetter, move)

            if isWinner(theBoard, computerLetter):
                printBoard(theBoard)
                print('The computer has beaten you! You lose.')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    printBoard(theBoard)
                    print('The game is a tie!')
                    break
                else:
                    turn = 'player'

    if not playAgain():
        break
