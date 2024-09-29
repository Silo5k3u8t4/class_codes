# Minimax function
def minimax(coins_left, is_maximizing_player):
    # Base case: If no coins are left, it's a terminal state.
    if coins_left == 0:
        if is_maximizing_player:
            return -1  # AI loses if it's its turn and there are no coins.
        else:
            return 1   # AI wins if it's the opponent's turn and there are no coins.

    # Maximizer's turn (AI's turn)
    if is_maximizing_player:
        best_value = -float('inf')  # Set to worst possible for maximizer
        # Try picking 1, 2, or 3 coins
        for move in range(1, 4):
            if coins_left - move >= 0:
                value = minimax(coins_left - move, False)
                best_value = max(best_value, value)
        return best_value

    # Minimizer's turn (Opponent's turn)
    else:
        best_value = float('inf')  # Set to worst possible for minimizer
        for move in range(1, 4):
            if coins_left - move >= 0:
                value = minimax(coins_left - move, True)
                best_value = min(best_value, value)
        return best_value

# Function to find the best move for the AI
def find_best_move(coins_left):
    best_value = -float('inf')
    best_move = -1
    
    # Test all moves (1, 2, or 3 coins)
    for move in range(1, 4):
        if coins_left - move >= 0:
            value = minimax(coins_left - move, False)
            if value > best_value:
                best_value = value
                best_move = move

    return best_move

# Simple game loop
def play_game():
    coins_left = 15  # Starting number of coins
    while coins_left > 0:
        # Player's move
        print(f"Coins left: {coins_left}")
        player_move = int(input("Pick 1, 2, or 3 coins: "))
        coins_left -= player_move
        
        if coins_left == 0:
            print("You took the last coin! You lose.")
            break
        
        # AI's move
        ai_move = find_best_move(coins_left)
        print(f"AI picks {ai_move} coins.")
        coins_left -= ai_move
        
        if coins_left == 0:
            print("AI took the last coin! You win.")
            break

play_game()
