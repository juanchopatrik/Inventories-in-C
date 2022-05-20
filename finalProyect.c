#include <string.h>
#include <stdbool.h>
#include <stdio.h>
 
struct details
    {
        char brand[50];
		char model[50];
        float screen_size;
        int memory;
        int camera_resolution;
        int price;
        int stock;
    };

int models = 0;

struct details item[50]; 

int price_depends_plan();    

void show_inventary();

void populate_inventary();

void user_select_options();

void selector_functions(int selection_user);

void find_brand();

void telephones_list();

void main()
{
   
   user_select_options();

   printf("Thank you for using Hermes your Fido inventory system!!!!");
    
}

void populate_inventary(){

int n, i, room_inventary;
 
    printf("How many phones you want to enter :");
    scanf("%d", &n);


     room_inventary = models + n;

    if (room_inventary<=50)
    {
        for (i = 0; i < n; i++)
        {
            printf("Phone brand: \n");
            scanf("%s", item[i].brand);

            printf("Phone model: \n");
            scanf("%s", item[i].model);
            
            printf("Screen Size : \n");
            scanf("%f", &item[i].screen_size);
            
            printf("Memory: \n");
            scanf("%d", &item[i].memory);
            
            printf("Camera Resolution: \n");
            scanf("%d",  &item[i].camera_resolution);

            int plan = price_depends_plan();
            
            printf("Price: \n");
            scanf("%d",  &item[i].price);

            switch (plan)
            {
            case 1:
                break;
            case 2:
                item[i].price= item[i].price/1.2;
                break;
            case 3:
                item[i].price= item[i].price/1.3;
                break;
            default:
                break;
            }
            
            printf("Stock: \n");
            scanf("%d",  &item[i].stock);
        }

        models = models + n;

    }else
        printf("Sorry is not possible add more models");

}

int price_depends_plan(){

    int plan;

    printf("\n Enter the plan of cell\n");
    printf("\n Enter 1 if not have plan, the final price doesn't have any discount");
    printf("\n Enter 2 if you have a plan of 1 year, the final price have a 20%% discount");
    printf("\n Enter 3 if you have a plan of 1 year, the final price have a 30%% discount\n");
    printf("\n Please enter your plan selected: ");
    scanf("%d", &plan);

    return plan;   
}


void show_inventary(){

    printf("                        *****  INVENTORY ***** \n");
    printf("---------------------------------------------------------------------------------\n");
    printf(" BRAND | MODEL | SCREEN SIZE | MEMORY | CAMERA RESOLUTION |   PRICE   |  STOCK | \n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < models; i++){

        printf("  %s   |   %s  |     %f      |   %d   |       %d          |   %d      |   %d   | \n",
        item[i].brand, item[i].model, item[i].screen_size, item[i].memory,
        item[i].camera_resolution, item[i].price, item[i].stock );
        printf("--------------------------------------------------------------- -----------------\n");


    }

}

void user_select_options(){

    int input_user;

        printf(" Welcome to Hermes the Fido Inventory System, please\n");
        printf(" press the number that corresponds to the following options:\n");
        printf(" 1 for Populate the inventory \n");
        printf(" 2 for Display items of a particular brand\n");
        printf(" 3 for Process a buy-an-item transaction\n");
        printf(" 4 for Process a return-an-item transaction  \n");
        printf(" 5 for Display all the items in the inventory\n");
        printf(" 6 for Exit the system\n\n");
        printf(" please enter your choice :  ");
        scanf("%d", &input_user);

    selector_functions(input_user);
    
};


void selector_functions(int selection_user){

    switch (selection_user)
        {
        case 1:
            populate_inventary();
            user_select_options();
        case 2: 
            find_brand();
            user_select_options();
        case 3: 
            buy();
            user_select_options();
        case 5:
            show_inventary();
            user_select_options();
        case 6:
            break;
        default:
            break;
        }
}

void find_brand(){

    char brand[20];
    printf("Enter brand: ");
    scanf("%s", brand);

    printf("                        *****  INVENTORY ***** \n");
    printf("---------------------------------------------------------------------------------\n");
    printf(" BRAND | MODEL | SCREEN SIZE | MEMORY | CAMERA RESOLUTION |   PRICE   |  STOCK | \n");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < models; i++){

        if (strcmp(brand, item[i].brand) == 0 )
        {   
            printf(" %s | %s | %f      |   %d   |       %d          |   %d      |   %d   | \n",
            item[i].brand, item[i].model, item[i].screen_size, item[i].memory,
            item[i].camera_resolution, item[i].price, item[i].stock );
            printf("--------------------------------------------------------------------------------\n");
        }
   }
}


void buy(){
    
    printf("\nSelect the phone tha you want buy\n");
    
    char brand[20];
    printf("\nselect  brand: ");
    scanf("%s", brand);

    char model[20];
    printf("\nselect  Model: ");
    scanf("%s", model);

    int cant;
    printf("\n quantity of buy");
    scanf("%d", &cant);

    printf("                        *****  INVENTORY ***** \n");
    printf("---------------------------------------------------------------------------------\n");
    printf(" BRAND | MODEL | SCREEN SIZE | MEMORY | CAMERA RESOLUTION |   PRICE   |  STOCK | \n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < models; i++){

        if (strcmp(brand, item[i].brand) == 0 && strcmp(brand, item[i].brand) == 0 )
        {   
            
            if (item[i].stock == 0){
                printf(" Sorry there is no stock of this product ");
            }else if ( item[i].stock >= cant  )
               item[i].stock = item[i].stock - cant;
            else if ( item[i].stock < cant)
                printf(" Sorry there is not enough stock for this purchase select a lower quantity");

            printf("  %s   |   %s  |     %f      |   %d   |       %d          |   %d      |   %d   | \n",
            item[i].brand, item[i].model, item[i].screen_size, item[i].memory,
            item[i].camera_resolution, item[i].price, item[i].stock );
            printf("--------------------------------------------------------------------------------\n");
        }else
            printf("Sorry This product doesn't exist");
   }
    
}

void sell(){
    
    printf("\nSelect the phone tha you want buy\n");
    
    char brand[20];
    printf("\nselect  brand: ");
    scanf("%s", brand);

    char model[20];
    printf("\nselect  Model: ");
    scanf("%s", model);

    int cant;
    printf("\n quantity of buy");
    scanf("%d", &cant);

    printf("                        *****  INVENTORY ***** \n");
    printf("---------------------------------------------------------------------------------\n");
            printf(" BRAND | MODEL | SCREEN SIZE | MEMORY | CAMERA RESOLUTION |   PRICE   |  STOCK | \n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < models; i++){

        if (strcmp(brand, item[i].brand) == 0 && strcmp(brand, item[i].brand) == 0 )
        {   
            
            if (item[i].stock == 0){
                printf(" Sorry there is no stock of this product ");
            }else 
               item[i].stock = item[i].stock + cant;

            printf(" %s  |   %s  |   %f  |  %d  |    %d        |   %d    |   %d   | \n",
            item[i].brand, item[i].model, item[i].screen_size, item[i].memory,
            item[i].camera_resolution, item[i].price, item[i].stock );
            printf("--------------------------------------------------------------------------------\n");
        }else
            printf("Sorry This product doesn't exist");
   }
    
}

