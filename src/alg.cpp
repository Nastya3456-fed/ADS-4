// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
  int c = 0;
  int i = 0;
  for (i; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        c=c+1;
      }
    }
  }
  return c;
}
int countPairs2(int *arr, int len, int value) {
  int c = 0;
  int l = 0;
  int r = len - 1;
  while (l < r) {
    int sloj = arr[l] + arr[r];
    if (sloj == value) {
      c++;
      l++;
      r--;
    }
    else if (sloj < value) {
      l++;
    }
    else {
      r--;
    }
 }
return c;
}
int countPairs3(int *arr, int len, int value) {
  int c = 0;
  int i = 0;
  for (i; i < len; i++) {
    int iscom = value - arr[i];
    int l = i + 1;
    int r = len - 1;
    while (l <= r) {
      int sr = l + (r - l) / 2;
      if (arr[sr] == iscom) {
        c++;
        break;
      }
      else if (arr[sr] < iscom) {
        l = sr + 1;
      }
      else {
        r = sr - 1;
      }
    }
    }
  return c;
}
