//
// top N-selection problem
//
//1. find maximum top 1000 from 1billion element (user-name, user-login-time)
//2. find the median
//
//1. use min-heap of size N (=1000), for each input number k, replace the current min m with max(k,m). Afterward the heap holds the top N inputs.
