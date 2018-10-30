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
#include <vector>
#include <algorithm>

// BIG CHANGE MADE... proportion now has to be > chance rather than >= chance... so now if say a 1 plays a 9 in the Final 4 (where the proportion is 1, but the chance is extended to 1, the 9 seed wins as it should)

using namespace std;

void oneRoundOf64(); 
void oneRoundOf32();
void oneSweet16();
void oneElite8();

void twoRoundOf64();
void twoRoundOf32();
void twoSweet16();
void twoElite8();

void threeRoundOf64(); 
void threeRoundOf32();
void threeSweet16();
void threeElite8();

void fourRoundOf64(); 
void fourRoundOf32();
void fourSweet16();
void fourElite8();

void Final4();
void Championship();


int onesecond_advancing[8];
int onesweet_advancing[4];
int oneelite_advancing[2];
int onefour_advancing[1];


int twosecond_advancing[8];
int twosweet_advancing[4];
int twoelite_advancing[2];
int twofour_advancing[1];


int threesecond_advancing[8];
int threesweet_advancing[4];
int threeelite_advancing[2];
int threefour_advancing[1];

int foursecond_advancing[8];
int foursweet_advancing[4];
int fourelite_advancing[2];
int fourfour_advancing[1];

int final_four[4];
int championship_advancing[2];
int champion[1];

double widening = (double)1.0/2.75; // 1.0/3.0 makes sig between -1 and 1 // if want to turn off, make it 0
double total_games_with_sig = 0.0;
double sig_total = 0.0;
double sig_average = 0.0;

vector <double> sig_vals; // holds values read in on each line

// ROUND OF 64 WIN COUNTS
double bracketONEone = 0;
double bracketONEtwo = 0;
double bracketONEthree = 0;
double bracketONEfour = 0;
double bracketONEfive = 0;
double bracketONEsix = 0;
double bracketONEseven = 0;
double bracketONEeight = 0;
double bracketONEnine = 0;
double bracketONEten = 0;
double bracketONEeleven = 0;
double bracketONEtwelve = 0;
double bracketONEthirteen = 0;
double bracketONEfourteen = 0;
double bracketONEfifteen = 0;
double bracketONEsixteen = 0;

// ROUND OF 32 WIN COUNTS
int bracketONEone_ = 0;
int bracketONEtwo_ = 0;
int bracketONEthree_ = 0;
int bracketONEfour_ = 0;
int bracketONEfive_ = 0;
int bracketONEsix_ = 0;
int bracketONEseven_ = 0;
int bracketONEeight_ = 0;
int bracketONEnine_ = 0;
int bracketONEten_ = 0;
int bracketONEeleven_ = 0;
int bracketONEtwelve_ = 0;
int bracketONEthirteen_ = 0;
int bracketONEfourteen_ = 0;
int bracketONEfifteen_ = 0;
int bracketONEsixteen_ = 0;

// SWEET 16 WIN COUNTS
int bracketONE_one = 0;
int bracketONE_two = 0;
int bracketONE_three = 0;
int bracketONE_four = 0;
int bracketONE_five = 0;
int bracketONE_six = 0;
int bracketONE_seven = 0;
int bracketONE_eight = 0;
int bracketONE_nine = 0;
int bracketONE_ten = 0;
int bracketONE_eleven = 0;
int bracketONE_twelve = 0;
int bracketONE_thirteen = 0;
int bracketONE_fourteen = 0;
int bracketONE_fifteen = 0;
int bracketONE_sixteen = 0;

// ELITE 8 WIN COUNTS
int bracketONE__one = 0;
int bracketONE__two = 0;
int bracketONE__three = 0;
int bracketONE__four = 0;
int bracketONE__five = 0;
int bracketONE__six = 0;
int bracketONE__seven = 0;
int bracketONE__eight = 0;
int bracketONE__nine = 0;
int bracketONE__ten = 0;
int bracketONE__eleven = 0;
int bracketONE__twelve = 0;
int bracketONE__thirteen = 0;
int bracketONE__fourteen = 0;
int bracketONE__fifteen = 0;
int bracketONE__sixteen = 0;

int bracketONEgames = 0;







// ROUND OF 64 WIN COUNTS
double bracketTWOone = 0;
double bracketTWOtwo = 0;
double bracketTWOthree = 0;
double bracketTWOfour = 0;
double bracketTWOfive = 0;
double bracketTWOsix = 0;
double bracketTWOseven = 0;
double bracketTWOeight = 0;
double bracketTWOnine = 0;
double bracketTWOten = 0;
double bracketTWOeleven = 0;
double bracketTWOtwelve = 0;
double bracketTWOthirteen = 0;
double bracketTWOfourteen = 0;
double bracketTWOfifteen = 0;
double bracketTWOsixteen = 0;

// ROUND OF 32 WIN COUNTS
int bracketTWOone_ = 0;
int bracketTWOtwo_ = 0;
int bracketTWOthree_ = 0;
int bracketTWOfour_ = 0;
int bracketTWOfive_ = 0;
int bracketTWOsix_ = 0;
int bracketTWOseven_ = 0;
int bracketTWOeight_ = 0;
int bracketTWOnine_ = 0;
int bracketTWOten_ = 0;
int bracketTWOeleven_ = 0;
int bracketTWOtwelve_ = 0;
int bracketTWOthirteen_ = 0;
int bracketTWOfourteen_ = 0;
int bracketTWOfifteen_ = 0;
int bracketTWOsixteen_ = 0;

// SWEET 16 WIN COUNTS
int bracketTWO_one = 0;
int bracketTWO_two = 0;
int bracketTWO_three = 0;
int bracketTWO_four = 0;
int bracketTWO_five = 0;
int bracketTWO_six = 0;
int bracketTWO_seven = 0;
int bracketTWO_eight = 0;
int bracketTWO_nine = 0;
int bracketTWO_ten = 0;
int bracketTWO_eleven = 0;
int bracketTWO_twelve = 0;
int bracketTWO_thirteen = 0;
int bracketTWO_fourteen = 0;
int bracketTWO_fifteen = 0;
int bracketTWO_sixteen = 0;

// ELITE 8 WIN COUNTS
int bracketTWO__one = 0;
int bracketTWO__two = 0;
int bracketTWO__three = 0;
int bracketTWO__four = 0;
int bracketTWO__five = 0;
int bracketTWO__six = 0;
int bracketTWO__seven = 0;
int bracketTWO__eight = 0;
int bracketTWO__nine = 0;
int bracketTWO__ten = 0;
int bracketTWO__eleven = 0;
int bracketTWO__twelve = 0;
int bracketTWO__thirteen = 0;
int bracketTWO__fourteen = 0;
int bracketTWO__fifteen = 0;
int bracketTWO__sixteen = 0;

int bracketTWOgames = 0;





// ROUND OF 64 WIN COUNTS
double bracketTHREEone = 0;
double bracketTHREEtwo = 0;
double bracketTHREEthree = 0;
double bracketTHREEfour = 0;
double bracketTHREEfive = 0;
double bracketTHREEsix = 0;
double bracketTHREEseven = 0;
double bracketTHREEeight = 0;
double bracketTHREEnine = 0;
double bracketTHREEten = 0;
double bracketTHREEeleven = 0;
double bracketTHREEtwelve = 0;
double bracketTHREEthirteen = 0;
double bracketTHREEfourteen = 0;
double bracketTHREEfifteen = 0;
double bracketTHREEsixteen = 0;

// ROUND OF 32 WIN COUNTS
int bracketTHREEone_ = 0;
int bracketTHREEtwo_ = 0;
int bracketTHREEthree_ = 0;
int bracketTHREEfour_ = 0;
int bracketTHREEfive_ = 0;
int bracketTHREEsix_ = 0;
int bracketTHREEseven_ = 0;
int bracketTHREEeight_ = 0;
int bracketTHREEnine_ = 0;
int bracketTHREEten_ = 0;
int bracketTHREEeleven_ = 0;
int bracketTHREEtwelve_ = 0;
int bracketTHREEthirteen_ = 0;
int bracketTHREEfourteen_ = 0;
int bracketTHREEfifteen_ = 0;
int bracketTHREEsixteen_ = 0;

// SWEET 16 WIN COUNTS
int bracketTHREE_one = 0;
int bracketTHREE_two = 0;
int bracketTHREE_three = 0;
int bracketTHREE_four = 0;
int bracketTHREE_five = 0;
int bracketTHREE_six = 0;
int bracketTHREE_seven = 0;
int bracketTHREE_eight = 0;
int bracketTHREE_nine = 0;
int bracketTHREE_ten = 0;
int bracketTHREE_eleven = 0;
int bracketTHREE_twelve = 0;
int bracketTHREE_thirteen = 0;
int bracketTHREE_fourteen = 0;
int bracketTHREE_fifteen = 0;
int bracketTHREE_sixteen = 0;

// ELITE 8 WIN COUNTS
int bracketTHREE__one = 0;
int bracketTHREE__two = 0;
int bracketTHREE__three = 0;
int bracketTHREE__four = 0;
int bracketTHREE__five = 0;
int bracketTHREE__six = 0;
int bracketTHREE__seven = 0;
int bracketTHREE__eight = 0;
int bracketTHREE__nine = 0;
int bracketTHREE__ten = 0;
int bracketTHREE__eleven = 0;
int bracketTHREE__twelve = 0;
int bracketTHREE__thirteen = 0;
int bracketTHREE__fourteen = 0;
int bracketTHREE__fifteen = 0;
int bracketTHREE__sixteen = 0;

int bracketTHREEgames = 0;






// ROUND OF 64 WIN COUNTS
double bracketFOURone = 0;
double bracketFOURtwo = 0;
double bracketFOURthree = 0;
double bracketFOURfour = 0;
double bracketFOURfive = 0;
double bracketFOURsix = 0;
double bracketFOURseven = 0;
double bracketFOUReight = 0;
double bracketFOURnine = 0;
double bracketFOURten = 0;
double bracketFOUReleven = 0;
double bracketFOURtwelve = 0;
double bracketFOURthirteen = 0;
double bracketFOURfourteen = 0;
double bracketFOURfifteen = 0;
double bracketFOURsixteen = 0;

// ROUND OF 32 WIN COUNTS
int bracketFOURone_ = 0;
int bracketFOURtwo_ = 0;
int bracketFOURthree_ = 0;
int bracketFOURfour_ = 0;
int bracketFOURfive_ = 0;
int bracketFOURsix_ = 0;
int bracketFOURseven_ = 0;
int bracketFOUReight_ = 0;
int bracketFOURnine_ = 0;
int bracketFOURten_ = 0;
int bracketFOUReleven_ = 0;
int bracketFOURtwelve_ = 0;
int bracketFOURthirteen_ = 0;
int bracketFOURfourteen_ = 0;
int bracketFOURfifteen_ = 0;
int bracketFOURsixteen_ = 0;

