Closest Pair of Points

Implement the closest pair of points algorithm. For your output, I want the distance between the closest pair of points in every recursive call (including the overall solution) output to the console. (You don’t need to output the locations of the points.) To make sure that we get the same results for every call, you should make sure that, when there is an odd number of items, the left group (smaller x-coordinates) has one more item than the right group (larger x-coordinates). In any subproblem with three or fewer points, you should calculate the distances using brute-force. For full credit, your algorithm must run in O(n log n) time. Your input file will consist of n points, with n specified on the first line, and n additional lines containing the x- and y-coordinates, which will be real numbers (not integers). The file should be hardcoded to the name program2data.txt. For example
8
0.1251 56.3585
19.3304 80.8741
58.5009 47.9873
35.0291 89.5962
82.2840 74.6605
17.4108 85.8943
71.0501 51.3535
30.3995 1.4985

Please output your results with four digits of precision. Format your output identically to mine (with no leading or trailing spaces). My output for this trivial data set is (the indices are after sorting by x-coordinate and the distances include all points in between the two indices):

D[0,1]: 34.2222
D[2,3]: 80.1437
D[0,3]: 5.3747
D[4,5]: 47.7726
D[6,7]: 25.8731
D[4,7]: 12.9928
D[0,7]: 5.3747
