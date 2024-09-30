#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma warning (disable:4996)

//Definations

#define A 4.00
#define A_MINUS 3.75
#define B_PLUS 3.50
#define B 3.00
#define B_MINUS 2.75
#define C_PLUS 2.50
#define C 2.00
#define F 0.00

#define creditHoursAAA1003 3
#define creditHoursAAA1014 4


//static values
static double bhSem1Gpa = 0, bhSem2Gpa = 0, bhSem3Gpa = 0;
static double bhCgpa = 0;

static double jkSem1Gpa = 0, jkSem2Gpa = 0, jkSem3Gpa = 0;
static double jkCgpa = 0;



int main();
void admin();
void student();
double getGradeMarks(char grade[5]);

double getGradeMarks(char grade[5]) {
    if (strcmp(grade, "A") == 0 || strcmp(grade, "a") == 0)
        return A;
    else if (strcmp(grade, "A-") == 0 || strcmp(grade, "a-") == 0)
        return A_MINUS;
    else if (strcmp(grade, "B+") == 0 || strcmp(grade, "b+") == 0)
        return B_PLUS;
    else if (strcmp(grade, "B") == 0 || strcmp(grade, "b") == 0)
        return B;
    else if (strcmp(grade, "B-") == 0 || strcmp(grade, "b-") == 0)
        return B_MINUS;
    else if (strcmp(grade, "C+") == 0 || strcmp(grade, "c+") == 0)
        return C_PLUS;
    else if (strcmp(grade, "C") == 0 || strcmp(grade, "c") == 0)
        return C;
    else if (strcmp(grade, "F") == 0 || strcmp(grade, "f") == 0)
        return F;
    else {
        printf("That Is Not a Grade!\n");
        system("pause");
        printf("Please Try Again.");
        system("cls");
        admin();


    }
}


int main()
{
    int num;
    system("cls");
    printf("\n Welcome!\n");

    printf("==========================\n");
    printf("        Main  Page        \n");
    printf("==========================\n");

    printf("----------------------------------------------------------------------- \n");
    printf("Do You Want To Enter Admin Mode, Student Mode Or Exit The Program?\n");
    printf("----------------------------------------------------------------------- \n");
    printf("\n");
    printf("1. Admin Mode\n");
    printf("2. Student Mode\n");
    printf("3. Exit\n");
    printf("\n");
    printf("Please Enter 1, 2, or 3.\n>");
    rewind(stdin);
    scanf("%d", &num);
    printf("\n");

    switch (num) {
    case 1: system("pause");  admin();
    case 2: system("pause");  student();
    case 3: return 0;
    default:
        printf("That Is Not An Option! Please Try Again.\n");
        system("pause");
        main();
        return 0;
    }
}

