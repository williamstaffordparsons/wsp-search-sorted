# WSP-Search-Sorted
© 2024 William Stafford Parsons

## About
WSP-Search-Sorted is an optimal search algorithm as a substantial improvement to Binary Search, Exponential Search, Fibonacci Search and Interpolation Search.

Read more [here](https://williamstaffordparsons.github.io/wsp-search-sorted/).

## Example
``` c
#include <stdio.h>
#include "wsp_search_sorted.h"

int main(void) {
  const unsigned long input_ascending[6] = {1, 11, 111, 1111, 11111, 111111};
  const unsigned long input_descending[6] = {111111, 11111, 1111, 111, 11, 1};
  unsigned long position;

  if (wsp_search_sorted_ascending(0, 5, input_ascending, 111, &position) == 1) {
    printf("111 was found at position %lu in input_ascending.\n", position);
  }

  if (wsp_search_sorted_descending(0, 5, input_descending, 1, &position) == 1) {
    printf("1 was found at position %lu in input_descending.\n", position);
  }

  return 0;
}
```
