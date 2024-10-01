#include <stdio.h>

int main() {
    float total_selling_price, total_profit;
    float cost_price_per_item;

    printf("Enter the total selling price of 15 items: ");
    scanf("%f", &total_selling_price);
    printf("Enter the total profit earned: ");
    scanf("%f", &total_profit);

    float total_cost_price = total_selling_price - total_profit;
    cost_price_per_item = total_cost_price / 15;

    printf("Cost price of one item: %.2f\n", cost_price_per_item);

    return 0;
}
