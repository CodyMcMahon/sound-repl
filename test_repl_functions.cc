#include "test.h"
using namespace std;
#define bad_args REPL_ERROR("invalid_number_of_arguments")
#define gd REPL_PRINT("--SUCCESS--")
#define bd REPL_PRINT("--FAILURE--")

static map<string,sound_file*>files_in_memory;
static map<string,envelope*>envelopes_in_memory;

void ld(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  else{
    FILE* wav_file = fopen(arguments[0].c_str(),"rb");
    if(wav_file){
      files_in_memory[arguments[1]] = new sound_file(wav_file);
      gd;
    }
    else{
      bd;
    }
  }
}
void ldenv(vector<string>arguments){
  envelopes_in_memory[arguments[1]] = new envelope(arguments[0]);
  REPL_PRINT("--who knows if it worked tbh--");
}
void env(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else if(envelopes_in_memory[arguments[1]] == NULL){
    REPL_ERROR("env is not in memory");
  }
  else{
    files_in_memory[arguments[0]]->env_manip(envelopes_in_memory[arguments[1]]->get_scaled_envelope(files_in_memory[arguments[0]]->get_num_of_samples()));
    gd;
  }
}
void sv(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else{
    files_in_memory[arguments[0]]->save_to_file(arguments[1]);
    gd;
  }
}
void vol(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else{
    files_in_memory[arguments[0]]->mult_volume(atof(arguments[1].c_str()));
    gd;
  }
}
void rep(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else{
    files_in_memory[arguments[0]]->replicate(atoi(arguments[1].c_str()));
    gd;
  }
}
void rm(vector<string>arguments){
  if(arguments.size() != 1){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else{
    delete files_in_memory[arguments[0]];
    files_in_memory.erase(arguments[0]);
    gd;
  }
}
void cp(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else{
    files_in_memory[arguments[1]] = new sound_file(files_in_memory[arguments[0]]);
    gd;
  }
}
void mv(vector<string>arguments){
  if(arguments.size() != 2){
    bad_args;
    return;
  }
  if(files_in_memory[arguments[0]] == NULL){
    REPL_ERROR("var is not in memory");
  }
  else{
    files_in_memory[arguments[1]] = files_in_memory[arguments[0]];
    files_in_memory.erase(arguments[0]);
    gd;
  }
}
void vars(vector<string>arguments){
  if(arguments.size() != 0){
    bad_args;
    return;
  }
  int counter = 0;
  for(auto a : files_in_memory){
    cout << '[' << ++counter << "] name: " << a.first << "  size: " << a.second->get_num_of_samples() << endl;
  }
}
void qt(vector<string>arguments){
  if(arguments.size() != 0){
    bad_args;
    return;
  }
  REPL_OUTRO();
  exit(0);
}
void hp(vector<string>arguments){
  if(arguments.size() != 0){
    bad_args;
    return;
  }
  REPL_PRINT_HELP();
}
