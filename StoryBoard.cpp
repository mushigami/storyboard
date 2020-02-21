//============================================================================
// Name        : StoryBoard.cpp
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : StoryBoard functions' definition file of StoryBoard Project
//============================================================================


#include "StoryBoard.h"
#include "UserInterface.h"


StoryBoard::StoryBoard(){
	//std::cout << "Storyboard is created" << std::endl; //commented out not to have multiple messages on the screen
}

//Selector
void StoryBoard::processSelection(unsigned selection, Notes buff_note) {

	std::string inputText{ "" };
	switch (selection) {
	case 1: //addNote
	{
		std::vector<std::string> inputVector;
		inputVector = getTitleTagText();
		buff_note = StoryBoard::addNote(buff_note, inputVector);
		StoryBoard::pushNote(buff_note);
		StoryBoard::printNote(buff_note);
		break;
	}
	case 2: //DeletebyTitle
	{
		inputText = getString("Enter a title: ", "error");
		buff_note = StoryBoard::searchNoteByTitle(inputText);
		StoryBoard::printNote(buff_note);
		StoryBoard::deleteNote(buff_note);
		break;
	}

	case 3: //SearchbyTitle
	{
		inputText = getString("Enter a title: ", "error");
		buff_note = StoryBoard::searchNoteByTitle(inputText);
		StoryBoard::printNote(buff_note);
		break;
	}
	case 4: //SearchbyTag
	{
		inputText = getString("Enter a tag: ", "error");
		buff_note = StoryBoard::searchNoteByTag(inputText);
		StoryBoard::printNote(buff_note);
		break;
	}
	case 5: //SearchbyText
	{
		inputText = getString("Enter a text: ", "error");
		buff_note = StoryBoard::searchNoteByText(inputText);
		StoryBoard::printNote(buff_note);
		break;
	}

	case 6: {
		std::cout << "Size of the storyboard is: " << m_storyBoard.size() << std::endl;
		break;
	}

	case 7: {
		std::cout << "All stored notes: "<<std::endl;
		StoryBoard::showAllNotes();
		std::cout<< std::endl;
		break;
	}
		
	

	default:
		break;
	}
}
void StoryBoard::printNote(Notes note){
	std::cout<<"	+-------------------------------------------------+"<< std::endl;
	std::cout<<"	 Title:"<< note.title<<std::endl;
	std::cout<<"	 Tag:" ;
	for (unsigned i = 0; i < note.tag.size(); ++i)
	{
		std::cout<<note.tag[i]<< std::left<< " ";
	}			
	std::cout<<std::endl;
	std::cout<<"	 Text:"<< note.text<< std::endl;
	std::cout<<"	+-------------------------------------------------+"<< std::endl;
}
Notes StoryBoard::returnNote(unsigned index){
	std::vector<Notes> storyBoardVector;
	for (const auto& i : m_storyBoard)
		storyBoardVector.push_back(i);
	return storyBoardVector[index];
}
unsigned StoryBoard::returnSize(){
	return m_storyBoard.size();
}

//Search functions
Notes StoryBoard::searchNoteByTitle(std::string inputText) {

	Notes buff_note;
	unsigned foundFlag{ 2 };

	for (unsigned i = 0; i < m_storyBoard.size(); ++i)
	{
		if (inputText == m_storyBoard[i].title)
		{
			std::cout << "\nFound it" << std::endl;
			buff_note = m_storyBoard[i];//for multiple hits what to do?
			foundFlag = 1;
			break;
		}
		else foundFlag = 0;
	}

	if (foundFlag == 0) std::cout << "Nothing here" << std::endl;

	return buff_note;
}
Notes StoryBoard::searchNoteByTag(std::string inputText) {

	Notes buff_note;
	unsigned foundFlag{ 2 };

	for (unsigned i = 0; i < m_storyBoard.size() && foundFlag != 1 ; ++i)
	{
		for (unsigned j = 0; j < m_storyBoard[i].tag.size(); ++j)
		{
			if (inputText == m_storyBoard[i].tag[j])
			{
				std::cout << "\nFound it" << std::endl;
				buff_note = m_storyBoard[i]; //for multiple hits what to do?
				foundFlag = 1;
				break;
			}
			else foundFlag = 0;
		}
	}

	if (foundFlag == 0) std::cout << "Nothing here" << std::endl;

	return buff_note;
}
Notes StoryBoard::searchNoteByText(std::string inputText) {

	Notes buff_note;
	unsigned foundFlag{ 2 };
	for (unsigned i = 0; i < m_storyBoard.size(); ++i)
	{
		if (inputText == m_storyBoard[i].text)
		{
			std::cout << "\nFound it" << std::endl;//for multiple hits what to do?
			buff_note = m_storyBoard[i];
			foundFlag = 1;
			break;
		}
		else foundFlag = 0;
	}

	if (foundFlag == 0) std::cout << "Nothing here" << std::endl;
	
	return buff_note;
}

//Note modification functions
std::string StoryBoard::addToTitle(Notes note, std::string inputText) {
	note.title = inputText;
	return note.title;
}
std::vector<std::string>  StoryBoard::addToTag(Notes note, std::string inputText) {
	std::string buf;
	std::stringstream ss(inputText);

	while (ss >> buf)
		note.tag.push_back(buf);
	return note.tag;
}
std::string StoryBoard::addToText(Notes note, std::string inputText) {
	note.text = inputText;
	return note.text;
}
Notes StoryBoard::addToNote(Notes note, std::string temp_title, std::string temp_tag, std::string temp_text) {

	note.title = StoryBoard::addToTitle(note, temp_title);
	note.tag = StoryBoard::addToTag(note, temp_tag);
	note.text = StoryBoard::addToText(note, temp_text);


	return note;
}

//Storyboard modification functions

void StoryBoard::pushNote(Notes inputNote){
	m_storyBoard.push_back(inputNote);
}
Notes StoryBoard::addNote(Notes buff_note, std::vector<std::string> inputVector){
	Notes inputNote;

	//Add text to note title
	inputNote.title = StoryBoard::addToTitle(buff_note, inputVector[0]);
	inputNote.tag = StoryBoard::addToTag(buff_note, inputVector[1]);
	inputNote.text = StoryBoard::addToText(buff_note, inputVector[2]);

	return inputNote;
}
void StoryBoard::deleteNote(Notes deleted_note) {
	for (unsigned i = 0; i < m_storyBoard.size(); ++i)
	{
		if (deleted_note == m_storyBoard[i])
		{
			m_storyBoard.erase(m_storyBoard.begin() + i);
		}
	}
}


void StoryBoard::showAllNotes()
{
	for(int i=0; i< m_storyBoard.size(); ++i)
	{
		StoryBoard::printNote(m_storyBoard[i]);
		std::cout<<std::endl;
	}
}



