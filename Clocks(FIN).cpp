/*
CS210 Project One - Clocks
Kelly Reinersman
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <time.h>

using namespace std;
/*Global Variables*/
  int userInput; /*from the menu*/
  int inHour;/*hour from user*/
  int inMinutes;/*minutes from user*/
  int inSeconds;/*seconds from user*/
  int inHoursMil; /* miltime conversion*/
  bool valid = false;
  string timeOfDay= "AM";
  
int militaryTime (){
 if (inHour <= 11){
     timeOfDay = "AM";
     inHoursMil = inHour;
 }

    if((inHoursMil >= 12)&&(inHoursMil < 24)){ /* for hours in mil time 12:00---23:59 */
     timeOfDay = "PM";
  }
  return inHoursMil;
}


void ClockDisplay() {
if((inHoursMil >=12)&&(inHoursMil < 24)){
    timeOfDay = "PM";
} 
  else if  ((inHour >=1)&&(inHour <12) && (inHoursMil>=0)&&(inHoursMil < 12)){
    timeOfDay = "AM";
  }
	//Top Boarder
  cout << setw(26) << left << "****************************" << "     ";
	cout << setw(26) << right << "****************************" << endl;
	
  //Clock Print to Console
	
  cout << "*" << "       12-Hour Clock      *" << "     " << "*      24-Hour Clock       *" << endl;
	
  
  cout << "*        " <<setw(2)<<setfill('0')<< inHour << ":"<<setw(2)<<setfill('0')<< inMinutes << ":"<< setw(2)<<setfill('0')<< inSeconds << " " << timeOfDay<< "       *" << "     " << "*        "<<setw(2)<<setfill('0')<< militaryTime() << ":"<<setw(2)<<setfill('0')<< inMinutes << ":"<< setw(2)<<setfill('0')<< inSeconds << "          *" << endl; 
  //cout << "*        " << f12_hour << ":" << min << ":" << sec << " " << timeFrame << "       *" << "     " << "*        " << f24_hour << ":" << min << ":" << sec << "          *" << endl;
	//Bottom Boarder
  cout << setw(26) << left << "****************************" << "     ";
	cout << setw(26) << right << "****************************" << endl;
}

void MenuPrint() {

	//Prints the menu for the user to interact with

	cout << setw(26) << left << "****************************" << endl;
	cout << "* 1 - Add One Hour         *" << endl;
	cout << "* 2 - Add One Minute       *" << endl;
	cout << "* 3 - Add One Second       *" << endl;
	cout << "* 4 - Exit Program         *" << endl;
	cout << setw(26) << left << "****************************" << endl;

}
int AddHour(){
    inHour = inHour + 1;
 	inHoursMil = inHoursMil +1;
  if (inHour >= 12 ) {
      inHour = inHour- 12;
      timeOfDay = "PM";
  }
  if((inHoursMil >=12) && (inHoursMil < 24)){
      inHoursMil = inHoursMil +1 ; 
      timeOfDay = "PM";
  }
      if (inHoursMil >= 24){
          inHoursMil = inHoursMil-24;
          timeOfDay = "AM";
  }
    ClockDisplay();
  return inHour;
}
int AddMinute(){
  inMinutes = inMinutes + 1;
  if (inMinutes > 59){
    inHour = inHour +1;
    inMinutes = inMinutes - 60;
  }
    ClockDisplay();
    return inMinutes;
  }/*if over 60 minutes add an hour to the time*/
int AddSecond(){
  inSeconds = inSeconds +1;
    if(inSeconds > 59){
        inMinutes= inMinutes +1; /*if greater than 59 seconds add a minute to the time*/
        inSeconds = inSeconds - 60; /* make sure this works*/
        }
        if (inMinutes>59){
            inHour = inHour+1;
            }
  ClockDisplay();
  return inSeconds;
} 
void GetMenuInput(){
    cout << "What would you like to do? Please enter the menu option number only." << endl;
    cin >> userInput;
  if ((userInput < 1) || (userInput > 4 )){
    cout << "InValid Menu Entry" << endl;
  }
    if( userInput ==1 ){
      AddHour();
    }
    if( userInput ==2 ){
      AddMinute();
    }
    if(userInput == 3){
      AddSecond();
    }
    if ( userInput == 4 ){
      cout << "Goodbye for now. Exiting Program." << endl;
    }

  
  }
int GetUserTime (){
  bool valid = false;
   cout << "What time is it right now?" << endl;
    cout << "Enter Hour: "<< endl;
  cin >> inHour;
    cout << "Enter Minute: "<< endl;
  cin >> inMinutes;
    cout << "Enter Seconds: "<< endl;
  cin >> inSeconds;
  if ((inHour < 13 )&& (inHour >0) && (inMinutes>=0) && ( inMinutes < 60)&& (inSeconds >=0) && (inSeconds < 60)){ /*checking to see if time entered is valid*/
    valid = true;
}
  else{ 
    cout << "Not a Valid TimeFrame." << endl;
    }
return valid;
}

int main() {
  ClockDisplay(); /*display clock if valid entry*/
  GetUserTime();
  ClockDisplay();
  while(userInput!=4){
  MenuPrint();
  GetMenuInput();

  }
}