#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool check_if_cont(int data[14]) {
  int temp[14] = {0};
  for (int i = 0; i < 14; i++)
    temp[i] = data[i];
  int arraySize = sizeof(temp) / sizeof(temp[0]);
  sort(temp, temp + arraySize, greater<int>());
  for (int i = 0; i < 14; i++)
    if (temp[i] == temp[i + 1])
      return true;
  return false;
}

int task(string data) {
  int temp[14] = {0};
  for (int i = 0; i < data.length(); i++) {
    for (int j = 0; j < 14; j++)
      temp[j] = data[i + j];
    if (check_if_cont(temp) == false)
      return i + 14;
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
