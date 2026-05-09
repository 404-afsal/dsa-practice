/*
    Purpose: Maximize profit by  by choosing a single day to buy one stock and
    choosing a different day in the future to sell that stock.
    Note: Must buy before selling
*/
int maxProfit(int *prices, int pricesSize)
{
    int min_price = prices[0]; // Assume price in 1st day as minimum
    int max_profit = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min_price) // Is the price in current day smaller?
        {
            min_price = prices[i]; // Udpate buying price
        }
        if ((prices[i] - min_price) >= max_profit) // If profit in current day higher?
        {
            max_profit = prices[i] - min_price; // Choose the selling day
        }
    }
    return max_profit; // Return the maximum profit
}