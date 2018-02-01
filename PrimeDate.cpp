#include <iostream>
#include <fstream>
//Right, i want to make a simple program to find out if a number is prime.
//it's a good start. check back later for more. oh.. and dont forget to save!!!!
using namespace std;

int prime(int n){
int j;
        for (j=2; j<=n/2; j++){ //this will do the dividing, starting at 2 and ending at half of i, because everything is divisible by 1.
        if (n%j==0){ // whats the remainder of i/j? if there is no remainder than it divides evenly
        	return 0;
            }
        if (j==n/2){ // if it makes it here it's prime
        	return 1;
            }

        }
    	//if it makes it here it's not prime
		return 0;
}
int rev(int num){
        int r,rr;
        rr=0;
        while( num!=0){
                r = num%10;
                rr = rr*10+r;
                num /= 10;
        }
        return rr;
}

int main()
{
	ofstream primelist;
	primelist.open("primelist.txt") ;
    int y,m,d,n,o,c,b, max, maxday; //Year, Month, Day, Number, Option, Counting total prime, B comes before C, max primes on a day, day of max primes
    c=0;
    max=0;
    maxday=0;
    cout << "Gonna find some PRIMES! give a two digt year" << endl;
    cin >> y;
	
	primelist<< "Start Date,Subject,All Day Event\n"; //header line for importing to google calendar
	
    for (m=1; m<13; m++){ //12 months
        for (d=1; d<32; d++){ //every month has 31 days... gonna be a problem, but maybe google calednar will ignore the errors? if not i'll have to check it for realsies
			   // google calendar just puts, feb 31 onto march 3... so i guess i have to do my own check.
			   // feb 28 or 29... leap year
			   // 30 days are in april, june, sept, nov
			   if (m==2&&d==30) {// good but not getting leap years... thats fine it's not a really big deal pluss what a great conversation starter "you know if today were feb 29th it would be prime, but because it's not a leap year its just a normal day, sad huh?"
			   	cout<< "feb never has 30 days\n";
				   break;
			    }
			   if (m==4&&d==31) {
			   	cout<< "april only has 30 days\n";
				   break;
			    }
			    if (m==6&&d==31) {
			   	cout<< "june only has 30 days\n";
				   break;
			    }
			    if (m==9&&d==31) {
			   	cout<< "sept only has 30 days\n";
				   break;
			    }
			    if (m==11&&d==31) {
			   	cout<< "november only has 30 days\n";
				   break;
			    }
			    b=c; //counting the total primes
               
			   	n=d*10000+m*100+y; // ok, so set the type of date to n, 
                if (prime(n)){ // check if n is prime, prime function sends 1 for yes and 0 for nope and nothing else happens there. 
                	cout << n << " "; 
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " dmy" << "," << "true\n"; //this is for google calendars csv style format
				}
				n=d*10000+y*100+m;
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " dym" << "," << "true\n"; //should look like "2/12/18,121802 dym,true" but with a prime number of course
				}
				n=m*10000+d*100+y;
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " mdy" << "," << "true\n";
				}
				n=m*10000+y*100+d;
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " myd" << "," << "true\n";
				}
				n=y*10000+d*100+m;
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " ydm" << "," << "true\n";
				}
				n=y*10000+m*100+d;
				if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " ymd" << "," << "true\n";
				}
				
                n=rev(d*10000+m*100+y);
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " Rdmy" << "," << "true\n";
				}
                n=rev(d*10000+y*100+m);
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " Rdym" << "," << "true\n";
				}
                n=rev(m*10000+d*100+y);
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " Rmdy" << "," << "true\n";
				}
                n=rev(m*10000+y*100+d);
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " Rmyd" << "," << "true\n";
				}
                n=rev(y*10000+d*100+m);
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " Rydm" << "," << "true\n";
				}
                n=rev(y*10000+m*100+d);
                if (prime(n)){
                	cout << n << " ";
                	c++;
                	primelist<< m << "/" << d << "/" << y << "," << n << " Rymd" << "," << "true\n"; 
				}

                if (b<c) { //there was  prime on this day
                	if(max<c-b){
                		max =c-b;
                		maxday= m*10000+d*100+y; // not really useing this in the file, but it's cute in the cmd promt
					}
                	
                cout << endl;
                }
           }
    }


cout << endl << c << " total primes"<< endl << max << " ammount of primes on "<< maxday<<endl;

primelist.close();

   return 0;
}
