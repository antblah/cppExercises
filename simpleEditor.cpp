/*
* File: SimpleTextEditor.cpp
* -------------------------------------------------------
* This file implements a very basic command-line text editor
*/

#include <cctype>
#include <iostream>
#include "buffer.h"
#include "simpio.h"
#include "foreach.h"
using namespace std;


/* Function Prototypes */
void executeCommand(EditorBuffer & buffer, string line);
void displayBuffer(EditorBuffer & buffer);
void printHelpText();

/*
* Function:  Execute Command
* -------------------------------------------------------
* Executes the commands as specified by the buffer
*/

void executeCommand(EditorBuffer & buffer, string line) {
    switch(toupper(line[0])) {
        case 'I': foreach(char ch in line) {
            buffer.insertCharacter(ch);
        }
        displayBuffer(buffer);
        break;
        case 'D': deleteCharacter(); displayBuffer(buffer);
        case 'F': moveCursorForward(); displayBuffer(buffer);
        case 'B': moveCursorBackward(); displayBuffer(buffer);
        case 'J': moveCursorToStart(); displayBuffer(buffer);
        case 'E': moveCursorToEnd(); displayBuffer(buffer);
        case 'H': printHelpText(); break;
        case 'Q': exit(0);
        default: cout << "Illegal entry."  << endl; break; 
    }
}

/*
* Function: displayBuffer
* -------------------------------------------------------
* Displays the state of the buffer including the position of the cursor.
*/
void displayBuffer(EditorBuffer & buffer) {
    string str = buffer.getText();
    for(int i = 0; i < str.length(); i++) {
        cout << " " << str[i];
    }
    cout << endl;
    cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}


/*
* Function: printHelpText
* -------------------------------------------------------
* Displays execution command help text to the user.
*/

void printHelpText() {
    cout << "Editor commands: " << endl;
    cout << "Iabc...: Inserts the characters abc at the cursor position." << endl;
    cout << "F: Moves the cursor one position forward." << endl;
    cout << "B: Moves the cursor one position backward." << endl;
    cout << "D: Deletes the character after the cursor." << endl;
    cout << "J: Jumps to the beginning of the buffer." << endl;
    cout << "E: Jumps to the end of the buffer." << endl;
    cout << "H: Brings up this Help menu." << endl;
    cout << "Q: Exits the editor program." << endl;
}



int main() {

    return 0;
}
