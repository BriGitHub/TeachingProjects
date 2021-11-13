// ****************************************************************
// Rock.java
//
// Play Rock, Paper, Scissors with the user
//
// ****************************************************************

package labs;

import java.util.Random;
import java.util.Scanner;

public class Rock
{
	public static void main(String[] args)
	{
		String personPlay; 	//User's play -- "R", "P", or "S"
		String computerPlay; //Computer's play -- "R", "P", or "S"
		int computerInt; 	//Randomly generated number used to determine
							//computer's play
		
		Random generator = new Random();
		
		//Get player's play -- note that this is stored as a string
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter your play (R for rock, S for scissors, P for paper): ");
		personPlay = scan.nextLine();
		
		//Make player's play uppercase for ease of comparison
		personPlay = personPlay.toUpperCase();
		System.out.println(personPlay);
		
		//Does error checking to make sure the player put in a proper play
		while(!(personPlay.equals("R") || personPlay.equals("P") || personPlay.equals("S"))) {
			System.out.print("That is not a valid option, please "
					+ "enter (R for rock, S for scissors, P for paper):");
			personPlay = scan.nextLine();
			personPlay = personPlay.toUpperCase();
			System.out.println(personPlay);
		}
			
		//Generate computer's play (0,1,2)
		computerInt = generator.nextInt(3);
		
		//Translate computer's randomly generated play to string
		if(computerInt==0) {
			computerPlay = "R";
		} 
		else if (computerInt==1) {
			computerPlay = "P";
		}
		else {
			computerPlay = "S";
		}
		
		//Print computer's play
		//See who won. Use nested ifs instead of &&.
		if (personPlay.equals(computerPlay))
			System.out.println("It's a tie!");
		else if (personPlay.equals("R")) {
			if (computerPlay.equals("S"))
				System.out.println("Rock crushes scissors. You win!!");
			else 
				System.out.println("Paper covers rock. You lose.");
		}
		else if (personPlay.equals("P")) {
			if(computerPlay.equals("R"))
				System.out.println("Paper covers rock. You win!!");
			else
				System.out.println("Scissors cut paper. You lose.");
			
		}
		else {
			if(computerPlay.equals("P")) 
				System.out.println("Scissors cut paper. You win!!");
			else
				System.out.println("Rock crushes scissors. You lose.");
		}
		scan.close();
	}
}
