#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
  fstream txtFile;
  double countlines = 0;
  double countChar = 0;

  double countCharA = 0;
  double countCharAA = 0;
  double countCharAC = 0;
  double countCharAT = 0;
  double countCharAG = 0;

  double countCharC = 0;
  double countCharCA = 0;
  double countCharCC = 0;
  double countCharCT = 0;
  double countCharCG = 0;

  double countCharT = 0;
  double countCharTA = 0;
  double countCharTC = 0;
  double countCharTT = 0;
  double countCharTG = 0;

  double countCharG = 0;
  double countCharGA = 0;
  double countCharGC = 0;
  double countCharGT = 0;
  double countCharGG = 0;

  double probA = 0;
  double probAA = 0;
  double probAC = 0;
  double probAT = 0;
  double probAG = 0;

  double probC = 0;
  double probCA = 0;
  double probCC = 0;
  double probCT = 0;
  double probCG = 0;

  double probT = 0;
  double probTA = 0;
  double probTC = 0;
  double probTT = 0;
  double probTG = 0;

  double probG = 0;
  double probGA = 0;
  double probGC = 0;
  double probGT = 0;
  double probGG = 0;

  double mean = 0;
  double varianceTop =0;
  double variance =0;
  double stdDev = 0;
  string line;
  string answer;
  // opening the text file
  txtFile.open("dnaString.txt");
  // Error Statement if the text file cannot be opened
  if (!txtFile) {
      cout << "Unable to open file dnaString.txt";
      exit(1);   // Call system to stop
  }
  // reading each line (string) of  text file "dnaString.txt"
  while(getline(txtFile, line)){
    // counting each string/line
    countlines++;
    // for loop checking each character of the string
    for (unsigned int n = 0; n<line.length();n++){
      putchar(toupper(line.at(n)));
       if (line.at(n) == ' ') {
         // counting each character
         countChar--;
       }
       if (line.at(n) == 'a' || line.at(n) == 'A') {
         countCharA++;
         // Skip counting pairs if end of string
         if (n<(line.length()-1)){
           if (line.at(n+1) == 'a' || line.at(n) == 'A'){
             countCharAA++;
           }
           if (line.at(n+1) == 'c' || line.at(n) == 'C'){
             countCharAC++;
           }
           if (line.at(n+1) == 't' || line.at(n) == 'T'){
             countCharAT++;
           }
           if (line.at(n+1) == 'g' || line.at(n) == 'G'){
             countCharAG++;
           }
         }
       }
       if (line.at(n) == 'c' || line.at(n) == 'C') {
         countCharC++;
         // Skip counting pairs if end of string
         if (n<(line.length()-1)){
           if (line.at(n+1) == 'a' || line.at(n) == 'A') {
             countCharCA++;
           }
           if (line.at(n+1) == 'c' || line.at(n) == 'C') {
             countCharCC++;
           }
           if (line.at(n+1) == 't' || line.at(n) == 'T'){
             countCharCT++;
           }
           if (line.at(n+1) == 'g' || line.at(n) == 'G'){
             countCharCG++;
           }
         }
       }
       if (line.at(n) == 't' || line.at(n) == 'T') {
         countCharT++;
         // Skip counting pairs if end of string
         if (n<(line.length()-1)){
           if (line.at(n+1) == 'a' || line.at(n) == 'A') {
             countCharTA++;
           }
           if (line.at(n+1) == 'c' || line.at(n) == 'C') {
             countCharTC++;
           }
           if (line.at(n+1) == 't' || line.at(n) == 'T') {
             countCharTT++;
           }
           if (line.at(n+1) == 'g' || line.at(n) == 'G') {
             countCharTG++;
           }
         }
       }
       if (line.at(n) == 'g' || line.at(n) == 'G') {
         countCharG++;
         // Skip counting pairs if end of string
         if (n<(line.length()-1)){
           if (line.at(n+1) == 'a' || line.at(n) == 'A') {
             countCharGA++;
           }
           if (line.at(n+1) == 'c' || line.at(n) == 'C') {
             countCharGC++;
           }
           if (line.at(n+1) == 't' || line.at(n) == 'T') {
             countCharGT++;
           }
           if (line.at(n+1) == 'g' || line.at(n) == 'G') {
             countCharGG++;
           }
         }
        }
       countChar++;
    }
  }
  mean = countChar/countlines;
  txtFile.close();
  txtFile.open("dnaString.txt");
  // closes and opens the file again in order to get a variance that is outside
  //the for loop for accurate measure
  while(getline(txtFile, line)){
      varianceTop += pow(line.length() - mean, 2);
  }
  variance = varianceTop/countlines;
  stdDev = sqrt(variance);

