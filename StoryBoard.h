//============================================================================
// Name        : StoryBoard.h
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : StoryBoard class definition file of StoryBoard Project
//============================================================================


#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Notes.h"

class StoryBoard
	//A class that Notes are displayed on.
{
private:
	std::vector<Notes> m_storyBoard;

public:

	StoryBoard();

	//Selector
	void processSelection(unsigned selection, Notes buff_note);

	//Print function
	void printNote(Notes note);

	//Return function
	Notes returnNote(unsigned index);
	unsigned returnSize();

	//Search functions
	Notes searchNoteByTitle(std::string inputText);
	Notes searchNoteByTag(std::string inputText);
	Notes searchNoteByText(std::string inputText);
	
	//Note modification functions
	Notes addToNote(Notes note, std::string temp_title, std::string temp_tag, std::string temp_text);
	std::string addToTitle(Notes note, std::string inputText);
	std::string addToText(Notes note, std::string inputText);
	std::vector<std::string> addToTag(Notes note, std::string inputText);

	//Storyboard modification functions
	void pushNote(Notes inputNote);
	Notes addNote(Notes note, std::vector<std::string> inputVector);
	void deleteNote(Notes deleted_note);
	void showAllNotes();

};

