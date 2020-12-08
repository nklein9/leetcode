nums = [1,3,1,-1,3]


def main():
    hashtable = {}
    for i in nums:
        if i in hashtable:
            hashtable[i] = hashtable[i] + 1
        else:
            newdict = {i: 1}
            hashtable.update(newdict)
    for j in hashtable:
        if hashtable[j] == 1:
            print(j)
            return j


if __name__ == '__main__':
    main()
