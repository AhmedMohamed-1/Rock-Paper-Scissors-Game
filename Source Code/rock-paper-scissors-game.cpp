#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <thread>
#include <cstdlib>
#include "mmsystem.h";
using namespace std;

void Red_Color()
{
	system("color 4F");
}
void Green_Color()
{
	system("color 2F");
}
void Yellow_Color()
{
	system("color 6F");
}
void Black_color()
{
	system("color 0F");
}

void CoutCentered(string text)
{
	// This function will only center the text if it is less than the length of the console!
	// Otherwise it will just display it on the console without centering it.

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                           // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);                          // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize;                                      // Gets the size of the screen
	if (NewSBSize.X > text.size())
	{
		int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++)
			cout << " "; // Prints the spaces
	}
	cout << text << endl; // Prints the text centered :]
}

int audio_for_welcoming()
{
	const char* audioFilePath = "E:\\Ahmed\\Game_Project\\rock-paper-scissors-game\\Audios\\welcome.wav";

	// Play the audio file
	if (PlaySoundA(audioFilePath, NULL, SND_FILENAME | SND_ASYNC) == 0) {
		// An error occurred
		std::cerr << "Error playing audio: " << GetLastError() << std::endl;
		return 1;
	}
}
int audio_for_winning()
{
	const char* audioFilePath = "E:\\Ahmed\\Game_Project\\rock-paper-scissors-game\\Audios\\clapping.wav";

	// Play the audio file
	if (PlaySoundA(audioFilePath, NULL, SND_FILENAME | SND_ASYNC) == 0) {
		// An error occurred
		std::cerr << "Error playing audio: " << GetLastError() << std::endl;
		return 1;
	}
}

int audio_for_losing()
{
	const char* audioFilePath = "E:\\Ahmed\\Game_Project\\rock-paper-scissors-game\\Audios\\Game_over.wav";

	// Play the audio file
	if (PlaySoundA(audioFilePath, NULL, SND_FILENAME | SND_ASYNC) == 0) {
		// An error occurred
		std::cerr << "Error playing audio: " << GetLastError() << std::endl;
		return 1;
	}
}

void Record_screen(int& counter, int& won, int& loose, int& Draw)
{
	cout << "Number Of Games Played" << setw(10) << " : " << counter << endl;
	cout << "The Number Of Times You Won" << setw(5) << " : " << won << endl;
	cout << "The Number Of Times You Lost" << setw(4) << " : " << loose << endl;
	cout << "Number Of Times a Draw" << setw(10) << " : " << Draw << endl;
	if (won > loose)
	{
		audio_for_winning();
		cout << "\n";
		CoutCentered("You are the Winner : )");
		Green_Color();
		cout << endl;
	}
	else if (loose > won)
	{
		audio_for_losing();
		cout << "\n";
		CoutCentered("You are Loser :(");
		Red_Color();
		cout << endl;
	}
	cout << "\n\n";
}


enum choices
{
	Rock = 1,
	Paper = 2,
	Scissors = 3
};

int Pc_choice()
{
	// Generate a random number [1 - 3]
	int From = 1;
	int To = 3;
	return rand() % (To - From + 1) + From;
}

bool valid_yes(string& Qusition)
{
	if (Qusition == "Yes" || Qusition == "yes" || Qusition == "y" || Qusition == "Y")
	{
		return true;
	}
	return false;
}

bool valid_no(string& Qusition)
{
	if (Qusition == "No" || Qusition == "no" || Qusition == "n" || Qusition == "N")
	{
		return true;
	}
	return false;
}

bool validation(string& Type_Again)
{
	if (valid_yes(Type_Again) || valid_no(Type_Again))
	{
		return true;
	}

	return false;
}

bool validation_num(int& input_user_num)
{
	if (input_user_num > 0 && input_user_num < 4)
	{
		return true;
	}

	return false;
}

string choices[4]{ "", "Rock", "Paper", "Scissors" };
//                [0]    [1]     [2]        [3]

// To Import Audio we need this line
#pragma comment(lib, "winmm.lib")

