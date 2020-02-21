//============================================================================
// Name        : Test.cpp
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : StoryBoard test functions' definition file of StoryBoard Project
//============================================================================

#include "Test.h"


int main()
{
	std::cout << "test starting" << std::endl;
	std::cout << "Storyboard testing is starting ... " << "\n\n\t\tTest List"<<std::endl;
	
	std::cout << "01- ";
	test_addToTitle(test_string_1);

	std::cout << "02- ";
	test_addToTag(test_string_1, test_vector_1);

	std::cout << "03- ";
	test_addToText(test_string_1);

	std::cout << "04- ";
	test_addToNote(test_note_1, test_string_1, test_string_2, test_string_3);

	std::cout << "05- ";
	test_addNote(test_note_3, test_vector_3);

	std::cout << "06- ";
	test_pushNote(test_note_1);

	std::cout << "07- ";
	test_deleteNote(test_note_1, test_note_2);

	std::cout << "08- ";
	test_searchByTitle(test_note_1, test_string_1);

	std::cout << "09- ";
	test_searchByTag(test_note_1, test_vector_1);

	std::cout << "10- ";
	test_searchByText(test_note_1, test_string_2);

	test_showResults();
	
	std::cout << "test ended" << std::endl;
	std::cin.get();
	std::cin.ignore();
	return 0;
}


void test_showResults()
{
	std::cout << "\nIn total " << testCount << " number of tests performed" << std::endl;
	std::cout << "Test success ratio is " << static_cast<double>(testCount - failCount) / testCount * 100 << "%." << std::endl;
}

void test_addToTitle(const std::string & string_1)
{
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard

	outputNote.title = test_StoryBoard.addToTitle(emptyNote, string_1);//simulate function

	if (outputNote.title == string_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToTitle test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{	
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToTitle test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}
	
}
void test_addToTag(const std::string & string_1, const std::vector<std::string> & vector_1)
{
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard

	std::string buf;
	std::stringstream ss(string_1);

	while (ss >> buf)
		outputNote.tag.push_back(buf);

	if (outputNote.tag == vector_1)
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToTag test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToTag test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}
}
void test_addToText(const std::string & string_1)
{
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard

	outputNote.text = test_StoryBoard.addToText(emptyNote, string_1);//simulate function

	if (outputNote.text == string_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToText test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToText test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}

}
void test_addToNote(const Notes & note_1, const std::string & string_1, const std::string & string_2, const std::string & string_3)
{
	
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard
	outputNote = test_StoryBoard.addToNote(emptyNote,string_1,string_2,string_3);	
	
	if (outputNote == note_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addToNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addtoNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< " Failcount: " << failCount 
			<< std::endl;
	}

}
void test_addNote(const Notes & note_1, const std::vector<std::string> & vector_1)
{
	++testCount; //counting how many tests are performed
	Notes outputNote;

	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard

	outputNote = test_StoryBoard.addNote(emptyNote,vector_1);

	if (outputNote == note_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}
	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "addNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< " Failcount: " << failCount 
			<< std::endl;
	}
}

void test_pushNote(const Notes & note_1)
{
	++testCount; //counting how many tests are performed
	Notes outputNote;

	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard

	test_StoryBoard.pushNote(note_1);
	outputNote = test_StoryBoard.returnNote(0);

	if (outputNote == note_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "pushNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}
	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "pushNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}
}
void test_deleteNote(const Notes & note_1, const Notes & note_2)
{
	//uses pushNote function to add a note. 
	++testCount; //counting how many tests are performed
	Notes deletedNote;
	unsigned oldSize{ 0 }, newSize{ 0 };

	test_StoryBoard = empty_StoryBoard;

	test_StoryBoard.pushNote(test_note_1);
	test_StoryBoard.pushNote(test_note_2); 

	oldSize = test_StoryBoard.returnSize();

	test_StoryBoard.deleteNote(test_note_1);
	
	newSize = test_StoryBoard.returnSize();
	if (oldSize == (newSize + 1) )
		{
			std::cout
				<< std::setw(20)
				<< std::left
				<< std::setfill('-')
				<< "deleteNote test ";
			std::cout
				<< std::setw(20)
				<< std::setfill('-')
				<< std::right
				<< " OK"
				<< std::endl;
		}
	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "deleteNote test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}

}

void test_searchByTitle(const Notes & note_1, const std::string & string_1)
{
	//uses pushNote function to add a note. 
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard
	test_StoryBoard.pushNote(note_1);
	
	std::streambuf* orig_buf = std::cout.rdbuf();//get buffer(to suppress cout messages of original function)
	std::cout.rdbuf(NULL);//make null (to suppress cout messages of original function)

	outputNote = test_StoryBoard.searchNoteByTitle(string_1);

	std::cout.rdbuf(orig_buf);//make normal (to suppress cout messages of original function)

	if (outputNote == note_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "searchByTitle test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "searchByTitle test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}
}
void test_searchByTag(const Notes & note_1, const std::vector<std::string> & vector_1)
{
	//uses pushNote function to add a note. 
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard
	test_StoryBoard.pushNote(note_1);

	std::streambuf* orig_buf = std::cout.rdbuf();//get buffer(to suppress cout messages of original function)
	std::cout.rdbuf(NULL);//make null (to suppress cout messages of original function)

	outputNote = test_StoryBoard.searchNoteByTag(vector_1[2]);

	std::cout.rdbuf(orig_buf);//make normal (to suppress cout messages of original function)

	if (outputNote == note_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "searchByTag test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "searchByTag test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<< std::endl;
	}


}
void test_searchByText(const Notes & note_1, const std::string & string_1)
{
	//uses pushNote function to add a note. 
	++testCount; //counting how many tests are performed
	Notes outputNote;
	outputNote = emptyNote; //clear the result note
	test_StoryBoard = empty_StoryBoard;  //clear the storyboard
	test_StoryBoard.pushNote(note_1);

	std::streambuf* orig_buf = std::cout.rdbuf();//get buffer(to suppress cout messages of original function)
	std::cout.rdbuf(NULL);//make null (to suppress cout messages of original function)

	outputNote = test_StoryBoard.searchNoteByText(string_1);

	std::cout.rdbuf(orig_buf);//make normal (to suppress cout messages of original function)

	if (outputNote == note_1)//expected result
	{
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "searchByText test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " OK"
			<< std::endl;
	}

	else
	{
		++failCount;//counting how many tests are failed
		std::cout
			<< std::setw(20)
			<< std::left
			<< std::setfill('-')
			<< "searchByText test ";
		std::cout
			<< std::setw(20)
			<< std::setfill('-')
			<< std::right
			<< " FAIL"
			<<std::endl;
	}
}