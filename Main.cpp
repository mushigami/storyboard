//============================================================================
// Name        : Main.cpp
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : main function call file of StoryBoard Project
//============================================================================

#include <iostream>
#include <vector>
#include <string>

#include "StoryBoard.h"
#include "UserInterface.h"



int main() {

	//Variable initializations
	StoryBoard storyBoard;
	Notes buff_note, inputNote;
	unsigned selection{ 99 };
	std::string inputText{ "" };
	int validInput[] = {0,1,2,3,4,5,6,7};
	showMainMenu(); // Show menu on the screen
	
	do
	{
		system("CLS"); //Clear screen (Windows only)
		showMainMenu();
		selection = GetInteger("\nPlease input a num (0 - 7): ", "Wrong input", validInput, 8);
		storyBoard.processSelection(selection, buff_note);
		system("pause"); //Wait for key press (Windows only)
	}
	while (selection);
	showQuitMessage();

	return 0;
}
