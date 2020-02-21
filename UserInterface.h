//============================================================================
// Name        : UserInterface.cpp
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : StoryBoard UI functions' header file of StoryBoard Project
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//get functions
std::string getString(const char * prompt, const char* error);
unsigned int getSelection();
std::vector<std::string> getTitleTagText();
int GetInteger(const char * prompt, const char* error, const int validInput[], int validInputLength);

//display functions
void showMainMenu();
void showQuitMessage();