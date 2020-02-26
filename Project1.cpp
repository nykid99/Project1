// Kenneth Cho
//2325383
//kecho@chapman.edu
//CPSC350
//Project1
/*This is a simple analysis program that will compute basic statistics for a list of DNA strings.
The program reads the lines in a text file that contain dna sequences specified by the user,
computes the sum, mean, variance, andstandard deviation of the length of the DNA strings in the list,
he relative probability of each nucleotide (A,C,T, or G), as well as the probability of each nucleotide bigram
AA, AC, AT, AG, CA, CC, CT, CG, etc) across the entire collection.

the program will then generate 1000 DNA strings whose lengthsfollowa Gaussian distribution with the same mean andvariance as calculated above.
The relative frequency of nucleotides will also follow the statistics calculated above. the 1000 strings are written to a file called yourname.out*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){ //main method
  double Aprob = 0;
  double Cprob = 0; //these double variables will hold the probabilites for single nucleotides and biagrams
  double Tprob = 0;
  double Gprob = 0;
  double AAprob = 0;
  double ACprob = 0;
  double ATprob = 0;
  double AGprob = 0;
  double CAprob = 0;
  double CCprob = 0;
  double CTprob = 0;
  double CGprob = 0;
  double TAprob = 0;
  double TCprob = 0;
  double TTprob = 0;
  double TGprob = 0;
  double GAprob = 0;
  double GCprob = 0;
  double GTprob = 0;
  double GGprob = 0;

  float mean = 0;          // mean value
  float variance = 0;      // the variance
  float standev = 0;       //standard deviation
  float numberofLines = 0; //number of lines in the text file
  float lengthtotal = 0;   //sum of the length of strings


  float Atotal = 0;        //total number of single nucleotides and bigram in the text file
  float Ctotal = 0;
  float Ttotal = 0;
  float Gtotal = 0;
  float AAtotal = 0;
  float ACtotal = 0;
  float ATtotal = 0;
  float AGtotal = 0;
  float CAtotal = 0;
  float CCtotal = 0;
  float CTtotal = 0;
  float CGtotal = 0;
  float TAtotal = 0;
  float TCtotal = 0;
  float TTtotal = 0;
  float TGtotal = 0;
  float GAtotal = 0;
  float GCtotal = 0;
  float GTtotal = 0;
  float GGtotal = 0;

  int start;       // starter string
  string inty;     //input string
  int cont;
  ifstream inFile;   //input stream
  ofstream outFile;  //output stream
  string line;       //this will hold the string in the lines in the text files
  string filename;   //file name
  float linelength;  //length of the line
  const double pi = 3.1415926535897; //pi is declared here as a constant
  float gaussian;                    //this is the C
  string enterLine;

  string combline;   //this holds the strings that will be printed out the yourname.out
  float a;           //these numbers are used in the outFile process
  float b;
  float d;
  float k;
  cout << "welcome to the dna program!" << endl;
  cout << "please press y to start the program or n to stop the program" << endl;
  cin >> inty;
  while(true){
    if(inty == "y"||"Y"){               //if user types in y, the program continues into a while loop
      while(inty == "y"||"Y"){          //while the input is y or Y, user is asked again if they would like to continue running
        cout << "If you would like to run the program, press 1. if you would like to quit, press 2" << endl;
        cin >> start;
        if(start == 1){                                  //if the user presses 1, the program starts
          cout << "please enter the filename: " << endl; //the name of the file is acquired here from the user
          cin >> filename;
          inFile.open(filename);
          if (inFile.fail()){                            //if file is not found, the system exits
            cerr << "Error opening file" << endl;
            cout << "exiting program" << endl;
            exit(1);
          }
          else if(inFile.is_open()){                     //if the file is found and open, through the getline function,
            while(getline(inFile, line)){                // the length of each line in the text file and the number of lines are
              linelength += (line.size()-1);             //acquired
              ++numberofLines;
            }
            inFile.close();
            mean = linelength/numberofLines;             //with the linelength and the number of lines, the mean is calculated
            inFile.open(filename);
            while(getline(inFile, line)){                //again, through the getline, the mean is subtracted from the length of each line amnd squared
              variance+=(pow(((line.size()-1)-mean),2)); //then, it is added to the variance
            }
            inFile.close();
            variance = variance/numberofLines;           //the variance calculation is completed by dividing itself by the number of lines
            standev = sqrt(variance);                    //a standard deviation is calculated by square rooting the variance
            inFile.open(filename);
            while(getline(inFile, line)){                 //through the getline while loop, the number of each single nuclotides is
              for(int i = 0; i<line.size();++i){          //added to the totals depending on the alphabet
                char ch = line[i];
                if(toupper(ch) == 'A'){
                  Atotal += 1;
                }
                else if(toupper(ch) == 'C'){
                  Ctotal += 1;
                }
                else if(toupper(ch) == 'T'){
                  Ttotal += 1;
                }
                else if(toupper(ch) == 'G'){
                  Gtotal += 1;
                }
              }
            }
            inFile.close();
            inFile.open(filename);
            while(getline(inFile, line)){
              for(int i = 0; i<line.size();i+=2){                   //the number of bigrams in the text files are calculated here
                char first = line[i];                               //the for loop gets two values each time it iterates
                char second = line[i+1];                            //the first letter is stored in first, and the second one is stored in second
                if(toupper(first) == 'A' && toupper(second) == 'A'){  //depending on the order of the bigram combination, the number of bigrams is added to the specific total
                  AAtotal++;
                }
                else if(toupper(first) == 'A' && toupper(second) == 'C'){
                  ACtotal++;
                }
                else if(toupper(first) == 'A' && toupper(second) == 'T'){
                  ATtotal++;
                }
                else if(toupper(first) == 'A' && toupper(second) == 'G'){
                  AGtotal++;
                }
                else if(toupper(first) == 'C' && toupper(second) == 'A'){
                  CAtotal++;
                }
                else if(toupper(first) == 'C' && toupper(second) == 'C'){
                  CCtotal++;
                }
                else if(toupper(first) == 'C' && toupper(second) == 'T'){
                  CTtotal++;
                }
                else if(toupper(first) == 'C' && toupper(second) == 'G'){
                  CGtotal++;
                }
                else if(toupper(first) == 'T' && toupper(second) == 'A'){
                  TAtotal++;
                }
                else if(toupper(first) == 'T' && toupper(second) == 'C'){
                  TCtotal++;
                }
                else if(toupper(first) == 'T' && toupper(second) == 'T'){
                  TTtotal++;
                }
                else if(toupper(first) == 'T' && toupper(second) == 'G'){
                  TGtotal++;
                }
                else if(toupper(first) == 'G' && toupper(second) == 'A'){
                  GAtotal++;
                }
                else if(toupper(first) == 'G' && toupper(second) == 'C'){
                  GCtotal++;
                }
                else if(toupper(first) == 'G' && toupper(second) == 'T'){
                  GTtotal++;
                }
                else if(toupper(first) == 'G' && toupper(second) == 'G'){
                  GGtotal++;
                }
              }
            }
            Aprob = Atotal/linelength; //the probabilites for single nucleotides and bigrams are calculated here
            Cprob = Ctotal/linelength;
            Tprob = Ttotal/linelength;
            Gprob = Gtotal/linelength;
            AAprob = AAtotal/(linelength/2);
            ACprob = ACtotal/(linelength/2);
            ATprob = ATtotal/(linelength/2);
            AGprob = AGtotal/(linelength/2);
            CAprob = CAtotal/(linelength/2);
            CCprob = CCtotal/(linelength/2);
            CTprob = CTtotal/(linelength/2);
            CGprob = CGtotal/(linelength/2);
            TAprob = TAtotal/(linelength/2);
            TCprob = TCtotal/(linelength/2);
            TTprob = TTtotal/(linelength/2);
            TGprob = TGtotal/(linelength/2);
            GAprob = GAtotal/(linelength/2);
            GCprob = GCtotal/(linelength/2);
            GTprob = GTtotal/(linelength/2);
            GGprob = GGtotal/(linelength/2);
            outFile.open("yourname.out");
            outFile << "name: Kenneth Cho" << endl;
            outFile << "id: 2325383" << endl;
            outFile << "course: CPSC350" << endl;
            outFile << "project name: Project 1" << endl;
            outFile << endl;
            for(int i=0;i<1000;++i){         //this for loop writes 1000 lines of dna strings
              combline = "";                 //using the probabilites and equations calculated above and in the loops
              a = (rand()%100);              //random number a and b are acquired here they are in the range (0,1]
              a /= 100;
              b = (rand()%100);
              b /= 100;
              gaussian = (sqrt((-2)*log(a))*cos(2*pi*b)); //standard gaussian is calculated
              d = (standev*gaussian)+mean;                //d is a normal random variable
              if(remainder(d,1) > 0.5){                  //this part of the equation rounds up the number of d
                d += (1-remainder(d,1));                 //if the remainter is more than 0.5, it is round up
              }
              else{                                      //if it isn't it is not rounded up
                d -= remainder(d,1);
              }
              for(int i=0;i<d;++i){                      //the randomly generated d is used here to write to the file
                float k = (rand()%100);                  //another random float, k is generated to randonly choose the letter that will be written to the file
                k /= 100;

                if(k <= Tprob){                          //if k is less or equal to the probability of t, T is written
                  combline += "T";
                }
                else if(k >= Tprob && k <= Aprob + Tprob) { //if k is more or equal to the probability of t, and less than or equal to the probability of a and t combined, A is written
                  combline += "A";
                }
                else if(k >= Aprob + Tprob && k <= Tprob + Aprob + Cprob){//if k is more than or equal to the probability of A and T combined,
                  combline += "C";                                        //and less than the probability of T, A and C combined, C is written
                }
                else{
                  combline += "G";                                        //else, it writes G
                }
              }
              outFile << combline << endl;         //the selected letters are combined as a string "combline" and written to the text file
            }
            outFile.close();                        //file is closed
          }
        }
        else if(start == 2){  //if the user types in 2, the system ends
          cout << "shutting down program" << endl;
          exit(0);
        }
        else{                 //if it is not a valid input, the program asks the user again
          cout << "wrong input, try again: " << endl;
          cin >> start;
        } //all the information that need to be printed out are done here

        cout << "The Sum of the length of the DNA strings is:" << linelength << endl;
        cout << "The Mean of the length of the DNA strings is " << mean << endl;
        cout << "The variance of the length of the DNA strings is: " << variance << endl;
        cout << "The Standard Deviation of the length of the DNA stings is: " << standev << endl;
        cout << endl;
        cout << "Here is the relative probability of each nucleotide:" << endl;
        cout << endl;
        cout << "A: " << Aprob << endl;
        cout << "C: " << Cprob << endl;
        cout << "T: " << Tprob << endl;
        cout << "G: " << Gprob << endl;
        cout << endl;
        cout << "Here is the relative probability of each nucleotide bigram:" << endl;
        cout << "AA: " << AAprob << endl;
        cout << "AC: " << ACprob << endl;
        cout << "AT: " << ATprob << endl;
        cout << "AG: " << AGprob << endl;
        cout << "CA: " << CAprob << endl;
        cout << "CC: " << CCprob << endl;
        cout << "CT: " << CTprob << endl;
        cout << "CG: " << CGprob << endl;
        cout << "TA: " << TAprob << endl;
        cout << "TC: " << TCprob << endl;
        cout << "TT: " << TTprob << endl;
        cout << "TG: " << TGprob << endl;
        cout << "GA: " << GAprob << endl;
        cout << "GC: " << GCprob << endl;
        cout << "GT: " << GTprob << endl;
        cout << "GG: " << GGprob << endl;
      }
    }
    else if(inty == "n"){           //if user types in n, the program shuts down
      cout << "shutting down program" << endl;
      exit(0);
    }
    else{                           //if the user types in an invalid input, the system asks again
      cout << "wrong input, try again" << endl;
      cin>>inty;
    }
  }
}
