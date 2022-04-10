/* The Hot-Cold Game, number prediction program. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 


void printHeader( void ); /* function prototype */

/* function main begins program execution */
int main()
{
   int predictions[ 20 ];  /* create array of 20 int elements */
   const char ordinary[10][10] = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth" }; /* initialize array for ordinary */
   const char accuracy[3][10] = { "Bingo!", "True", "False" }; /* initialize array for accuracy */
	const char clue[3][10] = { "HOT!", "COLD!", "STABLE!" }; /* initialize array for clue */
	int number; /* define randomly selected number value by the computer */
   int guess; /* define guess value to be read from user */
   int i; /* define loop counter1 */
   int j; /* define loop counter2 */
  	int k; /* define loop counter3 */
  	int m; /* define loop counter4 */
	int a; /* define variable1 */
  	int b; /* define variable2 */
  	
  	
   for( i = 0; i <= 30; ++i ){ /* initialization of the the control value as 0, identification of loop continuation condition and increment of control variable by 1 */ 
   		
   	if ( i != 15 ){ /* if counter1(i) is not equals to 15 */
		printf( "*" ); /* display the message */
	   } /* end if */
	   	
	   else {  /* if counter1(i) equals to 15 */
		printf( " Welcome to The Hot-Cold Game " ); /* display the message */
	   } /* end else */
	    	
	} /* end for */

	
	/* display the descriptions about the game */
	printf( "\n\n ---Rules & Definitions---"
			"\n #the computer will select a number between 0 and 100"
			"\n #You will have 10 guesses."
			"\n #Please, enter a number between 0 to 1000."
			"\n STABLE!: You are still the same distance from the true value."
			"\n COLD!: You are getting away from the real value."
			"\n HOT!: You are getting closer to the real value."
			"\n GOOD LUCK!\n" );
	
   printf("\n\n");
   	
   srand( time( NULL ) ); /* randomize random number generator using current time */
  	number = rand() % 100; /* pick random number from 0 to 1000 */
  	
  	j = 0; /* initialize loop counter2(j) to 0 */
  	
	 /* processing phase */
	 /* get predictions from the user and display them in tabular format*/
   while(j < 10){ /* loop 10 times */
   	printf( "->Please, enter your %s prediction: ", ordinary[ j ] ); /* prompt for forecast input, display predciction no. */
   	scanf( "%d", &predictions[ j ] ); /* read as i. prediction and set element at location j */
   	printf("\n");
   		
   	printHeader();
   		
		for( k = 0; k < (j + 1); ++k) { /* initialization of the the control value as 0, identification of loop continuation condition and increment of control variable by 1*/ 
				
			if ( predictions[ k ] == number ){ /* if player finds the number (the forecast is equal to the true value ), continue with next iteration of loop */
					
				if( (k == 0) ){ /* if player finds the number at first guess( the forecast is equal to the true value ), continue with next iteration of loop */
					printf( "%10d. %18d %20s  %19s \n", k+1 , predictions[ k ], accuracy[ 0 ], "*******");	/* display a message that includes prediciton no. , prediction, accuracy status, clue ( Message1 )*/
        			printf( "\n***Congratulations! You got the right result at your first prediction.***\n" ); /* display a greeting message for first prediction ( Message1 ) */
				} /* end if */
				
				else{	/* if player finds the number at other guesses, continue with next iteration of loop */
					printf( "%10d. %18d %20s %19s \n", k+1 , predictions[ k ], accuracy[ 1 ], "*******" ); /* display a message that includes prediciton no. , prediction, accuracy status, clue ( Message2 ) */
					printf( "\n***Congratulations! You got the right result at your %s prediction.***\n", ordinary[ k ] ); /* display a greeting message for (k+1). prediction ( Message2 )  */
       			} /* end if */
       			
       		j = 10;/* initialize loop counter2(j) to 10 and finish the while loop */
       		break; /* break loop only if prediction value equals real value */
       		
       	}/* end if */
       		
       	else{ /* if player makes the wrong guess ( the forecast is not equal to the true value ), continue with next iteration of loop */
       			
       		if ( k == 0 ) { /* if player makes the wrong guess at first guess ( the forecast is not equal to the true value ), continue with next iteration of loop */
        			printf( "%10d. %18d %20s %18s \n", k+1 , predictions[ k ], accuracy[ 2 ], "-----" ); /* display a message that includes prediciton no. , prediction, accuracy status, clue ( Message3 ) */
        		}/* end if */
        		
        		else if (k == 9){ /* if player makes the wrong guess at last guess ( the forecast is not equal to the true value ), continue with next iteration of loop */
        			printf( "%10d. %18d %20s %18s \n", k+1 , predictions[ k ], accuracy[ 2 ], "-----" ); /* display a message that includes prediciton no. , prediction, accuracy status, clue ( Message4 ) */
        			printf( "\nSorry! You didn't reach the right value in any of your choices."
							"\nThe real value was %d.", number);	/* display a consolation message and the real value ( Message4 )  */
				} /* end if */
				
				else { /* if k is not equal to 0 or 9, give a clue to the user, continue with next iteration of loop */
       				a = fabs( predictions[ k ] - number ); /* initialize variable1 as the absolute value of the result of the " ( k + 1 ). guess - real prediction " */ 
        				b = fabs( predictions[ k - 1 ] - number ); /* initialize variable2 as the absolute value of the result of the " (k . guess - real prediction " */ 
        
        			if ( a > b ) { /* if a is greater than b, continue with next iteration of loop */
      					printf( "%10d. %18d %20s %12d-->%d %s \n", k+1 , predictions[ k ], accuracy[ 2 ], predictions[ k - 1 ], predictions[ k ], clue[ 1 ] ); 
      					/* display a message that prediciton no. , prediction, accuracy status, previus forecast, current forecast and clue ( Message5 ), say you approach */
					} /* end if */
					
					else if ( a == b ){ /* if a equals b, continue with next iteration of loop */
						printf( "%10d. %18d %20s %12d-->%d %s \n", k+1 , predictions[ k ], accuracy[ 2 ], predictions[ k - 1 ], predictions[ k ], clue[ 2 ] );
							/* display a message that includse prediciton no. , prediction, accuracy status, previus forecast, current forecast and clue ( Message6 ), say there is no change */
					} /* end else if */
					
					else{ /* if a is neither equal to nor greater than b, continue with next iteration of loop */
						printf( "%10d. %18d %20s %12d-->%d %s \n", k+1 , predictions[ k ], accuracy[ 2 ], predictions[ k - 1 ], predictions[ k ], clue[ 0 ] );
							/* display a message that includes prediciton no. , prediction, accuracy status, previus forecast, current forecast and clue ( Message7 ), say you are getting away */
					} /* end else if */
				
				} /* end else */
		 			
			} /* end else */
			
		} /* end for */

	j++; /* increment counter2(j) */
	printf( "\n\n\n" );
	
	} /* end while */

printf("\n\n");
system("pause");
return 0; /* indicate that program ended successfully */

} /* end function main */

/* print a header for the output */
void printHeader( void )
{
   int m; /* define counter4 */

   printf( "   Prediction No.   |   Prediction   |   Accuracy Status   |     Clue   \n" ); /* output column head */

   /* output line of - characters */
   for( m = 0; m <= 75 ; ++m ){ /* initialization of the the control value as 0, identification of loop continuation condition and increment of control variable by 1 */ 
			printf("-");
		} /* end for */
		
	printf( "\n" ); /* start new line of output */	
} /* end function printHeader **/




