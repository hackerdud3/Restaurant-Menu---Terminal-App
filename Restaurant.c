#include <stdio.h>

void read_menu(FILE *fptr_menu, int *c1, double *p1,int *c2,double *p2,int *c3,double *p3);
void read_discount(FILE *fptr_disc, int *d1, int *d2, int *d3);
int read_choice(int c1,int c2,int c3,double p1,double p2,double p3);
int price_off(double price, int discount);
void selection();
void discount_price(int d1, int d2, int d3, double price);
void summary(int menu,double status);
void another_order(int grand);
void grand_t(double grand);
double grand =0.0;
int discount_type(int d1,int d2,int d3);


int main()
{
    FILE *fptr_menu;
    FILE *fptr_disc;
    int c1,c2,c3;
    double p1,p2,p3,status;
    int d1,d2,d3,d_type,discount;
    int menu;
    double price,total_price;
    
    
    




    fptr_menu = fopen("menu.txt","r");
    fptr_disc = fopen("discount.txt","r");
    if(fptr_menu == NULL||fptr_disc ==NULL){
        printf("couldn't open file!");
        return 1;
    }


    


    read_menu(fptr_menu, &c1 ,&p1,&c2,&p2,&c3,&p3);
    // printf("1.Calorie is %d - Price is %.2lf \n",c1,p1);
    read_discount(fptr_disc, &d1,&d2,&d3);
    menu = read_choice(c1, c2, c3, p1, p2, p3);

    switch (menu)
    {
    case 1:price= p1;
    printf("You selected \nPaneer -  Price :- %.2lfrs", p1);
        break;
    case 2:price=p2;
    printf("You selected \nChicken 65 -  Price :- %.2lfrs",p2);
        break;
    case 3: price=p3;
    printf("You selected \nChicken Biryani - Price :- %.2lfrs",p3);
        break;
    case 0: exit(0);
    default:printf("\nInvalid option\n");
    return main();
        break;
    }
  
    printf("\n\nYou can apply coupons for discount\n WELCOME50 - for %d%% off on this order\n SNACKS30 - for %d%% off on this order\n PD10 - for %d%% on this order\n",d1,d2,d3);
    //discount_price(d1,d2,d3, price);
    
    discount = discount_type(d1,d2,d3);

   
    status = price_off(price,discount);
    printf("Coupon code is applied successfully\n");
    printf("\nyour price after discount is %.2lfrs\n",status);
    grand=grand+status;
    selection();
    another_order(grand);
    
    summary(menu,status);

    fclose(fptr_menu);
    fclose(fptr_disc);
    return 0;
 }
 int discount_type(int d1,int d2,int d3){
     int discount,d_type;
      printf("\nEnter your discount type (1-2-3): ");
    scanf("%d",&d_type);
      switch (d_type)
    {
    case 1: discount = d1;
        break;  
    case 2: discount = d2;
        break;
    case 3: discount = d3;
        break;

    default:printf("Invalid discount offer or expired, please choose correctly");
    return discount_type(d1,d2,d3);
        break;
        
    }
    return discount;

 }

   void read_menu(FILE *fptr_menu, int *c1, double *p1,int *c2,double *p2,int *c3,double *p3){
       fscanf(fptr_menu ,"%d",c1);
       fscanf(fptr_menu,"%lf",p1);
       fscanf(fptr_menu, "%d",c2);
       fscanf(fptr_menu,"%lf",p2);
       fscanf(fptr_menu,"%d",c3);
       fscanf(fptr_menu,"%lf",p3);
       return;

   }
   void read_discount(FILE *fptr_disc, int *d1, int *d2, int *d3){
       fscanf(fptr_disc,"%d",d1);
       fscanf(fptr_disc,"%d",d2);
       fscanf(fptr_disc,"%d",d3);
       return;

   }

    int read_choice(int c1,int c2,int c3,double p1,double p2,double p3){

    int choice;
    printf("\nSelect Food item : \n1 - Paneer (%d calories) = %.2lfrs\n2 - Chicken 65 (%d calories) = %.2lfrs\n3 - Chicken Biryani (%d calories) = %.2lfrs\n0 - To exit menu\n",c1,p1,c2,p2,c3,p3);
    scanf("%d",&choice);
    return choice;
}
int price_off(double price, int discount){
    price = price * (100-discount)/100;
    return price;
   }


void selection(){
    printf("\nDo you want to continue to place the order? (Y|N) ");
    char ch;
    
     scanf("%s",&ch);
    if(ch== 'Y'||ch=='y'){
        printf("your order is placed successfully");
        
    }
    else if (ch =='N'|| ch =='n')
    {printf("your order is cancelled");
    
        return;
    }
    else{
        printf("Invalid choice, enter again");
    return selection();
    }
return;

}
void discount_price(int d1, int d2, int d3, double price){
    int d_type,discount;
    printf("\nEnter your discount type (1-2-3): ");
    scanf("%d",&d_type);

    switch (d_type)
    {
    case 1: discount = d1;
        break;  
    case 2: discount = d2;
        break;
    case 3: discount = d3;
        break;

    default:printf("Invalid discount offer or expired, please choose correctly");
    return discount_price(d1,d2,d3, price);
    break;
    }
     int status = price_off(price,discount);
     printf("Coupon code is applied successfully\n");
     printf("\nyour price after discount is %.2lfrs\n",status);





}
void another_order(int grand){
    printf("\n\nDo you want to place another order? (Y|N) ");
    char another;
    scanf("%s",&another);
    if(another== 'Y'||another=='y'){
        return main();
        
    }
    else if (another =='N'|| another =='n')
    {
       grand_t(grand);
        return;
    }
    else{
        printf("Invalid choice, enter again");
        return another_order(grand);

    }
}
void grand_t (double grand){
printf("\nGrand total :- %.2lfrs", grand);
return;
}
void summary(int menu, double status){
printf("\n\nOrder summary");
switch (menu)
{
case 1: 
printf("\nYou ordered paneer");

    break;
case 2:
printf("\nYou ordered Chicken 65");

break;
case 3:printf("\nYou ordered Chicken Biryani");

break;
default:
    break;
}
printf("\nTotal bill:-%.2lfrs",status);


}
   
