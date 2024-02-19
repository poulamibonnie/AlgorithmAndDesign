Closest Pair of Points

Implement the closest pair of points algorithm. For your output, I want the distance between the closest pair of points in every recursive call (including the overall solution) output to the console. (You don’t need to output the locations of the points.) To make sure that we get the same results for every call, you should make sure that, when there is an odd number of items, the left group (smaller x-coordinates) has one more item than the right group (larger x-coordinates). In any subproblem with three or fewer points, you should calculate the distances using brute-force. For full credit, your algorithm must run in O(n log n) time. Your input file will consist of n points, with n specified on the first line, and n additional lines containing the x- and y-coordinates, which will be real numbers (not integers). The file should be hardcoded to the name program2data.txt. For example

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Data Table</title>
<style>
    table {
        width: 100%;
        border-collapse: collapse;
    }
    th, td {
        border: 1px solid black;
        padding: 8px;
        text-align: center;
    }
    th {
        background-color: #f2f2f2;
    }
</style>
</head>
<body>

<table>
  <tr>
    <th>Column 1</th>
    <th>Column 2</th>
  </tr>
  <tr>
    <td>8</td>
    <td>0.1251 56.3585</td>
  </tr>
  <tr>
    <td>19.3304</td>
    <td>80.8741</td>
  </tr>
  <tr>
    <td>58.5009</td>
    <td>47.9873</td>
  </tr>
  <tr>
    <td>35.0291</td>
    <td>89.5962</td>
  </tr>
  <tr>
    <td>82.2840</td>
    <td>74.6605</td>
  </tr>
  <tr>
    <td>17.4108</td>
    <td>85.8943</td>
  </tr>
  <tr>
    <td>71.0501</td>
    <td>51.3535</td>
  </tr>
  <tr>
    <td>30.3995</td>
    <td>1.4985</td>
  </tr>
</table>

</body>
</html>

Please output your results with four digits of precision. Format your output identically to mine (with no leading or trailing spaces). My output for this trivial data set is (the indices are after sorting by x-coordinate and the distances include all points in between the two indices):

D[0,1]: 34.2222
D[2,3]: 80.1437
D[0,3]: 5.3747
D[4,5]: 47.7726
D[6,7]: 25.8731
D[4,7]: 12.9928
D[0,7]: 5.3747
