#ifndef envelope_h
#define envelope_h

#include <vector>
#include <iostream>

using namespace std;

class envelope{
  private:
    short int* header;
    short int width;
    short int height; 
    short int pixel_x;
    short int pixel_y;
    short int scalar;    
    vector<double> *data;
    short int bit;
    short int total;
  public:
    ~envelope();
    envelope(string);
    vector<double>*get_scaled_envelope(unsigned int); 
};
#endif 
