#include "io.h"
#include "graph.h"

// prints the int value in width of fieldWidth
void seneca::printInt(int value, int fieldWidth) {
    cout << value;
    for (int i = 0; i < fieldWidth - intDigits(value); i++) {
        cout << " ";
    }
}
    // if the user enters non digit values, the function will hang in an endless loop.
    int seneca::getInt(int min, int max) {
        int val = min - 1;
        bool done = false;
        while (!done) {
            cin >> val;
            if (val < min || val > max) {
                cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
            }
            else {
                done = true;
            }
        }
        return val;
    }

    // moves the cursor backwards
    void seneca::goBack(int n) {
        for (int i = 0; i < n; cout << "\b", i++);
    }

    // displays the user interface menu
    int seneca::menu(int noOfSamples) {
        line(28);
        cout << "| No Of Samples: ";
        printInt(noOfSamples, 5);
        cout << "     |" << endl;
        line(28);
        cout << "| 1- Set Number of Samples |" << endl;
        cout << "| 2- Enter Samples         |" << endl;
        cout << "| 3- Graphs                |" << endl;
        cout << "| 0- Exit                  |" << endl;
        cout << "\\ >                        /";
        goBack(24);

        return getInt(0, 3);
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void seneca::printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    // draw line
    void seneca::labelLine(int n, const char* label) {
        cout << "+";
        for (int i = 0; i < n - 2; cout << "-", i++);
        cout << "+";
        if (label) {
            goBack(n - 4);
            cout << label;
        }
        cout << endl;
    }

    // draws a line
    void seneca::line(int n) {
        cout << "+";
        for (int i = 0; i < n - 2; cout << "-", i++);
        cout << "+";
        cout << endl;
    }

