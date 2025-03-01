// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if(value <= 1)
    return false;
  if(value <= 3)
    return true;
  if (value % 2 == 0 || value % 3 == 0)
    return false;
  for(uint64_t i = 5; i * i <= value; i += 6){
    if (value % i == 0 || value % (i + 2) == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t num = 2;
  while(count < n){
    if(checkPrime(num)){
      count++;
    }
    num++;
  }
  return num - 1;
}

uint64_t nextPrime(uint64_t value) {
  if(value <= 1)
    return 2;
  uint64_t prime = value;
  bool found = false;
  while(!found){
    prime++;
    if(chechPrime(prime)){
      found = true;
    }
  }
  return prime;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++){
    if(chechPrime(i)){
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for(uint64_t i = lbound; i < hbound - 1; i++){
    if(chechPrime(i) && chechPrime(i+2)){
      count++;
    }
  }
  return count;
}
