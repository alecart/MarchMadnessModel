/**********************************************
* Program:  MM.C                              *
* Author: Carter Alexander                    *
* Date:  July 10, 2018                        *
*                                             *
* Abstract: Ensemble Model for the NCAA Men's *
* Basketball Tournament                       *
*                                             *
**********************************************/
#include <iostream> // cout and cin
#include <fstream> // file insertion
#include <ctime> // time()
#include <cstdlib> // rand(), srand()
#include <unistd.h> // sleep()
#include <cmath> // Box Muller's log() and sin() functions

using namespace std;

void RoundOf64(); 
void RoundOf32();
void Sweet16();
void Elite8();
void Final4();
void Championship();
int second_advancing[8];
int sweet_advancing[4];
int elite_advancing[2];
int four_advancing[1];
double widening = .05; //.05 makes sig between -0.15 and 0.15 // if want to turn off, make it 0

int main() 
{
	// ROUND OF 64 WIN COUNTS
	double one = 0;
	double two = 0;
	double three = 0;
	double four = 0;
	double five = 0;
	double six = 0;
	double seven = 0;
	double eight = 0;
	double nine = 0;
	double ten = 0;
	double eleven = 0;
	double twelve = 0;
	double thirteen = 0;
	double fourteen = 0;
	double fifteen = 0;
	double sixteen = 0;
	
	// ROUND OF 32 WIN COUNTS
	int one_ = 0;
	int two_ = 0;
	int three_ = 0;
	int four_ = 0;
	int five_ = 0;
	int six_ = 0;
	int seven_ = 0;
	int eight_ = 0;
	int nine_ = 0;
	int ten_ = 0;
	int eleven_ = 0;
	int twelve_ = 0;
	int thirteen_ = 0;
	int fourteen_ = 0;
	int fifteen_ = 0;
	int sixteen_ = 0;
	
	// SWEET 16 WIN COUNTS
	int _one = 0;
	int _two = 0;
	int _three = 0;
	int _four = 0;
	int _five = 0;
	int _six = 0;
	int _seven = 0;
	int _eight = 0;
	int _nine = 0;
	int _ten = 0;
	int _eleven = 0;
	int _twelve = 0;
	int _thirteen = 0;
	int _fourteen = 0;
	int _fifteen = 0;
	int _sixteen = 0;
	
	// ELITE 8 WIN COUNTS
	int __one = 0;
	int __two = 0;
	int __three = 0;
	int __four = 0;
	int __five = 0;
	int __six = 0;
	int __seven = 0;
	int __eight = 0;
	int __nine = 0;
	int __ten = 0;
	int __eleven = 0;
	int __twelve = 0;
	int __thirteen = 0;
	int __fourteen = 0;
	int __fifteen = 0;
	int __sixteen = 0;
	
	int games = 0;
	
	
	for (int i = 0; i < 100; i++)
	{
		games++;
		RoundOf64();
		RoundOf32();
		Sweet16();
		Elite8();
		
		// TALLYING THE ROUND OF 64 WINS
		if (second_advancing[0] == 0)
			one++;
		
		if (second_advancing[0] == 15)
			sixteen++;
		
		if (second_advancing[1] == 1)
			two++;
		
		if (second_advancing[1] == 14)
			fifteen++;
		
		if (second_advancing[2] == 2)
			three++;
		
		if (second_advancing[2] == 13)
			fourteen++;
		
		if (second_advancing[3] == 3)
			four++;
		
		if (second_advancing[3] == 12)
			thirteen++;
		
		if (second_advancing[4] == 4)
			five++;
		
		if (second_advancing[4] == 11)
			twelve++;
		
		if (second_advancing[5] == 5)
			six++;
		
		if (second_advancing[5] == 10)
			eleven++;
		
		if (second_advancing[6] == 6)
			seven++;
		
		if (second_advancing[6] == 9)
			ten++;
		
		if (second_advancing[7] == 7)
			eight++;
		
		if (second_advancing[7] == 8)
			nine++;

		
		// TALLYING THE ROUND OF 32 WINS
		if (sweet_advancing[0] == 0)
			one_++;
		
		if (sweet_advancing[0] == 15)
			sixteen_++;
		
		if (sweet_advancing[0] == 7)
			eight_++;
		
		if (sweet_advancing[0] == 8)
			nine_++;
		
		if (sweet_advancing[1] == 1)
			two_++;
		
		if (sweet_advancing[1] == 14)
			fifteen_++;
		
		if (sweet_advancing[1] == 6)
			seven_++;
		
		if (sweet_advancing[1] == 9)
			ten_++;
		
		if (sweet_advancing[2] == 2)
			three_++;
		
		if (sweet_advancing[2] == 13)
			fourteen_++;
		
		if (sweet_advancing[2] == 5)
			six_++;
		
		if (sweet_advancing[2] == 10)
			eleven_++;
		
		if (sweet_advancing[3] == 3)
			four_++;
		
		if (sweet_advancing[3] == 4)
			five_++;
		
		if (sweet_advancing[3] == 12)
			thirteen_++;
		
		if (sweet_advancing[3] == 11)
			twelve_++;	
		
		
		
		// TALLYING THE SWEET 16 WINS
		if (elite_advancing[0] == 0) 
			_one++;
		
		if (elite_advancing[0] == 15)
			_sixteen++;
		
		if (elite_advancing[0] == 7)
			_eight++;
		
		if (elite_advancing[0] == 8)
			_nine++;
		
		if (elite_advancing[0] == 4)
			_five++;
		
		if (elite_advancing[0] == 11)
			_twelve++;
		
		if (elite_advancing[0] == 3)
			_four++;
		
		if (elite_advancing[0] == 12)
			_thirteen++;
		
		if (elite_advancing[1] == 10)
			_eleven++;
			
		if (elite_advancing[1] == 2)
			_three++;
			
		if (elite_advancing[1] == 13)
			_fourteen++;
			
		if (elite_advancing[1] == 6)
			_seven++;
			
		if (elite_advancing[1] == 9)
			_ten++;
			
		if (elite_advancing[1] == 1)
			_two++;
			
		if (elite_advancing[1] == 14)
			_fifteen++;
		
		if (elite_advancing[1] == 5)
			_six++;
		

		
		// TALLYING THE ELITE 8 WINS
		if (four_advancing[0] == 0) 
			__one++;
		
		if (four_advancing[0] == 1)
			__two++;
		
		if (four_advancing[0] == 2)
			__three++;
		
		if (four_advancing[0] == 3)
			__four++;
		
		if (four_advancing[0] == 4)
			__five++;
		
		if (four_advancing[0] == 5)
			__six++;
		
		if (four_advancing[0] == 6)
			__seven++;
		
		if (four_advancing[0] == 7)
			__eight++;
		
		if (four_advancing[0] == 8)
			__nine++;
			
		if (four_advancing[0] == 9)
			__ten++;
			
		if (four_advancing[0] == 10)
			__eleven++;
			
		if (four_advancing[0] == 11)
			__twelve++;
			
		if (four_advancing[0] == 12)
			__thirteen++;
			
		if (four_advancing[0] == 13)
			__fourteen++;
		
		if (four_advancing[0] == 14)
			__fifteen++;
			
		if (four_advancing[0] == 15)
			__sixteen++;
	}
	
	cout << endl;
	cout << "1 seed Round of 64 wins: " << one << "\t vs. win percentage: " << one/games <<	endl;
	cout << "2 seed Round of 64 wins: "  << two << "\t vs. win percentage: " << two/games << endl;
	cout << "3 seed Round of 64 wins: " << three << "\t vs. win percentage: " << three/games << endl;
    cout << "4 seed Round of 64 wins: " << four << "\t vs. win percentage: " << four/games << endl;
	cout << "5 seed Round of 64 wins: " << five << "\t vs. win percentage: " << five/games << endl;
	cout << "6 seed Round of 64 wins: " << six << "\t vs. win percentage: " << six/games << endl;
	cout << "7 seed Round of 64 wins: " << seven << "\t vs. win percentage: " << seven/games << endl;
	cout << "8 seed Round of 64 wins: " << eight << "\t vs. win percentage: " << eight/games << endl; 
	cout << "9 seed Round of 64 wins: " << nine << "\t vs. win percentage: " << nine/games << endl;
	cout << "10 seed Round of 64 wins: " << ten << "\t vs. win percentage: " << ten/games << endl;
	cout << "11 seed Round of 64 wins: " << eleven << "\t vs. win percentage: " << eleven/games << endl;
	cout << "12 seed Round of 64 wins: " << twelve << "\t vs. win percentage: " << twelve/games << endl;
	cout << "13 seed Round of 64 wins: " << thirteen << "\t vs. win percentage: " << thirteen/games << endl;
	cout << "14 seed Round of 64 wins: " << fourteen << "\t vs. win percentage: " << fourteen/games << endl;
	cout << "15 seed Round of 64 wins: " << fifteen << "\t vs. win percentage: " << fifteen/games << endl;
	cout << "16 seed Round of 64 wins: " << sixteen << "\t vs. win percentage: " << sixteen/games << endl << endl;
	
	cout << "1 seed Round of 32 wins: " << one_ << endl;
	cout << "2 seed Round of 32 wins: " << two_ << endl;
	cout << "3 seed Round of 32 wins: " << three_ << endl;
    cout << "4 seed Round of 32 wins: " << four_ << endl;
	cout << "5 seed Round of 32 wins: " << five_ << endl;
	cout << "6 seed Round of 32 wins: " << six_ << endl;
	cout << "7 seed Round of 32 wins: " << seven_ << endl;
	cout << "8 seed Round of 32 wins: " << eight_ << endl; 
	cout << "9 seed Round of 32 wins: " << nine_ << endl;
	cout << "10 seed Round of 32 wins: " << ten_ << endl;
	cout << "11 seed Round of 32 wins: " << eleven_ << endl;
	cout << "12 seed Round of 32 wins: " << twelve_ << endl;
	cout << "13 seed Round of 32 wins: " << thirteen_ << endl;
	cout << "14 seed Round of 32 wins: " << fourteen_ << endl;
	cout << "15 seed Round of 32 wins: " << fifteen_ << endl;
	cout << "16 seed Round of 32 wins: " << sixteen_ << endl << endl;
	
	cout << "1 seed Sweet 16 wins: " << _one << endl;
	cout << "2 seed Sweet 16 wins: " << _two << endl;
	cout << "3 seed Sweet 16 wins: " << _three << endl;
    cout << "4 seed Sweet 16 wins: " << _four << endl;
	cout << "5 seed Sweet 16 wins: " << _five << endl;
	cout << "6 seed Sweet 16 wins: " << _six << endl;
	cout << "7 seed Sweet 16 wins: " << _seven << endl;
	cout << "8 seed Sweet 16 wins: " << _eight << endl; 
	cout << "9 seed Sweet 16 wins: " << _nine << endl;
	cout << "10 seed Sweet 16 wins: " << _ten << endl;
	cout << "11 seed Sweet 16 wins: " << _eleven << endl;
	cout << "12 seed Sweet 16 wins: " << _twelve << endl;
	cout << "13 seed Sweet 16 wins: " << _thirteen << endl;
	cout << "14 seed Sweet 16 wins: " << _fourteen << endl;
	cout << "15 seed Sweet 16 wins: " << _fifteen << endl;
	cout << "16 seed Sweet 16 wins: " << _sixteen << endl << endl;
	
	cout << "1 seed Elite 8 wins: " << __one << endl;
	cout << "2 seed Elite 8 wins: " << __two << endl;
	cout << "3 seed Elite 8 wins: " << __three << endl;
    cout << "4 seed Elite 8 wins: " << __four << endl;
	cout << "5 seed Elite 8 wins: " << __five << endl;
	cout << "6 seed Elite 8 wins: " << __six << endl;
	cout << "7 seed Elite 8 wins: " << __seven << endl;
	cout << "8 seed Elite 8 wins: " << __eight << endl; 
	cout << "9 seed Elite 8 wins: " << __nine << endl;
	cout << "10 seed Elite 8 wins: " << __ten << endl;
	cout << "11 seed Elite 8 wins: " << __eleven << endl;
	cout << "12 seed Elite 8 wins: " << __twelve << endl;
	cout << "13 seed Elite 8 wins: " << __thirteen << endl;
	cout << "14 seed Elite 8 wins: " << __fourteen << endl;
	cout << "15 seed Elite 8 wins: " << __fifteen << endl;
	cout << "16 seed Elite 8 wins: " << __sixteen << endl;
}

