//============================================================================
// Name        : UserInterface.cpp
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : StoryBoard UI functions' declaration file of StoryBoard Project
//============================================================================

#include "UserInterface.h"

int GetInteger(const char * prompt, const char* error, const int validInput[], int validInputLength)
{
	int input;
	bool inputFailure;

	const int IGNORE_CHARS = 256;
	do
	{

		inputFailure = false;

		std::cout << prompt;
		std::cin >> input;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
			inputFailure = true;
		}
		else
		{
			for(int i = 0; validInputLength; i++)
			{
				if(input == validInput[i])
				{
					return input;
				}
			}


			std::cout << error << std::endl;
			inputFailure = true;
		}


	}while(inputFailure);

	return -1;

}

std::string getString(const char * prompt, const char* error)
{

	const int IGNORE_CHARS = 256;

	std::string input;
	bool failure;
	std::cin.clear();
	std::cin.ignore(IGNORE_CHARS, '\n');
	do
	{
		failure = false;

		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
			failure = true;
		}

	} while (failure);

	return input;
}

std::vector<std::string> getTitleTagText()
{


	std::vector<std::string> inputVector;
	std::string inputTitle{ "" }, inputTag{ "" }, inputText{ "" };

	inputTitle = getString("Enter a title: ", "error title");
	inputVector.push_back(inputTitle);

	inputTag = getString("Enter tags with spaces: ", "error tag");
	inputVector.push_back(inputTag);

	inputText = getString("Enter a text: ", "error text");
	inputVector.push_back(inputText);

	return inputVector;

}

//Display functions
void showMainMenu() {

	std::cout <<"	+-------------------------------------------------+"<< std::endl;
	std::cout <<"	|                   STORYBOARD                    |"<< std::endl;
	std::cout <<"	+=================================================+"<< std::endl;
	std::cout <<"	| 1. Add a note to the storyboard                 |"<< std::endl;
	std::cout <<"	| 2. Delete a note from the storyboard            |"<< std::endl;
	std::cout <<"	| 3. Search the storyboard by Title               |"<< std::endl;
	std::cout <<"	| 4. Search the storyboard by Tag                 |"<< std::endl;
	std::cout <<"	| 5. Search the storyboard by Text                |"<< std::endl;
	std::cout <<"	| 6. Display number of notes in the storyboard    |"<< std::endl;
	std::cout <<"	| 7. Display all the notes in the storyboard      |"<< std::endl;
	std::cout <<"	| 0. Quit the program                             |"<< std::endl;
	std::cout <<"	+-------------------------------------------------+"<< std::endl;


}

void showQuitMessage()
{
	std::cout << "\nPress ENTER to quit";
	std::cin.get();
	std::cin.ignore();
}