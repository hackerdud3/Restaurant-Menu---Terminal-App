# Restaurant-Menu---Terminal-App
Section - Restaurant Menu
C Programming: Create Terminal Apps

I developed a c-program which shows menu(LIST of food items) and user can select food to eat. Food has calorie and price. When user selects for a particular food item it showers valid coupons on that order, the user can apply a coupon code on it to avail discount on the price depending on the discount percentage. I used to files, menu.txt and discount.txt, the food items and corresponding coupon codes are read from the file.

Function Prototypes:

By Nandikanti Vinay
read_menu()
void read_menu(FILE *fPtr_menu, int *c1, double *p1, int *c2, double *p2, int *c3, double *p3);
read_discounts()
void read_discounts(FILE *fPtr_discount, int *d1, int *d2, int *d3);
get_menu_choice()
int read_choice(int c1, int c2, int c3, double p1, double p2, double p3);
offer_price()
int price_off(double price , int discount);
discount_price()
void discount_price(int d1,int d2,int d3,double price);
continue_order()
void selection();
another_order()
void another_order(int grand);
order_summary()
void summary(int menu,double status);
grand_total()
void grand_t(double grand); 
