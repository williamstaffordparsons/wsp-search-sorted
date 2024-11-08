#include "wsp_search_sorted.h"

unsigned char wsp_search_sorted_ascending(unsigned long low,
                                          unsigned long high,
                                          unsigned long *haystack,
                                          unsigned long needle,
                                          unsigned long *position) {
  unsigned long _gap;
  unsigned long gap;

  if (haystack[high] == needle) {
    *position = high;
    return 1;
  }

  if (
    haystack[low] < needle &&
    haystack[high] > needle
  ) {
    high--;
    gap = high - low;

    while (
      haystack[high] != needle &&
      gap > 1
    ) {
      if (
        gap > 32 &&
        (_gap = high >> 3) &&
        _gap > low &&
        haystack[_gap] >= needle
      ) {
        high = _gap;
        gap = high - low;

        while (
          haystack[high] < needle &&
          gap > 1
        ) {
          high += gap >> 1;
          gap = (gap + 1) >> 1;
        }
      } else {
        while (
          haystack[high] != needle &&
          gap > 1
        ) {
          while (
            haystack[high] > needle &&
            gap > 1
          ) {
            high -= gap >> 1;
            gap = (gap + 1) >> 1;
          }

          while (
            haystack[high] < needle &&
            gap > 1
          ) {
            high += gap >> 1;
            gap = (gap + 1) >> 1;
          }
        }
      }
    }

    low = high;
  }

  if (haystack[low] == needle) {
    *position = low;
    return 1;
  }

  return 0;
}

unsigned char wsp_search_sorted_descending(unsigned long low,
                                           unsigned long high,
                                           unsigned long *haystack,
                                           unsigned long needle,
                                           unsigned long *position) {
  unsigned long _gap;
  unsigned long gap;

  if (haystack[high] == needle) {
    *position = high;
    return 1;
  }

  if (
    haystack[low] > needle &&
    haystack[high] < needle
  ) {
    high--;
    gap = high - low;

    while (
      haystack[high] != needle &&
      gap > 1
    ) {
      if (
        gap > 32 &&
        (_gap = high >> 3) &&
        _gap > low &&
        haystack[_gap] <= needle
      ) {
        high = _gap;
        gap = high - low;

        while (
          haystack[high] > needle &&
          gap > 1
        ) {
          high += gap >> 1;
          gap = (gap + 1) >> 1;
        }
      } else {
        while (
          haystack[high] != needle &&
          gap > 1
        ) {
          while (
            haystack[high] < needle &&
            gap > 1
          ) {
            high -= gap >> 1;
            gap = (gap + 1) >> 1;
          }

          while (
            haystack[high] > needle &&
            gap > 1
          ) {
            high += gap >> 1;
            gap = (gap + 1) >> 1;
          }
        }
      }
    }

    low = high;
  }

  if (haystack[low] == needle) {
    *position = low;
    return 1;
  }

  return 0;
}