#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

char line[80];
int available_seats[10][2];
unsigned long long ticket_price[20][20];
int choosen_seat_number[10];
int set_seat_number[10];
int country;
int ticket_category;
unsigned long long total_money;
int confirm;
char trakingID[20];

struct nametype
{
    char first[20];
    char last[20];
};
struct traveller_information
{
    struct nametype name;
    char gender[8];
    char passport_no[15];
    char phone_number[15];
    char Ticket_Category[20];
    int seat_no;
};

struct bKash_payment{ // bKashh
    char bKash_number[20];
    char otp_number[10];
   // char trx_id[20];
    char pin[20];
};
struct card_payment{ //card
    char card_number[20];
    char card_validity[25];
    char cvv[20];
};
struct payment_type{
    struct bKash_payment bKash;
    struct card_payment card;
};
void welcome();
void update_seat_file(FILE *fp);
void display_ticket_price(FILE *fp);
void upload_ticket_price(FILE *fp);
void display_countries(FILE *fp);
void read_availble_seats(FILE *fp);
void display_available_seats(int *seat_need);
int input_seat_no();
void take_traveller_details(struct traveller_information *obj);
void modify_details(int m, struct traveller_information *t);
void display_and_modify_info(struct traveller_information *t, int s);
void modify_given_card_details(struct payment_type *p);
void save_traveller_details(struct traveller_information *obj, FILE *fp, int s);
void ask_for_payment();
void payment_by_card();
void payment_by_bKash();
void update_available_seat();
void generate_ticket_traking_id();
void good_wish();
void make_zero_choosen_seat_number();

