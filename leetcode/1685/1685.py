def getSumAbsoluteDifferences(nums):
  # [1, 4, 6, 8, 10]

  adjacent_diffs = []
  pre = 0
  for num in nums:
    if pre != 0:
      t = num - pre
      adjacent_diffs.append(t)
    pre = num
  print(adjacent_diffs)
  # [3, 2, 2, 2]

  forward = []
  for i in range(0, len(adjacent_diffs) + 1):
    t = 0
    if i > 0:
      t += forward[i - 1] + i * adjacent_diffs[i - 1]
    forward.append(t)
  # [0, 3, 7, 13, 21]

  adjacent_diffs.reverse()
  # [2, 2, 2, 3]

  backward = []
  for i in range(0, len(adjacent_diffs) + 1):
    t = 0
    if i > 0:
      t += backward[i - 1] + i * adjacent_diffs[i - 1]
    backward.append(t)
  #[0, 2, 6, 12, 24]

  backward.reverse()

  ret = []
  for i in range(0, len(adjacent_diffs) + 1):
    ret.append(forward[i] + backward[i])
  
  return ret

if __name__ == "__main__":
  nums = [1, 4, 6, 8, 10]
  print(getSumAbsoluteDifferences(nums))
  