// To pick out the specific elements of the array based on the matchups:
// EXAMPLE:
// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
// [1, 2, 3, 4, 12, 6, 10, 9]
// [1, 2, 6, 4]
// [1, 6]
// [1]
// The team at the beginning of the array plays the team at the end; then play the next team in front vs. the previous team in back, and so on

void RoundOf64()
{
	srand(time(0)); // re-seeding the random number

	ifstream inFile("J10RoundOf64.dat"); // reading from this file of data
	
	double num; // num = random number 
	double chance; // chance = win percentage
	int advancing[8]; // filling one region with the teams advancing
	double matchups[16][16]; // to hold the proportions for each RoundOf64 matchup
	
	double next; // to hold the next proportion
	inFile >> next;
	
	for (int i = 0; i < 16; i++) // placing the 256 proportions into the array
	{
		for (int j = 0; j < 16; j++)
		{
			matchups[i][j] = next;
			inFile >> next;
		}
		
	}
	
	int advancing_index = 0;
	int i = 0;
	int j = 15;
	
	while ((i < 8) && (j > 7)) // we start i at 0 and j at 15, and increment i and decrement j until the 8 seed plays the 9 seed
	{
		num = rand(); // random integer generator
		chance = num / RAND_MAX; // creates number between 0.0 and 1.0
		
		if (matchups[i][j] >= chance)                             // EXAMPLE OF HOW THIS PROCESS WOULD WORK:
		{									                      // First game is index 0 vs. index 15 (1 vs. 16) and let's say chance = .57
			advancing[advancing_index] = i;
            cout << "seed: " << advancing[advancing_index] + 1 << endl;	
			cout << "chance that decided who won last round: " << chance << endl;	
			cout <<  "matchup proportion: " << matchups[i][j] << endl;	// Since matchups[0][15] = 1, it's always between 0 and chance
			advancing_index++;						              // Next, the seed that advances (i) is the 1st team placed in the advancing teams array (1 seed/0 element)
		}                                                         // The advancing_index is incremented so that the next team to advance is placed in the advancing[1] element
		
		else                                                      // If the proportion is greater than the chance, then the seed who was less likely to win advances instead
		{                                                         // Then, the seed that advances (j) is the 1st team placed in the advancing teams array (0 element)
			advancing[advancing_index] = j;   
			cout << "seed: " << advancing[advancing_index] + 1 << endl;  
			cout << "chance that decided who won last round: " << chance << endl;
			cout << "matchup proportion: " << matchups[i][j] << endl;		// The advancing_index is incremented so that the next team to advance is placed in the advancing[1] element
			advancing_index++;
		}
		
		i++;                                                      // i is incremented and j is decremented so that the next matchup can be played (2 vs. 15)
		j--;	                                                  // this process will stop when i reaches 9 and j reaches 8 since this isn't a possible RoundOf64 matchup
	}
	
	for (int i = 0; i < 8; i++)
	{
		second_advancing[i] = advancing[i];
		cout << second_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl;
	
	sleep(1);
}

void RoundOf32() // takes in the array called advancing and sorts through the elements based on the teams remaining
{		
	// new array variable set = to advancing array with for loop element by element
	
	cout << "\n\n\n\n";
	srand(time(0)); // re-seeding the random number

	ifstream inFile("J10RoundOf32.dat"); // RoundOf32 data file
	
	double num;
	double num1;
	double num2;
	double chance;
	double u1;
	double u2;
	const double PI = 3.141592653589793238463;
	double sig;
	double advancing[4]; // to hold the teams who will advance to the Sweet16
	double matchups[16][16]; // to hold the proportions for each RoundOf32 matchup
	
	double next;
	inFile >> next;
	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			matchups[i][j] = next;
			inFile >> next;
		}
	}
	
	// if the 1 plays the 8 seed in the 2nd round, need to compare the variable chance with matchups[0][7]
	// if the 2 plays the 10 seed in the 2nd round, need to compare the variable chance with matchups[1][9]
	// so whatever seeds are in the 8 elements of advancing[8] need to be paired such as advancing[0] plays advancing[7], advancing[1] plays advancing[6], 2 vs. 5, 3 vs. 4
	// to do this, whatever is held at advancing[0] (say it's the 1 seed so it's 0) and held at advancing[7] (say it's the 9 seed so it's 8) has to be the proportion we look at from the file
	// so since the 1 seed is playing the 9 seed, we need to compare matchups[0][8] with chance
	
	int advancing_index = 0;
	int i = 0;
	int j = 7;
	
	
	while (i < 4 && j > 3)
	{
		num = rand();
		num1 = rand();
		num2 = rand();
		chance = num / RAND_MAX;
		
		u1 = num1 / RAND_MAX;
		u2 = num2 / RAND_MAX;
		sig = (widening)*sqrt(-2*(log(u1))) * sin(2*PI*u2); // Box-Muller Transform given 2 random numbers between 0 and 1
		
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "u1 = " << u1 << endl;
		cout << "u2 = " << u2 << endl;
		cout << "chance before adding sig: " << chance << endl;
		
		chance = chance + sig;
		
		cout << "sig: " << sig << endl;
		
		cout << "chance after adding sig: " << chance << endl;
		
		if (chance > 1)
			chance = 1;
		
		if (chance < 0)
			chance = 0;
		
		cout << "chance after adding sig with possible overextension: " << chance << endl;
		
		
		if (matchups[second_advancing[i]][second_advancing[j]] >= chance)
		{
			advancing[advancing_index] = second_advancing[i];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;	
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[second_advancing[i]][second_advancing[j]] << endl;
		}
		
		else
		{
			advancing[advancing_index] = second_advancing[j];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[second_advancing[i]][second_advancing[j]] << endl;
		}
			
		i++;
		j--;
	}
	
	for (int i = 0; i < 4; i++)
	{
		sweet_advancing[i] = advancing[i];
		cout << sweet_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}

