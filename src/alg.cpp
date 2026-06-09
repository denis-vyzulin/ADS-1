// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t cnt = 0, i = 2;
  while (true) {
    if (checkPrime(i)) cnt++;
    if (cnt == n) return i;
    i++;
  }
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  while (true) {
    if (checkPrime(++value)) return value;
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  uint64_t i = 2;
  while (i < hbound) {
    if (!checkPrime(i)) {
      i++; continue;
    }
    sum += i; i++;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt = 0;
  uint64_t prev = 0;
  while (lbound < hbound) {
    if (!checkPrime(lbound)) {
      lbound++;
      continue;
    }
    
    if (prev != 0 && lbound == prev + 2) cnt++;
    prev = lbound; lbound++;
  }
  return cnt;
}
