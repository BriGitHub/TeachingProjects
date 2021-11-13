// ****************************************************************
// Guess.java 		Author: Brianna Martinson
//
// Play a game where the user guesses a number from 1 to 10
//
// ****************************************************************

package labs;

import java.util.Random;
import java.util.Scanner;

public class Guess {
	public static void main(String[] args) {
		int numToGuess; //Number the user tries to guess 
		int guess; //The user's guess
		int guessCount=1; //Number of times the user guessed
		int highCount=0, lowCount=0; //Number of high and low guesses
		
		Random generator = new Random();
		Scanner scan = new Scanner (System.in);
		
		//randomly generate the number to guess 
		numToGuess = generator.nextInt(11) + 1;
		
		//print message asking user to enter a guess 
		System.out.print ("Guess the number from 1 to 10: ");
		guess = scan.nextInt();
		
		//read in guess
		
		while (numToGuess != guess) //keep going as long as the guess is wrong 
		{
			guessCount++;
			if (guess > numToGuess) {
				highCount++;
				
				//print message saying guess is too high
				System.out.println("Sorry, but that number is too high.");
				
				//get another guess from the user 
				System.out.print ("Guess again: ");
				guess = scan.nextInt();
			}
			else {
				lowCount++;
				
				//print message saying guess is too low
				System.out.println("Sorry, but that number is too low.");
				
				//get another guess from the user 
				System.out.print ("Guess again: ");
				guess = scan.nextInt();
			}
			
		}
		
		//print message saying guess is right 
		System.out.println("Yup, that is the correct number, " + guess);
		System.out.println("Number of guesses: " + guessCount);
		System.out.println("Number of trys too high: " + highCount);
		System.out.println("Number of trys too low: " + lowCount);
		
		
		scan.close();
	}
}
