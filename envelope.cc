#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "envelope.h"


envelope::envelope(string file_name){
  FILE* bmp_file = fopen(file_name.c_str(),"rb");
  this->header = (short int*)malloc(80);
  fread(this->header,sizeof(short int),20,bmp_file);
  this->width = this->header[9];
  this->height = this->header[11];
  this->bit = this->header[14];
  this->total = this->width * this->height; 
  vector<vector<int>> temp_img(this->height);
  int byte_width = this->bit/8;
  for(int i = 0; i < this->height; i++){
    int block_worth = 0;
    char temp;
    for(int j = 0;j < byte_width; j++){
      scanf(&temp,8,1,bmp_file);
      block_worth+=temp;
    }
    temp_img[i].push_back(block_worth);
  }
  this->data = new vector<double>(this->width);
  for(int i = 0; i < this->width; i++){
    int max_val = 0;
    int max_index = 0;
    for(int j = 0; j < this->height; j++){
      if(temp_img[j][i] > max_val){
        max_val = temp_img[j][i];
        max_index = j;
      }
      (*this->data)[i]=(this->height - max_index) / (double)this->height;
    }
  }
  fclose(bmp_file);
}
envelope::~envelope(){
  delete header;
  delete data;
}
vector<double>* envelope::get_scaled_envelope(unsigned int new_size){
  unsigned int copy_per_sample = new_size/this->width;
  unsigned int copy_in_last_sample = new_size%this->width;
  vector<double>*new_envelope = new vector<double>(new_size);
  for(int i = 0; i < new_size; i++){
    (*new_envelope)[i] = (*this->data)[i/copy_per_sample];
  }
  return new_envelope;
}
