#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
using namespace std;
// Basic/Main Functions Prototypes
void header();
int mainMenu();
string loginMenu();
void clearScreen();
void storeData();
void storeCred();
void storeFlight();
void loadData();
int convert(string);
void addUser(string name, string pass, string role);
void createaccount();
// Passenger Functions Prototypes
int passengerMenu();
void registrationP();
void pDataIntoArray(string pname, string pcnic, string passport, string pnum, string pmail, string pgender);
void flightP();
void pFlightDataIntoArray(string departCity, string arrCity, string trip, string departDate, string pClassF, int adultF, int childF, int infantF, int totalSeatsF);
int bookP();
string parserecord(string line, int field);
void bookedFlightsP();
void invoice();
void cancelFlights();
// Admin Functions Prototypes
int adminMenu();
void viewPData();
void viewPTravelData();
void seats();
void addFlights();
void viewFlightsA();
void sorting();
// BASIC/MAIN DATA STRUCTURES
const int MAX_RECORDS = 200;
string usernameA[MAX_RECORDS];
string passwordsA[MAX_RECORDS];
string rolesA[MAX_RECORDS];
// PASSENGER DATA STRUCTURES
string pName[MAX_RECORDS];
string passport[MAX_RECORDS];
string cnic[MAX_RECORDS];
string mail[MAX_RECORDS];
string gender[MAX_RECORDS];
string pNum[MAX_RECORDS];
string pClass[MAX_RECORDS];
string pDepartCity[MAX_RECORDS];
string pArrCity[MAX_RECORDS];
string pTrip[MAX_RECORDS];
string pDepartDate[MAX_RECORDS];
int optionF[MAX_RECORDS]; // Flight Option
int adult[MAX_RECORDS];
int child[MAX_RECORDS];
int infant[MAX_RECORDS];
int totalSeats[MAX_RECORDS];
int total[MAX_RECORDS]; // Expenditures
string seating[MAX_RECORDS];
// int userCount = 0;
// int count = 0;
// ADMIN DATA STRUCTURES
string aDepartDate[MAX_RECORDS];
string aDepartCity[MAX_RECORDS];
string aArrCity[MAX_RECORDS];
string aTrip[MAX_RECORDS];
string aDepartTime[MAX_RECORDS];
// float total[MAX_RECORDS];
// Count Variables
int entry_count = -1, flight_count = -1, user_count = 0, total_count = 0;
string username;
main()
{
    loadData();
    string who = " ";
    // Options to select.. Variables
    int option = 0,
        optionP = 0,
        optionA = 0,
        totalSeats = 0;

    while (option < 4)
    {
        header();
        option = mainMenu();
        if (option == 1)
        {
            header();
            who = loginMenu();

            // Passenger
            if (who == "user")
            {
                optionP = 0;
                while (optionP < 6)
                {
                    header();
                    optionP = passengerMenu();
                    // REGISTRATION
                    if (optionP == 1)
                    {
                        header();
                        registrationP();
                        clearScreen();
                    }
                    // Enter Flight Details
                    else if (optionP == 2)
                    {
                        header();
                        flightP();
                        clearScreen();
                    }
                    // Book from available Flights
                    else if (optionP == 3)
                    {
                        header();
                        optionF[entry_count] = bookP();
                        if (optionF[entry_count] == 1)
                        {
                            invoice();
                        }
                        clearScreen();
                    }
                    // View booked flights
                    else if (optionP == 4)
                    {
                        header();
                        bookedFlightsP();
                        clearScreen();
                    }
                    // Cancel booked flights
                    else if (optionP == 5)
                    {
                        header();
                        cancelFlights();
                        clearScreen();
                    }
                }
            }

            // ADMIN
            else if (who == "admin")
            {
                optionA = 0;
                while (optionA < 7)
                {
                    header();
                    optionA = adminMenu();
                    // View Passengers Data
                    if (optionA == 1)
                    {
                        header();
                        viewPData();
                        clearScreen();
                    }
                    // View Passengers travel Data
                    else if (optionA == 2)
                    {
                        header();
                        viewPTravelData();
                        clearScreen();
                    }
                    // Add new flights
                    else if (optionA == 3)
                    {
                        header();
                        addFlights();
                        clearScreen();
                    }

                    else if (optionA == 4)
                    {
                        header();
                        viewFlightsA();
                        clearScreen();
                    }

                    // Allot Seats
                    else if (optionA == 5)
                    {
                        header();
                        seats();
                        clearScreen();
                    }

                    // Ordered Passengers
                    else if (optionA == 6)
                    {
                        header();
                        sorting();
                        clearScreen();
                    }
                }
            }
            else if (who == "EXIT")
            {
                cout << "Please Sign Up first" << endl;
                clearScreen();
            }
        }

        if (option == 2)
        {
            header();
            cout << "Main Menu  >   Sign Up " << endl;
            cout << "---------------------" << endl;
            createaccount();
            clearScreen();
        }
        else if (option == 3)
        {
            header();
            cout << "Main Menu  >   Details " << endl;
            cout << "---------------------" << endl;
            cout << "Developed By :- Muhammad Abdullah" << endl;
            cout << "Registration No :- 2021-CS-82" << endl;
            cout << "Section :- CS-B" << endl;
            cout << "Submitted To :- DR.AWAIS" << endl;
            clearScreen();
        }
    }
    storeFlight();
    storeCred();
    storeData();
}
// END OF MAIN FUNCTION
void header()
{
    system("CLS");
    cout << " ------------------------------------------------------------------------------------------------------------- " << endl;
    cout << "                                                                                                              |" << endl;
    cout << "|  ********  *******  *     *       ********  *****  ******   *       *****   *       *  *******   ********   |" << endl;
    cout << "|  *      *  *     *  *   *         *      *    *    *    *   *         *     * *     *  *         *          |" << endl;
    cout << "|  ********  *******  * **          * **** *    *    *  **    *         *     *   *   *  ******    ********   |" << endl;
    cout << "|  *         *     *  *    *        *      *    *    *    *   *         *     *     * *  *                *   |" << endl;
    cout << "|  *         *     *  *      *      *      *  *****  *     *  *******  *****  *       *  *******   ********   |" << endl;
    cout << " ------------------------------------------------------------------------------------------------------------- " << endl;
    // cout << entry_count << endl;
}
// MAIN MENU
int mainMenu()
{
    int option;
    cout << "Main Menu " << endl;
    cout << "---------------------" << endl;
    cout << "Select one of the following options..." << endl;

    cout << "1- Login" << endl;
    cout << "2- Sign Up" << endl;
    cout << "3- Details" << endl;
    cout << "4- Exit" << endl;
    cout << "Your Option..";
    cin >> option;
    return option;
}
string loginMenu()
{
    cout << "Main Menu  >   Login" << endl;
    cout << "---------------------" << endl;
    cout << "Enter username :- ";
    cin >> username;
    cout << "Enter password :- ";
    string pass;
    cin >> pass;

    for (int i = 0; i < MAX_RECORDS; i++)
    {
        if (usernameA[i] == username && passwordsA[i] == pass)
        {
            return rolesA[i];
        }
    }
    return "EXIT";
}
void createaccount()
{
    bool flag = true;
    int c = 0, x;
    char ch;
    string user, pass, role;
    cout << "Enter the username: " << endl;
    cin >> user;
    while (flag)
    {
        cout << "Enter the password: " << endl;
        cin >> pass;
        c = 0;
        for (int i = 0; i < pass.length(); i++)
        {
            ch = pass[i];
            x = ch;
            if (pass[i] >= 48 && pass[i] <= 57)
            {
                c++;
            }
        }
        if (c == 0 || pass.length() < 2)
        {
            flag = true;
            cout << "Password Should Contain a Number and should be more than 1 character" << endl;
        }
        else
        {
            flag = false;
        }
    }

    cout << "Enter the role: " << endl;
    cin >> role;
    addUser(user, pass, role);
}
void addUser(string username, string password, string role)
{

    if (total_count < MAX_RECORDS)
    {
        usernameA[total_count] = username;
        passwordsA[total_count] = password;
        rolesA[total_count] = role;
        if (role == "user")
        {
            entry_count++;
        }

        total_count++;

        cout
            << endl
            << "Registered Successfully . You could login now" << endl
            << endl;
    }
    else
    {
        cout << "No More Space To Add Users." << endl;
    }
}
// MENU OF PASSENGER
int passengerMenu()
{
    int optionP;
    cout << "Main Menu  >   Login    >   Passenger" << endl;
    cout << "---------------------" << endl;
    cout << "Select one of the following options..." << endl;
    cout << "1- Registration" << endl;
    cout << "2- Enter Flight Details" << endl;
    cout << "3- Book from available Flights" << endl;
    cout << "4- See booked Flights " << endl;
    cout << "5- Cancel A flight  " << endl;
    cout << "6- Exit  " << endl;
    cout << "Your Option..";
    cin >> optionP;
    return optionP;
}
// REGISTRATION OF PASSENGER
void registrationP()
{
    string pName, cnic, pNum, mail, gender, passport;
    if (entry_count < MAX_RECORDS)
    {
        cout << "Main Menu  >   Login    >   Passenger    >    Registration" << endl;
        cout << "---------------------" << endl;

        cout << "Enter your name :- " << endl;
        cin >> pName;
        cout << "Enter your CNIC :- " << endl;
        cin >> cnic;
        cout << "Enter your passport no. :- " << endl;
        cin >> passport;
        cout << "Enter your Phone Number :- " << endl;
        cin >> pNum;
        cout << "Enter your email :- " << endl;
        cin >> mail;
        cout << "Enter your Gender :- " << endl;
        cin >> gender;
        pDataIntoArray(pName, cnic, passport, pNum, mail, gender);
    }
    else
    {
        cout << "No more space to enter records";
    }
}
void pDataIntoArray(string pname, string pcnic, string passportx, string pnum, string pmail, string pgender)
{
    pName[entry_count] = pname;
    cnic[entry_count] = pcnic;
    passport[entry_count] = passportx;
    pNum[entry_count] = pnum;
    mail[entry_count] = pmail;
    gender[entry_count] = pgender;
}
// FLIGHT DETAILS OF PASSENGER
void flightP()
{
    string departCity, arrCity, trip, departDate, pClass;
    int adult, child, infant, totalSeats;
    if (entry_count < MAX_RECORDS)
    {
        cout << "Main Menu  >   Login    >   Passenger    >    Enter Flight Details" << endl;
        cout << "---------------------" << endl;
        cout << "Departure from :- " << endl;
        cin >> departCity;
        cout << "Arrival To :- " << endl;
        cin >> arrCity;
        cout << "Trip Type :- " << endl;
        cin >> trip;
        cout << "Depart Date :-" << endl;
        cin >> departDate;
        cout << "---------Passengers----------" << endl;
        cout << "No of Passengers (Adult) :- " << endl;
        cin >> adult;
        cout << "No of Passengers (Child) :- " << endl;
        cin >> child;
        cout << "No of Passengers (Infant) :- " << endl;
        cin >> infant;
        cout << "---------Class---------" << endl;
        cout << "Enter Class :- " << endl;
        cin >> pClass;
        totalSeats = adult + child;
        pFlightDataIntoArray(departCity, arrCity, trip, departDate, pClass, adult, child, infant, totalSeats);
    }
    else
    {
        cout << "No more space to enter records";
    }
}
void pFlightDataIntoArray(string departCity, string arrCity, string trip, string departDate, string pClassF, int adultF, int childF, int infantF, int totalSeatsF)
{
    pDepartCity[entry_count] = departCity;
    pArrCity[entry_count] = arrCity;
    pTrip[entry_count] = trip;
    pDepartDate[entry_count] = departDate;
    pClass[entry_count] = pClassF;
    adult[entry_count] = adultF;
    child[entry_count] = childF;
    infant[entry_count] = infantF;
    totalSeats[entry_count] = totalSeatsF;
}
// Book from available Flights
int bookP()
{
    cout << "Main Menu  >   Login    >   Passenger    >   Book from available Flights" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < flight_count; i++)
    {
        if (pDepartCity[entry_count] == aDepartCity[i] && pArrCity[entry_count] == aArrCity[i] && pDepartDate[entry_count] == aDepartDate[i])
        {
            cout << "1- From \t " << pDepartCity[entry_count] << "\t To \t " << pArrCity[entry_count] << " \t at \t " << aDepartTime[i] << "\t \t " << pDepartDate[entry_count] << endl;
            cin >> optionF[entry_count];
            return optionF[entry_count];
        }
        else
        {
            optionF[entry_count] = 0;
        }
    }
    return optionF[entry_count];
}
void invoice()
{
    cout << endl
         << "Departure "
         << "\t"
         << "Arrival"
         << "\t"
         << "Trip"
         << "\t"
         << "Date"
         << "\t"
         << "Adults"
         << "\t"
         << "Child"
         << "\t"
         << "Infants"
         << "\t"
         << "Class " << endl;
    cout << pDepartCity[entry_count] << "\t" << pArrCity[entry_count] << "\t" << pTrip[entry_count] << "\t" << pDepartDate[entry_count] << "\t" << adult[entry_count] << "\t" << child[entry_count] << "\t" << infant[entry_count] << "\t" << pClass[entry_count] << endl;

    cout << endl
         << "--------Expenditures---------" << endl;

    cout << "No of Passengers (Adult)(600$) :- " << adult[entry_count] << endl;
    cout << "No of Passengers (Child) (450$):- " << child[entry_count] << endl;
    cout << "No of Passengers (Infant)(0$) :- " << infant[entry_count] << endl
         << endl;
    total[entry_count] = (adult[entry_count] * 600) + (child[entry_count] * 450);
    if (pClass[entry_count] == "Business" || pClass[entry_count] == "business")
    {
        total[entry_count] = total[entry_count] + 400;
    }
    cout << "Your Total Expenditure :- " << total[entry_count] << "$" << endl;
}
// See booked Flights
void bookedFlightsP()
{
    int i = 0;
    cout << "Main Menu  >   Login    >   Passenger    >   See booked Flights" << endl;
    cout << "---------------------" << endl;
    cout << "Your Flights..." << endl;
    for (int j = 0; j < MAX_RECORDS; j++)
    {
        if (rolesA[j] == "admin")
        {
            i--;
        }
        else if (usernameA[j] == username)
        {
            i = j + i;
            // cout << j << endl
            //      << i << endl;
            if (optionF[i] == 1)
            {
                cout << "1- From \t " << pDepartCity[i] << "\t To \t " << pArrCity[i] << " \t at \t 12:00 \t \t " << pDepartDate[i] << endl;
                cout << "Your Total Expenditure :- " << total[i] << endl;
            }
            else if (optionF[i] == 0)
            {
                cout << "No booked flights yet!!" << endl;
            }
        }
    }
}
// Cancel Flights
void cancelFlights()
{
    int i = 0;
    int cancel;
    cout << "Main Menu  >   Login    >   Passenger    >   Cancel A flight" << endl;
    cout << "---------------------" << endl;
    cout << "Your Flights..." << endl
         << endl;
    for (int j = 0; j < MAX_RECORDS; j++)
    {
        if (rolesA[j] == "admin")
        {
            i--;
        }
        else if (usernameA[j] == username)
        {
            i = j + i;
            if (optionF[i] == 1)
            {
                cout << "1- From \t " << pDepartCity[i] << "\t To \t " << pArrCity[i] << " \t at \t 12:00 \t \t " << pDepartDate[i] << endl;
                cout << "Your Total Expenditure :- " << total[i] << endl;
                cout << "Your Option..";
                cin >> cancel;
                if (cancel == 1)
                {
                    cout << "Flight has been cancelled!!";
                    optionF[entry_count] = 0;
                }
            }

            else if (optionF[i] == 0)
            {
                cout << "No booked flights yet!!" << endl
                     << endl;
            }
        }
    }
}
// ADMIN
// MENU OF ADMIN
int adminMenu()
{
    int optionA;
    cout << "Main Menu  >   Login    >   Admin " << endl;
    cout << "---------------------" << endl;
    cout << "Select one of the following options..." << endl;
    cout << "1- View Passengers Data" << endl;
    cout << "2- View Passengers travel Data" << endl;
    cout << "3- Add new flights " << endl;
    cout << "4- View flights " << endl;
    cout << "5- Allot Seats  " << endl;
    cout << "6- Ordered Passengers  " << endl;
    cout << "7- Exit" << endl;
    cout << "Your Option..";
    cin >> optionA;
    return optionA;
}
// VIEW PASSENGERS DATA
void viewPData()
{
    cout << "Main Menu  >   Login    >   Admin >   View Passengers Data" << endl;
    cout << "---------------------" << endl;
    cout << "Name"
         << "\t"
         << "CNIC"
         << "\t"
         << "Passport"
         << "\t"
         << "Phone"
         << "\t"
         << "Email"
         << "\t"
         << "Gender"
         << "\t"
         << "Seats"
         << "\t"
         << "Total" << endl;
    for (int i = 0; i <= entry_count; i++)
    {
        cout << pName[i] << "\t" << cnic[i] << "\t" << passport[i] << "\t\t" << pNum[i] << "\t " << mail[i] << "\t " << gender[i] << "\t " << seating[i] << "\t " << total[i] << endl;
    }
}
// VIEW PASSENGERS TRAVEL DATA
void viewPTravelData()
{
    cout << "Main Menu  >   Login    >   Admin >   View Passengers travel Data" << endl;
    cout << "---------------------" << endl;
    cout << "Departure"
         << "\t"
         << "Arrival"
         << "\t"
         << "Trip"
         << "\t"
         << "Date"
         << "\t"
         << "Adults"
         << "\t"
         << "Child"
         << "\t"
         << "Infants"
         << "\t"
         << "Class " << endl;
    for (int i = 0; i <= entry_count; i++)
    {
        cout << pDepartCity[i] << "\t" << pArrCity[i] << "\t" << pTrip[i] << "\t" << pDepartDate[i] << "\t" << adult[i] << "\t" << child[i] << "\t" << infant[i] << "\t" << pClass[i] << endl;
    }
}
// ADD FLIGHTS
void addFlights()
{
    cout << flight_count << endl;
    cout << "Main Menu  >   Login    >   Admin    >   Add new flights" << endl;
    cout << "---------------------" << endl;
    cout << "Departure from :- " << endl;
    cin >> aDepartCity[flight_count];
    cout << "Arrival To :- " << endl;
    cin >> aArrCity[flight_count];
    cout << "Trip Type :- " << endl;
    cin >> aTrip[flight_count];
    cout << "Depart Date :-" << endl;
    cin >> aDepartDate[flight_count];
    cout << "Depart Time :- " << endl;
    cin >> aDepartTime[flight_count];
    flight_count++;
}
void viewFlightsA()
{
    cout << flight_count << endl;

    cout << "Main Menu  >   Login    >   Admin >   View Flights" << endl;
    cout << "---------------------" << endl;
    cout << "Departure"
         << "\t"
         << "Arrival"
         << "\t"
         << "Trip"
         << "\t"
         << "DepartDate"
         << "\t"
         << "DepartTime"
         << endl;
    for (int i = 0; i < flight_count; i++)
    {
        cout << aDepartCity[i] << "\t" << aArrCity[i] << "\t" << aTrip[i] << "\t" << aDepartDate[i] << "\t" << aDepartTime[i] << endl;
    }
}
// ALLOT SEATS
void seats()
{
    int total = 0;
    string seat;
    cout << "Main Menu  >   Login    >   Admin    >   Allot Seats" << endl;
    cout << "---------------------" << endl;
    cout << "Departure"
         << "\t"
         << "Arrival"
         << "\t"
         << "Trip"
         << "\t"
         << "Date"
         << "\t"
         << "Adults"
         << "\t"
         << "Child"
         << "\t"
         << "Infants"
         << "\t"
         << "Class" << endl;
    for (int i = 0; i <= entry_count; i++)
    {
        cout << pDepartCity[i] << "\t" << pArrCity[i] << "\t" << pTrip[i] << "\t" << pDepartDate[i] << "\t" << adult[i] << "\t" << child[i] << "\t" << infant[i] << "\t" << pClass[i] << endl;

        cout << "No of Passengers (Adult) :- " << adult[i] << endl;
        cout << "No of Passengers (Child) :- " << child[i] << endl;
        cout << "No of Passengers (Infant) :- " << infant[i] << endl
             << endl;
        total = (adult[i]) + (child[i]);

        cout << "Enter Seat Range :- ";
        cin >> seating[i];
    }
}
void clearScreen()
{
    cout << "Press any key to continue " << endl;
    getch();
    system("cls");
}

