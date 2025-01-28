#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CATEGORIES 5
#define PRODUCTS 5
#define SUBPRODUCTS 3

// validate integer
int getValidatedIntInput(const char* prompt) {
    int value;
    char buffer[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endptr;
            value = strtol(buffer, &endptr, 10);
            if (endptr != buffer && *endptr == '\n') {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid integer.\n");
    }
}

// validate float
float getValidatedFloatInput(const char* prompt) {
    float value;
    char buffer[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endptr;
            value = strtof(buffer, &endptr);
            if (endptr != buffer && *endptr == '\n') {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

int main() {
    int categoryin, productin, subproductsin, isPWDorSenior, quantity;

    // categories
    char categories[CATEGORIES][100] = {"Mobile phones & Tablets", "Laptops & Computers", "PC Parts & Accessories", "Networking", "Printers"};

    // products
    char products[CATEGORIES][PRODUCTS][200] = {
        {"iPhone 15 Pro Max", "Samsung Galaxy S24 Ultra", "Realme Note 60x", "INFINIX Zero Flip", "Vivo V40 5G"},
        {"ACER NITRO 5 AN515-58-55LG", "ASUS M1605YA-MB634WSM/ RYZEN 5-7430U", "Lenovo ThinkPad X260", "Apple Macbook Air M1 2020", "MSI Modern 15 B7M-266PH"},
        {"Processors", "Motherboards", "Memory", "Graphics Card", "Keyboard"},
        {"Router A", "Router B", "Router C", "Router D", "Router E"},
        {"EPSON L3250 Wi-Fi All-in-One Ink Tank Printer", "CANON G1010 CIS SF Printer", "BROTHER MFC-T4500DW AIO Ink Tank Printer", "UNICORN Ender 3 3D Printer", "Epson C13T00V100 Black Ink Cartridges"}
    };

    // subproducts
    char subproducts[CATEGORIES][PRODUCTS][SUBPRODUCTS][300] = {
        {
            {"128GB", "256GB", "512GB"},
            {"128GB", "256GB", "512GB"},
            {"64GB", "128GB", "256GB"},
            {"Flip Black", "Flip Gold", "Flip Purple"},
            {"40MP", "50MP", "60MP"}
        },
        {
            {"8GB RAM, 512GB SSD", "16GB RAM, 1TB SSD", "32GB RAM, 2TB SSD"},
            {"8GB RAM, 512GB SSD", "16GB RAM, 1TB SSD", "32GB RAM, 2TB SSD"},
            {"4GB RAM, 256GB SSD", "8GB RAM, 512GB SSD", "16GB RAM, 1TB SSD"},
            {"M1 Chip", "M2 Chip", "Pro Display"},
            {"FHD Display", "QHD Display", "4K Display"}
        },
        {
            {"Intel Core i5", "Intel Core i7", "Intel Core i9"},
            {"Asus Motherboard", "MSI Motherboard", "Gigabyte Motherboard"},
            {"8GB RAM", "16GB RAM", "32GB RAM"},
            {"RTX 3060", "RTX 3070", "RTX 3080"},
            {"Mechanical Keyboard", "RGB Keyboard", "Wireless Keyboard"}
        },
        {
            {"Router 2.4GHz", "Router 5GHz", "Dual-Band Router"},
            {"Router Basic", "Router Advanced", "Router Pro"},
            {"Router Home", "Router Office", "Router Industrial"},
            {"Router Budget", "Router Premium", "Router Enterprise"},
            {"Router Mini", "Router Standard", "Router Max"}
        },
        {
            {"Standard Ink", "High-Yield Ink", "Photo Ink"},
            {"Basic Ink", "Pro Ink", "Ultra Ink"},
            {"Low Capacity", "Medium Capacity", "High Capacity"},
            {"PLA Material", "ABS Material", "TPU Material"},
            {"Small Ink", "Medium Ink", "Large Ink"}
        }
    };

    // prices of products
    float prices[CATEGORIES][PRODUCTS][SUBPRODUCTS] = {
        {
            {70990, 75990, 80990},
            {79856, 84856, 89856},
            {4799, 5799, 6799},
            {29999, 32999, 35999},
            {37999, 39999, 41999}
        },
        {
            {43999, 49999, 55999},
            {37495, 43495, 49495},
            {63999, 69999, 75999},
            {42490, 48490, 54490},
            {32499, 37499, 42499}
        },
        {
            {10000, 15000, 20000},
            {5000, 8000, 12000},
            {3000, 5000, 8000},
            {20000, 30000, 40000},
            {2000, 4000, 6000}
        },
        {
            {1500, 2500, 3500},
            {2000, 3000, 4000},
            {1000, 2000, 3000},
            {2500, 3500, 4500},
            {3000, 4000, 5000}
        },
        {
            {10250, 12500, 15000},
            {4995, 5995, 6995},
            {39950, 49950, 59950},
            {8285, 9285, 10285},
            {275, 375, 475}
        }
    };

    // stocks of products
    int stock[CATEGORIES][PRODUCTS][SUBPRODUCTS] = {
        {
            {10, 5, 2},
            {8, 4, 1},
            {15, 10, 5},
            {6, 3, 2},
            {4, 2, 1}
        },
        {
            {5, 3, 1},
            {7, 4, 2},
            {3, 2, 1},
            {6, 3, 2},
            {8, 5, 3}
        },
        {
            {10, 5, 3},
            {8, 6, 4},
            {12, 8, 5},
            {7, 5, 3},
            {20, 15, 10}
        },
        {
            {25, 20, 15},
            {30, 25, 20},
            {15, 10, 5},
            {10, 8, 6},
            {12, 10, 8}
        },
        {
            {8, 6, 4},
            {10, 8, 6},
            {5, 4, 3},
            {7, 5, 3},
            {20, 15, 10}
        }
    };

    float total = 0;
    int cartCount = 0;
    char cart[100][100];
    float cartPrices[100];
    int cartQuantities[100];

    int mainLoop = 1;
    while (mainLoop) {
        if (cartCount == 0) {
           printf("\
********************************************************\n\
*                                                      *\n\
*     _____ _____ ____ _   _                           *\n\
*    |_   _| ____/ ___| | | |                          *\n\
*      | | |  _|| |   | |_| |                          *\n\
*      | | | |__| |___|  _  |                          *\n\
*      |_| |_____|____|_| |_|                          *\n\
*                                                      *\n\
*           _____ ___  ____  _____                     *\n\
*          | ____/ _ \\/ ___|| ____|                   *\n\
*          |  _|| | | \\___ \\|  _|                    *\n\
*          | |__| |_| |___) | |___                     *\n\
*          |_____\\___/|____/|_____|                   *\n\
*                                                      *\n\
*                                                      *\n\
*             Where you can shop with ease...          *\n\
*                                                      *\n\
*    ⚡ Mobile  |  💻 Laptops  |  🔧 PC Parts          *\n\
*    🌐 Network |  🖨️ Printers                         *\n\
*                                                      *\n\
********************************************************\n");
            printf("Welcome to TechEase! A store where you can shop with ease.\n");
        }
        
        printf("\nWhat would you like to do?\n");
        printf("1. View Categories and Shop\n");
        printf("2. View Cart\n");
        printf("3. Checkout\n");
        printf("0. Exit\n");

        int choice = getValidatedIntInput("\nEnter your choice: ");
        
        if (choice == 0) {
            break;
        }
        
        switch(choice) {
            case 1: {
                int shopping = 1;
                while (shopping) {
                    printf("\nCategories:\n");
                    for (int i = 0; i < CATEGORIES; i++) {
                        printf("%d. %s\n", i + 1, categories[i]);
                    }
                    printf("0. Back to Main Menu\n");

                    categoryin = getValidatedIntInput("\nEnter Category (1-5) or 0 to go back: ");

                    if (categoryin == 0) {
                        break;
                    }
                    if (categoryin < 1 || categoryin > CATEGORIES) {
                        printf("Invalid category. Please try again.\n");
                        continue;
                    }

                    int selectedCategory = categoryin - 1;
                    printf("\nProducts in %s:\n", categories[selectedCategory]);
                    for (int i = 0; i < PRODUCTS; i++) {
                        printf("%d. %s\n", i + 1, products[selectedCategory][i]);
                    }

                    productin = getValidatedIntInput("\nEnter Product (1-5): ");

                    if (productin < 1 || productin > PRODUCTS) {
                        printf("Invalid product. Please try again.\n");
                        continue;
                    }

                    int selectedProduct = productin - 1;
                    printf("\nSubproducts for %s:\n", products[selectedCategory][selectedProduct]);
                    for (int i = 0; i < SUBPRODUCTS; i++) {
                        if (stock[selectedCategory][selectedProduct][i] > 0) {
                            printf("%d. %s - Php %.2f (Stock: %d)\n", i + 1, 
                                   subproducts[selectedCategory][selectedProduct][i], 
                                   prices[selectedCategory][selectedProduct][i],
                                   stock[selectedCategory][selectedProduct][i]);
                        }
                    }

                    subproductsin = getValidatedIntInput("\nEnter Subproduct (1-3): ");

                    if (subproductsin < 1 || subproductsin > SUBPRODUCTS) {
                        printf("Invalid subproduct. Please try again.\n");
                        continue;
                    }

                    int selectedSubproduct = subproductsin - 1;

                    if (stock[selectedCategory][selectedProduct][selectedSubproduct] <= 0) {
                        printf("Sorry, the selected subproduct is out of stock.\n");
                        continue;
                    }

                    printf("\nYou have selected %s (%s) - Php %.2f\n",
                           subproducts[selectedCategory][selectedProduct][selectedSubproduct],
                           products[selectedCategory][selectedProduct],
                           prices[selectedCategory][selectedProduct][selectedSubproduct]);

                    quantity = getValidatedIntInput("\nEnter Quantity: ");

                    if (quantity > stock[selectedCategory][selectedProduct][selectedSubproduct]) {
                        printf("Sorry, we only have %d in stock.\n", 
                               stock[selectedCategory][selectedProduct][selectedSubproduct]);
                        continue;
                    }

                    snprintf(cart[cartCount], 100, "%s (%s - %s)", 
                             products[selectedCategory][selectedProduct], 
                             categories[selectedCategory],
                             subproducts[selectedCategory][selectedProduct][selectedSubproduct]);
                    cartPrices[cartCount] = prices[selectedCategory][selectedProduct][selectedSubproduct];
                    cartQuantities[cartCount] = quantity;
                    total += prices[selectedCategory][selectedProduct][selectedSubproduct] * quantity;
                    cartCount++;

                    stock[selectedCategory][selectedProduct][selectedSubproduct] -= quantity;

                    printf("\nItem added to cart successfully!\n");
                    printf("1. Continue Shopping\n");
                    printf("2. Back to Main Menu\n");
                    
                    int nextAction = getValidatedIntInput("Enter your choice: ");
                    
                    if (nextAction == 2) {
                        break;
                    } else if (nextAction == 3) {
                        shopping = 0;
                    }
                }
                break;
            }
            
            case 2: {
                while (cartCount > 0) {
                    printf("\n=== Current Cart ===\n");
                    for (int i = 0; i < cartCount; i++) {
                        printf("%d. %s - Php %.2f x %d\n", i + 1, cart[i], cartPrices[i], cartQuantities[i]);
                    }
                    printf("====================\n\n");
                    printf("Total: Php %.2f\n", total);

                    printf("\n1. Remove item from cart\n");
                    printf("2. Continue shopping\n");
                    printf("3. Proceed to checkout\n");
                    printf("0. Back to main menu\n");
                    
                    int cartChoice = getValidatedIntInput("Enter your choice: ");

                    if (cartChoice == 0) {
                        break;
                    } else if (cartChoice == 2) {
                        break;
                    } else if (cartChoice == 3) {
                        goto checkout;
                    } else if (cartChoice == 1) {
                        int removeIndex, removeQuantity;
                        removeIndex = getValidatedIntInput("\nEnter the item number to remove from cart: ");
                        removeIndex--;

                        if (removeIndex < 0 || removeIndex >= cartCount) {
                            printf("Invalid item number. Please try again.\n");
                            continue;
                        }

                        removeQuantity = getValidatedIntInput("Enter the quantity to remove: ");

                        if (removeQuantity < 1 || removeQuantity > cartQuantities[removeIndex]) {
                            printf("Invalid quantity. Please try again.\n");
                            continue;
                        }

                        // amount tas subtract
                        float itemTotal = cartPrices[removeIndex] * removeQuantity;
                        total -= itemTotal;

                        // restore if hindi narmove item
                        char itemName[100];
                        strcpy(itemName, cart[removeIndex]);
                        
                        // update array stock
                        for (int i = 0; i < CATEGORIES; i++) {
                            for (int j = 0; j < PRODUCTS; j++) {
                                if (strstr(itemName, products[i][j]) != NULL) {
                                    for (int k = 0; k < SUBPRODUCTS; k++) {
                                        if (strstr(itemName, subproducts[i][j][k]) != NULL) {
                                            // Restore the stock
                                            stock[i][j][k] += removeQuantity;
                                            printf("Stock restored: %d items returned to inventory\n", removeQuantity);
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }

                        // remove || update 
                        if (removeQuantity == cartQuantities[removeIndex]) {
                            // remove item
                            for (int i = removeIndex; i < cartCount - 1; i++) {
                                strcpy(cart[i], cart[i + 1]);
                                cartPrices[i] = cartPrices[i + 1];
                                cartQuantities[i] = cartQuantities[i + 1];
                            }
                            cartCount--;
                            printf("Item removed from cart.\n");
                        } else {
                            // sa quantity
                            cartQuantities[removeIndex] -= removeQuantity;
                            printf("Quantity updated in cart.\n");
                        }
                    }
                }
                if (cartCount == 0) {
                    printf("\nYour cart is empty! Returning to main menu...\n");
                }
                break;
            }
            
            case 3: {
                checkout:
                if (cartCount == 0) {
                    printf("\nYour cart is empty! Cannot proceed to checkout.\n");
                    break;
                }

                printf("\n=== Receipt ===\n");
                for (int i = 0; i < cartCount; i++) {
                    printf("%d. %s - Php %.2f x %d\n", i + 1, cart[i], cartPrices[i], cartQuantities[i]);
                }
                printf("Total before discount: Php %.2f\n", total);

                isPWDorSenior = getValidatedIntInput("\nAre you a PWD or Senior Citizen? (1 for Yes, 0 for No): ");

                if (isPWDorSenior == 1) {
                    float discount = total * 0.20;
                    total -= discount;
                    printf("Discount applied (20%%): Php %.2f\n", discount);
                }

                float tax = total * 0.12;
                total += tax;
                printf("Tax (12%%): Php %.2f\n", tax);
                printf("Total after tax: Php %.2f\n", total);
                printf("================\n");

                // user bayad
                float amount = getValidatedFloatInput("\nEnter the amount: ");

               // if kasya pera
                if (amount >= total) {
                    float change = amount - total;
                    printf("Amount given: Php %.2f\n", amount);
                    printf("Change: Php %.2f\n", change);
                    cartCount = 0;
                    total = 0;
                    printf("\nThank you for your purchase! Returning to main menu...\n");
                } else {
                    printf("Insufficient funds! Please enter a sufficient amount.\n");
                }
                printf("================\n\n");
                break;
                

                
            }
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nThank you for shopping at TechEase, where you can shop with ease!\n");
    return 0;
}
