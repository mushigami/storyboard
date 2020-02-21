//============================================================================
// Name        : Notes.h
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : Notes class definition header file of StoryBoard Project
//============================================================================

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Notes
{

public:

	std::string title{ "" };
	std::vector<std::string> tag;
	std::string text{ "" };

	// Notes()
	// {
		// std::string title{ "" };
		// std::vector<std::string> tag;
		// std::string text{ "" };
	// }

	// Notes(std::string inputTitle, std::vector<std::string> inputTag, std::string inputText)
	// {
		// std::string title = inputTitle;
		// std::vector<std::string> tag = inputTag;
		// std::string text = inputText;
	// }


	//Overload equality operator
	bool operator==(const Notes &other) const {
		return  title == other.title ||
			tag == other.tag ||
			text == other.text;
	};

	//Overload assignment operator
	const Notes &operator=(const Notes &other)
	{
		title = other.title;
		tag = other.tag;
		text = other.text;
		return *this;
	};

};