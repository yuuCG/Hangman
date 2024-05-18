#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// We need 30 words for each category
vector<string> animals = { "dog", "cat", "elephant", "giraffe", "lion", "tiger", "bear", "wolf", "fox", "rabbit", "deer", "moose", "horse", "cow", "pig", "sheep", "goat", "chicken", "duck", "turkey", "eagle", "hawk", "owl", "parrot", "penguin", "dolphin", "whale", "shark", "octopus", "jellyfish" };
vector<string> countries = { "usa", "canada", "mexico", "brazil", "argentina", "chile", "peru", "england", "france", "germany", "italy", "spain", "portugal", "russia", "china", "japan", "india", "australia", "new zealand", "egypt", "south africa", "nigeria", "kenya", "ethiopia", "morocco", "saudi arabia" };
vector<string> fruits = { "apple", "banana", "orange", "grape", "strawberry", "blueberry", "raspberry", "blackberry", "kiwi", "watermelon", "cantaloupe", "honeydew", "pineapple", "mango", "papaya", "peach", "pear", "plum", "cherry", "apricot", "fig", "date", "coconut", "avocado", "lemon", "lime" };
vector<string> vegetables = { "carrot", "broccoli", "cauliflower", "cabbage", "lettuce", "spinach", "kale", "collard greens", "swiss chard", "beet", "turnip", "radish", "potato", "sweet potato", "yam", "onion", "garlic", "shallot", "leek", "scallion", "asparagus", "green bean", "snap pea", "bell pepper", "jalapeno", "habanero" };
vector<string> colors = { "red", "orange", "yellow", "green", "blue", "purple", "pink", "brown", "black", "white", "gray", "silver", "gold", "bronze", "copper", "platinum", "turquoise", "teal", "aqua", "navy", "indigo", "violet", "magenta", "maroon", "crimson" };
vector<string> shapes = { "circle", "square", "triangle", "rectangle", "pentagon", "hexagon", "heptagon", "octagon", "nonagon", "decagon", "dodecagon", "ellipse", "oval", "crescent", "star", "heart", "cylinder", "cone", "sphere", "cube", "pyramid", "prism", "torus", "mobius strip", "fractal" };
vector<string> sports = { "soccer", "football", "basketball", "baseball", "hockey", "tennis", "golf", "rugby", "cricket", "volleyball", "badminton", "table tennis", "bowling", "billiards", "darts", "archery", "fencing", "boxing", "wrestling", "karate", "taekwondo", "judo", "jiu jitsu", "aikido", "kendo" };
vector<string> instruments = { "guitar", "piano", "violin", "cello", "flute", "clarinet", "saxophone", "trumpet", "trombone", "drum", "xylophone", "harmonica", "accordion", "banjo", "mandolin", "ukulele", "harp", "bagpipes", "didgeridoo", "theremin", "ocarina", "kazoo", "maracas", "tambourine", "castanets" };
vector<string> professions = { "doctor", "nurse", "teacher", "engineer", "scientist", "programmer", "artist", "musician", "actor", "athlete", "chef", "mechanic", "plumber", "electrician", "carpenter", "farmer", "police officer", "firefighter", "soldier", "sailor", "pilot", "astronaut", "architect", "lawyer", "judge" };
vector<string> ords = { "dog", "cat", "elephant", "giraffe", "lion", "tiger", "bear", "wolf", "fox", "rabbit", "deer", "moose", "horse", "cow", "pig", "sheep", "goat", "chicken", "duck", "turkey", "eagle", "hawk", "owl", "parrot", "penguin", "dolphin", "whale", "shark", "octopus", "jellyfish", "usa", "canada", "mexico", "brazil", "argentina", "chile", "peru", "england", "france", "germany", "italy", "spain", "portugal", "russia", "china", "japan", "india", "australia", "new zealand", "egypt", "south africa", "nigeria", "kenya", "ethiopia", "morocco", "saudi arabia", "apple", "banana", "orange", "grape", "strawberry", "blueberry", "raspberry", "blackberry", "kiwi", "watermelon", "cantaloupe", "honeydew", "pineapple", "mango", "papaya", "peach", "pear", "plum", "cherry", "apricot", "fig", "date", "coconut", "avocado", "lemon", "lime", "carrot", "broccoli", "cauliflower", "cabbage", "lettuce", "spinach", "kale", "collard greens", "swiss chard", "beet", "turnip", "radish", "potato", "sweet potato", "yam", "onion", "garlic", "shallot", "leek", "scallion", "asparagus", "green bean", "snap pea", "bell pepper", "jalapeno", "habanero", "red", "orange", "yellow", "green", "blue", "purple", "pink", "brown", "black", "white", "gray", "silver", "gold", "bronze", "copper", "platinum", "turquoise", "teal", "aqua", };


// Function to get a random word from a category
string getRandomWord(vector<string> category)
{
	cout << "Tell me three number you like most: ";
	int a, b, c;
	cin >> a >> b >> c;
	int serect_key = (a - b + c) * (a * b * c);
	int Index = serect_key % category.size();
	return category[Index];
}
 
// Function to check if a letter is in the word
bool isLetterInWord(string word, char letter)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == letter)
		{
			return true;
		}
	}
	return false;
}

// Function to check the word with blanks for missing letters
bool checkWord(string word, char charGuess)
{
	bool correctGuess = false;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == charGuess)
		{
			correctGuess = true;
			break;
		}
	}
	return correctGuess;
}

