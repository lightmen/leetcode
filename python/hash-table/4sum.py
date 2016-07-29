class Solution(object):
    def fourSum(self, nums, target):
        nums.sort()
        ret = []

        for i in range(0,len(nums)-3):
            if i > 0 and nums[i] == nums[i-1]:
                continue

            for j in range(i+1,len(nums)-2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue

                start = j + 1
                end = len(nums) - 1
                while start < end:
                    if start > j + 1 and nums[start] == nums[start-1]:
                        start += 1
                        continue

                    sum = nums[i] + nums[j] + nums[start] + nums[end]
                    if sum == target:
                        ret.append([nums[i], nums[j], nums[start], nums[end]])
                        start += 1
                        end -= 1
                        while start < end and nums[start] == nums[start-1]:
                            start += 1
                        while start < end and nums[end] == nums[end+1]:
                            end -= 1
                    elif sum > target:
                        end -= 1
                    else:
                        start += 1

        return ret
