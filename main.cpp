#include <iostream>
using namespace std;

const char CHARACTERS[4] = { 'a', 'b', 'c', 'd' };

void endGame(string toPrompt);

void clearConsole() {
	system("cls");
}

/*

	asks the user a question, with a given answer set to display, and the correct
	indx of the correct answer in that answer set.

*/
char askQuestion(string question, string answerSet[]) {
	char receivedAnswer;

	cout << question << "\n";
	for (int i = 0; i < 2; i++)
		cout << "\t" << CHARACTERS[i] << ") " << answerSet[i] << "\n";

	cin >> receivedAnswer;
	clearConsole(); // clear our console and return the correct answer
	return receivedAnswer;
}

int main()
{
	bool enterHouse = askQuestion("It was October 31st, most commonly known as halloween, and you're out trick-or-treating. As your going home to home, you see a house that seems eerily creepy, do you go inside?", new string[2]{"Go Inside", "Skip the house"}) == 'a';

	if (!enterHouse) {
		endGame("You decide to skip that house. You then go to cross the street, your mind fuzzy from trying to figure out what that house was about. So you cross the street without looking, and you get hit by a car and die.");
		return 1;
	}

	bool justOne = askQuestion("You go inside, there is a bowl of candy with a \"Take one\" sign on it. Do you just take one, or take a handful?", new string[2]{ "Just one.", "Take a handful." }) == 'a';
	if (!justOne) {
		endGame("You took a handful of candy, at that moment a man bursts out of the wall behind you with a chainsaw. It is not on, however the jump scare made you fall down the steps that were to your left. You cry out in pain, at that point a bookshelf at the bottom of the steps falls over from the crashing, and crushes you alive.Your ribs are crackedand your lungs collapsed.");
		return 1;
	}

	bool goToAttic = askQuestion("You take just one candy and decide to continue through the home, you come acroos what appears to be a skeleton. You touch it to see if it is real or fake, and it feels real. Thats when you notice the house smells of dead bodies.", new string[2]{"Find where the smell is coming from, which means going into the attic.", "Decide to turn around and leave."}) == 'a';
	if (!goToAttic) {
		endGame("You got shot by the homeowner while trying to go out the front door.");
		return 1;
	}

	bool leaveHouse = askQuestion("You decided to go investigate the smell, so you pull down the ladder to the attic and climb up the steps. Once you get to the top you find many things that would scare anyone alive, bodies upon bodies, as you tretch through, you realize they're rubber.", new string[2]{ "Decide to leave and continue trick or treating", "Continue looking through the attic" }) == 'a';
	if (!leaveHouse) {
		endGame("As you keep looking through the attic, you find old jewelry, and it all appears to be real and pure diamonds.");
		return 1;
	}

	bool trickOrTreating = askQuestion("As you are sneaking out the front door, the homeowner confronts you, and he threatens to kill you if you don't tell him why your here.", new string[2]{"'I'm here for trick-or-treating'", "Run for it"}) == 'a';
	if (!trickOrTreating) {
		endGame("You tried to run, however the homeowner caught up with you and tackled you. He didn't hurt you but he called the cops, which leads to you being driven and your parents are told about what you did.");
		return 1;
	}

	bool runForIt = askQuestion("He doesn't believe you and reaches for a weapon that seems to be behind the door.", new string[2]{"Run for it", "Tackle him"}) == 'a';
	if (!runForIt) {
		endGame("You were able to tackle him, however he yelled and his neighbors came out and fought you. You eventually were so badly injured, that you died.");
		return 1;
	}

	clearConsole();
	endGame("You successfully ran away, and decided to go home.");
}

void endGame(string prompt) {
	cout << prompt;
	cout << "\n\n";
	
	bool replay = askQuestion("Would you like to replay?", new string[2]{ "Yes.", "No." }) == 'a';
	if (replay)
		main();
}