// Function to display the word with blanks for missing letters
void displayWord(string word, vector<char> guessedLetters)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (find(guessedLetters.begin(), guessedLetters.end(), word[i]) != guessedLetters.end())
		{
			cout << word[i] << ' ';
		}
		else
		{
			cout << "_ ";
		}
	}
}

// Function to display the hangman
void displayHangman(int heartLefts,string Word)
{
	// We will display the hangman in 6 stages
	if (heartLefts <= 6) cout << "======|======";
	else
	{
		cout << "\n\n\n\n\n\n\n=============\n";
		return;
	}
	if (heartLefts <= 5) cout << "\n      o      ";
	else
	{
		cout << "\n\n\n\n\n\n=============\n";
		return;
	}
	if (heartLefts <= 4) cout << "\n      |      ";
	else
	{
		cout << "\n\n\n\n\n=============\n";
		return;
	}
	if (heartLefts <= 3) cout << "\n     /|\\     ";
	else
	{
		cout << "\n\n\n\n=============\n";
		return;
	}
	if (heartLefts <= 2) cout << "\n      |       ";
	else
	{
		cout << "\n\n\n=============\n";
		return;
	}
	if (heartLefts == 2)
	{
		cout << "\n\n=============\n";
		cout << "You have 2 hearts left\n";
		return;
	}
	if (heartLefts == 1)
	{
		cout << "\n     /       ";
		cout << "\n==============\n";
		cout << "You have 1 heart left\n";
		return;
	}
	if (heartLefts == 0)
	{
		cout << "\n     / \\     ";
		cout << "\n=============\n";
		cout << "You are hanged! The word was: ";
		cout << Word << '\n';
	}
}

// Function to check if the player has won
bool checkWin(string word, vector<char> guessedLetters)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (find(guessedLetters.begin(), guessedLetters.end(), word[i]) == guessedLetters.end())
		{
			return false;
		}
	}
	return true;
}

// Function to check if the player has lost
bool checkLoss(int heartLefts)
{
	if (heartLefts == 0)
	{
		return true;
	}
	return false;
}

// Function to display the menu
void displayTheMenu()
{
	cout << "Welcome to Hangman!\n";
	cout << "We have a few categories for you to choose from:\n";
	cout << "1. Animals\n";
	cout << "2. Countries\n";
	cout << "3. Fruits\n";
	cout << "4. Vegetables\n";
	cout << "5. Colors\n";
	cout << "6. Shapes\n";
	cout << "7. Sports\n";
	cout << "8. Musical Instruments\n";
	cout << "9. Professions\n";
	cout << "10. Random\n";
	int category;
	int try_again = 1;
	do {
		cout << "Please enter the number of the category you want to play: ";
		do {
			cin >> category;
			if (category < 1 || category > 10)
			{
				cout << "Invalid category number. Please enter a number between 1 and 10: ";
			}
		} while (category < 1 || category > 10);
		string word;
		switch (category)
		{
		case 1:
			cout << "You have selected the Animals category!\n";
			word = getRandomWord(animals);
			break;
		case 2:
			cout << "You have selected the Countries category!\n";
			word = getRandomWord(countries);
			break;
		case 3:
			cout << "You have selected the Fruits category!\n";
			word = getRandomWord(fruits);
			break;
		case 4:
			cout << "You have selected the Vegetables category!\n";
			word = getRandomWord(vegetables);
			break;
		case 5:
			cout << "You have selected the Colors category!\n";
			word = getRandomWord(colors);
			break;
		case 6:
			cout << "You have selected the Shapes category!\n";
			word = getRandomWord(shapes);
			break;
		case 7:
			cout << "You have selected the Sports category!\n";
			word = getRandomWord(sports);
			break;
		case 8:
			cout << "You have selected the Musical Instruments category!\n";
			word = getRandomWord(instruments);
			break;
		case 9:
			cout << "You have selected the Professions category!\n";
			word = getRandomWord(professions);
			break;
		case 10:
			cout << "You have selected the Random category!\n";
			word = getRandomWord(ords);
			break;
		}
	vector<char> guessedLetters;
	int heartLefts = 7;
	bool win = false;
	bool loss = false;
	displayHangman(heartLefts, word);
	cout << "The word is: ";
	displayWord(word, guessedLetters);
	cout << '\n';
	do
	{
		cout << "Please enter a letter to guess: ";
		char charGuess;
		cin >> charGuess;
		guessedLetters.push_back(charGuess);
		if (checkWord(word, charGuess))
		{
			cout << "You guessed a correct letter!\n";
		}
		else
		{
			cout << "You guessed a wrong letter!\n";
			heartLefts--;
		}
		displayHangman(heartLefts, word);
		if (heartLefts > 0)
		{
			cout << "The word is: ";
			displayWord(word, guessedLetters);
		}
		cout << '\n';
		if (checkWin(word, guessedLetters))
		{
			win = true;
			break;
		}
		if (checkLoss(heartLefts))
		{
			loss = true;
			break;
		}
	} while (!win && !loss);
	if (win)
	{
		cout << "Congratulations! You won!\n";
	}
	if (loss)
	{
		cout << "You lost! Better luck next time!\n";
	}
	cout << "Do you want to play again? (1 for yes, 0 for no): ";
	do
	{
		cin >> try_again;
		if (try_again != 0 && try_again != 1)
		{
			cout << "Invalid input. Please enter 1 or 0: ";
		}
	} while (try_again != 0 && try_again != 1);
	} while (try_again == 1);
}