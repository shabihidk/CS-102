Racing Program Readme

This racing program is a simple console based racing game written in C++. Below is an explanation of the variable and function names, as well as of their roles in the code.


Variables:

Car Structure:

position (int): The current position of a car on the racing track.

points (int): Stores the points a car has accumulated during the race.

RacingTrack Structure:

trackLength (int): The length of the racing track.

racingTrack (RacingTrack): instance representing the racingTrack.

car1 and car2 (Car): instances representing the two cars racing.

userInput (char): Takes the input for controlling the cars.


Functions:

displayRaceTrack:

Parameters: Car& car1, Car& car2, int trackLength

Description: Displays the current state of the racing track, including the positions of the two cars and their respective points.

adjustCar1:

Parameters: Car& car, RacingTrack& racingTrack, char userInput

Description: Adjusts the position and points for Car 1 based on user input (a for left, d for right). Ensures points stay within the range [0, 300].

adjustCar2:

Parameters: Car& car, const RacingTrack& racingTrack, char userInput

Description: Adjusts the position and points for Car 2 based on user input (j for left, l for right). Ensures points stay within the range [0, 300].

main:

Description: This is the main function where the game loop runs. It initializes the racing track and cars, displays the race track and then goes into the game loop where it continually takes in and processes user input.

Additional Information:

The program uses the _getch() function from the conio.h library to get a single key input.

The game loop continues until user quit by pressing 'q'.