// SWEET 16 WIN COUNTS
int bracketFOUR_one = 0;
int bracketFOUR_two = 0;
int bracketFOUR_three = 0;
int bracketFOUR_four = 0;
int bracketFOUR_five = 0;
int bracketFOUR_six = 0;
int bracketFOUR_seven = 0;
int bracketFOUR_eight = 0;
int bracketFOUR_nine = 0;
int bracketFOUR_ten = 0;
int bracketFOUR_eleven = 0;
int bracketFOUR_twelve = 0;
int bracketFOUR_thirteen = 0;
int bracketFOUR_fourteen = 0;
int bracketFOUR_fifteen = 0;
int bracketFOUR_sixteen = 0;

// ELITE 8 WIN COUNTS
int bracketFOUR__one = 0;
int bracketFOUR__two = 0;
int bracketFOUR__three = 0;
int bracketFOUR__four = 0;
int bracketFOUR__five = 0;
int bracketFOUR__six = 0;
int bracketFOUR__seven = 0;
int bracketFOUR__eight = 0;
int bracketFOUR__nine = 0;
int bracketFOUR__ten = 0;
int bracketFOUR__eleven = 0;
int bracketFOUR__twelve = 0;
int bracketFOUR__thirteen = 0;
int bracketFOUR__fourteen = 0;
int bracketFOUR__fifteen = 0;
int bracketFOUR__sixteen = 0;

int bracketFOURgames = 0;

