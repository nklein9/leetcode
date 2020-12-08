# This is a sample Python script.

def main():
    prices = [2,1,2,0,1]

    profit = 0
    holding = -1
    i = 0

    print(len(prices))

    while i + 1 <= len(prices):
        print("i: ", i)
        print("price: ", str(prices[i]))
        if i+1 == len(prices):
            if holding != -1:
                profit = profit + prices[i]
                print("final sell. Profit= ", str(profit))
        elif holding != -1 and (prices[i] > prices[i + 1]):
            profit = profit + prices[i]
            holding = -1
            print("sell. Profit= ", str(profit))
        elif holding == -1 and (prices[i] < prices[i + 1]):
            holding = prices[i]
            profit = profit - holding
            print("buy. Profit= ", str(profit))
        else:
            print("Hold. Profit= ", str(profit))
        i = i + 1

    return profit


if __name__ == "__main__":
    main()
