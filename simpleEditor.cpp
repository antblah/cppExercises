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


/* Main */
int main() {
    EditorBuffer buffer;
    while(true) {
        string cmd = getLine("*");
        if (cmd != "") executeCommand(buffer, cmd);
    }

    return 0;
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

/*
* Implementation notes:  Constructor and destructor
* -------------------------------------------------------
* 
*/

EditorBuffer::EditorBuffer() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    length = 0;
    cursor = 0;
}

EditorBuffer::~EditorBuffer() {
    delete[] array;
}

/*
* Implementation notes:  moveCursor Methods
* -------------------------------------------------------
* 
*/
void EditorBuffer::moveCursorForward() {
    if(cursor < length) cursor++;
}

void EditorBuffer::moveCursorBackward() {
    if(cursor > length) cursor--;
}

void EditorBuffer::moveCursorToStart() {
    cursor = 0;
}

void EditorBuffer::moveCursorToEnd() {
    cursor = length; 
}


/*
* Implementation notes:  Insertion and Deletion
* -------------------------------------------------------
* 
*/

void EditorBuffer::insertCharacter(char ch) {
    if(cursor == length) expandCapacity();
    for(int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }

    array[cursor] = ch;
    length++;
    cursor++;
}

void EditorBuffer::deleteCharacter() {
    if(cursor < length) {
        for(int i = cursor + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
        length--;
    }
}


/*
* Implementation notes:   Get methods: getText, getCursor
* -------------------------------------------------------
* 
*/

string EditorBuffer::getText() const {
    return string(array, length);
}

int EditorBuffer::getCursor() const {
    return cursor;
}

/*
* Implementation notes:   Expand Capacity
* -------------------------------------------------------
* 
*/

void EditorBuffer::expandCapacity() {
    char *oldarray = array;
    capacity *= 2;
    array = new char[capacity];
    for(int i = 0; i < length; i++) {
        array[i] = oldarray[i];
    }
    delete[] oldarray;
}

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
        case 'D': buffer.deleteCharacter(); displayBuffer(buffer); break;
        case 'F': buffer.moveCursorForward(); displayBuffer(buffer); break;
        case 'B': buffer.moveCursorBackward(); displayBuffer(buffer); break;
        case 'J': buffer.moveCursorToStart(); displayBuffer(buffer); break;
        case 'E': buffer.moveCursorToEnd(); displayBuffer(buffer); break;
        case 'H': printHelpText(); break;
        case 'Q': exit(0);
        default: cout << "Illegal entry."  << endl; break; 
    }
}