void Sweet16()
{
	cout << "\n\n\n\n";
	
	srand(time(0));
	
	ifstream inFile("J10Sweet16.dat");
	
	double num;
	double num1;
	double num2;
	double chance;
	double u1;
	double u2;
	double sig;
	const double PI = 3.141592653589793238463;
	double advancing[2]; // to hold the teams who will advance to the Elite8
	double matchups[16][16]; // to hold the proportions for each Sweet16 matchup
	double one;
	double two;
	double data;
	
	double next;
	inFile >> next;
	int advancing_index = 0;
	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			matchups[i][j] = next;
			inFile >> next;
		}
	}

	int i = 0;
	int j = 3;
	
	while (i < 2 && j > 1)
	{
		num = rand();
		chance = num / RAND_MAX;
		num1 = rand();
		num2 = rand();
		
		u1 = num1 / RAND_MAX;
		u2 = num2 / RAND_MAX;
		sig = (widening)*sqrt(-2*(log(u1))) * sin(2*PI*u2);
		
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "u1 = " << u1 << endl;
		cout << "u2 = " << u2 << endl;
		cout << "chance before adding sig: " << chance << endl;
		
		chance = chance + sig;
		
		cout << "sig: " << sig << endl;
		
		cout << "chance after adding sig: " << chance << endl;
		
		if (chance > 1)
			chance = 1;
		
		if (chance < 0)
			chance = 0;
		
		cout << "chance after adding sig with possible overextension: " << chance << endl;
		
		
		
		if (matchups[sweet_advancing[i]][sweet_advancing[j]] == 0 && matchups[sweet_advancing[j]][sweet_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (sweet_advancing[j] + 1); // numerator 14 
			two = (sweet_advancing[j] + 1 + sweet_advancing[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data >= chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = sweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = sweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[sweet_advancing[i]][sweet_advancing[j]] >= chance)
			{
				advancing[advancing_index] = sweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[sweet_advancing[i]][sweet_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = sweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[sweet_advancing[i]][sweet_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 2; i++)
	{
		elite_advancing[i] = advancing[i];
		cout << elite_advancing[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);
}


void Elite8()
{
	cout << "\n\n\n\n";
	
	srand(time(0));
	
	ifstream inFile("J10Elite8.dat");

	double num;
	double num1;
	double num2;
	double u1;
	double u2;
	double sig;
	const double PI = 3.141592653589793238463;
	double chance;
	double advancing[1]; // to hold the team who will advance to the Final4
	double matchups[16][16]; // to hold the proportions for each Elite8 matchup
	double one;
	double two;
	double data;
	
	double next;
	inFile >> next;
	
	int advancing_index = 0;
	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			matchups[i][j] = next;
			inFile >> next;
		}
	}	
	
	int i = 0;
	int j = 1;
	
	while (i < 1 && j > 0)
	{
		num = rand();
		chance = num / RAND_MAX;
		num1 = rand();
		num2 = rand();
		
		u1 = num1 / RAND_MAX;
		u2 = num2 / RAND_MAX;
		sig = (widening)*sqrt(-2*(log(u1))) * sin(2*PI*u2);
		
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "u1 = " << u1 << endl;
		cout << "u2 = " << u2 << endl;
		cout << "chance before adding sig: " << chance << endl;
		
		chance = chance + sig;
		
		cout << "sig: " << sig << endl;
		
		cout << "chance after adding sig: " << chance << endl;
		
		if (chance > 1)
			chance = 1;
		
		if (chance < 0)
			chance = 0;
		
		cout << "chance after adding sig with possible overextension: " << chance << endl;
		
		if (matchups[elite_advancing[i]][elite_advancing[j]] == 0 && matchups[elite_advancing[j]][elite_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Elite 8 have never won in the Elite 8 before
		{
			cout << endl;
			one = (elite_advancing[j] + 1);
			two = (elite_advancing[j] + 1 + elite_advancing[i] + 1);
			data = one/two;
			
			if (data >= chance)
			{
				advancing[advancing_index] = elite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		
			else
			{
				advancing[advancing_index] = elite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		}
		
		
		else
		{
			if (matchups[elite_advancing[i]][elite_advancing[j]] >= chance)
			{
				advancing[advancing_index] = elite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[elite_advancing[i]][elite_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = elite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[elite_advancing[i]][elite_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 1; i++)
	{
		four_advancing[i] = advancing[i];
		cout << four_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}


/*void Final4()
{
	cout << "\n\n\n\n";
	
	ifstream inFile("Final4.dat");
}

void Championship()
{
	ifstream inFile("Championship.dat");
}*/