int main() 
{	
	int final4_one = 0;
	int final4_two = 0;
	int final4_three = 0;
	int final4_four = 0;
	int final4_five = 0;
	int final4_six = 0;
	int final4_seven = 0;
	int final4_eight = 0;
	int final4_nine = 0;
	int final4_ten = 0;
	int final4_eleven = 0;
	int final4_twelve = 0;
	int final4_thirteen = 0;
	int final4_fourteen = 0;
	int final4_fifteen = 0;
	int final4_sixteen = 0;
	
			
		
	int champion_one = 0;
	int champion_two = 0;
	int champion_three = 0;
	int champion_four = 0;
	int champion_five = 0;
	int champion_six = 0;
	int champion_seven = 0;
	int champion_eight = 0;
	int champion_nine = 0;
	int champion_ten = 0;
	int champion_eleven = 0;
	int champion_twelve = 0;
	int champion_thirteen = 0;
	int champion_fourteen = 0;
	int champion_fifteen = 0;
	int champion_sixteen = 0;
	
	for (int i = 0; i < 1; i++)
	{		
		for (int i = 0; i < 1; i++)
		{
			bracketONEgames++;
			oneRoundOf64();
			oneRoundOf32();
			oneSweet16();
			oneElite8();
			
			// TALLYING THE ROUND OF 64 WINS
			if (onesecond_advancing[0] == 0)
				bracketONEone++;
			
			if (onesecond_advancing[0] == 15)
				bracketONEsixteen++;
			
			if (onesecond_advancing[1] == 1)
				bracketONEtwo++;
			
			if (onesecond_advancing[1] == 14)
				bracketONEfifteen++;
			
			if (onesecond_advancing[2] == 2)
				bracketONEthree++;
			
			if (onesecond_advancing[2] == 13)
				bracketONEfourteen++;
			
			if (onesecond_advancing[3] == 3)
				bracketONEfour++;
			
			if (onesecond_advancing[3] == 12)
				bracketONEthirteen++;
			
			if (onesecond_advancing[4] == 4)
				bracketONEfive++;
			
			if (onesecond_advancing[4] == 11)
				bracketONEtwelve++;
			
			if (onesecond_advancing[5] == 5)
				bracketONEsix++;
			
			if (onesecond_advancing[5] == 10)
				bracketONEeleven++;
			
			if (onesecond_advancing[6] == 6)
				bracketONEseven++;
			
			if (onesecond_advancing[6] == 9)
				bracketONEten++;
			
			if (onesecond_advancing[7] == 7)
				bracketONEeight++;
			
			if (onesecond_advancing[7] == 8)
				bracketONEnine++;

			
			// TALLYING THE ROUND OF 32 WINS
			if (onesweet_advancing[0] == 0)
				bracketONEone_++;
			
			if (onesweet_advancing[0] == 15)
				bracketONEsixteen_++;
			
			if (onesweet_advancing[0] == 7)
				bracketONEeight_++;
			
			if (onesweet_advancing[0] == 8)
				bracketONEnine_++;
			
			if (onesweet_advancing[1] == 1)
				bracketONEtwo_++;
			
			if (onesweet_advancing[1] == 14)
				bracketONEfifteen_++;
			
			if (onesweet_advancing[1] == 6)
				bracketONEseven_++;
			
			if (onesweet_advancing[1] == 9)
				bracketONEten_++;
			
			if (onesweet_advancing[2] == 2)
				bracketONEthree_++;
			
			if (onesweet_advancing[2] == 13)
				bracketONEfourteen_++;
			
			if (onesweet_advancing[2] == 5)
				bracketONEsix_++;
			
			if (onesweet_advancing[2] == 10)
				bracketONEeleven_++;
			
			if (onesweet_advancing[3] == 3)
				bracketONEfour_++;
			
			if (onesweet_advancing[3] == 4)
				bracketONEfive_++;
			
			if (onesweet_advancing[3] == 12)
				bracketONEthirteen_++;
			
			if (onesweet_advancing[3] == 11)
				bracketONEtwelve_++;	
			
			
			
			// TALLYING THE SWEET 16 WINS
			if (oneelite_advancing[0] == 0) 
				bracketONE_one++;
			
			if (oneelite_advancing[0] == 15)
				bracketONE_sixteen++;
			
			if (oneelite_advancing[0] == 7)
				bracketONE_eight++;
			
			if (oneelite_advancing[0] == 8)
				bracketONE_nine++;
			
			if (oneelite_advancing[0] == 4)
				bracketONE_five++;
			
			if (oneelite_advancing[0] == 11)
				bracketONE_twelve++;
			
			if (oneelite_advancing[0] == 3)
				bracketONE_four++;
			
			if (oneelite_advancing[0] == 12)
				bracketONE_thirteen++;
			
			if (oneelite_advancing[1] == 10)
				bracketONE_eleven++;
				
			if (oneelite_advancing[1] == 2)
				bracketONE_three++;
				
			if (oneelite_advancing[1] == 13)
				bracketONE_fourteen++;
				
			if (oneelite_advancing[1] == 6)
				bracketONE_seven++;
				
			if (oneelite_advancing[1] == 9)
				bracketONE_ten++;
				
			if (oneelite_advancing[1] == 1)
				bracketONE_two++;
				
			if (oneelite_advancing[1] == 14)
				bracketONE_fifteen++;
			
			if (oneelite_advancing[1] == 5)
				bracketONE_six++;
			
			
			
			// TALLYING THE ELITE 8 WINS
			if (onefour_advancing[0] == 0) 
				bracketONE__one++;
			
			if (onefour_advancing[0] == 1)
				bracketONE__two++;
			
			if (onefour_advancing[0] == 2)
				bracketONE__three++;
			
			if (onefour_advancing[0] == 3)
				bracketONE__four++;
			
			if (onefour_advancing[0] == 4)
				bracketONE__five++;
			
			if (onefour_advancing[0] == 5)
				bracketONE__six++;
			
			if (onefour_advancing[0] == 6)
				bracketONE__seven++;
			
			if (onefour_advancing[0] == 7)
				bracketONE__eight++;
			
			if (onefour_advancing[0] == 8)
				bracketONE__nine++;
				
			if (onefour_advancing[0] == 9)
				bracketONE__ten++;
				
			if (onefour_advancing[0] == 10)
				bracketONE__eleven++;
				
			if (onefour_advancing[0] == 11)
				bracketONE__twelve++;
				
			if (onefour_advancing[0] == 12)
				bracketONE__thirteen++;
				
			if (onefour_advancing[0] == 13)
				bracketONE__fourteen++;
			
			if (onefour_advancing[0] == 14)
				bracketONE__fifteen++;
				
			if (onefour_advancing[0] == 15)
				bracketONE__sixteen++;
		}
		
		cout << endl;
		
		
		for (int i = 0; i < 1; i++)
		{
			bracketTWOgames++;
			twoRoundOf64();
			twoRoundOf32();
			twoSweet16();
			twoElite8();
			
			// TALLYING THE ROUND OF 64 WINS
			if (twosecond_advancing[0] == 0)
				bracketTWOone++;
			
			if (twosecond_advancing[0] == 15)
				bracketTWOsixteen++;
			
			if (twosecond_advancing[1] == 1)
				bracketTWOtwo++;
			
			if (twosecond_advancing[1] == 14)
				bracketTWOfifteen++;
			
			if (twosecond_advancing[2] == 2)
				bracketTWOthree++;
			
			if (twosecond_advancing[2] == 13)
				bracketTWOfourteen++;
			
			if (twosecond_advancing[3] == 3)
				bracketTWOfour++;
			
			if (twosecond_advancing[3] == 12)
				bracketTWOthirteen++;
			
			if (twosecond_advancing[4] == 4)
				bracketTWOfive++;
			
			if (twosecond_advancing[4] == 11)
				bracketTWOtwelve++;
			
			if (twosecond_advancing[5] == 5)
				bracketTWOsix++;
			
			if (twosecond_advancing[5] == 10)
				bracketTWOeleven++;
			
			if (twosecond_advancing[6] == 6)
				bracketTWOseven++;
			
			if (twosecond_advancing[6] == 9)
				bracketTWOten++;
			
			if (twosecond_advancing[7] == 7)
				bracketTWOeight++;
			
			if (twosecond_advancing[7] == 8)
				bracketTWOnine++;

			
			// TALLYING THE ROUND OF 32 WINS
			if (twosweet_advancing[0] == 0)
				bracketTWOone_++;
			
			if (twosweet_advancing[0] == 15)
				bracketTWOsixteen_++;
			
			if (twosweet_advancing[0] == 7)
				bracketTWOeight_++;
			
			if (twosweet_advancing[0] == 8)
				bracketTWOnine_++;
			
			if (twosweet_advancing[1] == 1)
				bracketTWOtwo_++;
			
			if (twosweet_advancing[1] == 14)
				bracketTWOfifteen_++;
			
			if (twosweet_advancing[1] == 6)
				bracketTWOseven_++;
			
			if (twosweet_advancing[1] == 9)
				bracketTWOten_++;
			
			if (twosweet_advancing[2] == 2)
				bracketTWOthree_++;
			
			if (twosweet_advancing[2] == 13)
				bracketTWOfourteen_++;
			
			if (twosweet_advancing[2] == 5)
				bracketTWOsix_++;
			
			if (twosweet_advancing[2] == 10)
				bracketTWOeleven_++;
			
			if (twosweet_advancing[3] == 3)
				bracketTWOfour_++;
			
			if (twosweet_advancing[3] == 4)
				bracketTWOfive_++;
			
			if (twosweet_advancing[3] == 12)
				bracketTWOthirteen_++;
			
			if (twosweet_advancing[3] == 11)
				bracketTWOtwelve_++;	
			
			
			
			// TALLYING THE SWEET 16 WINS
			if (twoelite_advancing[0] == 0) 
				bracketTWO_one++;
			
			if (twoelite_advancing[0] == 15)
				bracketTWO_sixteen++;
			
			if (twoelite_advancing[0] == 7)
				bracketTWO_eight++;
			
			if (twoelite_advancing[0] == 8)
				bracketTWO_nine++;
			
			if (twoelite_advancing[0] == 4)
				bracketTWO_five++;
			
			if (twoelite_advancing[0] == 11)
				bracketTWO_twelve++;
			
			if (twoelite_advancing[0] == 3)
				bracketTWO_four++;
			
			if (twoelite_advancing[0] == 12)
				bracketTWO_thirteen++;
			
			if (twoelite_advancing[1] == 10)
				bracketTWO_eleven++;
				
			if (twoelite_advancing[1] == 2)
				bracketTWO_three++;
				
			if (twoelite_advancing[1] == 13)
				bracketTWO_fourteen++;
				
			if (twoelite_advancing[1] == 6)
				bracketTWO_seven++;
				
			if (twoelite_advancing[1] == 9)
				bracketTWO_ten++;
				
			if (twoelite_advancing[1] == 1)
				bracketTWO_two++;
				
			if (twoelite_advancing[1] == 14)
				bracketTWO_fifteen++;
			
			if (twoelite_advancing[1] == 5)
				bracketTWO_six++;
			
			
			
			// TALLYING THE ELITE 8 WINS
			if (twofour_advancing[0] == 0) 
				bracketTWO__one++;
			
			if (twofour_advancing[0] == 1)
				bracketTWO__two++;
			
			if (twofour_advancing[0] == 2)
				bracketTWO__three++;
			
			if (twofour_advancing[0] == 3)
				bracketTWO__four++;
			
			if (twofour_advancing[0] == 4)
				bracketTWO__five++;
			
			if (twofour_advancing[0] == 5)
				bracketTWO__six++;
			
			if (twofour_advancing[0] == 6)
				bracketTWO__seven++;
			
			if (twofour_advancing[0] == 7)
				bracketTWO__eight++;
			
			if (twofour_advancing[0] == 8)
				bracketTWO__nine++;
				
			if (twofour_advancing[0] == 9)
				bracketTWO__ten++;
				
			if (twofour_advancing[0] == 10)
				bracketTWO__eleven++;
				
			if (twofour_advancing[0] == 11)
				bracketTWO__twelve++;
				
			if (twofour_advancing[0] == 12)
				bracketTWO__thirteen++;
				
			if (twofour_advancing[0] == 13)
				bracketTWO__fourteen++;
			
			if (twofour_advancing[0] == 14)
				bracketTWO__fifteen++;
				
			if (twofour_advancing[0] == 15)
				bracketTWO__sixteen++;
		}
		
		cout << endl << endl << endl << endl;
		
		
		for (int i = 0; i < 1; i++)
		{
			bracketTHREEgames++;
			threeRoundOf64();
			threeRoundOf32();
			threeSweet16();
			threeElite8();
			
			// TALLYING THE ROUND OF 64 WINS
			if (threesecond_advancing[0] == 0)
				bracketTHREEone++;
			
			if (threesecond_advancing[0] == 15)
				bracketTHREEsixteen++;
			
			if (threesecond_advancing[1] == 1)
				bracketTHREEtwo++;
			
			if (threesecond_advancing[1] == 14)
				bracketTHREEfifteen++;
			
			if (threesecond_advancing[2] == 2)
				bracketTHREEthree++;
			
			if (threesecond_advancing[2] == 13)
				bracketTHREEfourteen++;
			
			if (threesecond_advancing[3] == 3)
				bracketTHREEfour++;
			
			if (threesecond_advancing[3] == 12)
				bracketTHREEthirteen++;
			
			if (threesecond_advancing[4] == 4)
				bracketTHREEfive++;
			
			if (threesecond_advancing[4] == 11)
				bracketTHREEtwelve++;
			
			if (threesecond_advancing[5] == 5)
				bracketTHREEsix++;
			
			if (threesecond_advancing[5] == 10)
				bracketTHREEeleven++;
			
			if (threesecond_advancing[6] == 6)
				bracketTHREEseven++;
			
			if (threesecond_advancing[6] == 9)
				bracketTHREEten++;
			
			if (threesecond_advancing[7] == 7)
				bracketTHREEeight++;
			
			if (threesecond_advancing[7] == 8)
				bracketTHREEnine++;

			
			// TALLYING THE ROUND OF 32 WINS
			if (threesweet_advancing[0] == 0)
				bracketTHREEone_++;
			
			if (threesweet_advancing[0] == 15)
				bracketTHREEsixteen_++;
			
			if (threesweet_advancing[0] == 7)
				bracketTHREEeight_++;
			
			if (threesweet_advancing[0] == 8)
				bracketTHREEnine_++;
			
			if (threesweet_advancing[1] == 1)
				bracketTHREEtwo_++;
			
			if (threesweet_advancing[1] == 14)
				bracketTHREEfifteen_++;
			
			if (threesweet_advancing[1] == 6)
				bracketTHREEseven_++;
			
			if (threesweet_advancing[1] == 9)
				bracketTHREEten_++;
			
			if (threesweet_advancing[2] == 2)
				bracketTHREEthree_++;
			
			if (threesweet_advancing[2] == 13)
				bracketTHREEfourteen_++;
			
			if (threesweet_advancing[2] == 5)
				bracketTHREEsix_++;
			
			if (threesweet_advancing[2] == 10)
				bracketTHREEeleven_++;
			
			if (threesweet_advancing[3] == 3)
				bracketTHREEfour_++;
			
			if (threesweet_advancing[3] == 4)
				bracketTHREEfive_++;
			
			if (threesweet_advancing[3] == 12)
				bracketTHREEthirteen_++;
			
			if (threesweet_advancing[3] == 11)
				bracketTHREEtwelve_++;	
			
			
			
			// TALLYING THE SWEET 16 WINS
			if (threeelite_advancing[0] == 0) 
				bracketTHREE_one++;
			
			if (threeelite_advancing[0] == 15)
				bracketTHREE_sixteen++;
			
			if (threeelite_advancing[0] == 7)
				bracketTHREE_eight++;
			
			if (threeelite_advancing[0] == 8)
				bracketTHREE_nine++;
			
			if (threeelite_advancing[0] == 4)
				bracketTHREE_five++;
			
			if (threeelite_advancing[0] == 11)
				bracketTHREE_twelve++;
			
			if (threeelite_advancing[0] == 3)
				bracketTHREE_four++;
			
			if (threeelite_advancing[0] == 12)
				bracketTHREE_thirteen++;
			
			if (threeelite_advancing[1] == 10)
				bracketTHREE_eleven++;
				
			if (threeelite_advancing[1] == 2)
				bracketTHREE_three++;
				
			if (threeelite_advancing[1] == 13)
				bracketTHREE_fourteen++;
				
			if (threeelite_advancing[1] == 6)
				bracketTHREE_seven++;
				
			if (threeelite_advancing[1] == 9)
				bracketTHREE_ten++;
				
			if (threeelite_advancing[1] == 1)
				bracketTHREE_two++;
				
			if (threeelite_advancing[1] == 14)
				bracketTHREE_fifteen++;
			
			if (threeelite_advancing[1] == 5)
				bracketTHREE_six++;
			
			
			
			// TALLYING THE ELITE 8 WINS
			if (threefour_advancing[0] == 0) 
				bracketTHREE__one++;
			
			if (threefour_advancing[0] == 1)
				bracketTHREE__two++;
			
			if (threefour_advancing[0] == 2)
				bracketTHREE__three++;
			
			if (threefour_advancing[0] == 3)
				bracketTHREE__four++;
			
			if (threefour_advancing[0] == 4)
				bracketTHREE__five++;
			
			if (threefour_advancing[0] == 5)
				bracketTHREE__six++;
			
			if (threefour_advancing[0] == 6)
				bracketTHREE__seven++;
			
			if (threefour_advancing[0] == 7)
				bracketTHREE__eight++;
			
			if (threefour_advancing[0] == 8)
				bracketTHREE__nine++;
				
			if (threefour_advancing[0] == 9)
				bracketTHREE__ten++;
				
			if (threefour_advancing[0] == 10)
				bracketTHREE__eleven++;
				
			if (threefour_advancing[0] == 11)
				bracketTHREE__twelve++;
				
			if (threefour_advancing[0] == 12)
				bracketTHREE__thirteen++;
				
			if (threefour_advancing[0] == 13)
				bracketTHREE__fourteen++;
			
			if (threefour_advancing[0] == 14)
				bracketTHREE__fifteen++;
				
			if (threefour_advancing[0] == 15)
				bracketTHREE__sixteen++;
		}
		
		cout << endl << endl << endl << endl;
		
		
		for (int i = 0; i < 1; i++)
		{
			bracketFOURgames++;
			fourRoundOf64();
			fourRoundOf32();
			fourSweet16();
			fourElite8();

			// TALLYING THE ROUND OF 64 WINS
			if (foursecond_advancing[0] == 0)
				bracketFOURone++;
			
			if (foursecond_advancing[0] == 15)
				bracketFOURsixteen++;
			
			if (foursecond_advancing[1] == 1)
				bracketFOURtwo++;
			
			if (foursecond_advancing[1] == 14)
				bracketFOURfifteen++;
			
			if (foursecond_advancing[2] == 2)
				bracketFOURthree++;
			
			if (foursecond_advancing[2] == 13)
				bracketFOURfourteen++;
			
			if (foursecond_advancing[3] == 3)
				bracketFOURfour++;
			
			if (foursecond_advancing[3] == 12)
				bracketFOURthirteen++;
			
			if (foursecond_advancing[4] == 4)
				bracketFOURfive++;
			
			if (foursecond_advancing[4] == 11)
				bracketFOURtwelve++;
			
			if (foursecond_advancing[5] == 5)
				bracketFOURsix++;
			
			if (foursecond_advancing[5] == 10)
				bracketFOUReleven++;
			
			if (foursecond_advancing[6] == 6)
				bracketFOURseven++;
			
			if (foursecond_advancing[6] == 9)
				bracketFOURten++;
			
			if (foursecond_advancing[7] == 7)
				bracketFOUReight++;
			
			if (foursecond_advancing[7] == 8)
				bracketFOURnine++;

			
			// TALLYING THE ROUND OF 32 WINS
			if (foursweet_advancing[0] == 0)
				bracketFOURone_++;
			
			if (foursweet_advancing[0] == 15)
				bracketFOURsixteen_++;
			
			if (foursweet_advancing[0] == 7)
				bracketFOUReight_++;
			
			if (foursweet_advancing[0] == 8)
				bracketFOURnine_++;
			
			if (foursweet_advancing[1] == 1)
				bracketFOURtwo_++;
			
			if (foursweet_advancing[1] == 14)
				bracketFOURfifteen_++;
			
			if (foursweet_advancing[1] == 6)
				bracketFOURseven_++;
			
			if (foursweet_advancing[1] == 9)
				bracketFOURten_++;
			
			if (foursweet_advancing[2] == 2)
				bracketFOURthree_++;
			
			if (foursweet_advancing[2] == 13)
				bracketFOURfourteen_++;
			
			if (foursweet_advancing[2] == 5)
				bracketFOURsix_++;
			
			if (foursweet_advancing[2] == 10)
				bracketFOUReleven_++;
			
			if (foursweet_advancing[3] == 3)
				bracketFOURfour_++;
			
			if (foursweet_advancing[3] == 4)
				bracketFOURfive_++;
			
			if (foursweet_advancing[3] == 12)
				bracketFOURthirteen_++;
			
			if (foursweet_advancing[3] == 11)
				bracketFOURtwelve_++;	
			
			
			
			// TALLYING THE SWEET 16 WINS
			if (fourelite_advancing[0] == 0) 
				bracketFOUR_one++;
			
			if (fourelite_advancing[0] == 15)
				bracketFOUR_sixteen++;
			
			if (fourelite_advancing[0] == 7)
				bracketFOUR_eight++;
			
			if (fourelite_advancing[0] == 8)
				bracketFOUR_nine++;
			
			if (fourelite_advancing[0] == 4)
				bracketFOUR_five++;
			
			if (fourelite_advancing[0] == 11)
				bracketFOUR_twelve++;
			
			if (fourelite_advancing[0] == 3)
				bracketFOUR_four++;
			
			if (fourelite_advancing[0] == 12)
				bracketFOUR_thirteen++;
			
			if (fourelite_advancing[1] == 10)
				bracketFOUR_eleven++;
				
			if (fourelite_advancing[1] == 2)
				bracketFOUR_three++;
				
			if (fourelite_advancing[1] == 13)
				bracketFOUR_fourteen++;
				
			if (fourelite_advancing[1] == 6)
				bracketFOUR_seven++;
				
			if (fourelite_advancing[1] == 9)
				bracketFOUR_ten++;
				
			if (fourelite_advancing[1] == 1)
				bracketFOUR_two++;
				
			if (fourelite_advancing[1] == 14)
				bracketFOUR_fifteen++;
			
			if (fourelite_advancing[1] == 5)
				bracketFOUR_six++;
			
			
			
			// TALLYING THE ELITE 8 WINS
			if (fourfour_advancing[0] == 0) 
				bracketFOUR__one++;
			
			if (fourfour_advancing[0] == 1)
				bracketFOUR__two++;
			
			if (fourfour_advancing[0] == 2)
				bracketFOUR__three++;
			
			if (fourfour_advancing[0] == 3)
				bracketFOUR__four++;
			
			if (fourfour_advancing[0] == 4)
				bracketFOUR__five++;
			
			if (fourfour_advancing[0] == 5)
				bracketFOUR__six++;
			
			if (fourfour_advancing[0] == 6)
				bracketFOUR__seven++;
			
			if (fourfour_advancing[0] == 7)
				bracketFOUR__eight++;
			
			if (fourfour_advancing[0] == 8)
				bracketFOUR__nine++;
				
			if (fourfour_advancing[0] == 9)
				bracketFOUR__ten++;
				
			if (fourfour_advancing[0] == 10)
				bracketFOUR__eleven++;
				
			if (fourfour_advancing[0] == 11)
				bracketFOUR__twelve++;
				
			if (fourfour_advancing[0] == 12)
				bracketFOUR__thirteen++;
				
			if (fourfour_advancing[0] == 13)
				bracketFOUR__fourteen++;
			
			if (fourfour_advancing[0] == 14)
				bracketFOUR__fifteen++;
				
			if (fourfour_advancing[0] == 15)
				bracketFOUR__sixteen++;
		}
		
		cout << endl;
		cout << "Bracket One Results:" << endl;
		cout << "1 seed Round of 64 wins: " << bracketONEone << "\t vs. win percentage: " << bracketONEone/bracketONEgames <<	endl;
		cout << "2 seed Round of 64 wins: "  << bracketONEtwo << "\t vs. win percentage: " << bracketONEtwo/bracketONEgames << endl;
		cout << "3 seed Round of 64 wins: " << bracketONEthree << "\t vs. win percentage: " << bracketONEthree/bracketONEgames << endl;
		cout << "4 seed Round of 64 wins: " << bracketONEfour << "\t vs. win percentage: " << bracketONEfour/bracketONEgames << endl;
		cout << "5 seed Round of 64 wins: " << bracketONEfive << "\t vs. win percentage: " << bracketONEfive/bracketONEgames << endl;
		cout << "6 seed Round of 64 wins: " << bracketONEsix << "\t vs. win percentage: " << bracketONEsix/bracketONEgames << endl;
		cout << "7 seed Round of 64 wins: " << bracketONEseven << "\t vs. win percentage: " << bracketONEseven/bracketONEgames << endl;
		cout << "8 seed Round of 64 wins: " << bracketONEeight << "\t vs. win percentage: " << bracketONEeight/bracketONEgames << endl; 
		cout << "9 seed Round of 64 wins: " << bracketONEnine << "\t vs. win percentage: " << bracketONEnine/bracketONEgames << endl;
		cout << "10 seed Round of 64 wins: " << bracketONEten << "\t vs. win percentage: " << bracketONEten/bracketONEgames << endl;
		cout << "11 seed Round of 64 wins: " << bracketONEeleven << "\t vs. win percentage: " << bracketONEeleven/bracketONEgames << endl;
		cout << "12 seed Round of 64 wins: " << bracketONEtwelve << "\t vs. win percentage: " << bracketONEtwelve/bracketONEgames << endl;
		cout << "13 seed Round of 64 wins: " << bracketONEthirteen << "\t vs. win percentage: " << bracketONEthirteen/bracketONEgames << endl;
		cout << "14 seed Round of 64 wins: " << bracketONEfourteen << "\t vs. win percentage: " << bracketONEfourteen/bracketONEgames << endl;
		cout << "15 seed Round of 64 wins: " << bracketONEfifteen << "\t vs. win percentage: " << bracketONEfifteen/bracketONEgames << endl;
		cout << "16 seed Round of 64 wins: " << bracketONEsixteen << "\t vs. win percentage: " << bracketONEsixteen/bracketONEgames << endl << endl;
		
		cout << "1 seed Round of 32 wins: " << bracketONEone_ << endl;
		cout << "2 seed Round of 32 wins: " << bracketONEtwo_ << endl;
		cout << "3 seed Round of 32 wins: " << bracketONEthree_ << endl;
		cout << "4 seed Round of 32 wins: " << bracketONEfour_ << endl;
		cout << "5 seed Round of 32 wins: " << bracketONEfive_ << endl;
		cout << "6 seed Round of 32 wins: " << bracketONEsix_ << endl;
		cout << "7 seed Round of 32 wins: " << bracketONEseven_ << endl;
		cout << "8 seed Round of 32 wins: " << bracketONEeight_ << endl; 
		cout << "9 seed Round of 32 wins: " << bracketONEnine_ << endl;
		cout << "10 seed Round of 32 wins: " << bracketONEten_ << endl;
		cout << "11 seed Round of 32 wins: " << bracketONEeleven_ << endl;
		cout << "12 seed Round of 32 wins: " << bracketONEtwelve_ << endl;
		cout << "13 seed Round of 32 wins: " << bracketONEthirteen_ << endl;
		cout << "14 seed Round of 32 wins: " << bracketONEfourteen_ << endl;
		cout << "15 seed Round of 32 wins: " << bracketONEfifteen_ << endl;
		cout << "16 seed Round of 32 wins: " << bracketONEsixteen_ << endl << endl;
		
		cout << "1 seed Sweet 16 wins: " << bracketONE_one << endl;
		cout << "2 seed Sweet 16 wins: " << bracketONE_two << endl;
		cout << "3 seed Sweet 16 wins: " << bracketONE_three << endl;
		cout << "4 seed Sweet 16 wins: " << bracketONE_four << endl;
		cout << "5 seed Sweet 16 wins: " << bracketONE_five << endl;
		cout << "6 seed Sweet 16 wins: " << bracketONE_six << endl;
		cout << "7 seed Sweet 16 wins: " << bracketONE_seven << endl;
		cout << "8 seed Sweet 16 wins: " << bracketONE_eight << endl; 
		cout << "9 seed Sweet 16 wins: " << bracketONE_nine << endl;
		cout << "10 seed Sweet 16 wins: " << bracketONE_ten << endl;
		cout << "11 seed Sweet 16 wins: " << bracketONE_eleven << endl;
		cout << "12 seed Sweet 16 wins: " << bracketONE_twelve << endl;
		cout << "13 seed Sweet 16 wins: " << bracketONE_thirteen << endl;
		cout << "14 seed Sweet 16 wins: " << bracketONE_fourteen << endl;
		cout << "15 seed Sweet 16 wins: " << bracketONE_fifteen << endl;
		cout << "16 seed Sweet 16 wins: " << bracketONE_sixteen << endl << endl;
		
		cout << "1 seed Elite 8 wins: " << bracketONE__one << endl;
		cout << "2 seed Elite 8 wins: " << bracketONE__two << endl;
		cout << "3 seed Elite 8 wins: " << bracketONE__three << endl;
		cout << "4 seed Elite 8 wins: " << bracketONE__four << endl;
		cout << "5 seed Elite 8 wins: " << bracketONE__five << endl;
		cout << "6 seed Elite 8 wins: " << bracketONE__six << endl;
		cout << "7 seed Elite 8 wins: " << bracketONE__seven << endl;
		cout << "8 seed Elite 8 wins: " << bracketONE__eight << endl; 
		cout << "9 seed Elite 8 wins: " << bracketONE__nine << endl;
		cout << "10 seed Elite 8 wins: " << bracketONE__ten << endl;
		cout << "11 seed Elite 8 wins: " << bracketONE__eleven << endl;
		cout << "12 seed Elite 8 wins: " << bracketONE__twelve << endl;
		cout << "13 seed Elite 8 wins: " << bracketONE__thirteen << endl;
		cout << "14 seed Elite 8 wins: " << bracketONE__fourteen << endl;
		cout << "15 seed Elite 8 wins: " << bracketONE__fifteen << endl;
		cout << "16 seed Elite 8 wins: " << bracketONE__sixteen << endl << endl << endl;
		
		//
		//
		//
		//
		//
		//
		//
		//
		
		cout << endl << endl << endl << endl;
		cout << "Bracket Two Results:" << endl;
		cout << "1 seed Round of 64 wins: " << bracketTWOone << "\t vs. win percentage: " << bracketTWOone/bracketTWOgames <<	endl;
		cout << "2 seed Round of 64 wins: "  << bracketTWOtwo << "\t vs. win percentage: " << bracketTWOtwo/bracketTWOgames << endl;
		cout << "3 seed Round of 64 wins: " << bracketTWOthree << "\t vs. win percentage: " << bracketTWOthree/bracketTWOgames << endl;
		cout << "4 seed Round of 64 wins: " << bracketTWOfour << "\t vs. win percentage: " << bracketTWOfour/bracketTWOgames << endl;
		cout << "5 seed Round of 64 wins: " << bracketTWOfive << "\t vs. win percentage: " << bracketTWOfive/bracketTWOgames << endl;
		cout << "6 seed Round of 64 wins: " << bracketTWOsix << "\t vs. win percentage: " << bracketTWOsix/bracketTWOgames << endl;
		cout << "7 seed Round of 64 wins: " << bracketTWOseven << "\t vs. win percentage: " << bracketTWOseven/bracketTWOgames << endl;
		cout << "8 seed Round of 64 wins: " << bracketTWOeight << "\t vs. win percentage: " << bracketTWOeight/bracketTWOgames << endl; 
		cout << "9 seed Round of 64 wins: " << bracketTWOnine << "\t vs. win percentage: " << bracketTWOnine/bracketTWOgames << endl;
		cout << "10 seed Round of 64 wins: " << bracketTWOten << "\t vs. win percentage: " << bracketTWOten/bracketTWOgames << endl;
		cout << "11 seed Round of 64 wins: " << bracketTWOeleven << "\t vs. win percentage: " << bracketTWOeleven/bracketTWOgames << endl;
		cout << "12 seed Round of 64 wins: " << bracketTWOtwelve << "\t vs. win percentage: " << bracketTWOtwelve/bracketTWOgames << endl;
		cout << "13 seed Round of 64 wins: " << bracketTWOthirteen << "\t vs. win percentage: " << bracketTWOthirteen/bracketTWOgames << endl;
		cout << "14 seed Round of 64 wins: " << bracketTWOfourteen << "\t vs. win percentage: " << bracketTWOfourteen/bracketTWOgames << endl;
		cout << "15 seed Round of 64 wins: " << bracketTWOfifteen << "\t vs. win percentage: " << bracketTWOfifteen/bracketTWOgames << endl;
		cout << "16 seed Round of 64 wins: " << bracketTWOsixteen << "\t vs. win percentage: " << bracketTWOsixteen/bracketTWOgames << endl << endl;
		
		cout << "1 seed Round of 32 wins: " << bracketTWOone_ << endl;
		cout << "2 seed Round of 32 wins: " << bracketTWOtwo_ << endl;
		cout << "3 seed Round of 32 wins: " << bracketTWOthree_ << endl;
		cout << "4 seed Round of 32 wins: " << bracketTWOfour_ << endl;
		cout << "5 seed Round of 32 wins: " << bracketTWOfive_ << endl;
		cout << "6 seed Round of 32 wins: " << bracketTWOsix_ << endl;
		cout << "7 seed Round of 32 wins: " << bracketTWOseven_ << endl;
		cout << "8 seed Round of 32 wins: " << bracketTWOeight_ << endl; 
		cout << "9 seed Round of 32 wins: " << bracketTWOnine_ << endl;
		cout << "10 seed Round of 32 wins: " << bracketTWOten_ << endl;
		cout << "11 seed Round of 32 wins: " << bracketTWOeleven_ << endl;
		cout << "12 seed Round of 32 wins: " << bracketTWOtwelve_ << endl;
		cout << "13 seed Round of 32 wins: " << bracketTWOthirteen_ << endl;
		cout << "14 seed Round of 32 wins: " << bracketTWOfourteen_ << endl;
		cout << "15 seed Round of 32 wins: " << bracketTWOfifteen_ << endl;
		cout << "16 seed Round of 32 wins: " << bracketTWOsixteen_ << endl << endl;
		
		cout << "1 seed Sweet 16 wins: " << bracketTWO_one << endl;
		cout << "2 seed Sweet 16 wins: " << bracketTWO_two << endl;
		cout << "3 seed Sweet 16 wins: " << bracketTWO_three << endl;
		cout << "4 seed Sweet 16 wins: " << bracketTWO_four << endl;
		cout << "5 seed Sweet 16 wins: " << bracketTWO_five << endl;
		cout << "6 seed Sweet 16 wins: " << bracketTWO_six << endl;
		cout << "7 seed Sweet 16 wins: " << bracketTWO_seven << endl;
		cout << "8 seed Sweet 16 wins: " << bracketTWO_eight << endl; 
		cout << "9 seed Sweet 16 wins: " << bracketTWO_nine << endl;
		cout << "10 seed Sweet 16 wins: " << bracketTWO_ten << endl;
		cout << "11 seed Sweet 16 wins: " << bracketTWO_eleven << endl;
		cout << "12 seed Sweet 16 wins: " << bracketTWO_twelve << endl;
		cout << "13 seed Sweet 16 wins: " << bracketTWO_thirteen << endl;
		cout << "14 seed Sweet 16 wins: " << bracketTWO_fourteen << endl;
		cout << "15 seed Sweet 16 wins: " << bracketTWO_fifteen << endl;
		cout << "16 seed Sweet 16 wins: " << bracketTWO_sixteen << endl << endl;
		
		cout << "1 seed Elite 8 wins: " << bracketTWO__one << endl;
		cout << "2 seed Elite 8 wins: " << bracketTWO__two << endl;
		cout << "3 seed Elite 8 wins: " << bracketTWO__three << endl;
		cout << "4 seed Elite 8 wins: " << bracketTWO__four << endl;
		cout << "5 seed Elite 8 wins: " << bracketTWO__five << endl;
		cout << "6 seed Elite 8 wins: " << bracketTWO__six << endl;
		cout << "7 seed Elite 8 wins: " << bracketTWO__seven << endl;
		cout << "8 seed Elite 8 wins: " << bracketTWO__eight << endl; 
		cout << "9 seed Elite 8 wins: " << bracketTWO__nine << endl;
		cout << "10 seed Elite 8 wins: " << bracketTWO__ten << endl;
		cout << "11 seed Elite 8 wins: " << bracketTWO__eleven << endl;
		cout << "12 seed Elite 8 wins: " << bracketTWO__twelve << endl;
		cout << "13 seed Elite 8 wins: " << bracketTWO__thirteen << endl;
		cout << "14 seed Elite 8 wins: " << bracketTWO__fourteen << endl;
		cout << "15 seed Elite 8 wins: " << bracketTWO__fifteen << endl;
		cout << "16 seed Elite 8 wins: " << bracketTWO__sixteen << endl;
		
		//
		//
		//
		//
		//
		//
		//
		//
		//
		
		cout << endl << endl << endl << endl;
		cout << "Bracket Three Results:" << endl;
		cout << "1 seed Round of 64 wins: " << bracketTHREEone << "\t vs. win percentage: " << bracketTHREEone/bracketTHREEgames <<	endl;
		cout << "2 seed Round of 64 wins: "  << bracketTHREEtwo << "\t vs. win percentage: " << bracketTHREEtwo/bracketTHREEgames << endl;
		cout << "3 seed Round of 64 wins: " << bracketTHREEthree << "\t vs. win percentage: " << bracketTHREEthree/bracketTHREEgames << endl;
		cout << "4 seed Round of 64 wins: " << bracketTHREEfour << "\t vs. win percentage: " << bracketTHREEfour/bracketTHREEgames << endl;
		cout << "5 seed Round of 64 wins: " << bracketTHREEfive << "\t vs. win percentage: " << bracketTHREEfive/bracketTHREEgames << endl;
		cout << "6 seed Round of 64 wins: " << bracketTHREEsix << "\t vs. win percentage: " << bracketTHREEsix/bracketTHREEgames << endl;
		cout << "7 seed Round of 64 wins: " << bracketTHREEseven << "\t vs. win percentage: " << bracketTHREEseven/bracketTHREEgames << endl;
		cout << "8 seed Round of 64 wins: " << bracketTHREEeight << "\t vs. win percentage: " << bracketTHREEeight/bracketTHREEgames << endl; 
		cout << "9 seed Round of 64 wins: " << bracketTHREEnine << "\t vs. win percentage: " << bracketTHREEnine/bracketTHREEgames << endl;
		cout << "10 seed Round of 64 wins: " << bracketTHREEten << "\t vs. win percentage: " << bracketTHREEten/bracketTHREEgames << endl;
		cout << "11 seed Round of 64 wins: " << bracketTHREEeleven << "\t vs. win percentage: " << bracketTHREEeleven/bracketTHREEgames << endl;
		cout << "12 seed Round of 64 wins: " << bracketTHREEtwelve << "\t vs. win percentage: " << bracketTHREEtwelve/bracketTHREEgames << endl;
		cout << "13 seed Round of 64 wins: " << bracketTHREEthirteen << "\t vs. win percentage: " << bracketTHREEthirteen/bracketTHREEgames << endl;
		cout << "14 seed Round of 64 wins: " << bracketTHREEfourteen << "\t vs. win percentage: " << bracketTHREEfourteen/bracketTHREEgames << endl;
		cout << "15 seed Round of 64 wins: " << bracketTHREEfifteen << "\t vs. win percentage: " << bracketTHREEfifteen/bracketTHREEgames << endl;
		cout << "16 seed Round of 64 wins: " << bracketTHREEsixteen << "\t vs. win percentage: " << bracketTHREEsixteen/bracketTHREEgames << endl << endl;
		
		cout << "1 seed Round of 32 wins: " << bracketTHREEone_ << endl;
		cout << "2 seed Round of 32 wins: " << bracketTHREEtwo_ << endl;
		cout << "3 seed Round of 32 wins: " << bracketTHREEthree_ << endl;
		cout << "4 seed Round of 32 wins: " << bracketTHREEfour_ << endl;
		cout << "5 seed Round of 32 wins: " << bracketTHREEfive_ << endl;
		cout << "6 seed Round of 32 wins: " << bracketTHREEsix_ << endl;
		cout << "7 seed Round of 32 wins: " << bracketTHREEseven_ << endl;
		cout << "8 seed Round of 32 wins: " << bracketTHREEeight_ << endl; 
		cout << "9 seed Round of 32 wins: " << bracketTHREEnine_ << endl;
		cout << "10 seed Round of 32 wins: " << bracketTHREEten_ << endl;
		cout << "11 seed Round of 32 wins: " << bracketTHREEeleven_ << endl;
		cout << "12 seed Round of 32 wins: " << bracketTHREEtwelve_ << endl;
		cout << "13 seed Round of 32 wins: " << bracketTHREEthirteen_ << endl;
		cout << "14 seed Round of 32 wins: " << bracketTHREEfourteen_ << endl;
		cout << "15 seed Round of 32 wins: " << bracketTHREEfifteen_ << endl;
		cout << "16 seed Round of 32 wins: " << bracketTHREEsixteen_ << endl << endl;
		
		cout << "1 seed Sweet 16 wins: " << bracketTHREE_one << endl;
		cout << "2 seed Sweet 16 wins: " << bracketTHREE_two << endl;
		cout << "3 seed Sweet 16 wins: " << bracketTHREE_three << endl;
		cout << "4 seed Sweet 16 wins: " << bracketTHREE_four << endl;
		cout << "5 seed Sweet 16 wins: " << bracketTHREE_five << endl;
		cout << "6 seed Sweet 16 wins: " << bracketTHREE_six << endl;
		cout << "7 seed Sweet 16 wins: " << bracketTHREE_seven << endl;
		cout << "8 seed Sweet 16 wins: " << bracketTHREE_eight << endl; 
		cout << "9 seed Sweet 16 wins: " << bracketTHREE_nine << endl;
		cout << "10 seed Sweet 16 wins: " << bracketTHREE_ten << endl;
		cout << "11 seed Sweet 16 wins: " << bracketTHREE_eleven << endl;
		cout << "12 seed Sweet 16 wins: " << bracketTHREE_twelve << endl;
		cout << "13 seed Sweet 16 wins: " << bracketTHREE_thirteen << endl;
		cout << "14 seed Sweet 16 wins: " << bracketTHREE_fourteen << endl;
		cout << "15 seed Sweet 16 wins: " << bracketTHREE_fifteen << endl;
		cout << "16 seed Sweet 16 wins: " << bracketTHREE_sixteen << endl << endl;
		
		cout << "1 seed Elite 8 wins: " << bracketTHREE__one << endl;
		cout << "2 seed Elite 8 wins: " << bracketTHREE__two << endl;
		cout << "3 seed Elite 8 wins: " << bracketTHREE__three << endl;
		cout << "4 seed Elite 8 wins: " << bracketTHREE__four << endl;
		cout << "5 seed Elite 8 wins: " << bracketTHREE__five << endl;
		cout << "6 seed Elite 8 wins: " << bracketTHREE__six << endl;
		cout << "7 seed Elite 8 wins: " << bracketTHREE__seven << endl;
		cout << "8 seed Elite 8 wins: " << bracketTHREE__eight << endl; 
		cout << "9 seed Elite 8 wins: " << bracketTHREE__nine << endl;
		cout << "10 seed Elite 8 wins: " << bracketTHREE__ten << endl;
		cout << "11 seed Elite 8 wins: " << bracketTHREE__eleven << endl;
		cout << "12 seed Elite 8 wins: " << bracketTHREE__twelve << endl;
		cout << "13 seed Elite 8 wins: " << bracketTHREE__thirteen << endl;
		cout << "14 seed Elite 8 wins: " << bracketTHREE__fourteen << endl;
		cout << "15 seed Elite 8 wins: " << bracketTHREE__fifteen << endl;
		cout << "16 seed Elite 8 wins: " << bracketTHREE__sixteen << endl;
		
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		
		
		cout << endl << endl << endl << endl;
		cout << "Bracket Four Results:" << endl;
		cout << "1 seed Round of 64 wins: " << bracketFOURone << "\t vs. win percentage: " << bracketFOURone/bracketFOURgames <<	endl;
		cout << "2 seed Round of 64 wins: "  << bracketFOURtwo << "\t vs. win percentage: " << bracketFOURtwo/bracketFOURgames << endl;
		cout << "3 seed Round of 64 wins: " << bracketFOURthree << "\t vs. win percentage: " << bracketFOURthree/bracketFOURgames << endl;
		cout << "4 seed Round of 64 wins: " << bracketFOURfour << "\t vs. win percentage: " << bracketFOURfour/bracketFOURgames << endl;
		cout << "5 seed Round of 64 wins: " << bracketFOURfive << "\t vs. win percentage: " << bracketFOURfive/bracketFOURgames << endl;
		cout << "6 seed Round of 64 wins: " << bracketFOURsix << "\t vs. win percentage: " << bracketFOURsix/bracketFOURgames << endl;
		cout << "7 seed Round of 64 wins: " << bracketFOURseven << "\t vs. win percentage: " << bracketFOURseven/bracketFOURgames << endl;
		cout << "8 seed Round of 64 wins: " << bracketFOUReight << "\t vs. win percentage: " << bracketFOUReight/bracketFOURgames << endl; 
		cout << "9 seed Round of 64 wins: " << bracketFOURnine << "\t vs. win percentage: " << bracketFOURnine/bracketFOURgames << endl;
		cout << "10 seed Round of 64 wins: " << bracketFOURten << "\t vs. win percentage: " << bracketFOURten/bracketFOURgames << endl;
		cout << "11 seed Round of 64 wins: " << bracketFOUReleven << "\t vs. win percentage: " << bracketFOUReleven/bracketFOURgames << endl;
		cout << "12 seed Round of 64 wins: " << bracketFOURtwelve << "\t vs. win percentage: " << bracketFOURtwelve/bracketFOURgames << endl;
		cout << "13 seed Round of 64 wins: " << bracketFOURthirteen << "\t vs. win percentage: " << bracketFOURthirteen/bracketFOURgames << endl;
		cout << "14 seed Round of 64 wins: " << bracketFOURfourteen << "\t vs. win percentage: " << bracketFOURfourteen/bracketFOURgames << endl;
		cout << "15 seed Round of 64 wins: " << bracketFOURfifteen << "\t vs. win percentage: " << bracketFOURfifteen/bracketFOURgames << endl;
		cout << "16 seed Round of 64 wins: " << bracketFOURsixteen << "\t vs. win percentage: " << bracketFOURsixteen/bracketFOURgames << endl << endl;
		
		cout << "1 seed Round of 32 wins: " << bracketFOURone_ << endl;
		cout << "2 seed Round of 32 wins: " << bracketFOURtwo_ << endl;
		cout << "3 seed Round of 32 wins: " << bracketFOURthree_ << endl;
		cout << "4 seed Round of 32 wins: " << bracketFOURfour_ << endl;
		cout << "5 seed Round of 32 wins: " << bracketFOURfive_ << endl;
		cout << "6 seed Round of 32 wins: " << bracketFOURsix_ << endl;
		cout << "7 seed Round of 32 wins: " << bracketFOURseven_ << endl;
		cout << "8 seed Round of 32 wins: " << bracketFOUReight_ << endl; 
		cout << "9 seed Round of 32 wins: " << bracketFOURnine_ << endl;
		cout << "10 seed Round of 32 wins: " << bracketFOURten_ << endl;
		cout << "11 seed Round of 32 wins: " << bracketFOUReleven_ << endl;
		cout << "12 seed Round of 32 wins: " << bracketFOURtwelve_ << endl;
		cout << "13 seed Round of 32 wins: " << bracketFOURthirteen_ << endl;
		cout << "14 seed Round of 32 wins: " << bracketFOURfourteen_ << endl;
		cout << "15 seed Round of 32 wins: " << bracketFOURfifteen_ << endl;
		cout << "16 seed Round of 32 wins: " << bracketFOURsixteen_ << endl << endl;
		
		cout << "1 seed Sweet 16 wins: " << bracketFOUR_one << endl;
		cout << "2 seed Sweet 16 wins: " << bracketFOUR_two << endl;
		cout << "3 seed Sweet 16 wins: " << bracketFOUR_three << endl;
		cout << "4 seed Sweet 16 wins: " << bracketFOUR_four << endl;
		cout << "5 seed Sweet 16 wins: " << bracketFOUR_five << endl;
		cout << "6 seed Sweet 16 wins: " << bracketFOUR_six << endl;
		cout << "7 seed Sweet 16 wins: " << bracketFOUR_seven << endl;
		cout << "8 seed Sweet 16 wins: " << bracketFOUR_eight << endl; 
		cout << "9 seed Sweet 16 wins: " << bracketFOUR_nine << endl;
		cout << "10 seed Sweet 16 wins: " << bracketFOUR_ten << endl;
		cout << "11 seed Sweet 16 wins: " << bracketFOUR_eleven << endl;
		cout << "12 seed Sweet 16 wins: " << bracketFOUR_twelve << endl;
		cout << "13 seed Sweet 16 wins: " << bracketFOUR_thirteen << endl;
		cout << "14 seed Sweet 16 wins: " << bracketFOUR_fourteen << endl;
		cout << "15 seed Sweet 16 wins: " << bracketFOUR_fifteen << endl;
		cout << "16 seed Sweet 16 wins: " << bracketFOUR_sixteen << endl << endl;
		
		cout << "1 seed Elite 8 wins: " << bracketFOUR__one << endl;
		cout << "2 seed Elite 8 wins: " << bracketFOUR__two << endl;
		cout << "3 seed Elite 8 wins: " << bracketFOUR__three << endl;
		cout << "4 seed Elite 8 wins: " << bracketFOUR__four << endl;
		cout << "5 seed Elite 8 wins: " << bracketFOUR__five << endl;
		cout << "6 seed Elite 8 wins: " << bracketFOUR__six << endl;
		cout << "7 seed Elite 8 wins: " << bracketFOUR__seven << endl;
		cout << "8 seed Elite 8 wins: " << bracketFOUR__eight << endl; 
		cout << "9 seed Elite 8 wins: " << bracketFOUR__nine << endl;
		cout << "10 seed Elite 8 wins: " << bracketFOUR__ten << endl;
		cout << "11 seed Elite 8 wins: " << bracketFOUR__eleven << endl;
		cout << "12 seed Elite 8 wins: " << bracketFOUR__twelve << endl;
		cout << "13 seed Elite 8 wins: " << bracketFOUR__thirteen << endl;
		cout << "14 seed Elite 8 wins: " << bracketFOUR__fourteen << endl;
		cout << "15 seed Elite 8 wins: " << bracketFOUR__fifteen << endl;
		cout << "16 seed Elite 8 wins: " << bracketFOUR__sixteen << endl;
		
		
		
		Final4();
		Championship();
		
		
		for (int i = 0; i < 2; i++)
		{
			if (championship_advancing[i] == 0) 
				final4_one++;
			
			if (championship_advancing[i] == 15)
				final4_sixteen++;
			
			if (championship_advancing[i] == 7)
				final4_eight++;
			
			if (championship_advancing[i] == 8)
				final4_nine++;
			
			if (championship_advancing[i] == 4)
				final4_five++;
			
			if (championship_advancing[i] == 11)
				final4_twelve++;
			
			if (championship_advancing[i] == 3)
				final4_four++;
			
			if (championship_advancing[i] == 12)
				final4_thirteen++;
			
			if (championship_advancing[i] == 10)
				final4_eleven++;
				
			if (championship_advancing[i] == 2)
				final4_three++;
				
			if (championship_advancing[i] == 13)
				final4_fourteen++;
				
			if (championship_advancing[i] == 6)
				final4_seven++;
				
			if (championship_advancing[i] == 9)
				final4_ten++;
				
			if (championship_advancing[i] == 1)
				final4_two++;
				
			if (championship_advancing[i] == 14)
				final4_fifteen++;
			
			if (championship_advancing[i] == 5)
				final4_six++;
		}
		
		
		
		// TALLYING THE ELITE 8 WINS
		if (champion[0] == 0) 
			champion_one++;
		
		if (champion[0] == 1)
			champion_two++;
		
		if (champion[0] == 2)
			champion_three++;
		
		if (champion[0] == 3)
			champion_four++;
		
		if (champion[0] == 4)
			champion_five++;
		
		if (champion[0] == 5)
			champion_six++;
		
		if (champion[0] == 6)
			champion_seven++;
		
		if (champion[0] == 7)
			champion_eight++;
		
		if (champion[0] == 8)
			champion_nine++;
			
		if (champion[0] == 9)
			champion_ten++;
			
		if (champion[0] == 10)
			champion_eleven++;
			
		if (champion[0] == 11)
			champion_twelve++;
			
		if (champion[0] == 12)
			champion_thirteen++;
			
		if (champion[0] == 13)
			champion_fourteen++;
		
		if (champion[0] == 14)
			champion_fifteen++;
			
		if (champion[0] == 15)
			champion_sixteen++;
	}
	
	cout << endl << endl << endl;
	cout << "1 seed Final 4 wins: " << final4_one << endl;
	cout << "2 seed Final 4 wins: " << final4_two << endl;
	cout << "3 seed Final 4 wins: " << final4_three << endl;
	cout << "4 seed Final 4 wins: " << final4_four << endl;
	cout << "5 seed Final 4 wins: " << final4_five << endl;
	cout << "6 seed Final 4 wins: " << final4_six << endl;
	cout << "7 seed Final 4 wins: " << final4_seven << endl;
	cout << "8 seed Final 4 wins: " << final4_eight << endl; 
	cout << "9 seed Final 4 wins: " << final4_nine << endl;
	cout << "10 seed Final 4 wins: " << final4_ten << endl;
	cout << "11 seed Final 4 wins: " << final4_eleven << endl;
	cout << "12 seed Final 4 wins: " << final4_twelve << endl;
	cout << "13 seed Final 4 wins: " << final4_thirteen << endl;
	cout << "14 seed Final 4 wins: " << final4_fourteen << endl;
	cout << "15 seed Final 4 wins: " << final4_fifteen << endl;
	cout << "16 seed Final 4 wins: " << final4_sixteen << endl;
	
	cout << endl << endl << endl;
	cout << "1 seed Championship wins: " << champion_one << endl;
	cout << "2 seed Championship wins: " << champion_two << endl;
	cout << "3 seed Championship wins: " << champion_three << endl;
	cout << "4 seed Championship wins: " << champion_four << endl;
	cout << "5 seed Championship wins: " << champion_five << endl;
	cout << "6 seed Championship wins: " << champion_six << endl;
	cout << "7 seed Championship wins: " << champion_seven << endl;
	cout << "8 seed Championship wins: " << champion_eight << endl; 
	cout << "9 seed Championship wins: " << champion_nine << endl;
	cout << "10 seed Championship wins: " << champion_ten << endl;
	cout << "11 seed Championship wins: " << champion_eleven << endl;
	cout << "12 seed Championship wins: " << champion_twelve << endl;
	cout << "13 seed Championship wins: " << champion_thirteen << endl;
	cout << "14 seed Championship wins: " << champion_fourteen << endl;
	cout << "15 seed Championship wins: " << champion_fifteen << endl;
	cout << "16 seed Championship wins: " << champion_sixteen << endl;
	
	
	cout << endl << endl << "using widening = 1.0/2.75 so sig is from -1.09... to 1.09..." << endl;
	
	sig_average = sig_total / total_games_with_sig;
	
	cout << endl << endl << "total_games_with_sig = " << total_games_with_sig << endl << endl;
	
	cout << endl << endl << "sig_total using absolute value of sig values = " << sig_total << endl << endl;
	
	cout << endl << endl << "sig absolute value average for each RoundOf32(), Sweet16(), Elite8(), Final4(), and Championship() game = " << sig_average << endl << endl;
	
	
	double number;
	double percentages[63];
	
	for (int i = 0; i < 63; i++)
	{
		number = rand();
		percentages[i] = number/RAND_MAX;
	}
	/*
	cout << endl << endl << "BRACKET ONE" << endl;
	
	cout << "ROUND OF 64" << endl;
	cout << "Game 1: " << percentages[0] << endl;
	cout << "Game 2: " << percentages[1]  << endl;
	cout << "Game 3: " << percentages[2] << endl;
	cout << "Game 4: " << percentages[3] << endl;
	cout << "Game 5: " << percentages[4] << endl;
	cout << "Game 6: " << percentages[5] << endl;
	cout << "Game 7: " << percentages[6] << endl;
	cout << "Game 8: " << percentages[7] << endl;
	
	cout << "ROUND OF 32" << endl;
	cout << "Game 9: " << percentages[8] << endl;
	cout << "Game 10: " << percentages[9] << endl;
	cout << "Game 11: " << percentages[10] << endl;
	cout << "Game 12: " << percentages[11] << endl;
	
	cout << "SWEET 16" << endl;
	cout << "Game 13: " << percentages[12] << endl;
	cout << "Game 14: " << percentages[13] << endl;
	
	cout << "ELITE 8" << endl;
	cout << "Game 15: " << percentages[14] << endl;

	
	cout << endl << endl << "BRACKET TWO" << endl;
	
	cout << "ROUND OF 64" << endl;
	cout << "Game 1: " << percentages[15] << endl;
	cout << "Game 2: " << percentages[16] << endl;
	cout << "Game 3: " << percentages[17] << endl;
	cout << "Game 4: " << percentages[18] << endl;
	cout << "Game 5: " << percentages[19] << endl;
	cout << "Game 6: " << percentages[20] << endl;
	cout << "Game 7: " << percentages[21] << endl;
	cout << "Game 8: " << percentages[22] << endl;
	
	cout << "ROUND OF 32" << endl;
	cout << "Game 9: " << percentages[23] << endl;
	cout << "Game 10: " << percentages[24] << endl;
	cout << "Game 11: " << percentages[25] << endl;
	cout << "Game 12: " << percentages[26] << endl;
	
	cout << "SWEET 16" << endl;
	cout << "Game 13: " << percentages[27] << endl;
	cout << "Game 14: " << percentages[28] << endl;
	
	cout << "ELITE 8" << endl;
	cout << "Game 15: " << percentages[29] << endl;
	
	
	
	cout << endl << endl << "BRACKET THREE" << endl;
	
	cout << "ROUND OF 64" << endl;
	cout << "Game 1: " << percentages[30] << endl;
	cout << "Game 2: " << percentages[31] << endl;
	cout << "Game 3: " << percentages[32] << endl;
	cout << "Game 4: " << percentages[33] << endl;
	cout << "Game 5: " << percentages[34] << endl;
	cout << "Game 6: " << percentages[35] << endl;
	cout << "Game 7: " << percentages[36] << endl;
	cout << "Game 8: " << percentages[37] << endl;
	
	cout << "ROUND OF 32" << endl;
	cout << "Game 9: " << percentages[38] << endl;
	cout << "Game 10: " << percentages[39] << endl;
	cout << "Game 11: " << percentages[40] << endl;
	cout << "Game 12: " << percentages[41] << endl;
	
	cout << "SWEET 16" << endl;
	cout << "Game 13: " << percentages[42] << endl;
	cout << "Game 14: " << percentages[43] << endl;
	
	cout << "ELITE 8" << endl;
	cout << "Game 15: " << percentages[44] << endl;
	
	
	
	
	cout << endl << endl << "BRACKET FOUR" << endl;
	
	cout << "ROUND OF 64" << endl;
	cout << "Game 1: " << percentages[45] << endl;
	cout << "Game 2: " << percentages[46] << endl;
	cout << "Game 3: " << percentages[47] << endl;
	cout << "Game 4: " << percentages[48] << endl;
	cout << "Game 5: " << percentages[49] << endl;
	cout << "Game 6: " << percentages[50] << endl;
	cout << "Game 7: " << percentages[51] << endl;
	cout << "Game 8: " << percentages[52] << endl;
	
	cout << "ROUND OF 32" << endl;
	cout << "Game 9: " << percentages[53] << endl;
	cout << "Game 10: " << percentages[54] << endl;
	cout << "Game 11: " << percentages[55] << endl;
	cout << "Game 12: " << percentages[56] << endl;
	
	cout << "SWEET 16" << endl;
	cout << "Game 13: " << percentages[57] << endl;
	cout << "Game 14: " << percentages[58] << endl;
	
	cout << "ELITE 8" << endl;
	cout << "Game 15: " << percentages[59] << endl;
	
	
	
	
	cout << "FINAL 4" << endl;
	cout << "Game 61: " << percentages[60] << endl;
	cout << "Game 62: " << percentages[61] << endl;
	
	
	
	cout << "TITLE GAME" << endl;
	cout << "Game 63: " << percentages[62] << endl;
	
	*/
	//cout << "contents of vector: " << endl;
	
	//for (int i = 0; i < sig_vals.size(); i++)
	//	cout << "i: " << i + 1 << " " << sig_vals[i] << endl;
}