//Still cant get the grade part to work.
void admin()
{

    char tcrName[50], stdName[50], stdId[10], tcrId[10];
    char grade;
    int student, mark, total = 0, stdValid = 0, tcrValid = 0, i;

    char checkTcrName[][50] = { "Gary Chanderin" };
    char checkTcrId[][10] = { "LPO123" };
    char checkStdName[][50] = { "Badrul Haziq", "Jonathan Khishern" };
    char checkStdId[][10] = { "LPK123", "LPK456" };

admin:

    system("cls");
    printf("============================\n");
    printf("        Admin   Mode         \n");
    printf("============================\n");

    printf("Please Enter Your Name\n >");
    rewind(stdin);
    scanf(" %49[^\n]", &tcrName);
    printf("\n");
    printf("Please Enter Your Id\n >");
    rewind(stdin);
    scanf("%9[^\n]", &tcrId);



    for (int i = 0; i < sizeof(tcrName) / sizeof(tcrName[0]); i++) {
        if (strcmp(tcrName, checkTcrName[i]) == 0 && strcmp(tcrId, checkTcrId[i]) == 0)
        {
            tcrValid = 1;
            break;
        }
    }
    if (tcrValid)
    {
        printf("\n");
        printf("Welcome, %s Your Id Number Is %s\n", tcrName, tcrId);
        printf("--------------------------------------------------------\n");
        printf("\n");

        printf("Enter Any Key To Contine.");
        system("pause");
        system("cls");

    std:

        system("cls");
;        printf("==============================================\n");
        printf("        Verify  Student  Name  and  ID        \n");
        printf("==============================================\n");

        printf("Please Enter The Student's Name: ");
        rewind(stdin);
        scanf("%49[^\n]", &stdName);

        printf("Please Enter The Student's Id: ");
        rewind(stdin);
        scanf("%9[^\n]", &stdId);
        printf("\n");

        printf("The Student's Name Is %s And The Id Number Is %s\n", stdName, stdId);
        printf("-------------------------------------------------------------------\n");
        printf("\n");

        system("pause");

        for (int i = 0; i < sizeof(stdName) / sizeof(stdName[0]); i++) {
            if (strcmp(stdName, checkStdName[i]) == 0 && strcmp(stdId, checkStdId[i]) == 0)
            {
                stdValid = 1;
                break;
            }
        }
        if (stdValid)
        {
            int sem1AAA1003, sem1AAA1014, sem2AAA1003, sem2AAA1014, sem3AAA1003, sem3AAA1014;
            double sem1QPAAA1003 = 0, sem1QPAAA1014 = 0, sem2QPAAA1003 = 0, sem2QPAAA1014 = 0, sem3QPAAA1003 = 0, sem3QPAAA1014 = 0;
            char grade[5];
            double result1, result2, result3, result4, result5, result6;


            system("cls");

            printf("===================================\n");
            printf("        Enter  Student  Grade        \n");
            printf("===================================\n");

            printf("Semester 1\n");
            printf("Enter Student's Grade For Course AAA1003: ");
            scanf("%s", grade);
            result1 = getGradeMarks(grade);
            sem1AAA1003 = result1;

            printf("Enter Student's Grade For Course AAA1014: ");
            scanf("%s", grade);
            result2 = getGradeMarks(grade);
            sem1AAA1014 = result2;
            printf("\n");

            printf("Semester 2\n");
            printf("Enter Student's Grade For Course AAA1003: ");
            scanf("%s", grade);
            result3 = getGradeMarks(grade);
            sem2AAA1003 = result3;

            printf("Enter Student's Grade For Course AAA1014: ");
            scanf("%s", grade);
            result4 = getGradeMarks(grade);
            sem2AAA1014 = result4;
            printf("\n");

            printf("Semester 3\n");
            printf("Enter Student's Grade For Course AAA1003: ");
            scanf("%s", grade);
            result5 = getGradeMarks(grade);
            sem3AAA1003 = result5;

            printf("Enter Student's Grade For Course AAA1014: ");
            scanf("%s", grade);
            result6 = getGradeMarks(grade);
            sem3AAA1014 = result6;
            printf("\n");

            system("pause");

            sem1QPAAA1003 = sem1AAA1003 * creditHoursAAA1003;
            sem1QPAAA1014 = sem1AAA1014 * creditHoursAAA1014;

            sem2QPAAA1003 = sem2AAA1003 * creditHoursAAA1003;
            sem2QPAAA1014 = sem2AAA1014 * creditHoursAAA1014;

            sem3QPAAA1003 = sem3AAA1003 * creditHoursAAA1003;
            sem3QPAAA1014 = sem3AAA1014 * creditHoursAAA1014;

            if (strcmp(stdName, "Badrul Haziq") == 0) 
            {

                bhSem1Gpa = (sem1QPAAA1003 + sem1QPAAA1014) / (creditHoursAAA1003 + creditHoursAAA1014);
                bhSem2Gpa = (sem2QPAAA1003 + sem2QPAAA1014) / (creditHoursAAA1003 + creditHoursAAA1014);
                bhSem3Gpa = (sem3QPAAA1003 + sem3QPAAA1014) / (creditHoursAAA1003 + creditHoursAAA1014);

                bhCgpa = (bhSem1Gpa + bhSem2Gpa + bhSem3Gpa) / 3;

                printf("The Student %s, Id Number: %s Has a\n", stdName, stdId);
                printf("\n");
                system("cls");

                printf("================================\n");
                printf("        Student  Results        \n");
                printf("================================\n");
                printf("\n");

                printf("==================================\n");
                printf("Semester 1 GPA: %.2f\n", bhSem1Gpa);
                printf("Semester 2 GPA: %.2f\n", bhSem2Gpa);
                printf("Semester 3 GPA: %.2f\n", bhSem3Gpa);
                printf("==================================\n");
                printf("\n");

                printf("====================\n");
                printf("CGPA: %.2f\n", bhCgpa);
                printf("====================\n");

                system("pause");
                system("cls");
            
            }
            else if (strcmp(stdName, "Jonathan Khishern") == 0) { 

                jkSem1Gpa = (sem1QPAAA1003 + sem1QPAAA1014) / (creditHoursAAA1003 + creditHoursAAA1014);
                jkSem2Gpa = (sem2QPAAA1003 + sem2QPAAA1014) / (creditHoursAAA1003 + creditHoursAAA1014);
                jkSem3Gpa = (sem3QPAAA1003 + sem3QPAAA1014) / (creditHoursAAA1003 + creditHoursAAA1014);

                jkCgpa = (jkSem1Gpa + jkSem2Gpa + jkSem3Gpa) / 3;

                printf("The Student %s, Id Number: %s Has a\n", stdName, stdId);
                printf("\n");

                system("cls");

                printf("================================\n");
                printf("        Student  Results        \n");
                printf("================================\n");
                printf("\n");

                printf("==================================\n");
                printf("Semester 1 GPA: %.2f\n", jkSem1Gpa);
                printf("Semester 2 GPA: %.2f\n", jkSem2Gpa);
                printf("Semester 3 GPA: %.2f\n", jkSem3Gpa);
                printf("==================================\n");
                printf("\n");

                printf("====================\n");
                printf("CGPA: %.2f\n", jkCgpa);
                printf("====================\n");

                system("pause");
                system("cls");

            }

            else
                return 0;



            int number;
        confirmation:

            printf("=============================================\n");
            printf("        Do  You  Want  To  Continue?         \n");
            printf("=============================================\n");


            printf("1.Continue Back To  Main Page\n");
            printf("\n");
            printf("2.Exit Program\n");
            printf("\n");
            printf("Please Enter 1, 2.\n>");
            rewind(stdin);
            scanf("%d", &number);
            printf("\n");

            switch (number) 
            {
            case 1: system("pause");  main();
            case 2: return 0;
            default:
                printf("That Is Not An Option! Please Try Again.\n");
                system("pause");
                system("cls");
                goto confirmation;
                return 0;
            
            
            }
        }
        else {
            printf("You Have Entered An Invalid Name or Code.\n");
            printf("Please Try Again!\n");
            system("pause");
            goto std;

        }


    }
    else
    {
        printf("The Name and Id That You Have Entered Is Invalid.\n");
        printf("Please Try Again!\n");
        system("pause");
        goto admin;

    }
    system("pause");
}

