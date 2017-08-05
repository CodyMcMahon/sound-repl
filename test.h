#ifndef shit_test_HHHHHH
#define shit_test_HHHHHH

#include "sound_file.h"
#include "envelope.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

//extern map<string,sound_file*>files_in_memory;
//extern map<string,envelope*>envelopes_in_memory;

//core functions
void REPL_INTRO();
void REPL_OUTRO();
void REPL_QUEUE_INPUT();
void REPL_BAD_FUN();
void REPL_PRINT(string);
void REPL_ERROR(string);
void REPL_SET_PRINTING(int);
void REPL_SET_ERROR_REPORTING(int);
void REPL_PRINT_HELP();

//repl functions
void ld(vector<string>);
void ldenv(vector<string>);
void env(vector<string>);
void sv(vector<string>);
void vol(vector<string>);
void rep(vector<string>);
void rm(vector<string>);
void cp(vector<string>);
void mv(vector<string>);
void vars(vector<string>);
void qt(vector<string>);
void hp(vector<string>);

#endif
