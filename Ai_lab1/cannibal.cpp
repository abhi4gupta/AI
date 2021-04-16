#include<bits/stdc++.h>
using namespace std;

int intialmissionaries = 3;

int intialCannibal = 3;

int finalmissinories = 0;

int  finalCannibal = 0;

int  Mystatus = 0; 

int flagptr = 0;

int grouping = 0;

void printSolution(string boatPass1, string boatPass2)
{
    cout<<endl;
   
    for (int i = 0;i <finalmissinories;i++){ 
        
        cout << " MISSIONARIES "; 

    }
    for (int i = 0; i < finalCannibal; i++){

        cout << " CANNIBAL "; 

    }

    if (flagptr == 0){

        cout << " -------------   in boat (" << boatPass1 << "," << boatPass2 << ")    ";

    }
    else{

         cout << "    in boat (" << boatPass1 << "," << boatPass2 << ")  -------------------  ";
    }
    for (int i = 0; i < intialmissionaries; i++){

        cout << " MISSIONARIES ";

    }
    for (int i = 0; i < intialCannibal; i++){

        cout << " CANNIBAL "; 

    }

    cout<<endl;
}


int success() {

    return (finalCannibal == 3 && finalmissinories == 3) ? 0 : 1;

}

void MissnariesAndCannibal()
{
    while (success()){
        if(flagptr){
            if(grouping==1){

                printSolution("MISSIONARIES", "MISSIONARIES");
                finalmissinories = finalmissinories + 2;

            }
            else if(grouping==2){
                   
                 printSolution("CANNIBAL", "CANNIBAL");
                finalCannibal = finalCannibal + 2;

            }
            else if(grouping==3){

                printSolution("MISSIONARIES", "CANNIBAL");
                finalCannibal = finalCannibal + 1;
                finalmissinories = finalmissinories + 1;

            }
            if(success()){
                if (((finalCannibal > 1 && finalmissinories == 0) || intialmissionaries == 0))
                {

                    finalCannibal--;
                    grouping = 1;
                    printSolution("CANNIBAL", "   " );
                    flagptr = 0;

                }
                
                else if ((intialCannibal + 2) > intialmissionaries)
                {

                    finalCannibal--; finalmissinories--;

                    grouping = 2;
                    printSolution("CANNIBAL", "MISSIONARIES");
                    flagptr = 0;

                }
            }
        }
        else{
               if(grouping==1){

                 printSolution("CANNIBAL", "   ");


                 intialCannibal++;

               }
               if(grouping==2){

                      printSolution("CANNIBAL", "MISSIONARIES");


                      intialCannibal++; intialmissionaries++;

               }
               if (((intialmissionaries - 2) >= intialCannibal && (finalmissinories + 2) >= 
                finalCannibal) || (intialmissionaries - 2) == 0)
            {

               
               intialmissionaries = intialmissionaries - 2;


                grouping = 1;
                
                printSolution("MISSIONARIES", "MISSIONARIES");


                flagptr = 1;

                


            }
            else if ((intialCannibal - 2) < (intialmissionaries && (finalmissinories == 0 || (finalCannibal + 2) 
                <= finalmissinories)) || intialmissionaries == 0)
            {

               
                intialCannibal = intialCannibal - 2;

                grouping = 2;

                printSolution("CANNIBAL", "CANNIBAL");

                flagptr = 1;

            }
   
            else if ((intialCannibal--) <= (intialmissionaries--) && (finalmissinories++) >= (finalCannibal++))
            {

                 intialCannibal = intialCannibal - 1;

                intialmissionaries = intialmissionaries - 1;

                grouping = 3;
                
                printSolution("MISSIONARIES", "CANNIBAL");

                flagptr = 1;

               

            }

        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
   freopen("D:/input.txt","r",stdin);
   freopen("D:/output.txt","w",stdout);
   #endif
    cout << "-------------  MISSIONARIES AND CANNIBAL PROBLEM SOLVED BY ABHISHEK---------- \n";
    printSolution("   ", "   ");


    MissnariesAndCannibal();


    printSolution("   ", "   ");

}