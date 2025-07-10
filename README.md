## Day 1, First Problem (Calculate distance)



We were given two arrays of int: list1 and list2. They contain five 5-digit numbers. The task was to pair up the smallest values from both arrays and calculate their total distance. For example, the smallest number on the left list is 10, and the smallest number in the right list is 4; their distance equals 6. The goal was to return the total distance between the left and right lists.



My initial thought was to use a brute-force approach and iterate through the whole list, comparing their values at the same indexes. But then I realised that those values had to be the smallest, so arrays had to be sorted before the iteration.

After my first attempt, the result was incorrect due to an incorrect calculation of the difference between the numbers. After many attempts and scanning through code, I have noticed that the total distance value is negative, which is impossible in current problem. The key was to calculate the distance using abs(), to avoid negative numbers. Just after I have coded total distance += abs(list2\[i]-list1\[i]), it gave a correct answer.



## Day 1, Second Problem (Similarity Score)



We were given the same two arrays. This time the goal was to check how often each number from the left array appears in the right array and calculate total similarity score,  by adding up each number in the left list and multiplying it by the number of times that number appears in the right list.



The initial approach I have taken was to calculate the total similarity score based on the appearances of the number from the left array in the right array by using a double for loop. After its completion, I have realised that the task was not just to calculate each appearance but also to calculate a proper similarity score. So my question was, how do I keep track of each number occurrence, so I can use it later on?

Then I came up with the idea of using an unordered\_map that fits well for this task.

Since an unordered map can only store unique keys, we can easily count the number of occurrences. After we know how many times each number in list2 appears, we can properly calculate the similarity score.

For that, we need to iterate through the list1 and check if the hash map contains the value, if it does contain the value, which was stored from list2 with an occurrence counter. We increase the similarity score by the number multiplied by its frequency count.

This way we can calculate the total similarity score based on the problem's requirements.