// To pick out the specific elements of the array based on the matchups:
// EXAMPLE:
// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
// [1, 2, 3, 4, 12, 6, 10, 9]
// [1, 2, 6, 4]
// [1, 6]
// [1]
// The team at the beginning of the array plays the team at the end; then play the next team in front vs. the previous team in back, and so on

void oneRoundOf64()
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
		cout << "Bracket One" << endl;
		
		if (matchups[i][j] > chance)                             // EXAMPLE OF HOW THIS PROCESS WOULD WORK:
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
		onesecond_advancing[i] = advancing[i];
		cout << onesecond_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl;
	
	sleep(1);
}

void oneRoundOf32() // takes in the array called advancing and sorts through the elements based on the teams remaining
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
		total_games_with_sig++;
		sig_total += abs(sig);
		//sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[onesecond_advancing[i]][onesecond_advancing[j]] > chance)
		{
			advancing[advancing_index] = onesecond_advancing[i];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;	
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[onesecond_advancing[i]][onesecond_advancing[j]] << endl;
		}
		
		else
		{
			advancing[advancing_index] = onesecond_advancing[j];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[onesecond_advancing[i]][onesecond_advancing[j]] << endl;
		}
			
		i++;
		j--;
	}
	
	for (int i = 0; i < 4; i++)
	{
		onesweet_advancing[i] = advancing[i];
		cout << onesweet_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}

