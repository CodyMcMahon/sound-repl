#include "sound_file.h"
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

sound_file::sound_file(string file_name){
  FILE* wav_file = fopen(file_name.c_str(),"rb");
  this->header = (unsigned int*)malloc(44);
  fread(this->header,sizeof(unsigned int),11,wav_file);
  this->num_of_samples = this->header[10]/2;
  data = new vector<short int>(this->num_of_samples);
  fread(&(*this->data)[0],sizeof(short int),this->num_of_samples,wav_file);
  fclose(wav_file);
}

sound_file::sound_file(FILE* wav_file){
  this->header = (unsigned int*)malloc(44);
  fread(this->header,sizeof(unsigned int),11,wav_file);
  this->num_of_samples = this->header[10]/2;
  //printf("# of Samples %i\n", this->header[10]);
  data = new vector<short int>(this->num_of_samples);
  fread(&(*this->data)[0],sizeof(short int),this->num_of_samples,wav_file);
  fclose(wav_file);
}

sound_file::sound_file(sound_file *f_to_c){
  this->header = (unsigned int*)malloc(44);
  memcpy(this->header,f_to_c->header,44);
  this->num_of_samples = f_to_c->num_of_samples;
  this->data = new vector<short int>(*f_to_c->data);
}

sound_file::~sound_file(){
  free(this->header);
  delete this->data;
}

void sound_file::replicate(int multiplier){
  this->num_of_samples *= (multiplier+1);
  this->header[10] = this->num_of_samples;
  vector<short int>temp_copy(*this->data);
  for(int i = 0 ; i < (multiplier);i++){
    for(short int a : temp_copy){
      this->data->push_back(a);
    }
  }
}

unsigned int sound_file::get_num_of_samples(){
  return this->num_of_samples;
}

void sound_file::save_to_file(string file_name){
  FILE* wav_file = fopen(file_name.c_str(),"wb");
  fwrite(this->header,sizeof(unsigned int),11,wav_file);
  fwrite(&(*this->data)[0],sizeof(short int),this->num_of_samples,wav_file);
  fclose(wav_file);
}

void sound_file::mult_volume(double mult){
  int l = this->num_of_samples;
  for(int i = 0; i < l; i++){
    (*this->data)[i]*=mult;
  }
}
void sound_file::env_manip(vector<double>*env){
  int l = this->num_of_samples;
  for(int i = 0; i < l; i++){
    (*this->data)[i]*=(*env)[i];
  }
}



























