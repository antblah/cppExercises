/*
* Function: buffer.cpp
* -------------------------------------------------------
* 
*/

#include <iostream>
#include "buffer.h"
using namespace std;

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

