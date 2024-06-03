#include <iostream>
#include <conio.h> 
// For _getch(), this allows us to take one key input 

using namespace std;


struct Car {
    int position;
    int points;
};

struct RacingTrack {
    int trackLength;
};

void displayRaceTrack(Car& car1, Car& car2, int trackLength) {
    cout << "Racing Track: ";
    //print loop for car track along w cars
    for (int i = 0; i < trackLength; ++i) {
        if (i == car1.position) {
            cout << "[1]"; 
        } else if (i == car2.position) {
            cout << "[2]";
        } else {
            cout << "-"; 
        }
    }
cout << endl;

    cout << "Car 1 - Position: " << car1.position + 1 << " Points: " << car1.points << endl;
    cout << "Car 2 - Position: " << car2.position +  1<< " Points: " << car2.points << endl;
      cout<< "Press 'Q' to Quit \n";
}

Car adjustCar1(Car& car, RacingTrack& racingTrack, char userInput) {
    if (userInput == 'a') {
        // Move Car 1 to the left and adjust points
        car.position = max(0, car.position - 1);
        car.points -= 10;
    } else if (userInput == 'd') {
        // Move Car 1 to the right and adjust points
        car.position = min(racingTrack.trackLength - 1, car.position + 1);
        car.points += 10;
    }


    car.points = max(0, min(car.points, 300));

    return car;
}

Car adjustCar2(Car& car, const RacingTrack& racingTrack, char userInput) {
    if (userInput == 'j') {
        // Move Car 2 to the left and adjust points
        car.position = max(0, car.position - 1);
        car.points -= 10;
    } else if (userInput == 'l') {
        // Move Car 2 to the right and adjust points
        car.position = min(racingTrack.trackLength - 1, car.position + 1);
        car.points += 10;
    }

    // Ensure points don't go below 0 or above 300
    car.points = max(0, min(car.points, 300));

    return car;
}

int main() {
    // Initialize the racing track
    RacingTrack racingTrack;
    racingTrack.trackLength = 30;

    // Initialize cars
    Car car1, car2;

    char userInput;

    // Game loop
    while (true) {
        // Display the race track
        displayRaceTrack(car1, car2, racingTrack.trackLength);

        // Get user input
        userInput = _getch();

        // Adjust the position and points for the respective car based on user input
        if (userInput == 'q') {
            // Quit the game if 'q' is pressed
            cout << "Quitting the game. Thanks for playing!" << endl;
            break;
        }

        car1 = adjustCar1(car1, racingTrack, userInput);
        car2 = adjustCar2(car2, racingTrack, userInput);

      

        // Clear the console screen (for Windows)
        system("cls");
    }

    return 0;
}



