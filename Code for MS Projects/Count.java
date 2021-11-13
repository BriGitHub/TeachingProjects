//********************************************************** 
//	Count.java		Author: Brianna Martinson
//
//	This program reads in strings (phrases) and counts the
//	number of blank characters and certain other letters
//	in the phrase.
//**********************************************************

package labs;

import java.util.Scanner;

public class Count {
	public static void main (String[] args) {
		String phrase; // a string of characters
		int countBlank; // the number of blanks (spaces) in the phrase
		int length; // the length of the phrase
		char ch; // an individual character in the string
		int i = 0; // the counter for each letter in the phrase
		int countA, countE, countS, countT;
		Scanner scan = new Scanner (System.in);
		
		// Print a program header 
		System.out.println ();
		System.out.println ("Character Counter"); 
		System.out.println ();
		
		// Read in a string and find its length 
		System.out.print ("Enter a sentence or phrase (type quit to stop): "); 
		phrase = scan.nextLine();
		phrase = phrase.toLowerCase();
		length = phrase.length();
		
		// Initialize counts 
		countBlank = 0;
		countA=0;
		countE=0;
		countS=0;
		countT=0;
		
		// a for loop to go through the string character by character 
		// and count the blank spaces
		// the for loop is inside a while loop so the user can do multiple phrases
		while (!(phrase.equals("quit"))) {
			for (i=0; i<length; i++) {
				ch = phrase.charAt(i);
				if(ch == ' ') {
					countBlank++;
				}
				else if(ch == 'a') {
					countA++;
				}
				else if(ch == 'e') {
					countE++;
				}
				else if(ch == 's') {
					countS++;
				}
				else if(ch == 't') {
					countT++;
				}
			}
			// Print the results
			System.out.println ();
			System.out.println ("Number of blank spaces: " + countBlank); 
			System.out.println ();
			System.out.println ("Number of a's: " + countA); 
			System.out.println ("Number of e's: " + countE); 
			System.out.println ("Number of s's: " + countS); 
			System.out.println ("Number of t's: " + countT); 
			
			System.out.print ("Enter a sentence or phrase (type quit to stop): "); 
			phrase = scan.nextLine();
			phrase = phrase.toLowerCase();
			length = phrase.length();
			
			countBlank = 0;
			countA=0;
			countE=0;
			countS=0;
			countT=0;
		}
		
		scan.close();
	}
}
