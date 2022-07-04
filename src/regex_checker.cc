#include "regex_checker.hh"
#include <regex>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

unsigned int RegexChecker::_match(const std::string& line,
                                  const unsigned int& line_number)
{
  unsigned int nb_hits = 0;

  for (string pattern : this->patterns) {
    regex regex(pattern);
    smatch match;
    string::const_iterator searchStart(line.cbegin());
    unsigned int begin = 0;

    while (regex_search(searchStart, line.cend(), match, regex)) {
      const unsigned int start_match = match.position(0) + begin;
      const unsigned int end_match = start_match + match[0].str().size();

      string before_match = line.substr(0, start_match);
      string during_match = line.substr(start_match, end_match - start_match);
      string after_match  = line.substr(end_match, line.size() - end_match);

      begin = end_match;

      printf("\033[93mLine %d:\033[0m %s\033[91m%s\033[0m%s\n",
              line_number,
              before_match.c_str(),
              during_match.c_str(),
              after_match.c_str());

      searchStart = match.suffix().first;
      nb_hits++;
    }
  }
  return nb_hits;
}

void RegexChecker::check(const std::string& file_path) {
  ifstream file(file_path);
  
  string line;
  unsigned int line_count = 1;
  unsigned int total_hits = 0;
  while (getline(file, line)) {
    unsigned int nb_hits = this->_match(line, line_count);
    total_hits += nb_hits;
    line_count++;
  }
  if (total_hits)
    printf("\033[91mTotal: %d matches\033[0m\n", total_hits);
}