//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <time.h>
//#include <locale>
//#include <sstream>
//#include <string>
//
//
//using namespace std;
//
//// Variable declarations
//int a = 1, b = 1;
//int pos = 6;
//const int m = 11, n = 21;
//char board[m][n] = { };
//
//bool bombActive = false, immunityActive = true;
//int bombRow = -1, bombCol = -1; 
//unsigned long bombTimer = 0; 
//int bombRange = 1; 
//
//bool spacePressed = false;   
//int enemyCounter = 0;  
//int senemyCounter = 0;
//
//bool stageCheck = false;
//bool speedBoostActive = false, extendedRangeActive = false, imunityActive = false;
//unsigned long speedBoostTimer = 0, extendedRangeTimer = 0, powerUpTimer = 0,immunityTimer = 0;
//const unsigned long powerupDuration = 3500;
//char currentPowerUp = ' ';
//bool powerupAvailable = true;
//int lives = 3;  
//int score = 0;
//int currentStage = 1; 
//int totalEnemies;
//const int maxBlocks = 10; 
//int blockRows[maxBlocks];
//int blockCols[maxBlocks];
//int numMovingBlocks = 0; 
//int blockRow = -1, blockCol = -1;
//unsigned long blockMoveTimer;
//unsigned long blockMoveInterval = 5000; 
//bool specialBombActive = false;
//int specialBombRow, specialBombCol;
//unsigned long specialBombTimer;
//
//// Function declarations
//void move(char mv);
//int showMenu(); 
//void intBoard();
//void displayBoard();
//void flashPlayer();
//void blocks();
//void spawnPowerUp();  
//void spawnEnemies(int count);
//void moveEnemies();
//void updateEnemyPosition(int oldRow, int oldCol, int newRow, int newCol);
//void updateSEnemyPosition(int oldRow, int oldCol, int newRow, int newCol);   
//void hideCursor();
//void showCursor();
//void clearScreen();
//void placeBomb(int prevRow, int prevCol);
//void explodeBomb();
//void displayExplosionEffect();
//void removeExplosionEffect();
//void checkPowerUp(int row, int col);
//void handleTimers();
//void resetPowerUp();
//void handlePlayerDeath();
//void gameOver();   
//void checkCollisionWithBomb(int explosionRow, int explosionCol);
//void countEnemies();
//void moveToStage1();
//void moveToStage2();
//void moveToStage3();     
//void spawnMovingBlocks(int count);
//void spawnSpecialEnemies(int count);
//void moveBlocks();
//void handleSpecialBomb();
//void highScore();
//void win();
//void playSound(const char* filename);
//
//
//int main()
//{
//    pos = 7;  
//    //  For random seed
//    srand(time(NULL));  
//    if (stageCheck == false)
//    {
//        showMenu();
//        // Hide cursor at the start
//        hideCursor();
//
//        // Initialize the game board
//        intBoard();
//        //  Initializing the P at 1,1 and displaying the updated board
//        board[1][1] = 'P';
//        spawnPowerUp();
//        spawnEnemies(3);
//        displayBoard();
//
//        //  Movement input by the user
//        while (true) {
//
//            clearScreen();  // Clear the screen before drawing the updated board
//            displayBoard();  // Display updated board
//
//            char input = 'G';
//            if (_kbhit()) {
//                input = _getch();
//                if (input == 'Q' || input == 'q') return 0;
//
//                if (input == ' ') {
//                    placeBomb(a, b); 
//                }
//                else {
//                    move(input);  // Move player
//                }
//            }
//
//            handleTimers();  // Manage timers for power-ups
//
//
//            if (bombActive && GetTickCount64() - bombTimer >= 1500) {
//                explodeBomb();  // Handle bomb explosion  
//            }
//
//            // Adjust sleep timing based on speed boost
//            Sleep(speedBoostActive ? 50 : 100);
//
//
//            // Reset enemyCounter to avoid overflow
//            if (enemyCounter >= 10000) {
//                enemyCounter = 0;
//            }
//
//            // Move enemies periodically based on enemyCounter
//            if (enemyCounter % 4 == 0) {
//                moveEnemies();
//            }
//            enemyCounter++;
//
//            countEnemies();
//
//            // Check if all enemies are destroyed and move to stage 2
//            if (totalEnemies == 0) {
//                break;
//            }
//        }
//
//        system("cls");
//        moveToStage2();
//    }
//}
//
//
//int showMenu()  
//{
//
//    hideCursor();  
//    char ch;
//    char menu;
//    for (int i = 0; i < 3; i++) {
//        cout << endl;
//    }
//
//menu:
//    // Including the UTF-8 to display emojis
//    system("chcp 65001 > nul");
//    setlocale(LC_ALL, "en_US.UTF-8");
//
//    // Required menu
//    cout << endl;
//    wcout << L"\t\t\t\t\tB0MBER MAN ☢" << endl << endl;
//    cout << "\t\t\t\t\t1- Start   " << endl;
//    cout << "\t\t\t\t\t2- Instructions   " << endl;
//    cout << "\t\t\t\t\t3- High scores   " << endl;
//    cout << "\t\t\t\t\t4- Quit    " << endl;
//
//    do {
//        ch = _getch();
//        switch (ch) {
//        case '1':
//            system("cls");
//            break;
//        case '2':
//            system("cls");
//            cout << endl << endl;
//            wcout << L"\t\t\t\t\t-- Instructions⚡ --" << endl << endl;
//            cout << "\t\t\t\t-- W,A,S,D to move --  " << endl;
//            cout << "\t\t\t\t-- Space to drop bombs --  " << endl;
//            wcout << L"\t\t\t\t-- Drop bombs ☠  on all enemies to win --  " << endl;
//            cout << "\t\t\t\t-- Bomb detonates after a short delay --" << endl;
//            cout << "\t\t\t\t-- You have multiple lives --" << endl;
//            wcout << L"\t\t\t\t-- Q to quit ❌ the game (Loser) -- " << endl;
//            cout << "\t\t\t\t-- 'P' is you --" << endl;
//            cout << "\t\t\t\t-- '0' are the blocks that you can destroy --" << endl;
//            cout << "\t\t\t\t-- '#' are the blocks that you can not destroy --" << endl;
//            cout << "\t\t\t\t-- 'E' are the deadly enemies that can kill you --" << endl;
//            cout << "\t\t\t\t-- 'S' are the special enemies that drops an invisible bomb when destroyed --" << endl;
//            cout << "\t\t\t\t-- '=' are the moving blocks that can not be destroyed --" << endl;
//            cout << "\t\t\t\t-- '!' is the range of your only weapon (Bomb) --" << endl;
//            cout << "\t\t\t\t-- You can also obtain powerups from time to time --" << endl;
//            cout << "\t\t\t\t-- 'I' for player's immunity --" << endl;
//            cout << "\t\t\t\t-- '+' for increasing bomb's range --" << endl;
//            cout << "\t\t\t\t-- '$' for increasing player's speed --" << endl;
//            cout << "\t\t\t\t-- There are multiple stages to this game --" << endl;
//            cout << "\t\t\t\t-- X to go back to the menu --" << endl << endl;
//            cout << "\t\t\t\t\t\t Good Luck :) " << endl;  
//            cout << endl << "Press any key to start the game........" << endl;
//            menu = _getch();
//            menu = toupper(menu);
//            if (menu == 'X') {
//                system("cls");
//                goto menu;
//            }
//            else {
//                system("cls");
//                break;
//            }
//        case '3':
//            system("cls");
//            highScore();
//            break;
//        case '4':
//            cout << "Exiting......." << endl;
//            exit (0);
//            break;
//        default:
//            break;
//        }
//    } while (ch != '1' && ch != '2' && ch != '3' && ch != '4');
//}
//
////  Function for the movement
//void move(char mv) {
//    int newa = a, newb = b;
//    switch (mv) {
//    case 'w': case 'W':
//        if (a > 0) newa = a - 1;
//        break;
//    case 's': case 'S':
//        if (a < m - 1) newa = a + 1;
//        break;
//    case 'a': case 'A':
//        if (b > 0) newb = b - 1;
//        break;
//    case 'd': case 'D':
//        if (b < n - 1) newb = b + 1;
//        break;
//    }
//
//    // Check for collision with enemy at the new position
//    if (board[newa][newb] == 'E') {
//        if (!immunityActive) {
//            flashPlayer();
//            handlePlayerDeath();  // Deduct a life and handle player death logic
//        }
//    }
//
//    // Check for collision with enemy at the new position
//    if (board[newa][newb] == 'S') {
//        if (!immunityActive) {
//            flashPlayer();
//            handlePlayerDeath();  // Deduct a life and handle player death logic
//        }
//    }
//
//
//    if (board[newa][newb] == ' ' || board[newa][newb] == currentPowerUp) {
//        board[a][b] = (bombActive && a == bombRow && b == bombCol) ? 'B' : ' ';
//        a = newa;
//        b = newb;
//        checkPowerUp(a, b);
//        board[a][b] = 'P';  // Move player to the new position   
//    }
//    else {
//        flashPlayer(); // Handle blocked movement
//    }
//}
//
//// Function for intial board generation
//void intBoard() {
//    //  Initializing the array to spaces
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            board[i][j] = ' ';
//        }
//    }
//
//    if (currentStage == 1)
//    {
//        // Displaying indestructible blocks
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if ((j % 2 == 0) && (i % 2 == 0)) {
//                    board[i][j] = '#';
//                }
//                else {
//                    board[i][j] = ' ';
//                }
//            }
//        }
//    }
//    else if (currentStage == 2)
//    {
//        // Displaying indestructible blocks with alternating patterns
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i % 2 == 0) { 
//                    if ((i / 2) % 2 == 0) {  
//                        if (j % 2 == 0 && j < 19) {  
//                            board[i][j] = '#';
//                        }
//                        else {
//                            board[i][j] = ' ';
//                        }
//                    }
//                    else { 
//                        if (j == 0 || j == 20) {  
//                            board[i][j] = ' ';
//                        }
//                        else if (j % 3 == 1) {  
//                            board[i][j] = '#';
//                        }
//                        else {
//                            board[i][j] = ' ';
//                        }
//                    }
//                }
//                else { 
//                  
//                    board[i][j] = ' ';
//                }
//            }
//        }
//    }
//    else if (currentStage == 3)
//    {
//        // Displaying indestructible blocks with alternating patterns
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i % 2 == 0) { 
//                    if (i % 4 == 0) {  
//                        if (j % 2 == 0) {  
//                            board[i][j] = '#';
//                        }
//                        else {
//                            board[i][j] = ' ';
//                        }
//                    }
//                    else { 
//                        if (j == 0 || j == 2 || j == 4 || j == 16 || j == 18 || j == 20) {
//                            board[i][j] = '#';
//                        }
//                        else if (j == 9 || j == 10) {
//                            board[i][j] = '#';
//                        }
//                        else {
//                            board[i][j] = ' ';
//                        }
//                    }
//                }
//                else { 
//                    board[i][j] = ' ';
//                }
//            }
//        }
//    
//    }
//
//    //  Displaying the destructible blocks
//    blocks();
//
//    //   For displaying the boundary
//    for (int i = 0; i < n; i++) {
//        board[0][i] = '-';
//        board[m - 1][i] = '-';
//    }
//    for (int i = 0; i < m; i++) {
//        board[i][0] = '|';
//        board[i][n - 1] = '|';
//    }
//}
//
//void displayBoard() {
//    static string buffer;
//    buffer.clear();
//
//    // Build the board string
//    for (int i = 0; i < m; i++) {
//        buffer.append("\t\t\t");
//        for (int j = 0; j < n; j++) {
//            buffer.append(1, board[i][j]);
//        }
//        buffer.append(1, '\n');
//    }
//
//    // Append stage number at the center
//    buffer.append("\n\t\t\t       Stage: " + to_string(currentStage)); 
//
//    // Add an empty line for spacing
//    buffer.append("\n\n");
//
//    // Append the score and lives below the grid
//    buffer.append("\t\t\tLives: ");
//    for (int i = 0; i < lives; i++) {
//        buffer.append("* ");
//    }
//
//    buffer.append("\n\t\t\tScore: " + to_string(score));
//
//    clearScreen(); 
//    cout << buffer;  // Output the buffered board content to the console
//}
//
//
//void spawnPowerUp() {
//    if (!powerupAvailable) return;
//
//    // Choose a random power-up
//    char powerUps[] = { '$', '+', 'I' };
//    int totalPowerUps = sizeof(powerUps) / sizeof(powerUps[0]);
//    currentPowerUp = powerUps[rand() % totalPowerUps];
//
//    // Randomly find a spot for the power-up
//    int row, col;
//    do {
//        row = rand() % (m - 2) + 1;
//        col = rand() % (n - 2) + 1;
//    } while (board[row][col] != ' '); 
//
//    board[row][col] = currentPowerUp;
//
//    // Set power-up as unavailable until the timer expires
//    powerupAvailable = false;
//    powerUpTimer = GetTickCount64();
//}
//
////  Function to change P to X when movement is blocked
//void flashPlayer() {
//
//    playSound("Movement block.wav");
//    board[a][b] = 'X';
//    displayBoard();
//
//    Sleep(101);
//
//    board[a][b] = 'P';
//    displayBoard();
//}
//
// // Function to display the destructible blocks
//void blocks() {
//
//
//    for (int i = 0; i <= pos; i++) 
//    {
//        for (int j = 0; j <= pos; j++) 
//        {
//            if (board[i][j] != '|' && board[i][j] != '-' && board[i][j] != '#' && board[i][j] != 'P') 
//            {
//                int row = rand() % m; 
//                int col = rand() % n; 
//
//                if ((board[row][col] == ' ') &&  !(row == a - 1 && col == b) && !(row == a + 1 && col == b) && !(row == a && col == b - 1) && !(row == a && col == b + 1) && !(row == 1 && col == 2) && !(row == 1 && col == 3) && !(row == 2 && col == 1) && !(row == 3 && col == 1) && !(row == 4 && col == 1))
//                {
//                    board[row][col] = '0';
//                }
//            }
//        }
//    }
//}
//
////Function to hide cursor using ANSI escape code
//void hideCursor() {
//    cout << "\033[?25l" << flush;
//}
//
////Function to show cursor using ANSI escape code
//void showCursor() {
//    cout << "\033[?25h" << flush;
//}
//
////Function to clear the screen using ANSI escape code
//void clearScreen() {
//    cout << "\033[H\033[J";  // Move cursor to top-left and clear screen
//    fflush(stdout);
//}
//
//// Function for playing sounds
//void playSound(const char* filename) {
//
//    std::wstring wideFilename = std::wstring(filename, filename + strlen(filename));
//    PlaySound(wideFilename.c_str(), NULL, SND_FILENAME | SND_ASYNC);
//}
//
//
//
//
//// Function to spawn enemies on the board
//void spawnEnemies(int count) {
//    int placed = 0;
//    while (placed < count) {
//        int row = rand() % (m - 2) + 1;
//        int col = rand() % (n - 2) + 1;
//        if (board[row][col] == ' ' && !(row == 1 && col == 2) && !(row == 1 && col == 3) && !(row == 2 && col == 1) && !(row == 3 && col == 1) && !(row == 4 && col == 1)) {
//            board[row][col] = 'E';
//            placed++;
//        }
//    }
//}
//
//// Function to move enemies independently
//void moveEnemies() {
//    for (int i = 1; i < m - 1; i++) {
//        for (int j = 1; j < n - 1; j++) {
//            if (board[i][j] == 'E') {  
//                int direction = rand() % 4; 
//                int newRow = i, newCol = j;
//
//                // Determine the new position based on the direction
//                switch (direction) {
//                case 0: newRow--; break;  // Move up
//                case 1: newRow++; break;  // Move down
//                case 2: newCol--; break;  // Move left
//                case 3: newCol++; break;  // Move right
//                }
//
//                if (newRow > 0 && newRow < m - 1 && newCol > 0 && newCol < n - 1) {
//                    // Allow the enemy to move to the player's position
//                    if (board[newRow][newCol] == ' ' || (newRow == a && newCol == b)) {
//                        updateEnemyPosition(i, j, newRow, newCol);  
//                    }
//                }
//
//                // Deduct life when player and enemy are on the same position
//                if (newRow == a && newCol == b) {  
//                    if (!immunityActive) {  
//                        flashPlayer();  
//                        handlePlayerDeath();
//                        board[newRow][newCol] = 'E';
//                    }
//                }
//
//               
//              
//            }
//            else if (board[i][j] == 'S') {
//                int direction = rand() % 4; 
//                int newRow = i, newCol = j;
//
//                // Determine the new position based on the direction
//                switch (direction) {
//                case 0: newRow--; break;  // Move up
//                case 1: newRow++; break;  // Move down
//                case 2: newCol--; break;  // Move left
//                case 3: newCol++; break;  // Move right
//                }
//
//                if (newRow > 0 && newRow < m - 1 && newCol > 0 && newCol < n - 1) {
//                    // Allow the enemy to move to the player's position
//                    if (board[newRow][newCol] == ' ' || (newRow == a && newCol == b)) {
//                        updateSEnemyPosition(i, j, newRow, newCol);
//                    }
//                }
//
//                // Deduct life when player and enemy are on the same position
//                if (newRow == a && newCol == b) {
//                    if (!immunityActive) {
//                        flashPlayer();
//                        handlePlayerDeath();
//                        board[newRow][newCol] = 'S';
//                    }
//                }
//
//
//
//            }
//        }
//    }
//}
//
//// Function to update the position of a normal enemy
//void updateEnemyPosition(int oldRow, int oldCol, int newRow, int newCol) {
//    board[oldRow][oldCol] = ' ';
//    board[newRow][newCol] = 'E';
//}
//
//// Function to update the position of a special enemy
//void updateSEnemyPosition(int oldRow, int oldCol, int newRow, int newCol) {
//    board[oldRow][oldCol] = ' ';
//    board[newRow][newCol] = 'S';
//}
//
//// Function to place bomb at the previous position
//void placeBomb(int prevRow, int prevCol) {
//    if (bombActive) return; 
//
//    bombRow = prevRow;
//    bombCol = prevCol;
//  
//    if (board[bombRow][bombCol] == ' ' || board[bombRow][bombCol] == 'P') {
//   
//        if (board[bombRow][bombCol] == ' ') {
//            board[bombRow][bombCol] = 'B';  // Place bomb if it's an empty spot
//        }
//        bombTimer = GetTickCount64();
//        bombActive = true;
//    }
//}
//
//
//
//// Function for the bomb explosion
//void explodeBomb() {
//    for (int i = bombRow - bombRange; i <= bombRow + bombRange; i++) {
//        for (int j = bombCol - bombRange; j <= bombCol + bombRange; j++) {
//          
//            if (i >= 0 && i < m && j >= 0 && j < n) {
//                // Check for enemy and destructible blocks
//                if (board[i][j] == 'E') { 
//                    score += 50;
//                    board[i][j] = ' ';
//                    totalEnemies--;   
//                }
//                else if (board[i][j] == '0') {
//                    score += 10;
//                    board[i][j] = ' '; 
//                }
//                else if (board[i][j] == 'S') {
//                    specialBombActive = true;
//                    specialBombRow = i;
//                    specialBombCol = j; 
//                    board[i][j] = (specialBombActive && i == specialBombRow && j == specialBombCol) ? 'B' : ' ';
//                    specialBombTimer = GetTickCount64(); 
//                    score += 60;
//                    totalEnemies--;  
//                }
//            }
//        }
//    }
//
//    displayExplosionEffect();
//    Sleep(300); 
//    removeExplosionEffect();
//    bombActive = false;
//    bombRow = bombCol = -1;
//}
//
//
//
//// Function for displaying explosion effect
//void displayExplosionEffect() {
//
//    playSound("Bomb explosion.wav");
//    for (int i = bombRow - bombRange; i <= bombRow + bombRange; i++) {
//        for (int j = bombCol - bombRange; j <= bombCol + bombRange; j++) {
//            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] != '#' && board[i][j] != '|' && board[i][j] != '-' && board[i][j] != '$' && board[i][j] != 'I' && board[i][j] != '+' && board[i][j] != '=') {
//            
//                if (i == a && j == b) {
//                    if (immunityActive) {
//                        continue;
//                    }
//                    else {
//                        flashPlayer(); 
//                        checkCollisionWithBomb(i, j);
//                    }
//                   
//                }
//                board[i][j] = '!';
//            }
//        }
//    }
//    displayBoard();
//}
//// Function for removing explosion effect
//void removeExplosionEffect() {
//    for (int i = bombRow - bombRange; i <= bombRow + bombRange; i++) {
//        for (int j = bombCol - bombRange; j <= bombCol + bombRange; j++) {
//            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == '!') {
//                board[i][j] = ' '; 
//            }
//        }
//    }
//    board[bombRow][bombCol] = ' ';
//}
//
//void checkPowerUp(int row, int col) {
//    if (board[row][col] == currentPowerUp) {
//        switch (currentPowerUp) {
//        case '$':  // Speed Boost
//            speedBoostActive = true;
//            speedBoostTimer = GetTickCount64();
//            break;
//        case '+':  // Increase bomb range
//            extendedRangeActive = true;
//            extendedRangeTimer = GetTickCount64();
//            bombRange = 2;
//            break;
//        case 'I': // Player Immunity
//            immunityActive = true;
//            immunityTimer = GetTickCount64();
//            break;
//        }
//
//        if(powerupAvailable == false) playSound("Powerup pick.wav");
//
//        // Increase score when power-up is collected
//        score += 20;  
//
//        // Disable power-up availability and start power-up timer
//        powerupAvailable = true;
//        powerUpTimer = GetTickCount64(); 
//    }
//}
//
//
//void handleTimers() {
//    unsigned long currentTime = GetTickCount64();
//
//    // Check if power-up has expired and reset if necessary
//    if (speedBoostActive && currentTime - speedBoostTimer > powerupDuration) {
//        resetPowerUp();
//    }
//
//    if (extendedRangeActive && currentTime - extendedRangeTimer > powerupDuration) { 
//         resetPowerUp(); 
//    }
//
//    if (immunityActive && currentTime - immunityTimer > powerupDuration) {
//        resetPowerUp();   
//    }
//
//    // Respawn power-up after some time
//    if (GetTickCount64() - powerUpTimer > 10000) spawnPowerUp();  
//}
//
//void resetPowerUp() {
//    speedBoostActive = false;
//    extendedRangeActive = false;
//    immunityActive = false;
//    bombRange = 1; // Reset bomb range
//}
//
//
//void handlePlayerDeath() {
//    lives--;  // Deduct a life if conditions are met
//    if (lives > 0) {
//        flashPlayer();  
//        board[a][b] = ' '; 
//        a = 1;
//        b = 1;  
//        board[a][b] = 'P'; 
//    }
//    else {
//        gameOver();  // End the game if lives are 0
//    }
//}
//
//// Function to gameover screen
//void gameOver() {
//    clearScreen();
//    wcout << L"\n\n\n\n\t\t\t\t   GAME OVER ☠\n\n";
//    cout << "\t\t\t      Better luck next time!\n\n";
//    cout << "\t\t\t   -- X to go back to the menu --" << endl;
//    cout << "\t\t\t   -- Q to quit the game --" << endl;
//    playSound("Game over.wav");
//    while (true) {
//        if (_kbhit()) { 
//            char ch = _getch(); 
//
//            if (ch == 'X' || ch == 'x') {
//                system("cls");
//                stageCheck = true;
//                moveToStage1();
//                return; 
//            }
//            else if (ch == 'Q' || ch == 'q') {
//                cout << "Exiting......." << endl; 
//                exit(0);  
//            }
//        }
//    }
//}
//
//void checkCollisionWithBomb(int explosionRow, int explosionCol) {
//    if (a == explosionRow && b == explosionCol && !immunityActive) {
//        handlePlayerDeath();
//    }
//}
//
//
//// Function to count the number of enemies on the grid
//void countEnemies() {
//    totalEnemies = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (board[i][j] == 'E') {
//                totalEnemies++;
//            }
//            else if(board[i][j] == 'S')
//            {
//                totalEnemies++;  
//            }
//        }
//    }
//}
//
//// Function to spawn moving blocks
//void spawnMovingBlocks(int count) {
//    for (int i = 0; i < count; i++) 
//    {
//        if (numMovingBlocks >= maxBlocks) break;
//
//        int row, col;
//        bool validPosition = false;
//
//        while (!validPosition) {
//            row = rand() % (m - 2) + 1;
//            col = rand() % (n - 2) + 1; 
//
//           
//            validPosition = (board[row][col] == ' ' &&
//                !(row == a && col == b) &&            
//                !(row == a - 1 && col == b) &&       
//                !(row == a + 1 && col == b) &&       
//                !(row == a && col == b - 1) &&       
//                !(row == a && col == b + 1));        
//        }
//
//        board[row][col] = '=';  // Place the moving block
//        blockRows[numMovingBlocks] = row;
//        blockCols[numMovingBlocks] = col; 
//        numMovingBlocks++; 
//    }
//}
//
//// Function to spawn special enemies
//void spawnSpecialEnemies(int count) {
//    for (int i = 0; i < count; i++)
//    {
//        int row, col;
//        bool validPosition = false;
//
//        while (!validPosition) {
//            row = rand() % (m - 2) + 1; 
//            col = rand() % (n - 2) + 1;
//
//          
//            validPosition = (board[row][col] == ' ' &&
//                !(row == a && col == b) &&            
//                !(row == a - 1 && col == b) &&      
//                !(row == a + 1 && col == b) &&       
//                !(row == a && col == b - 1) &&        
//                !(row == a && col == b + 1));        
//        }
//
//        board[row][col] = 'S'; // Place special enemy
//    }
//}
//
//
//void handleSpecialBomb() {
//
//    if (specialBombActive && GetTickCount64() - specialBombTimer >= 1500) {
//        for (int i = specialBombRow - bombRange; i <= specialBombRow + bombRange; i++) {
//            for (int j = specialBombCol - bombRange; j <= specialBombCol + bombRange; j++) {
//                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] != '#' && board[i][j] != '|' && board[i][j] != '-' && board[i][j] != '$' && board[i][j] != 'I' && board[i][j] != '+' && board[i][j] != '=') {
//                    if (board[i][j] == 'P' && !immunityActive) {
//                        flashPlayer();
//                        handlePlayerDeath(); // Damage player if hit
//                    }
//                    playSound("Bomb explosion.wav");    
//                    board[i][j] = '!';
//                }
//            }
//        }
//        displayBoard();
//        Sleep(300);
//
//        // Clear explosion and reset special bomb
//        for (int i = specialBombRow - bombRange; i <= specialBombRow + bombRange; i++) {
//            for (int j = specialBombCol - bombRange; j <= specialBombCol + bombRange; j++) {
//                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == '!') {
//                    board[i][j] = ' ';
//                }
//            }
//        }
//        specialBombActive = false; 
//    }
//}
//
//// Function to move moving-blocks
//void moveBlocks() {
//    for (int i = 0; i < numMovingBlocks; i++) {
//        int row = blockRows[i];
//        int col = blockCols[i];
//        int newRow = row, newCol = col;
//
//        // Try to move to a random adjacent space
//        int direction = rand() % 4;
//        switch (direction) {
//        case 0: newRow = row - 1; break; // Up
//        case 1: newRow = row + 1; break; // Down
//        case 2: newCol = col - 1; break; // Left
//        case 3: newCol = col + 1; break; // Right
//        }
//
//       
//        if (newRow > 0 && newRow < m - 1 && newCol > 0 && newCol < n - 1 &&
//            board[newRow][newCol] == ' ') {
//            board[row][col] = ' '; 
//            board[newRow][newCol] = '='; 
//            blockRows[i] = newRow; 
//            blockCols[i] = newCol;
//        }
//    }
//}
//
//// Function to high score screen
//void highScore()
//{
//    clearScreen();
//    cout << "\t\t\t      High Scores \n";
//    cout << "\t\t\t   -- X to go back to the menu --" << endl;
//
//    while (true) {
//        if (_kbhit()) { 
//            char ch = _getch(); 
//
//            if (ch == 'X' || ch == 'x') {
//                system("cls");
//                stageCheck = true;
//                moveToStage1();
//                return; 
//            }
//        }
//    }
//}
//
//
//// Function for stage 1
//void  moveToStage1()
//{
//    pos = 7;  
//    bombRow = -1;
//    bombCol = -1;
//    enemyCounter = 0;
//    senemyCounter = 0;
//    powerupAvailable = true;
//    score = 0;
//    currentStage = 1;
//    lives = 3;
//   
//    hideCursor();
//    showMenu();
//    intBoard();
//    a = 1, b = 1;
//    board[a][b] = 'P';
//    spawnPowerUp();
//    spawnEnemies(3);
//    displayBoard();
//    srand(time(NULL));
//
//    while (true) {
//
//        clearScreen();  
//        displayBoard(); 
//
//        char input = 'G';
//        if (_kbhit()) {
//            input = _getch();
//            if (input == 'Q' || input == 'q') exit(0);
//
//            if (input == ' ') {
//                placeBomb(a, b); 
//            }
//            else {
//                move(input);
//            }
//        }
//
//        handleTimers();  
//
//
//        if (bombActive && GetTickCount64() - bombTimer >= 1500) {
//            explodeBomb();  
//        }
//
//        Sleep(speedBoostActive ? 50 : 100);
//
//        if (enemyCounter >= 10000) {
//            enemyCounter = 0;
//        }
//
//        if (enemyCounter % 4 == 0) {
//            moveEnemies();
//        }
//        enemyCounter++;
//        countEnemies();
//
//        // Check if all enemies are destroyed and move to stage 2
//        if (totalEnemies == 0) {
//            break;
//        }
//    }
//
//    system("cls");
//    moveToStage2();
//}
//
//
//
//// Function for stage 2
//void moveToStage2() {
//    
//   
//     powerupAvailable = true; 
//     currentStage = 2;
//     blockMoveTimer = GetTickCount64();
//     score += 100;  // Add bonus score for moving to the next stage
//     lives = 3;
//     playSound("Next level.wav");
//     hideCursor();
//     srand(time(NULL));  
//     intBoard(); 
//     a = 1, b = 1;
//     board[a][b] = 'P';
//     spawnPowerUp();    
//     spawnMovingBlocks(5);
//     spawnEnemies(4);
//     displayBoard();
//
//    
//     while (true) {
//
//         clearScreen();   
//         displayBoard();  
//
//         char input = 'G';
//         if (_kbhit()) {
//             input = _getch();
//             if (input == 'Q' || input == 'q') return;
//
//             if (input == ' ') {
//                 placeBomb(a, b); 
//             }
//             else {
//                 move(input);
//             }
//         }
//
//         handleTimers(); 
//
//
//         if (bombActive && GetTickCount64() - bombTimer >= 1500) {
//             explodeBomb();  
//         }
//
//         Sleep(speedBoostActive ? 50 : 100);
//
//         if (enemyCounter >= 10000) {
//             enemyCounter = 0;
//         }
//
//         if (enemyCounter % 3 == 0) {
//             moveEnemies();
//         }
//         enemyCounter++;
//         countEnemies();
//
//         if (GetTickCount64() - blockMoveTimer > blockMoveInterval) {
//             moveBlocks();
//             blockMoveTimer = GetTickCount64(); 
//         }
//     
//
//         // Check if all enemies are destroyed and move to stage 3
//         if (totalEnemies == 0) {
//             break;  
//         } 
//     }
//     system("cls");
//     moveToStage3(); 
//}
//
//// Function for stage 3
//void moveToStage3() {
//
//   
//    powerupAvailable = true;  
//    pos = 6;
//    currentStage = 3;
//    blockMoveTimer = GetTickCount64(); 
//    score += 100;  // Add bonus score for moving to the next stage
//    lives = 4;  
//    playSound("Next level.wav");
//    hideCursor();
//    srand(time(NULL));
//    intBoard();
//    a = 1, b = 1;
//    board[a][b] = 'P';
//    spawnPowerUp();   
//    spawnMovingBlocks(7);
//    spawnEnemies(2);
//    spawnSpecialEnemies(3);
//    displayBoard();
//
//  
//    while (true) {
//
//        clearScreen(); 
//        displayBoard(); 
//
//        char input = 'G';
//        if (_kbhit()) {
//            input = _getch();
//            if (input == 'Q' || input == 'q')  return;
//
//            if (input == ' ') {
//                placeBomb(a, b); 
//            }
//            else {
//                move(input); 
//            }
//        }
//
//        handleTimers(); 
//
//        if (bombActive && GetTickCount64() - bombTimer >= 1500) {
//            explodeBomb(); 
//        }
//
//        handleSpecialBomb();
//
//        Sleep(speedBoostActive ? 50 : 100);
//
//        if (enemyCounter >= 10000) {
//            enemyCounter = 0;
//        }
//
//       
//        if (enemyCounter % 3 == 0) {
//            moveEnemies();
//        }
//
//        enemyCounter++;
//        countEnemies();
//
//        if (GetTickCount64() - blockMoveTimer > blockMoveInterval) {
//            moveBlocks();
//            blockMoveTimer = GetTickCount64();
//        }
//
//
//        // Check if all enemies are destroyed and move to win screen
//        if (totalEnemies == 0) {
//            system("cls");
//            win();
//            return;
//        }
//    }
//}
//
//// Function for win screen
//void win()
//{
//    clearScreen();
//    wcout << L"\n\n\n\n\t\t\t\t   YOU WIN :)\n\n";
//    cout << "\t\t\t   -- X to go back to the menu --" << endl;
//    cout << "\t\t\t   -- Q to quit the game --" << endl;
//    playSound("Win.wav");
//
//    while (true) {
//        if (_kbhit()) {
//            char ch = _getch();
//
//            if (ch == 'X' || ch == 'x') {
//                system("cls");
//                stageCheck = true;
//                moveToStage1();
//                return;
//            }
//            else if (ch == 'Q' || ch == 'q') {
//                cout << "Exiting......." << endl;
//                exit(0);
//            }
//        }
//    }
//}