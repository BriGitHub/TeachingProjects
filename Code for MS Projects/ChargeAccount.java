// ***************************************************************
// ChargeAccount.java		Author: Brianna Martinson
//
// Calculates how much someone needs to pay for their credit card
// ***************************************************************

package labs;

import java.util.Scanner;
import java.text.NumberFormat;

public class ChargeAccount {
	public static void main(String[]args) {
		// initializes all the variables needed for the program
		double prevBalance, charges, interest, newBalance, payment;
		Scanner scan = new Scanner (System.in);
		NumberFormat money = NumberFormat.getCurrencyInstance();
		
		// asks the user how much they did not pay from before
		System.out.print ("How much did you owe on your card last month? ");
		prevBalance = scan.nextDouble();
		// checks to make sure the user does not enter a negative amount
		while(prevBalance < 0) {
			System.out.println ("That is not valid, you can not be charged negative amount.");
			System.out.print ("Please enter how much you owed on your card last month: ");
			prevBalance = scan.nextDouble();
		}
		
		// asks the user how much they are charged for using the card
		System.out.print ("How much does the company charge you for having the card? ");
		charges = scan.nextDouble();
		// checks to make sure the user does not enter a negative amount
		while(charges < 0) {
			System.out.println ("That is not valid, you can not be charged negative amount.");
			System.out.print ("Please enter how much the company charges you: ");
			charges = scan.nextDouble();
		}
		
		
		System.out.println("\nCS CARD International Statement"
				+ "\n===============================\n");
		
		System.out.println("Previous Balance: \t" + money.format(prevBalance));
		 
		System.out.println("Additional Charges: \t" + money.format(charges));
		
		// calculates the interest rate by using the previous balance
		if (prevBalance == 0) {
			interest = 0;
			System.out.println("Interest: \t \t" + money.format(interest));
		}
		else { 
			interest = .02;
			prevBalance = (prevBalance*interest) + prevBalance;
			System.out.println("Interest: \t \t" + money.format(interest));
		}
		
		// calculates the new balance 
		newBalance = prevBalance + charges;
		if (newBalance < 50) {
			System.out.println("New Balance: \t \t" + money.format(newBalance));
		}
		else if (newBalance >= 50 && newBalance <= 300) {
			newBalance = 50;
			System.out.println("New Balance: \t \t" + money.format(newBalance));
		}
		else{
			newBalance = (newBalance * .2) + newBalance;
			System.out.println("New Balance: \t \t" + money.format(newBalance));
		}
		
		// calculates the total minimum payment by adding all the charges
		payment = newBalance;
		System.out.println("Minimum Payment: \t" + money.format(payment));
		
		scan.close();
	}
}