int main()
{
    int seat_need, n, payment_choice;
    struct traveller_information obj[10];
    struct payment_type p;
    FILE *fp_payment;
    FILE *fp;
    fp = fopen("All_Countries.txt", "r");
    upload_ticket_price(fp);
    fclose(fp);
    welcome();
    while(1){
        total_money =0;
        confirm =0;
        system("cls");
        printf("\t\t\t1 >> Show Countries\n\t\t\t2 >> Show All Countries Ticket Price\n\t\t\t3 >> Booking Ticket\n\n\t\t\t0 >> Exit\n\t\t\t");
        scanf("%d", &n);
        if(n==0)
        {
            return 0;
        }
        switch(n){
        case 1:
            fp = fopen("All_Countries.txt", "r");
            system("cls");
            display_countries(fp);
            fclose(fp);
            printf("\n\n\t\t\t\tPress any key to continue...");
            _getch();
            system("cls");
            break;
        case 2:
            fp = fopen("All_Countries_Ticket_Price.txt", "r");
            display_ticket_price(fp);
            fclose(fp);
            printf("\n\n\t\t\t\tPress any key to continue...");
            _getch();
            system("cls");
            break;
        case 3:
            make_zero_choosen_seat_number();
            system("cls");
            fp = fopen("All_Countries.txt", "r");
            display_countries(fp);
            fclose(fp);
            printf("\n\t\t\t Select the country you want to travell : ");
            scanf("%d",&country);
            int seat_number = 0;
            switch(country)
            {
            case 1: // Australia
                fp = fopen("AustraliaSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Australia_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Australia_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("AustraliaSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 2: // Austria
                fp = fopen("AustriaSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Austria_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Austria_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();

                    fp = fopen("AustriaSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 3:// Belgium
                fp = fopen("BelgiumSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Belgium_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Belgium_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("BelgiumSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 4://Brazil
                fp = fopen("BrazilSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Brazil_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Brazil_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    generate_ticket_traking_id();
                    printf("\t\t\t Choice Payment Method\n");
                    printf("\t\t\t  1 >> bKash\n\t\t\t  2 >> Card\n\t\t");
                    scanf("%d", &payment_choice);
                    if(payment_choice==1){
                        payment_by_bKash(&p);
                    }
                    else{
                        payment_by_card(&p);
                    }
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("BrazilSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 5: // Brunei
                fp = fopen("BruneiSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Brunei_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Brunei_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("BruneiSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 6: // Canada
                fp = fopen("CanadaSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Canada_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Canada_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("CanadaSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 7: // China
                 fp = fopen("ChinaSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("China_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("China_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("ChinaSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 8: // Denmark
                fp = fopen("DenmarkSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Denmark_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Denmark_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("DenmarkSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 9: // Egypt
                fp = fopen("EgyptSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Egypt_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Egypt_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("EgyptSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 10: // Finland
                fp = fopen("FinlandSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Finland_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Finland_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("FinlandSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 11: // France
                fp = fopen("FranceSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("France_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("France_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("FranceSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 12: // Germany
                fp = fopen("GermanySeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Germany_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Germany_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("GermanySeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 13: // Kuwait
                fp = fopen("KuwaitSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Kuwait_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Kuwait_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("KuwaitSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 14: // Malaysia
                fp = fopen("MalaysiaSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Malaysiay_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Malaysia_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("MalaysiaSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 15: // Norway
                fp = fopen("NorwaySeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Norway_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Norway_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("NorwaySeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 16: // Singapur
            fp = fopen("SingapurSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Singapur_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Singapur_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("SingapurSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 17: // Switzerland
                fp = fopen("SwitzerlandSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Switzerland_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Switzerland_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("SwitzerlandSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 18: // Thailand
                fp = fopen("ThailandSeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("Thailand_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("Thailand_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("ThailandSeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 19: // UAE
                fp = fopen("UAESeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("UAE_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("UAE_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("UAESeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;
            case 20: // USA
                fp = fopen("USASeats.txt", "r");
                read_availble_seats(fp);
                fclose(fp);
                display_available_seats(&seat_need);
                if(ticket_category==1){
                    fp = fopen("USA_Business_Seat_Details.txt", "a");
                }
                else{
                    fp = fopen("USA_Economic_Seat_Details.txt", "a");
                }
                for(int i=0; i<seat_need; i++){
                    take_traveller_details(&obj[i]);
                    display_and_modify_info(&obj[i], set_seat_number[i]);
                }
                ask_for_payment();
                if(confirm ==1){
                    for(int i=0; i<seat_need; i++){
                        save_traveller_details(&obj[i], fp, i);
                    }
                    fclose(fp);
                    update_available_seat();
                    fp = fopen("USASeats.txt", "w");
                    update_seat_file(fp);
                    fclose(fp);
                }
                break;

             default:
                 break;
            } // inner switch
        default:
            break;
        } //first switch

    }// infinite while
        return 0;
} // main

void display_available_seats(int *seat_need){
    int business=0, economic=0 ,ticket_need=0,s;

    for(int i=0; i<10; i++){
        if(available_seats[i][0]==0)
            business++;
        if(available_seats[i][1]==0)
            economic++;
    }
    while(1){
        system("cls");
        printf("\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  Available seats  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
        printf("\t\t  >>> Business class : %d\n\t\t  >>> Economic class : %d\n",business,economic);
        printf("\n\t\xdb\xdb\xdb\xdb\xdb\xdb  Which ticket do you want?  \xdb\xdb\xdb\xdb\xdb\xdb\n");
        printf("\n\t\t   1 >> Business Class\n\t\t   2 >> Economic Class\n\t\t");
        scanf("%d", &ticket_category);
        system("cls");
        printf("\n\t\xdb\xdb\xdb\xdb\xdb\xdb  How many ticket(s) do you want?  \xdb\xdb\xdb\xdb\xdb\xdb\n\t\t");
        scanf("%d",&ticket_need);
        if(ticket_category==1 && business >= ticket_need)
            break;
        else if(ticket_category==2 && economic >= ticket_need)
            break;
        else{
            continue;
        }
    }
    *seat_need = ticket_need;
    system("cls");
    if(ticket_category ==1 )
        printf("\t\t\tAvailable Business Class Seat Number(s):\n");
    else
        printf("\t\t\tAvailble Economic Class Seat Number(s):\n");

    printf("\n\t\t\t    ");
    for(int i=0; i<10; i++){
        if(available_seats[i][ticket_category-1]==0){
            printf("%d  ",i+1);
        }
        else
            printf("#  ");
    }
    printf("\n\n\t\t\tChoose %d seat(s) number you want to take : \n\t\t\t",ticket_need);
    for(int i=0; i<ticket_need; i++){
        scanf("%d",&s);
        set_seat_number[i]= s;
        choosen_seat_number[s-1]=1;
    }
    total_money = ticket_price[country-1][ticket_category-1] * ticket_need;
}

int input_seat_no(){
    int i,seatNo;
    for(i=0; i<10; i++){
        if(available_seats[i][ticket_category-1] == 0){
            seatNo = i+1;
            available_seats[i][ticket_category-1] = 1;
            break;
        }
    }
    return seatNo;
}

void take_traveller_details(struct traveller_information *t){
    system("cls");
    printf("\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  Input your details  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    int gender;
    printf("\t\tEnter first name: ");
    scanf("%s",t->name.first);
    printf("\t\tEnter last name: ");
    scanf("%s",t->name.last);
    printf("\n\t\tEnter your Gender\n\t\t  1->> MALE\n\t\t  2->> FEMALE\n\t\t");
    scanf("%d",&gender);
    if(gender==1)
        strcpy(t->gender, "MALE");
    else
        strcpy(t->gender, "FEMALE");
    printf("\n\t\tEnter your Passport No.: ");
    scanf("%s",t->passport_no);
    printf("\n\t\tEnter your phone number: ");
    scanf("%s", t->phone_number);
    strcpy(trakingID, t->phone_number);

    if(ticket_category == 1)
        strcpy(t->Ticket_Category, "Business Class");
    else
        strcpy(t->Ticket_Category, "Economic Class");
}

void update_seat_file(FILE *fp)
{
    for(int i =0; i<10; i++){
        fprintf(fp,"%d %d\n", available_seats[i][0], available_seats[i][1]);
    }
}
void save_traveller_details(struct traveller_information *obj, FILE *fp, int s){
    time_t ti;
    time(&ti);
    fprintf(fp,"-----------------------------------------------------------------\n");
    fprintf(fp,"Name: %s %s\n", obj->name.first,obj->name.last);
    fprintf(fp,"Gender : %s\n",obj->gender);
    fprintf(fp,"Passport No.: %s\n",obj->passport_no);
    fprintf(fp,"Mobile Number : %s\n",obj->phone_number);
    fprintf(fp,"Ticket Category : %s\n", obj->Ticket_Category);
    fprintf(fp,"Seat No : %d\n",set_seat_number[s]);
    fprintf(fp,"Ticket Parches time (date and time) : %s", ctime(&ti));
    fprintf(fp,"-----------------------------------------------------------------\n");
}
void display_and_modify_info(struct traveller_information *t, int s){
    while(1){
        system("cls");
        int m;
        printf("\t\t Modify details if wrong\n\n");
        printf("\t\t1 >> Name: %s %s\n", t->name.first,t->name.last);
        printf("\t\t2 >> Gender : %s\n",t->gender);
        printf("\t\t3 >> Passport No.: %s\n",t->passport_no);
        printf("\t\t4 >> Mobile Number : %s\n",t->phone_number);
        printf("\t\t* >> Ticket Category : %s\n", t->Ticket_Category);
        printf("\t\t* >> Seat No : %d\n",s);
        printf("\n\n\t\tEnter 0 to continue...\n\t\t");
        scanf("%d", &m);
        if(m == 0){
            break;
        }
        else{
            modify_details(m, t);
        }
    }
    system("cls");
}
void modify_details(int m, struct traveller_information *t){
    int x;
    system("cls");
    switch(m){
        case 1:
            printf("\t\t\tEnter First Name Carefully: ");
            scanf("%s", t->name.first);
            printf("\t\t\tEnter Last Name Carefully: ");
            scanf("%s", t->name.last);
            break;
        case 2:
            printf("\t\t\tEnter Gender Carefully:\n");
            printf("\t\t\t1 >> MALE\n\t\t\t2 >> FEMALE\n\t\t\t");
            scanf("%d",&x);
            if(x==1)
                strcpy(t->gender, "MALE");
            else
                strcpy(t->gender, "FEMALE");
            break;
        case 3:
            printf("\t\t\tEnter Passport Number Carefully: ");
            scanf("%s", t->passport_no);
            break;
        case 4:
            printf("\t\t\tEnter Mobile Number Carefully: ");
            scanf("%s", t->phone_number);
            break;
        default:
            break;
        }
}
void read_availble_seats(FILE *fp){
    int i,a,b;
    for(i=0; i<10; i++){
        fgets(line, 10, fp);
        sscanf(line, "%d %d", &a, &b);
        available_seats[i][0] = a;
        available_seats[i][1] = b;
    }
}
void ask_for_payment(){
    system("cls");
    int payment_method_choice;
    printf("\n\n\t\t\t Total Ticket Price : %llu (BDT)\n", total_money);
    printf("\n\t\t\t Do you want to confirm booking ?\n\n");
    printf("\t\t\t\t  1 >> YES\n\t\t\t\t  2 >> NO\n\n\t\t\t\t  ");
    scanf("%d", &confirm);
    if(confirm==1){
        generate_ticket_traking_id();
        system("cls");
        printf("\t\t\t Choice Payment Method\n\n");
        printf("\t\t\t\t1 >> bKash\n\t\t\t\t2 >> Card\n\t\t\t\t");
        scanf("%d", &payment_method_choice);
        switch(payment_method_choice){
            case 1:
                payment_by_bKash();
                break;
            case 2:
                payment_by_card();
                break;
            default:
                break;
        }
    }
    system("cls");
}
void payment_by_bKash(){
    system("cls");
    int x =0;
    struct payment_type p;
    printf("\t\t\tEnter bKash Number : ");
    scanf("%s",p.bKash.bKash_number);
    printf("\t\t\tEnter OTP : ");
    scanf("%s", p.bKash.otp_number);
    printf("\t\t\tEnter Pin Number : ");
    do{
        p.bKash.pin[x]=getch();
        if(p.bKash.pin[x]!='\r')
            printf("*");
        x++;
    }while(p.bKash.pin[x-1]!= '\r');
    printf("\n\n\t\t\tPress 1 for OK...");
    _getch();
    good_wish();
}
void payment_by_card(){
    system("cls");
    int x=0;
    struct payment_type p;
    printf("\t\t\tEnter Card Number : ");
    scanf("%s", p.card.card_number);
    printf("\t\t\tEnter Card Validity Date : ");
    scanf("%s", p.card.card_validity);
    printf("\t\t\tEnter CVV Number : ");
    do{
        p.card.cvv[x]=getch();
        if(p.card.cvv[x]!='\r')
            printf("*");
        x++;
    }while(p.card.cvv[x-1]!='\r');
    printf("\n\n\t\t\tEnter 1 for OK...");
    _getch();
    good_wish();
}
void display_ticket_price(FILE *fp){
    system("cls");
    while(fgets(line, 75, fp)!=NULL){
        printf("\t\t\t%s", line);
    }
}
void display_countries(FILE *fp){
   // system("cls");
    char serial[3], symbol[5], cName[25];
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Showing All Countries \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    while(fgets(line,70, fp) != NULL){
        sscanf(line, "%s %s %s",serial,symbol,cName);
        printf("\t\t\t\t     %s %s %s\n",serial, symbol,cName);
    }
}

void upload_ticket_price(FILE *fp){
    unsigned long long b_price, e_price;
    int i=0;
    char serial[3], symbol[5],cName[25];// ignore everything left price
    while(fgets(line,70, fp) != NULL){
        sscanf(line, "%s %s %s %llu %llu",serial,symbol,cName,&b_price, &e_price);
        ticket_price[i][0] = b_price;
        ticket_price[i][1] = e_price;
        i++;
    }
}
void good_wish(){
    system("cls");
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\xdb\xdb                                          \xdb\xdb\n");
    printf("\t\t\xdb\xdb       *** PAYMENT SUCCESSFUL ***         \xdb\xdb\n");
    printf("\t\t\xdb\xdb           HOPE YOU WILL HAVE             \xdb\xdb\n");
    printf("\t\t\xdb\xdb         A GOOD JOURNEY WITH US           \xdb\xdb\n");
  //  printf("\t\t\xdb\xdb                                          \xdb\xdb\n");
    printf("\t\t\xdb\xdb                                          \xdb\xdb\n");
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\n\n\t\tYour Ticket Traking ID : %s\n", trakingID);
    printf("\n\t\tShow the above tracking ID to get your ticket. \n");
    printf("\n\n\t\tPress any key to continue...\n");
    _getch();
}
void welcome(){
    printf("\n\n\n\n\n");
    printf("\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t\xdb\xdb\t____                                \xdb\xdb\n");
    printf("\t\t\t\xdb\xdb\t |  \\_______________                \xdb\xdb\n");
    printf("\t\t\t\xdb\xdb\t====( oooooooooo  O \\___            \xdb\xdb\n");
    printf("\t\t\t\xdb\xdb\t(________/=====>_________)--        \xdb\xdb\n");
    printf("\t\t\t\xdb\xdb\t           OO          o            \xdb\xdb\n");
    printf("\t\t\t\xdb\xdb                                          \xdb\xdb\n");
    printf("\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");

    printf("\n\t\t\t      Welcome to Airline Ticket Counter ! \n\n");
    printf("\n\n\t\t\t      Press any key to continue...");
    _getch();
    system("cls");
}
void update_available_seat(){
    for(int i=0; i<10; i++){
        if(choosen_seat_number[i]==1){
        available_seats[i][ticket_category-1]=1;
        }
    }
}
void make_zero_choosen_seat_number(){
    for(int i=0; i<10; i++){
        choosen_seat_number[i]=0;
    }
}

void generate_ticket_traking_id(){
    int i;
    for(i=0; trakingID[i] != '\0'; i++){
        trakingID[i]+= 65;
    }
    trakingID[i]='\0';
}
