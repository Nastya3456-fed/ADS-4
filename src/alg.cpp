// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  std::sort(arr, arr + len);
  int c = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        c = c+1;
        break;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1]) i++;
  }
  return c;
}
int countPairs2(int *arr, int len, int value) {
  std::sort(arr, arr + len);
  int c = 0;
  int l = 0;
  int r = len - 1;
  while (l < r) {
    int sloj = arr[l] + arr[r];
    if (sloj == value) {
      c++;
      l++;
      r--;
      while (l < r && arr[l] == arr[l - 1]) l++;
      while (l < r && arr[r] == arr[r + 1]) r--;
    } else if (sloj < value) {
      l++;
    } else {
      r--;
    }
  }
return c;
}
const int* const binarySearch(const int* const arr, const int arrlen, const int findnum) {
    int l = 0;
    int r = arrlen - 1;
    while (l <= r) {
        int sri = l + (r - l) / 2;
        const int* const sr = &arr[sri];
        if (findnum == *sr) {
            return sr;
        }
        if (findnum < *sr) {
            r = sri - 1;
        }
        else {
            l = sri + 1;
        }
    }
    return nullptr;
}

int countPairs3(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int c = 0;
    int k = len / 2;
    for (int i = 0; i < k; ++i) {
        int elem = arr[i];
        bool findsum = nullptr != binarySearch(arr, len, value - elem);
        if (findsum) {
            ++c;
        }
    }
    return c;
}
