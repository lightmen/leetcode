class Solution(object):
    def fourSum(self, nums, target):
        nums.sort()
        ret = []
        length = len(nums)
        for i in range(0,length-3):
            if i and nums[i] == nums[i-1]:
                continue

            for j in range(i+1,length-2):
                if j != i+1 and nums[j] == nums[j-1]:
                    continue

                start = j + 1
                end = length - 1

                sum = target - nums[i] - nums[j]
                while start < end:
                    if sum == nums[start] + nums[end]:
                        ret.append([nums[i], nums[j], nums[start], nums[end]])
                        start += 1
                        end -= 1
                        while start < end and nums[start] == nums[start-1]:
                            start += 1
                        while start < end and nums[end] == nums[end+1]:
                            end -= 1
                    elif sum < nums[start] + nums[end]:
                        end -= 1
                    else:
                        start += 1

        return ret
