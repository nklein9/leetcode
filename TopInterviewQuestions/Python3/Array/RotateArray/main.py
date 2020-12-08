# This is a sample Python script.

nums = [1,2,3,4,5,6,7]
k = 3


def main(rotation):
    while rotation > 0:
        x = nums.pop()
        nums.insert(0, x)
        rotation = rotation-1
    print(nums)


if __name__ == '__main__':
    main(k)
