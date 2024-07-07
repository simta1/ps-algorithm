| constraints           | time complexity                           | algorithm                                             |
|-----------------------|-------------------------------------------|-------------------------------------------------------|
| $n \le 10$            | $O(n!)$                                   |                                                       |
| $n \le 25$            | $O(2^n)$, $O(n^2 \cdot 2^n)$              |                                                       |
| $n \le 50$            | $O(\sqrt2^n)$                             |                                                       |
| $n \le 500$           | $O(n^3)$                                  |                                                       |
| $n \le 5,000$         | $O(n^2 \log n)$                           |                                                       |
| $n \le 100,000$       | $O(n \sqrt n)$, $O(n \log^2n)$            |                                                       |
| $n \le 1,000,000$     | $O(n \log n)$                             |                                                       |
| $n \le 5,000,000$     | $O(n \log n)$                             | SegmentTree(bottom-up only)                           |
| $n \le 10,000,000$    | $O(n)$                                    |                                                       |
| $n > $                | $O(logn)$, $O(1)$                         |                                                       |