// SORTED PASSENGERS
void sorting()
{
    cout << "Main Menu  >   Login    >   Admin    >   Ordered Passengers" << endl;
    cout << "---------------------" << endl;
    cout << "Name"
         << "\t"
         << "CNIC"
         << "\t"
         << "Passport"
         << "\t"
         << "Phone"
         << "\t"
         << "Email"
         << "\t"
         << "Gender"
         << "\t"
         << "Seats"
         << "\t"
         << "Total" << endl;
    for (int i = 0; i <= entry_count; i++)
    {
        for (int j = i + 1; j <= entry_count; j++)
        {
            if (total[j] > total[i])
            { // sort total
                int temp = total[i];
                total[i] = total[j];
                total[j] = temp;
                // sort pName
                string namex = pName[i];
                pName[i] = pName[j];
                pName[j] = namex;
                // sort cnic array
                string name1 = cnic[i];
                cnic[i] = cnic[j];
                cnic[j] = name1;
                // sort passport
                string name2 = passport[i];
                passport[i] = passport[j];
                passport[j] = name2;
                // sort pNum
                string name3 = pNum[i];
                pNum[i] = pNum[j];
                pNum[j] = name3;
                // sort mail
                string name4 = mail[i];
                mail[i] = mail[j];
                mail[j] = name4;
                // sort gender
                string name5 = gender[i];
                gender[i] = gender[j];
                gender[j] = name5;
                // sort gender
                string name6 = seating[i];
                seating[i] = seating[j];
                seating[j] = name6;
            }
        }
    }
    for (int i = 0; i <= entry_count; i++)
    {
        cout << pName[i] << "\t" << cnic[i] << "\t" << passport[i] << "\t" << pNum[i] << "\t" << mail[i] << "\t" << gender[i] << "\t" << seating[i] << "\t" << total[i] << endl;
    }
}
string parserecord(string line, int field)
{
    int commacount = 0;
    string item;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        if (commacount == field)
        {
            if (line[i] != ',')
            {
                item = item + line[i];
            }
        }
    }
    return item;
}
int convert(string n) // to convert a string into integer if its interger

