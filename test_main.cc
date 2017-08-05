#include "sound_file.h"
#include "envelope.h"
#include "test.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

int main(){
  REPL_INTRO();
  while(1){
    REPL_QUEUE_INPUT();
    stringstream in_parser;
    string input;
    string fun_name;
    getline(cin,input);
    string temp;
    vector<string>fun_args;
    in_parser << input;
    in_parser >> fun_name;
    int i = 10;
    while(i--){
      temp = "";
      in_parser >> temp;
      if(temp == ""){
        break;
      }
      else{
        fun_args.push_back(temp);
      }
    }
    if(fun_name == "ld"){
      ld(fun_args);
    }
    else if(fun_name == "ldenv"){
      ldenv(fun_args);
    }
    else if(fun_name == "env"){
      env(fun_args);
    }
    else if(fun_name == "sv"){
      sv(fun_args);
    }
    else if(fun_name == "vol"){
      vol(fun_args);
    }
    else if(fun_name == "rep"){
      rep(fun_args);
    }
    else if(fun_name == "rm"){
      rm(fun_args);
    }
    else if(fun_name == "cp"){
      cp(fun_args);
    }
    else if(fun_name == "mv"){
      mv(fun_args);
    }
    else if(fun_name == "vars"){
      vars(fun_args);
    }
    else if(fun_name == "qt"){
      qt(fun_args);
    }
    else if(fun_name == "hp"){
      hp(fun_args);
    }
    else{
      REPL_BAD_FUN();
    }
  }
}
