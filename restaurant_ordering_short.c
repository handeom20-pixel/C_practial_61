#include <stdio.h>

int main()
{
    char name[50];
    int choice, qty, totalItems = 0;
    float subtotal = 0, gst, total;

    int burger = 0, pizza = 0, sandwich = 0, fries = 0, drink = 0;

    printf("===== RESTAURANT ORDERING SYSTEM =====\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    while (1)
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Veg Burger   - Rs.120\n");
        printf("2. Veg Pizza    - Rs.250\n");
        printf("3. Sandwich     - Rs.150\n");
        printf("4. French Fries - Rs.100\n");
        printf("5. Cold Drink   - Rs.60\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            printf("Enter quantity: ");
            scanf("%d", &qty);

            if (qty <= 0)
            {
                printf("Please enter a valid quantity.\n");
                continue;
            }

            switch (choice)
            {
                case 1:
                    burger += qty;
                    subtotal += qty * 120;
                    break;
                case 2:
                    pizza += qty;
                    subtotal += qty * 250;
                    break;
                case 3:
                    sandwich += qty;
                    subtotal += qty * 150;
                    break;
                case 4:
                    fries += qty;
                    subtotal += qty * 100;
                    break;
                case 5:
                    drink += qty;
                    subtotal += qty * 60;
                    break;
            }

            totalItems += qty;
            printf("Item added successfully!\n");
        }
        else if (choice == 6)
        {
            if (totalItems == 0)
            {
                printf("No items ordered yet.\n");
                continue;
            }

            gst = subtotal * 0.05;
            total = subtotal + gst;

            printf("\n========== BILL ==========\n");
            printf("Customer: %s\n", name);

            if (burger)   printf("Veg Burger   x%d = Rs.%d\n", burger, burger * 120);
            if (pizza)    printf("Veg Pizza    x%d = Rs.%d\n", pizza, pizza * 250);
            if (sandwich) printf("Sandwich     x%d = Rs.%d\n", sandwich, sandwich * 150);
            if (fries)    printf("French Fries x%d = Rs.%d\n", fries, fries * 100);
            if (drink)    printf("Cold Drink   x%d = Rs.%d\n", drink, drink * 60);

            printf("--------------------------\n");
            printf("Subtotal : Rs.%.2f\n", subtotal);
            printf("GST 5%%   : Rs.%.2f\n", gst);
            printf("Total    : Rs.%.2f\n", total);
            printf("==========================\n");
        }
        else if (choice == 7)
        {
            printf("Thank you! Visit again.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
