#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <string>
using namespace std;


int senseDistance();
void getSensors(int sensors[]);
void printSensors(int sensors[], string labels[]);
int furthest(int sensors[]);


int main() {
    int sensors[4];  
    string labels[4]; 
    int dir;  
    srand(time(NULL)); 

    labels[0] = "north";  
    labels[1] = "west";
    labels[2] = "south";
    labels[3] = "east";

    for (int i = 0; i < 5; i++) { 
        getSensors(sensors);  
        printSensors(sensors, labels);  
        dir = furthest(sensors);
		cout<< endl;   
        cout << " robot is moving " << labels[dir] << endl << endl;  
    }  
    return 0;
}
    int senseDistance() {

    return rand() % 101;  
}


void getSensors(int sensors[]) {
    for (int i = 0; i < 4; i++) {
        sensors[i] = senseDistance(); 
    }
}

void printSensors(int sensors[], string labels[]) {
    cout << "sensors=[";
    for (int i = 0; i < 4; i++) {
        cout << labels[i] << "=" << sensors[i];
        if (i < 3) {
            cout << "][";  
        }
    }
    cout << "]" << endl;
}


int furthest(int sensors[]) {
    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (sensors[i] > sensors[maxIndex]) {
            maxIndex = i;  
        }
    }
    return maxIndex;
}
