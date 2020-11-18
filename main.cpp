#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

constexpr int FIELD_WIDTH = 10;
constexpr int FIELD_HEIGHT = 10;


int main() {
    //srand(unsigned(std::time(0)));
    
    const  int treasureX = rand() % FIELD_WIDTH;
    const  int treasureY = rand() % FIELD_HEIGHT;

    cout << "Treasure is here: " << treasureX << ", " << treasureY << endl;

    int pirateX = 0, pirateY = 0;
    std::string pirateName;
    char inputDirection;

    cout << "Hello, stranger! What is your name ? : ";
    cin >> pirateName;

    cout << "Welcome on Island,   " << pirateName << endl;
    cout << "You can walk around using 'w', 's', 'a', 'd' keys\n";

    bool isGameRunning = true;
    while (isGameRunning)
    {
        cout << "Choose your direction: ";
        cin >> inputDirection;

        switch (inputDirection)
        {
        case 'w':
        {
            pirateY++; // up
           if (pirateY > FIELD_HEIGHT) {
                pirateY = 0;
                }
            //pirateY = (10 + pirateY) % 10; // гарантирует, что всгда будем в промежутке 0 - 10
            break;
        }
        case 's':
        {
            pirateX--; // left
            if (pirateX <0) {
                pirateX = FIELD_WIDTH;
            }
            break;
        }
        case 'a':
        {
            pirateY--; // down
            if (pirateY <0) {
                pirateY = FIELD_HEIGHT;
            }
            break;
        }
        case 'd':
        {
            pirateX++; // right
            if (pirateX > FIELD_WIDTH) {
                pirateX = 0;
            }
            break;
        }
        case 'q': //game over
            cout << "Are you tired? Understand. See you. " << endl;
            isGameRunning = false;
            continue;
        
        default:
            break;
    }
    

    cout << endl << pirateName << ", you are at[" << pirateX << " " << pirateY << " " << endl;

        if (treasureX == pirateX && treasureY == pirateY) {
               cout << "You've found he treasure!" << endl;
               isGameRunning = false;
           }
           else {
                  cout << "Not here, looser!" << endl;
           }
    }
            
    system("pause");
}