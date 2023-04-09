#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item in the knapsack
struct Item {
    int weight;     // weight of the item
    int value;      // value of the item
};

// Function to compare items based on their value-to-weight ratio
int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    if (ratioA < ratioB) {
        return 1;
    } else if (ratioA > ratioB) {
        return -1;
    } else {
        return 0;
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Sort items based on their value-to-weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compareItems);

    double totalValue = 0;    // Total value of items in the knapsack
    int currentWeight = 0;    // Current weight of items in the knapsack

    for (int i = 0; i < n; i++) {
        // If the item can be fully included in the knapsack
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // If the item cannot be fully included, calculate the fraction
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }
    return totalValue;
}

//main function
int main() {
    int i,n,capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter max capacity: ");
    scanf("%d",&capacity);
    printf("\n");
    struct Item items[n];
    for(i=0;i<n;i++){
        printf("Enter Item %d Weight: ",(i+1));
        scanf("%d",&items[i].weight);
        printf("Enter Item %d Value: ",(i+1));
        scanf("%d",&items[i].value);
        printf("\n");
    }
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value of items in the knapsack: %.3lf\n", maxValue);
    return 0;
}