{
    if (n == "0")
    {
        return 0;
    }
    float num = 0;
    int x;
    for (int i = 0; i < n.length(); i++)
    {
        x = (n[n.length() - i - 1]) - 48;
        num = num + x * pow(10, i);
    }
    return num;
}
void loadData()
{
    string word1;
    fstream credFile;
    credFile.open("cred.txt", ios::in);
    int j = 0;
    while (!credFile.eof())
    {
        getline(credFile, word1);

        usernameA[j] = parserecord(word1, 0);
        passwordsA[j] = parserecord(word1, 1);
        rolesA[j] = parserecord(word1, 2);
        if (rolesA[j] == "user")
        {
            entry_count++;
        }
        j++;
    }
    credFile.close();
    string temp, temp1;
    string word;
    fstream file;
    file.open("admin.txt", ios::in);
    int i = 0;
    while (!file.eof())
    {
        getline(file, word);

        pName[i] = parserecord(word, 0);
        cnic[i] = parserecord(word, 1);
        passport[i] = parserecord(word, 2);
        pNum[i] = parserecord(word, 3);
        mail[i] = parserecord(word, 4);
        gender[i] = parserecord(word, 5);
        seating[i] = parserecord(word, 6);
        temp = parserecord(word, 7);
        total[i] = convert(temp);
        pDepartCity[i] = parserecord(word, 8);
        pArrCity[i] = parserecord(word, 9);
        pTrip[i] = parserecord(word, 10);
        pDepartDate[i] = parserecord(word, 11);
        temp = parserecord(word, 12);
        adult[i] = convert(temp);
        temp = parserecord(word, 13);
        child[i] = convert(temp);
        temp = parserecord(word, 14);
        infant[i] = convert(temp);
        pClass[i] = parserecord(word, 15);
        temp = parserecord(word, 16);
        optionF[i] = convert(temp);
        i++;
    }
    file.close();

    int z = 0;
    fstream fFile;
    string word2;
    fFile.open("flight.txt", ios::in);
    while (!fFile.eof())
    {
        getline(fFile, word2);
        aDepartCity[z] = parserecord(word2, 0);
        aArrCity[z] = parserecord(word2, 1);
        aTrip[z] = parserecord(word2, 2);
        aDepartDate[z] = parserecord(word2, 3);
        aDepartTime[z] = parserecord(word2, 4);
        z++;
        flight_count++;
    }
    fFile.close();
}
void storeData()
{
    // ADMIN STORE
    fstream adminFile;
    adminFile.open("admin.txt", ios::out);
    for (int i = 0; i <= entry_count; i++)
    {
        adminFile << pName[i];
        adminFile << ",";
        adminFile << cnic[i];
        adminFile << ",";
        adminFile << passport[i];
        adminFile << ",";
        adminFile << pNum[i];
        adminFile << ",";
        adminFile << mail[i];
        adminFile << ",";
        adminFile << gender[i];
        adminFile << ",";
        adminFile << seating[i];
        adminFile << ",";
        adminFile << total[i];
        adminFile << ",";
        adminFile << pDepartCity[i];
        adminFile << ",";
        adminFile << pArrCity[i];
        adminFile << ",";
        adminFile << pTrip[i];
        adminFile << ",";
        adminFile << pDepartDate[i];
        adminFile << ",";
        adminFile << adult[i];
        adminFile << ",";
        adminFile << child[i];
        adminFile << ",";
        adminFile << infant[i];
        adminFile << ",";
        adminFile << pClass[i];
        adminFile << ",";
        adminFile << optionF[i];
        adminFile << endl;
    }
    adminFile.close();
}
void storeCred()
{
    // ADMIN STORE
    fstream credFile;
    credFile.open("cred.txt", ios::out);
    for (int i = 0; i < total_count; i++)
    {
        credFile << usernameA[i];
        credFile << ",";
        credFile << passwordsA[i];
        credFile << ",";
        credFile << rolesA[i];
        credFile << endl;
    }
    credFile.close();
}
void storeFlight()
{
    // ADMIN STORE
    fstream fFile;
    fFile.open("flight.txt", ios::out);
    for (int i = 0; i < flight_count; i++)
    {
        fFile << aDepartCity[i];
        fFile << ",";
        fFile << aArrCity[i];
        fFile << ",";
        fFile << aTrip[i];
        fFile << ",";
        fFile << aDepartDate[i];
        fFile << ",";
        fFile << aDepartTime[i];
        fFile << endl;
    }
    fFile.close();
}