void oneSweet16()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[onesweet_advancing[i]][onesweet_advancing[j]] == 0 && matchups[onesweet_advancing[j]][onesweet_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (onesweet_advancing[j] + 1); // numerator 14 
			two = (onesweet_advancing[j] + 1 + onesweet_advancing[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data > chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = onesweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = onesweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[onesweet_advancing[i]][onesweet_advancing[j]] > chance)
			{
				advancing[advancing_index] = onesweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[onesweet_advancing[i]][onesweet_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = onesweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[onesweet_advancing[i]][onesweet_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 2; i++)
	{
		oneelite_advancing[i] = advancing[i];
		cout << oneelite_advancing[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);
}


void oneElite8()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		if (matchups[oneelite_advancing[i]][oneelite_advancing[j]] == 0 && matchups[oneelite_advancing[j]][oneelite_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Elite 8 have never won in the Elite 8 before
		{
			cout << endl;
			one = (oneelite_advancing[j] + 1);
			two = (oneelite_advancing[j] + 1 + oneelite_advancing[i] + 1);
			data = one/two;
			
			if (data > chance)
			{
				advancing[advancing_index] = oneelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		
			else
			{
				advancing[advancing_index] = oneelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		}
		
		
		else
		{
			if (matchups[oneelite_advancing[i]][oneelite_advancing[j]] > chance)
			{
				advancing[advancing_index] = oneelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[oneelite_advancing[i]][oneelite_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = oneelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[oneelite_advancing[i]][oneelite_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 1; i++)
	{
		onefour_advancing[i] = advancing[i];
		final_four[0] = advancing[i];
		cout << onefour_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}

















































void twoRoundOf64()
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
		cout << "Bracket Two" << endl;
		
		if (matchups[i][j] > chance)                             // EXAMPLE OF HOW THIS PROCESS WOULD WORK:
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
		twosecond_advancing[i] = advancing[i];
		cout << twosecond_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl;
	
	sleep(1);
}

void twoRoundOf32() // takes in the array called advancing and sorts through the elements based on the teams remaining
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		if (matchups[twosecond_advancing[i]][twosecond_advancing[j]] > chance)
		{
			advancing[advancing_index] = twosecond_advancing[i];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;	
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[twosecond_advancing[i]][twosecond_advancing[j]] << endl;
		}
		
		else
		{
			advancing[advancing_index] = twosecond_advancing[j];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[twosecond_advancing[i]][twosecond_advancing[j]] << endl;
		}
			
		i++;
		j--;
	}
	
	for (int i = 0; i < 4; i++)
	{
		twosweet_advancing[i] = advancing[i];
		cout << twosweet_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}

void twoSweet16()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[twosweet_advancing[i]][twosweet_advancing[j]] == 0 && matchups[twosweet_advancing[j]][twosweet_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (twosweet_advancing[j] + 1); // numerator 14 
			two = (twosweet_advancing[j] + 1 + twosweet_advancing[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data > chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = twosweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = twosweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[twosweet_advancing[i]][twosweet_advancing[j]] > chance)
			{
				advancing[advancing_index] = twosweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[twosweet_advancing[i]][twosweet_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = twosweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[twosweet_advancing[i]][twosweet_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 2; i++)
	{
		twoelite_advancing[i] = advancing[i];
		cout << twoelite_advancing[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);
}


void twoElite8()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		if (matchups[twoelite_advancing[i]][twoelite_advancing[j]] == 0 && matchups[twoelite_advancing[j]][twoelite_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Elite 8 have never won in the Elite 8 before
		{
			cout << endl;
			one = (twoelite_advancing[j] + 1);
			two = (twoelite_advancing[j] + 1 + twoelite_advancing[i] + 1);
			data = one/two;
			
			if (data > chance)
			{
				advancing[advancing_index] = twoelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		
			else
			{
				advancing[advancing_index] = twoelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		}
		
		
		else
		{
			if (matchups[twoelite_advancing[i]][twoelite_advancing[j]] > chance)
			{
				advancing[advancing_index] = twoelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[twoelite_advancing[i]][twoelite_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = twoelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[twoelite_advancing[i]][twoelite_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 1; i++)
	{
		twofour_advancing[i] = advancing[i];
		final_four[1] = advancing[i];
		cout << twofour_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}




























































void threeRoundOf64()
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
		cout << "Bracket Three" << endl;
		
		if (matchups[i][j] > chance)                             // EXAMPLE OF HOW THIS PROCESS WOULD WORK:
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
		threesecond_advancing[i] = advancing[i];
		cout << threesecond_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl;
	
	sleep(1);
}

void threeRoundOf32() // takes in the array called advancing and sorts through the elements based on the teams remaining
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		if (matchups[threesecond_advancing[i]][threesecond_advancing[j]] > chance)
		{
			advancing[advancing_index] = threesecond_advancing[i];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;	
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[threesecond_advancing[i]][threesecond_advancing[j]] << endl;
		}
		
		else
		{
			advancing[advancing_index] = threesecond_advancing[j];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[threesecond_advancing[i]][threesecond_advancing[j]] << endl;
		}
			
		i++;
		j--;
	}
	
	for (int i = 0; i < 4; i++)
	{
		threesweet_advancing[i] = advancing[i];
		cout << threesweet_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}

void threeSweet16()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[threesweet_advancing[i]][threesweet_advancing[j]] == 0 && matchups[threesweet_advancing[j]][threesweet_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (threesweet_advancing[j] + 1); // numerator 14 
			two = (threesweet_advancing[j] + 1 + threesweet_advancing[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data > chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = threesweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = threesweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[threesweet_advancing[i]][threesweet_advancing[j]] > chance)
			{
				advancing[advancing_index] = threesweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[threesweet_advancing[i]][threesweet_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = threesweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[threesweet_advancing[i]][threesweet_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 2; i++)
	{
		threeelite_advancing[i] = advancing[i];
		cout << threeelite_advancing[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);
}


void threeElite8()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		if (matchups[threeelite_advancing[i]][threeelite_advancing[j]] == 0 && matchups[threeelite_advancing[j]][threeelite_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Elite 8 have never won in the Elite 8 before
		{
			cout << endl;
			one = (threeelite_advancing[j] + 1);
			two = (threeelite_advancing[j] + 1 + threeelite_advancing[i] + 1);
			data = one/two;
			
			if (data > chance)
			{
				advancing[advancing_index] = threeelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		
			else
			{
				advancing[advancing_index] = threeelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		}
		
		
		else
		{
			if (matchups[threeelite_advancing[i]][threeelite_advancing[j]] > chance)
			{
				advancing[advancing_index] = threeelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[threeelite_advancing[i]][threeelite_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = threeelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[threeelite_advancing[i]][threeelite_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 1; i++)
	{
		threefour_advancing[i] = advancing[i];
		final_four[2] = advancing[i];
		cout << threefour_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}




































































void fourRoundOf64()
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
		cout << "Bracket Four" << endl;
		
		if (matchups[i][j] > chance)                             // EXAMPLE OF HOW THIS PROCESS WOULD WORK:
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
		foursecond_advancing[i] = advancing[i];
		cout << foursecond_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl;
	
	sleep(1);
}

void fourRoundOf32() // takes in the array called advancing and sorts through the elements based on the teams remaining
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		if (matchups[foursecond_advancing[i]][foursecond_advancing[j]] > chance)
		{
			advancing[advancing_index] = foursecond_advancing[i];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;	
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[foursecond_advancing[i]][foursecond_advancing[j]] << endl;
		}
		
		else
		{
			advancing[advancing_index] = foursecond_advancing[j];
			cout << "seed: " << advancing[advancing_index] + 1 << endl;
			cout << "chance that decided who won last round: " << chance << endl;
			advancing_index++;
			cout << "matchup proportion: " << matchups[foursecond_advancing[i]][foursecond_advancing[j]] << endl;
		}
			
		i++;
		j--;
	}
	
	for (int i = 0; i < 4; i++)
	{
		foursweet_advancing[i] = advancing[i];
		cout << foursweet_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}

void fourSweet16()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[foursweet_advancing[i]][foursweet_advancing[j]] == 0 && matchups[foursweet_advancing[j]][foursweet_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (foursweet_advancing[j] + 1); // numerator 14 
			two = (foursweet_advancing[j] + 1 + foursweet_advancing[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data > chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = foursweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = foursweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[foursweet_advancing[i]][foursweet_advancing[j]] > chance)
			{
				advancing[advancing_index] = foursweet_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[foursweet_advancing[i]][foursweet_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = foursweet_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[foursweet_advancing[i]][foursweet_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 2; i++)
	{
		fourelite_advancing[i] = advancing[i];
		cout << fourelite_advancing[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);
}


void fourElite8()
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		if (matchups[fourelite_advancing[i]][fourelite_advancing[j]] == 0 && matchups[fourelite_advancing[j]][fourelite_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Elite 8 have never won in the Elite 8 before
		{
			cout << endl;
			one = (fourelite_advancing[j] + 1);
			two = (fourelite_advancing[j] + 1 + fourelite_advancing[i] + 1);
			data = one/two;
			
			if (data > chance)
			{
				advancing[advancing_index] = fourelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		
			else
			{
				advancing[advancing_index] = fourelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << "\n\n";
			}
		}
		
		
		else
		{
			if (matchups[fourelite_advancing[i]][fourelite_advancing[j]] > chance)
			{
				advancing[advancing_index] = fourelite_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[fourelite_advancing[i]][fourelite_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = fourelite_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[fourelite_advancing[i]][fourelite_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 1; i++)
	{
		fourfour_advancing[i] = advancing[i];
		final_four[3] = advancing[i];
		cout << fourfour_advancing[i] + 1 << " ";
	}
	
	cout << endl << endl << endl;
	
	sleep(1);
}





















void Final4()
{
	cout << "\n\n\n\n";
	cout << "************************ FINAL FOUR ***************************" << endl;
	
	srand(time(0));
	
	ifstream inFile("J10Final4.dat");
	
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

	cout << final_four[0] + 1 << " vs. " << final_four[3] + 1<< endl;
	cout << final_four[1] + 1 << " vs. " << final_four[2] + 1<< endl;
	
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[final_four[i]][final_four[j]] == 0 && matchups[final_four[j]][final_four[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (final_four[j] + 1); // numerator 14 
			two = (final_four[j] + 1 + final_four[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data > chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = final_four[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = final_four[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[final_four[i]][final_four[j]] > chance)
			{
				advancing[advancing_index] = final_four[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[final_four[i]][final_four[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = final_four[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[final_four[i]][final_four[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 2; i++)
	{
		championship_advancing[i] = advancing[i];
		cout << championship_advancing[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);	

}









































void Championship()
{
	cout << "\n\n\n\n";
	
	cout << "************************ CHAMPIONSHIP ***************************" << endl;
	
	srand(time(0));
	
	ifstream inFile("J10Championship.dat");
	
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
		total_games_with_sig++;
		sig_total += abs(sig);
		sig_vals.push_back(sig);
		
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
		
		
		
		if (matchups[championship_advancing[i]][championship_advancing[j]] == 0 && matchups[championship_advancing[j]][championship_advancing[i]] != 1) // special situation we could encounter if 2 teams who advance to the Sweet 16 have never won in the Sweet 16 before
		{                         // 15               // 14                              // 14               // 15
			cout << endl;
			one = (championship_advancing[j] + 1); // numerator 14 
			two = (championship_advancing[j] + 1 + championship_advancing[i] + 1); // denominator; 14 + 15 = 29
			data = one/two; // 14/29 = .48...
			
			
			cout << "one: " << one << endl;
			cout << "two: " << two << endl;
			cout << "data: " << data << endl;
			
			if (data > chance) // if .48 > random # then the team advancing to the Sweet 16 is 15
			{
				advancing[advancing_index] = championship_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		
			else
			{
				advancing[advancing_index] = championship_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << data << endl;
			}
		}
		
		
		else
		{
			if (matchups[championship_advancing[i]][championship_advancing[j]] > chance)
			{
				advancing[advancing_index] = championship_advancing[i];
				cout << "seed: " << advancing[advancing_index] + 1 << endl;	
				cout << "chance that decided who won last round: " << chance << endl;
				advancing_index++;
				cout << "matchup proportion: " << matchups[championship_advancing[i]][championship_advancing[j]] << endl;
			}
		
			else
			{
				advancing[advancing_index] = championship_advancing[j];   
				cout << "seed: " << advancing[advancing_index] + 1 << endl;  
				cout << "chance that decided who won last round: " << chance << endl;								  
				advancing_index++;
				cout << "matchup proportion: " << matchups[championship_advancing[i]][championship_advancing[j]] << endl;
			}
		}
		
		i++;
		j--;
	}
	
	for (int i = 0; i < 1; i++)
	{
		champion[i] = advancing[i];
		cout << champion[i] + 1 << " ";
	}	
	
	cout << endl << endl << endl;
	
	sleep(1);	
}