#include "test.h"
#include <iostream>

static int error_reporting = 1;
static int printing = 1;
//HELP TEXT
static string help_string =
R"(---list of functions---

ld: loads .wav into memory
args: file_name, var_name

sv: saves var to .wav file
args: var_name, file_name

vol: multiplys volume of file
args: var_name, multiplier

rep: multiplys the variable X times
args: var_name, X

rm: removes variable from memory
args: var_name

cp: copies var
args: var_name, new_var_name

mv: moves var
args: var_name, new_var_name

vars: prints list of vars
args: NONE

qt: exits REPL
args: NONE

ldenv: loads envelope(.bmp)
args: file_name, env_name

env: performs envelope function on var
args: var_name, env_name

hp: what you just typed)";
//END HELP TEXT
void REPL_PRINT(string output){
  if(printing){
    cout << output << endl;
  }
}
void REPL_ERROR(string output){
  if(error_reporting){
    cout << output << endl;
  }
}
void REPL_SET_PRINTING(int setter){
  printing = setter;
}
void REPL_SET_ERROR_REPORTING(int setter){
  error_reporting = setter;
}
void REPL_INTRO(){
  REPL_PRINT("welcome!!");
}
void REPL_OUTRO(){
  REPL_PRINT("please come back soon");
}
void REPL_QUEUE_INPUT(){
  if(printing){
  cout << "♫ ";
  }
}
void REPL_BAD_FUN(){
  REPL_ERROR("--BAD INPUT-- (type \"hp\" for help)");
}
void REPL_PRINT_HELP(){
  cout << help_string << endl;
}