int main()
{
	int draw_points = 0;
	int win_points = 0;
	int loose_points = 0;
	int counter_for_N_games_played = 0;
	int User_choice = 0;
	string play_again = "";
	string Ask_to_play_again = "";
	srand((unsigned)(time(NULL)));
	audio_for_welcoming();
	CoutCentered("Welcome To The Game");
	this_thread::sleep_for(chrono::seconds(3));
	system("CLS");
	do
	{
		system("CLS");
		cout << "Choose a choice ";
		cout << "[1] Rock "
			<< "[2] Paper "
			<< "[3] Scissors\n";
		cin >> User_choice;

		while (!validation_num(User_choice) && cin.fail())
		{
			CoutCentered("Please Enter a valid number");
			this_thread::sleep_for(chrono::seconds(1));
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "Choose a choice ";
			cout << "[1] Rock " << "[2] Paper " << "[3] Scissors\n";
			cin >> User_choice;
		}

		int Pc = Pc_choice();
		counter_for_N_games_played++;
		// draw cases
		if (User_choice == Pc)
		{
			draw_points++;
			Yellow_Color();
			cout << "Your choice" << setw(8) << " : " << choices[User_choice] << "\n";
			cout << "computer choice" << setw(4) << " : " << choices[Pc] << "\n";
			cout << "The Winner Is" << setw(6) << " : "
				<< "This a Draw !\n";
		}

		// wining cases
		else if (User_choice == Paper && Pc == Rock)
		{
			win_points++;
			Green_Color();
			cout << "\a";
			cout << "Your choice" << setw(8) << " : " << choices[User_choice] << "\n";
			cout << "computer choice" << setw(4) << " : " << choices[Pc] << "\n";
			cout << "The Winner Is" << setw(6) << " : "
				<< "Great You Won\n";
		}
		else if (User_choice == Rock && Pc == Scissors)
		{
			win_points++;
			Green_Color();
			cout << "\a";
			cout << "Your choice" << setw(8) << " : " << choices[User_choice] << "\n";
			cout << "computer choice" << setw(4) << " : " << choices[Pc] << "\n";
			cout << "The Winner Is" << setw(6) << " : "
				<< "Great You Won\n";
		}
		else if (User_choice == Scissors && Pc == Paper)
		{
			win_points++;
			Green_Color();
			cout << "\a";
			cout << "Your choice" << setw(8) << " : " << choices[User_choice] << "\n";
			cout << "computer choice" << setw(4) << " : " << choices[Pc] << "\n";
			cout << "The Winner Is" << setw(6) << " : "
				<< "Great You Won\n";
		}

		// loose cases
		else
		{
			// else if (Pc == Rock && User_choice == Scissors)
			// else if (Pc == Paper && User_choice == Rock)
			// else if (Pc == Scissors && User_choice == Paper)
			loose_points++;
			Red_Color();
			cout << "Your choice" << setw(8) << " : " << choices[User_choice] << "\n";
			cout << "computer choice" << setw(4) << " : " << choices[Pc] << "\n";
			cout << "The Winner Is" << setw(6) << " : " << "Computer Won\n";
		}

		cout << "\n\n";
		CoutCentered("Play Again ?\n");
		CoutCentered("Yes : No\n");
		cin >> play_again;
		system("CLS");
		Black_color();
		while (!validation(play_again))
		{
			CoutCentered("Please Enter a valid answer");
			this_thread::sleep_for(chrono::seconds(1));
			cin.clear();
			system("CLS");
			CoutCentered("Play Again ?\n");
			CoutCentered("Yes : No\n");
			cin >> play_again;
			system("CLS");
		}

	} while (valid_yes(play_again));

	if (valid_no(play_again))
	{
		Record_screen(counter_for_N_games_played, win_points, loose_points, draw_points);
	}


	this_thread::sleep_for(chrono::seconds(3));
	system("CLS");
	Black_color();
	CoutCentered("Thanks For Playing");
	cout << endl;
	CoutCentered("Made by\"Ahmed Mohamed\"");
	this_thread::sleep_for(chrono::seconds(3));


	return 0;
}
