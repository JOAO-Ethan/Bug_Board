#include <vector>
#include <iomanip>
#include <iostream>

#include "Bug.h"
#include "Board.h"

using namespace std;

int displayMenu();

int main() {
    vector<Bug *> bug_vector;
    Board board;
    int choice;
    do {
        choice = displayMenu();
        cout << choice << endl;
        switch (choice) {
            case 1:
                board.clear();
                board.load("../bugs.txt");
                break;
            case 2:
                board.displayBugs();
                cout << endl;
                break;
            case 3: {
                int id;
                cout << "Which bug do you want to find ? ";
                cin >> id;
                board.findBug(id);
                break;
            }
            case 4:
                board.tap();
                break;
            case 5:
                board.displayLifeHistories();
                cout << endl;
                break;
            case 6:
                board.displayAllCells();
                cout << endl;
                break;
            case 7:
                board.run();
                break;
            case 8:
                board.exit();
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    } while (choice != 8);
    return 0;
}

int displayMenu() {
    cout << left << "1. Reload Bug Board (load data from file)" << endl;
    cout << left << "2. Display all Bugs" << endl;
    cout << left << "3. Find a Bug (given an id)" << endl;
    cout << left << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
    cout << left << "5. Display Life History of all Bugs (path taken)" << endl;
    cout << left << "6. Display all Cells listing their Bugs" << endl;
    cout << left << "7. Run simulation (generates a Tap every second)" << endl;
    cout << left << "8. Exit (write Life History of all Bugs to file)" << endl;

    int choice;
    cout << endl << "What is your choice ? ";
    cin >> choice;
    return choice;
}
