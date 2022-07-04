#include <regex>
#include <list>
using namespace std;

class RegexChecker {
  public:
  RegexChecker() = default;
  void check(const string& text_path);

  private:
  unsigned int _match(const std::string& line, const unsigned int& line_number);

  const string patterns[3] = {
    "[^\\s]\\s\\s+", // Double whitespaces
    "(\\.|,|:|\\?|!|;)[^\\s]", // punctuation symbols not followed by whitespaces
    "\\s(\\.|,|:|\\?|!|;)" // punctuation symbols preceded by whitespaces
  };
};