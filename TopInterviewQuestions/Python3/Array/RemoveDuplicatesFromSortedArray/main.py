# Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

from array import *


def main():
    nums = [0,0,1,1,1,2,2,3,3,4]

    print("length: ", len(nums))

    i = 0
    while i+1 < len(nums):
        print("i: ", i)
        if nums[i] == nums[i+1]:
            print("pop: ", nums[i+1])
            nums.pop(i+1)
            print("length: ", len(nums))
        else:
            i = i+1

    print("nums: ", nums)
    print("length: ", len(nums))
    return len(nums)


if __name__ == "__main__":
    main()
