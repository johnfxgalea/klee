// RUN: %llvmgcc %s -emit-llvm -O0 -c -o %t1.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out %t1.bc

#include <assert.h>

int main() {
  int x, y, z = 0;
  klee_make_symbolic(&x, sizeof x);
  klee_make_symbolic(&y, sizeof y);
  if (x) {
    assert(klee_is_symbolic(y));
  } else {
    assert(!klee_is_symbolic(z));
  }
  return 0;
}
