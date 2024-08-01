#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flags {
  int fl_e;
  int fl_b;
  int fl_v;
  int fl_n;
  int fl_s;
  int fl_t;
  int count_fl;
} Flag;

void parser(int argc, char** argv);
void read_f(char* file_n);
void flag_n(char* file_n);
void flag_b(char* file_n);
void flag_e(char* file_n, struct Flags flag);
void flag_t(char* file_n, struct Flags flag);
void flag_s(char* file_n);
void flag_v(char* file_n);

#endif