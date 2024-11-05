Bird-Obstacle-Game (Mini Project)


Overview
This is a simple C++ implementation of the classic Flappy Bird game, where the player controls a bird and navigates through randomly generated pipes to score points. The game uses the graphics.h library to render game elements and animate gameplay. This project demonstrates basic concepts of game development, such as collision detection, score tracking, and user interaction.


How to Play
Objective: Guide the bird through as many pipes as possible without hitting any obstacles. Each set of pipes passed successfully awards one point.
Controls:
Press the spacebar to make the bird jump.
Gravity continuously pulls the bird down, so you’ll need to time your jumps to keep it airborne.
Game Over: The game ends if the bird hits a pipe or goes out of the screen’s vertical boundaries. The final score will be displayed on the screen.


Features
Player-Controlled Bird: The bird’s vertical movement is controlled by the player, with gravity acting on it at all times.
Dynamic Pipe Generation: Pipes are randomly generated at varying heights to create unique challenges in each game session.
Score Display: The current score is displayed during gameplay, and the final score is shown on the Game Over screen.
Collision Detection: The game detects collisions between the bird and the pipes or screen boundaries, ending the game if a collision is detected.


Code Structure
Bird Struct: Represents the player-controlled bird, storing its position and velocity.
Pipe Struct: Represents each pair of pipes, storing the position and gap.
drawBird(Bird bird): Renders the bird at its current position.
drawPipe(Pipe pipe): Renders the pipes based on their current position and height.
checkCollision(Bird bird, Pipe pipe): Checks for collisions between the bird and the pipes or screen boundaries.
displayInstructions(): Shows the game instructions at the start of the game.


Dependencies
To compile and run this code, you need:
graphics.h: The code uses the graphics.h library, typically found in the Turbo C++ environment or compatible setups. If using a modern compiler like g++, you might need to set up graphics libraries compatible with your system.


Compilation and Execution
To compile this project on Windows using g++, use the following command:


g++ bird.cpp -o bird.exe -lgraph
Then, run the executable:
./bird.exe
Future Enhancements
This mini-project could be further improved with features like:

Adding sound effects for jumps and collisions.
Increasing difficulty with higher speeds as the score increases.
Implementing a start menu and replay option.
