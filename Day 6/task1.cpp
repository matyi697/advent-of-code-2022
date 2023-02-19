#include <fstream>
#include <iostream>
#include <string>

int task(std::string data) {
  for (int i = 0; i < data.length(); i++) {
    if ((data[i] == data[i + 1]) || (data[i] == data[i + 2]) ||
        (data[i] == data[i + 3]) || (data[i + 1] == data[i + 2]) ||
        (data[i + 1] == data[i + 3]) || (data[i + 2] == data[i + 3]))
      continue;
    else
      return i + 4;
  }
  return 0;
}

int main() {
  std::ifstream file("dataset.txt");
  std::string str;
  int ans = 0;
  while (std::getline(file, str))
    std::cout << task(str);
  return 0;
}