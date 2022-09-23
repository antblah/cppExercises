/*
* File: buffer
* -------------------------------------------------------
* This file defines the interface for the Simple Editor
*/


#ifndef _buffer_h
#define _buffer_h

/*
* Class EditorBuffer
* -------------------------------------------------------
* 
*/

class EditorBuffer {
    
public:

/*
* Constructor: EditorBuffer
* -------------------------------------------------------
* Basic Constructor which instantiates EditorBuffer object
*/

EditorBuffer();

/*
* Destructor: EditorBuffer
* -------------------------------------------------------
* Frees up heap storage allocated to object.  
*/

~EditorBuffer();



/*
* Methods: moveCursorForward; moveCursorBackward;
* -------------------------------------------------------
* 
*/

void moveCursorForward();
void moveCursorBackward();


/*
* Methods: moveCursorToStart; moveCursorToEnd;
* -------------------------------------------------------
* 
*/

void moveCursorToStart();
void moveCursorToEnd();


/*
* Methods: insertCharacter
* -------------------------------------------------------
* 
*/

void insertCharacter(char ch);


/*
* Methods: deleteCharacter
* -------------------------------------------------------
* 
*/

void deleteCharacter();


/*
* Methods: getText
* -------------------------------------------------------
* Returns the content of the buffer to the screen
*/

std::string getText() const;


/*
* Methods: getCursor
* -------------------------------------------------------
* Returns index of the cursor
*/

int getCursor() const;



private:
/*
* Implementation Notes:  Buffer Data Structure
* -------------------------------------------------------
* 
*/


/* Constants */
static const int INITIAL_CAPACITY = 10;


/* Instance Variables */
char *array;        /*  Dynamic array of characters      */
int capacity;       /*  Allocated size of that array     */
int length;         /*  Number of characters in buffer   */
int cursor;         /*  Index of characters after buffer */

/* Make it illegal to copy editor buffer */
EditorBuffer(const EditorBuffer & value) { }
const EditorBuffer & operator = (const EditorBuffer & rhs) {
    return *this;
}

/* Private Method Prototype */

void expandCapacity();

};

#endif