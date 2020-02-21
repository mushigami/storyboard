//============================================================================
// Name        : Test.h
// Author      : Ahmet Samet Celebi
// Version     : v2.0 - 02/02/2020
// Description : StoryBoard test header file of StoryBoard Project
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Notes.h"
#include "StoryBoard.h"





const std::string test_string_1{ "test string 1" };
const std::string test_string_2{ "test string 2" };
const std::string test_string_3{ "test string 3" };

const std::vector<std::string> test_vector_1{ "test", "string", "1" };
const std::vector<std::string> test_vector_2{ "test", "string", "2" };
const std::vector<std::string> test_vector_3{ test_string_1, test_string_2, test_string_3 };

const Notes test_note_1 { test_string_1 , test_vector_1, test_string_2 };
const Notes test_note_2 { test_string_2, test_vector_2, test_string_3 };
Notes test_note_3 { test_string_1, test_vector_2, test_string_3 };

unsigned testCount{ 0 };
unsigned failCount{ 0 };

const Notes emptyNote;
const std::vector<Notes> emptyNotesVector;
const StoryBoard empty_StoryBoard;

StoryBoard test_StoryBoard;

void test_addToTitle(const std::string & string_1);
void test_addToTag(const std::string & string_1, const std::vector<std::string> & vector_1);
void test_addToText(const std::string & string_1);
void test_addToNote(const Notes & note_1, const std::string & string_1, const std::string & string_2, const std::string & string_3);
void test_addNote(const Notes & note_1, const std::vector<std::string> & vector_1);
void test_pushNote(const Notes & note_1);
void test_deleteNote(const Notes & note_1, const Notes & note_2);
void test_searchByTitle(const Notes & note_1, const std::string & string_1);
void test_searchByTag(const Notes & note_1, const std::vector<std::string> & vector_1);
void test_searchByText(const Notes & note_1, const std::string & string_1);
void test_showResults();

