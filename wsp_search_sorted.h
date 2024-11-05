#ifndef WSP_SEARCH_SORTED_H
#define WSP_SEARCH_SORTED_H

unsigned char wsp_search_sorted_ascending(unsigned long low,
                                          unsigned long high,
                                          unsigned long *haystack,
                                          unsigned long needle,
                                          unsigned long *position);

unsigned char wsp_search_sorted_descending(unsigned long low,
                                           unsigned long high,
                                           unsigned long *haystack,
                                           unsigned long needle,
                                           unsigned long *position);

#endif
