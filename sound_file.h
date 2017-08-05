#ifndef sound_file_h
#define sound_file_h

#include <vector>
#include <iostream>

using namespace std;

class sound_file{
  private:
    unsigned int* header;
    unsigned int num_of_samples;
    vector<short int> *data;
  public:
    ~sound_file();
    sound_file(string);
    sound_file(FILE*);
    sound_file(sound_file*);
    unsigned int get_num_of_samples();
    void replicate(int);
    void mult_volume(double);
    void save_to_file(string);
    void env_manip(vector<double>*);
};

#endif
