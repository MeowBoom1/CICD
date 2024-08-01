#include "s21_cat.h"

int main(int argc, char* argv[]) {
  parser(argc, argv);
  return 0;
}

void parser(int argc, char** argv) {
  int value = 0;
  const struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                        {"number", 0, NULL, 'n'},
                                        {"squeeze-blank", 0, NULL, 's'},
                                        {NULL, 0, NULL, 0}};
  Flag flags = {0};
  while ((value = getopt_long(argc, argv, "+beEnstTv", long_options, NULL)) !=
         -1) {
    if (value == 'e') {
      flags.fl_e = 1;
      flags.fl_v = 1;
      flags.count_fl += 2;
      flag_e(argv[argc - 1], flags);
    } else if (value == 'b') {
      flags.fl_b = 1;
      flags.count_fl++;
      flag_b(argv[argc - 1]);
    } else if (value == 'v') {
      flags.fl_v = 1;
      flags.count_fl++;
      flag_v(argv[argc - 1]);
    } else if (value == 'n') {
      flags.fl_n = 1;
      flags.count_fl++;
      flag_n(argv[argc - 1]);
    } else if (value == 's') {
      flags.fl_s = 1;
      flags.count_fl++;
      flag_s(argv[argc - 1]);
    } else if (value == 't') {
      flags.fl_t = 1;
      flags.fl_v = 1;
      flags.count_fl += 2;
      flag_t(argv[argc - 1], flags);
    } else if (value == 'T') {
      flags.fl_t = 1;
      flags.count_fl++;
      flag_t(argv[argc - 1], flags);
    } else if (value == 'E') {
      flags.fl_e = 1;
      flags.count_fl++;
      flag_e(argv[argc - 1], flags);
    }
  }
  if (flags.count_fl == 0) read_f(argv[argc - 1]);
}

void read_f(char* file_n) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c;
    while ((c = fgetc(file)) != EOF) {
      putc(c, stdout);
    }
    fclose(file);
  }
}

void flag_n(char* file_n) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c0 = fgetc(file);
    char c = fgetc(file);
    int count = 1;
    if (c != EOF && c0 != EOF) {
      printf("%6i\t", count);
      count++;
    }
    while (c != EOF) {
      putc(c0, stdout);
      if (c0 == '\n' && c != EOF) {
        printf("%6i\t", count);
        count++;
      }
      c0 = c;
      c = fgetc(file);
    }
    printf("%c", c0);
    fclose(file);
  }
}

void flag_b(char* file_n) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c = fgetc(file);
    char p_c = ' ';
    int count = 1;
    if (c != EOF) {
      printf("%6i\t", count);
      count++;
    }
    while (c != EOF) {
      if (p_c == '\n' && c != '\n') {
        printf("%6i\t", count);
        printf("%c", c);
        count++;
      } else
        printf("%c", c);
      p_c = c;
      c = fgetc(file);
    }
    fclose(file);
  }
}

void flag_e(char* file_n, struct Flags flag) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c = fgetc(file);
    while (c != EOF) {
      if (c == '\n') {
        printf("$\n");
      } else if (((c >= 0 && c <= 31) || c == 127) && c != 9 && flag.fl_v) {
        printf("^%c", c + 64);
      } else {
        printf("%c", c);
      }
      c = fgetc(file);
    }
    fclose(file);
  }
}

void flag_t(char* file_n, struct Flags flag) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c;
    while ((c = fgetc(file)) != EOF) {
      if (c == '\n')
        printf("\n");
      else if (c == '\t') {
        printf("^I");
      } else if (((c >= 0 && c <= 31) || c == 127) && c != 14 && flag.fl_v) {
        printf("^%c", c + 64);
      } else
        printf("%c", c);
    }
    fclose(file);
  }
}

void flag_s(char* file_n) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c;
    int count = 0;
    char p_c = ' ';
    while ((c = fgetc(file)) != EOF) {
      if (count != 0 && p_c == '\n' && c == '\n')
        count++;
      else if (count == 0 && p_c == '\n' && c == '\n') {
        count++;
        printf("%c", c);
      } else {
        printf("%c", c);
        count = 0;
      }
      p_c = c;
    }
    fclose(file);
  }
}

void flag_v(char* file_n) {
  FILE* file = fopen(file_n, "r");
  if (file != NULL) {
    char c = fgetc(file);
    while (c != EOF) {
      if (c != '\n' && c != '\t') {
        if (c >= 0 && c <= 31) {
          printf("^");
          c += 64;
        } else if (c == 127) {
          printf("^");
          c -= 64;
        }
      }
      printf("%c", c);
      c = fgetc(file);
    }
    fclose(file);
  }
}