// probabilities of each individual combination
// compared probability of each nucleotide with the total amount of
//characters rather than nucleotide pairs because creating a nucleotide count
// variable caused too many errors
  probA = (countCharA/countChar)*100;
  probAA = (countCharAA/countChar)*100;
  probAC = (countCharAC/countChar)*100;
  probAT = (countCharAT/countChar)*100;
  probAG = (countCharAG/countChar)*100;

  probC = (countCharC/countChar)*100;
  probCA = (countCharCA/countChar)*100;
  probCC = (countCharCC/countChar)*100;
  probCT = (countCharCT/countChar)*100;
  probCG = (countCharCG/countChar)*100;

  probT = (countCharT/countChar)*100;
  probTA = (countCharTA/countChar)*100;
  probTC = (countCharTC/countChar)*100;
  probTT = (countCharTT/countChar)*100;
  probTG = (countCharTG/countChar)*100;

  probG = (countCharG/countChar)*100;
  probGA = (countCharGA/countChar)*100;
  probGC = (countCharGC/countChar)*100;
  probGT = (countCharGT/countChar)*100;
  probGG = (countCharGG/countChar)*100;
// result file where summary statistics and the new list is located
  ofstream resultFile("alekseifurlong.out");
  // Closing the text file
  txtFile.close();
    cout << "dnaString.txt has been read!" << endl;
    resultFile << "Name: Aleksei Furlong" << endl;
    resultFile << "Student ID: 2297345" << endl;
    resultFile << "Number of lines in the file: " << countlines <<endl;
    resultFile << "Number(Sum) of characters: " << countChar <<endl;
    resultFile << "Mean: " << mean <<endl;
    resultFile << "Variance: " << variance <<endl;
    resultFile << "Standard Deviation: " << stdDev <<endl;

    resultFile << "Probability of A: " << probA << "%"<< endl;
    resultFile << "Probability of AA: " << probAA << "%"<< endl;
    resultFile << "Probability of AC: " << probAC << "%"<< endl;
    resultFile << "Probability of AT: " << probAT << "%"<< endl;
    resultFile << "Probability of AG: " << probAG << "%"<< endl;

    resultFile << "Probability of C: " << probC << "%"<< endl;
    resultFile << "Probability of CA: " << probCA << "%"<< endl;
    resultFile << "Probability of CC: " << probCC << "%"<< endl;
    resultFile << "Probability of CT: " << probCT << "%"<< endl;
    resultFile << "Probability of CG: " << probCG << "%"<< endl;

    resultFile << "Probability of T: " << probT << "%"<< endl;
    resultFile << "Probability of TA: " << probTA << "%"<< endl;
    resultFile << "Probability of TC: " << probTC << "%"<< endl;
    resultFile << "Probability of TT: " << probTT << "%"<< endl;
    resultFile << "Probability of TG: " << probTG << "%"<< endl;

    resultFile << "Probability of G: " << probG << "%"<< endl;
    resultFile << "Probability of GA: " << probGA << "%"<< endl;
    resultFile << "Probability of GC: " << probGC << "%"<< endl;
    resultFile << "Probability of GT: " << probGT << "%"<< endl;
    resultFile << "Probability of GG: " << probGG << "%"<< endl;

    //  lines 236-238 were derived from this website
    //https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd; //Will be used to obtain a seed for the random number
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<double> realDistribution(0.0,1.0);
    std::default_random_engine generator;
    //Replace with mean, stdev respectively
    std::normal_distribution<double> distribution(mean,stdDev);
    // creating a list of 1000 strings
    int numString = 1000;
    int stringLength[1000]={};
    int indexVar = 0;

    while (indexVar<numString) {
      // rounded the numbers in order to have whole numbers
      int intLength = round(distribution(generator));
      // value of max at least 2x mean
      if (intLength > 0 && intLength < (2*mean)){
        stringLength[indexVar++] = intLength;
      }
    }
    string sequences[1000] = {};
    for (int i=0; i < numString; i++) {
      for (int j=0; j < stringLength[i]; j++) {
          //generate a character and generate random number
          //map and append number to letter
          double sampleDouble = realDistribution(gen);
          //cout << sampleDouble << endl;
          if (sampleDouble <= (probA/100)){
            sequences[i].append("A");
          }
          else if (sampleDouble <= ((probA+probC)/100)) {
            sequences[i].append("C");
          }
          else if (sampleDouble <= ((probA+probC+probG)/100)) {
            sequences[i].append("G");
          }
          else {
            sequences[i].append("T");
          }
      }
      // printing the 1000 strings
      resultFile << sequences[i]<<endl;
    }
  cout << "Would you like to print another list?" << endl;
  return 0;
}
