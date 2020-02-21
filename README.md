# storyboard
Storyboard application with functionalities too add/delete/search of a Note
StoryBoard application v2
Ahmet Samet Celebi 02/02/2020


/////HOW TO COMPILE/////
#For storyboard itself:
	-Files:
		-Main.cpp
		-Notes.h
		-StoryBoard.cpp
		-StoryBoard.h
		-UserInterface.cpp
		-UserInterface.h
		
	-Command for g++:(from the source codes' directory)
		g++ Main.cpp Notes.h StoryBoard.cpp StoryBoard.h UserInterface.h UserInterface.cpp -o storyboard.exe
		
#For test:
	-Files:
		-Test.cpp
		-Test.h
		-Notes.h
		-StoryBoard.cpp
		-StoryBoard.h		
		-UserInterface.cpp
		-UserInterface.h
		
	-Command for g++:(from the source codes' directory)
		g++ Test.cpp Test.h Notes.h StoryBoard.cpp StoryBoard.h UserInterface.h UserInterface.cpp -o test.exe


/////DESCRIPTION of STORYBOARD/////
-----------------------------------
A program that handles a story board to be used for notes.

After openning the application a menu will be displayed to enter a menu number.
Press ENTER after each time input your selection(also after each piece of text).

Menu
----
1- Adds a new note to the storyboard by entering a line of title, tag, text.
Whitespace is allowed. Tags with several words are split and stored as separate tags.

2- Deletes a note from the storyboard by searching the title of the note.
It shows the note before deleting.

3- Search by title. Exact match(including all whitespaces) is necessary. 
Displays the note when search result is positive.

4- Search by tag. Only one tag entry is necessary. 
Displays the note when search result is positive.

5- Search by text. Exact match(including all whitespaces) is necessary. 
Displays the note when search result is positive.

6- Displays the amount of notes currently in the Story Board.

7- Displays the all stored notes currently in the Story Board.

0- Quits storyboard.

/////DESCRIPTION of TEST/////
-----------------------------

Testing StoryBoard with premade test strings, vectors and Notes.
After execution it automatically perform the tests showing the results and the success rate.
