#include <iostream>
#include "regex_checker.hh"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf ("Usage: ./typo_checker src.tex\n");
    return -1;
  }

  string d[] = {"1", "2", "3"};
 
  RegexChecker rg;
  rg.check(argv[1]);
  return 0;
}