void student()
{

    //how to get data to display?

    char name[50], id[9];
    char checkStudentName[][50] = { "Badrul Haziq", "Jonathan Khishern" };
    char checkStudentId[][10] = { "LPK123", "LPK456" };
    int studentValid;

    int number;
    double aimCgpa = 0, nextCgpa = 0;


    studentValid = 0;

student:

    system("cls");
    printf("===============================\n");
    printf("        Student   Mode        \n");
    printf("===============================\n");

    printf("Please Enter Your Name:\n>");
    rewind(stdin);
    scanf("%49[^\n]", &name);
    printf("\n");

    printf("Please Enter Your Student Id:\n>");
    rewind(stdin);
    scanf("%9[^\n]", &id);
    printf("\n");



    for (int i = 0; i < sizeof(name) / sizeof(name[0]); i++)

    {

        if (strcmp(name, "Badrul Haziq") == 0)
        {
            printf("Welcome! Your Name is %s And Your Id Number Is %s\n", name, id);
            printf("--------------------------------------------------------------------\n");
            printf("\n");

            system("pause");
            system("cls");


            printf("==================================\n");
            printf("           Results  Page         \n");
            printf("==================================\n");
            printf("\n");

            printf("==================================\n");
            printf("Your Semester 1 GPA Is %.2f\n", bhSem1Gpa);

            printf("Your Semester 2 GPA Is %.2f\n", bhSem2Gpa);

            printf("Your Semester 3 GPA Is %.2f\n", bhSem3Gpa);
            printf("==================================\n");
            printf("\n");

            printf("=========================\n");
            printf("Your CGPA Is %.2f\n", bhCgpa);
            printf("=========================\n");

            system("pause");

        confirmation1:

            system("cls");
            printf("=============================================\n");
            printf("        Do  You  Want  To  Continue?         \n");
            printf("=============================================\n");
            printf("\n");

            printf("1.Do you want to calculate your next Cgpa to get an aimed Cgpa?\n");
            printf("\n");
            printf("2.Exit Program\n");
            printf("\n");
            printf("Please Enter 1, 2.\n>");
            rewind(stdin);
            scanf("%d", &number);
            printf("\n");

            switch (number)
            {
            case 1: system("pause");  goto aim1;
            case 2: system("pause");  exit(0);
            default:
                printf("That Is Not An Option! Please Try Again.\n");
                system("pause");
                system("cls");
                goto confirmation1;

            aim1:
                system("cls");

                printf("==============================\n");
                printf("        Desired  CGPA         \n");
                printf("==============================\n");
                printf("\n");

                printf("Please enter your the minimum CGPA you want to achieve for next semester.\n>");
                scanf("%lf", &aimCgpa);

                nextCgpa = 2 * aimCgpa - bhCgpa;

                if (nextCgpa <= 4.00) {
                    printf("\n");
                    printf("Your next Cgpa has to be %.2lf or higher.\n", nextCgpa);
                    system("pause");
                }

                else {
                    printf("\n");
                    printf("That goal is unreachable.\n");
                    system("pause");
                }


                system("cls");
                printf("=============================================\n");
                printf("        Do  You  Want  To  Continue?         \n");
                printf("=============================================\n");
                printf("\n");

                printf("1.Do you want to Try Again?\n");
                printf("\n");
                printf("2.Do you want to go back to the Main Page?\n");
                printf("\n");
                printf("3.Exit Program\n");
                printf("\n");
                printf("Please Enter 1, 2 or 3.\n>");
                rewind(stdin);
                scanf("%d", &number);
                printf("\n");

                switch (number)
                {
                case 1: system("pause");  goto aim1;
                case 2: system("pause");  main();
                case 3: exit(0);
                default:
                    printf("That Is Not An Option! Please Try Again.\n");
                    system("pause");
                    system("cls");
                    goto confirmation1;
                }


            }

        }
        else
        {
            printf("You Have Entered An Invalid Name Or Id.\n");
            system("pause");
            goto student;
        }
        system("pause");
        main();


    
    }



        if (strcmp(name, "Jonathan Khishern") == 0) 
        {
            printf("Welcome! Your Name is %s And Your Id Number Is %s\n", name, id);
            printf("--------------------------------------------------------------------\n");
            printf("\n");

            system("pause");
            system("cls");


            printf("==================================\n");
            printf("           Results  Page         \n");
            printf("==================================\n");
            printf("\n");

            printf("==================================\n");
            printf("Your Semester 1 GPA Is %.2f\n", jkSem1Gpa);

            printf("Your Semester 2 GPA Is %.2f\n", jkSem2Gpa);

            printf("Your Semester 3 GPA Is %.2f\n", jkSem3Gpa);
            printf("==================================\n");
            printf("\n");

            printf("=========================\n");
            printf("Your CGPA Is %.2f\n",jkCgpa);
            printf("=========================\n");

            system("pause");

        confirmation:

            system("cls");
            printf("=============================================\n");
            printf("        Do  You  Want  To  Continue?         \n");
            printf("=============================================\n");
            printf("\n");

            printf("1.Do you want to calculate your next Cgpa to get an aimed Cgpa?\n");
            printf("\n");
            printf("2.Exit Program\n");
            printf("\n");
            printf("Please Enter 1, 2.\n>");
            rewind(stdin);
            scanf("%d", &number);
            printf("\n");

            switch (number)
            {
            case 1: system("pause");  goto aim;
            case 2: system("pause");  exit(0);
            default:
                printf("That Is Not An Option! Please Try Again.\n");
                system("pause");
                system("cls");
                goto confirmation;

            aim:
                system("cls");

                printf("==============================\n");
                printf("        Desired  CGPA         \n");
                printf("==============================\n");
                printf("\n");

                printf("Please enter your the minimum CGPA you want to achieve for next semester.\n>");
                scanf("%lf", &aimCgpa);

                nextCgpa = 2 * aimCgpa - jkCgpa;

                if (nextCgpa <= 4.00) {
                    printf("\n");
                    printf("Your next Cgpa has to be %.2lf or higher.\n", nextCgpa);
                    system("pause");
                }

                else {
                    printf("\n");
                    printf("That goal is unreachable.\n");
                    system("pause");
                }


                system("cls");
                printf("=============================================\n");
                printf("        Do  You  Want  To  Continue?         \n");
                printf("=============================================\n");
                printf("\n");

                printf("1.Do you want to Try Again?\n");
                printf("\n");
                printf("2.Do you want to go back to the Main Page?\n");
                printf("\n");
                printf("3.Exit Program\n");
                printf("\n");
                printf("Please Enter 1, 2 or 3.\n>");
                rewind(stdin);
                scanf("%d", &number);
                printf("\n");

                switch (number)
                {
                case 1: system("pause");  goto aim1;
                case 2: system("pause");  main();
                case 3: exit(0);
                default:
                    printf("That Is Not An Option! Please Try Again.\n");
                    system("pause");
                    system("cls");
                    goto confirmation1;
                }

            
        }
        
    }
    else
    {
        printf("You Have Entered An Invalid Name Or Id.\n");
        system("pause");
        goto student;
    }
    system("pause");
    main();


}

