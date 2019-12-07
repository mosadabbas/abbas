//C++ include header files
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>
#include <array>
#include <future>
#include <time.h>

using namespace std;

class TicTacToe
{

private:

	string first_player = "", second_player = ""; //player name string
	int first_player_score = 0, second_player_score = 0, draw_score = 0, menu_choice = 0;
	char box_choice = 0; //varibales to store scores
	char first_player_symbol = 'X', second_player_symbol = 'O'; //deciding the symbols for the players
	int player_turn = 1; //STart with first_player turn
	bool there_is_winner = false; //set no player win in start
	int computer_move = 0;//making to start move from computer
	int total_move_counter = 0;// count the moves

public:

	TicTacToe() : game_array({ { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' } }) {//calling constructor

	}
	std::array<char, 9> game_array;
	void display_board() //Match board
	{
		cout << "		          TIC TAC TOE\n";
		cout << "			 " << game_array[0] << " | " << game_array[1] << " | " << game_array[2] << "\n";
		cout << "			 ___ ___ ___\n\n";
		cout << "			 " << game_array[3] << " | " << game_array[4] << " | " << game_array[5] << "\n";
		cout << "			 ___ ___ ___\n\n";
		cout << "			 " << game_array[6] << " | " << game_array[7] << " | " << game_array[8] << "\n";
	}

	void setting_board_choices(char choice) //Take player enetered choice on the board
	{
		switch (choice)
		{
		case 'A':
			if (player_turn % 2 != 0) { game_array[0] = first_player_symbol; }
			else game_array[0] = second_player_symbol; break;

		case 'B':
			if (player_turn % 2 != 0) { game_array[1] = first_player_symbol; }
			else game_array[1] = second_player_symbol; break;

		case 'C':
			if (player_turn % 2 != 0) { game_array[2] = first_player_symbol; }
			else game_array[2] = second_player_symbol; break;

		case 'D':
			if (player_turn % 2 != 0) { game_array[3] = first_player_symbol; }
			else game_array[3] = second_player_symbol; break;

		case 'E':
			if (player_turn % 2 != 0) { game_array[4] = first_player_symbol; }
			else game_array[4] = second_player_symbol; break;

		case 'F':
			if (player_turn % 2 != 0) { game_array[5] = first_player_symbol; }
			else game_array[5] = second_player_symbol; break;

		case 'G':
			if (player_turn % 2 != 0) { game_array[6] = first_player_symbol; }
			else game_array[6] = second_player_symbol; break;

		case 'H':
			if (player_turn % 2 != 0) { game_array[7] = first_player_symbol; }
			else game_array[7] = second_player_symbol; break;

		case 'I':
			if (player_turn % 2 != 0) { game_array[8] = first_player_symbol; }
			else game_array[8] = second_player_symbol; break;
		}
	}
//this function has been used to display the score
	void display_score() //Displaying score
	{
		cout << "		            Total scoring\n";
		cout << "		            ~~~~~\n";
		cout << "	  " << first_player << "		    draws		" << second_player << "\n";
		cout << "	   " << first_player_score << "	 	      " << draw_score << "			 " << second_player_score << "\n\n";

	}

	void two_player_moves() //Used when two players are playing check for winner
	{
		do {
			display_board();
			if (player_turn % 2 != 0)
			{
				cout << first_player << " Select Box";
			
				cin >> box_choice;
				setting_board_choices(box_choice);
				total_move_counter++;
			}
			else
			{
				cout << second_player << " Select Box";
				
				cin >> box_choice;
				setting_board_choices(box_choice);
				total_move_counter++;
			}
			check_winner_from_two_player(0);
			++player_turn;
		} while (there_is_winner == false);

	}

// to check who is the winner between both players
	void check_winner_from_two_player(int i) //Logics to decide winner
	{
		if (((game_array[0] == 'X') && (game_array[1] == 'X') && (game_array[2] == 'X')) || ((game_array[3] == 'X') && (game_array[4] == 'X') && (game_array[5] == 'X')) || ((game_array[6] == 'X') && (game_array[7] == 'X') && (game_array[8] == 'X'))) { display_board(); there_is_winner = true; cout << first_player << " WINs by a horizontal match!\n\n"; ++first_player_score; display_score(); menu_after_game(); }
		else if (((game_array[0] == 'O') && (game_array[1] == 'O') && (game_array[2] == 'O')) || ((game_array[3] == 'O') && (game_array[4] == 'O') && (game_array[5] == 'O')) || ((game_array[6] == 'O') && (game_array[7] == 'O') && (game_array[8] == 'O'))) { display_board(); there_is_winner = true; cout << second_player << " WINs by a horizontal match!\n\n"; ++second_player_score; display_score(); menu_after_game(); }
		else if (((game_array[0] == 'X') && (game_array[3] == 'X') && (game_array[6] == 'X')) || ((game_array[1] == 'X') && (game_array[4] == 'X') && (game_array[7] == 'X')) || ((game_array[2] == 'X') && (game_array[5] == 'X') && (game_array[8] == 'X'))) { display_board(); there_is_winner = true; cout << first_player << " WINs by a vertical match!\n\n"; ++first_player_score; display_score(); menu_after_game(); }
		else if (((game_array[0] == 'O') && (game_array[3] == 'O') && (game_array[6] == 'O')) || ((game_array[1] == 'O') && (game_array[4] == 'O') && (game_array[7] == 'O')) || ((game_array[2] == 'O') && (game_array[5] == 'O') && (game_array[8] == 'O'))) { display_board(); there_is_winner = true; cout << second_player << " WINs by a vertical match!\n\n"; ++second_player_score; display_score(); menu_after_game(); }
		else if (((game_array[0] == 'X') && (game_array[4] == 'X') && (game_array[8] == 'X')) || ((game_array[2] == 'X') && (game_array[4] == 'X') && (game_array[6] == 'X'))) { display_board(); there_is_winner = true; cout << first_player << " WINs by a diagonal match!\n\n"; ++first_player_score; display_score(); menu_after_game(); }
		else if (((game_array[0] == 'O') && (game_array[4] == 'O') && (game_array[8] == 'O')) || ((game_array[2] == 'O') && (game_array[4] == 'O') && (game_array[6] == 'O'))) { display_board(); there_is_winner = true; cout << second_player << " WINs by a diagonal match!\n\n"; ++second_player_score; display_score(); menu_after_game(); }
		else if (i == 1){ display_board(); there_is_winner = true; cout << second_player << " First player timed out!\n\n"; ++second_player_score; display_score(); menu_after_game(); }
		else if (i == 2){ display_board(); there_is_winner = true; cout << first_player << " Second player timed out!\n\n"; ++first_player_score; display_score(); menu_after_game(); }

		else if (total_move_counter == 9){
			display_board(); there_is_winner = true; cout << "Match Drawn\n\n"; ++draw_score; display_score(); menu_after_game();
		}
	}

	void computer_run()
	{
		if (first_player == "computer_player")
			do {
				computer_strategy();
				total_move_counter++;
				check_winner_from_two_player(0);
				++player_turn;
				display_board();
				cout << second_player << " Select Box";
				cin >> box_choice;
				setting_board_choices(box_choice);
				total_move_counter++;
				check_winner_from_two_player(0);
				++player_turn;
			} while (there_is_winner == false);
		else if (second_player == "computer_player")
			do {
				display_board();// call display_board function
				
				cout << first_player << " Select Box";
				cin >> box_choice;
				setting_board_choices(box_choice);
				total_move_counter++;
				check_winner_from_two_player(0);
				++player_turn;
				computer_strategy();
				total_move_counter++;
				check_winner_from_two_player(0);
				++player_turn;
			} while (there_is_winner == false);

	}

//This function has been designed for moving the computer turn
	void computer_strategy()
	{
		if (first_player == "computer_player" && computer_move == 0) { setting_board_choices('E'); computer_move++; }

		else if (first_player == "computer_player"&& computer_move == 1)
		{
			if (game_array[2] == 'C') { setting_board_choices('C'); computer_move++; }
			else if (game_array[8] == 'I') { setting_board_choices('I'); computer_move++; }
		}

		else if (first_player == "computer_player"&& computer_move == 2)
		{
			if (game_array[2] == 'X') {
				if (game_array[6] == 'G') { setting_board_choices('G'); computer_move++; }
				else if (game_array[8] == 'I') { setting_board_choices('I'); computer_move++; }
				else if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
			}
			if (game_array[8] == 'X') {
				if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
				else if (game_array[6] == 'G') { setting_board_choices('G'); computer_move++; }
			}
		}

		else if (first_player == "computer_player"&& computer_move == 3)
		{
			if (game_array[2] == 'X') {
				if (game_array[5] == 'F') { setting_board_choices('F'); computer_move++; }
				else if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
			}
			if (game_array[8] == 'X') {
				if (game_array[7] == 'H') { setting_board_choices('H'); computer_move++; }
				else if (game_array[2] == 'C') { setting_board_choices('C'); computer_move++; }
			}
		}

		else if (second_player == "computer_player" && computer_move == 0)
		{
			if (game_array[4] == 'E') { setting_board_choices('E'); computer_move++; }
			else if (game_array[2] == 'C') { setting_board_choices('C'); computer_move++; }
		}


		else if (second_player == "computer_player"&& computer_move == 1)
		{
			if (game_array[2] == 'C') { setting_board_choices('C'); computer_move++; }
			else if (game_array[8] == 'I') { setting_board_choices('I'); computer_move++; }
		}

		else if (second_player == "computer_player"&& computer_move == 2)
		{
			if (game_array[2] == 'O') {
				if (game_array[6] == 'G') { setting_board_choices('G'); computer_move++; }
				else if (game_array[8] == 'I') { setting_board_choices('I'); computer_move++; }
				else if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }

			}
			if (game_array[8] == 'O') {
				if (game_array[6] == 'G') { setting_board_choices('G'); computer_move++; }
				else if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
			}
		}
		else if (second_player == "computer_player"&& computer_move == 3)
		{
			if (game_array[2] == 'O') {
				if (game_array[5] == 'F') { setting_board_choices('F'); computer_move++; }
				else if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
			}
			if (game_array[8] == 'O') {
				if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
				if (game_array[7] == 'H') { setting_board_choices('H'); computer_move++; }
				else if (game_array[2] == 'C') { setting_board_choices('C'); computer_move++; }
			}
		}
		else if (second_player == "computer_player"&& computer_move == 4)
		{
			if (game_array[2] == 'O') {
				if (game_array[5] == 'F') { setting_board_choices('F'); computer_move++; }
				else if (game_array[0] == 'A') { setting_board_choices('A'); computer_move++; }
			}
			if (game_array[8] == 'O') {
				if (game_array[7] == 'H') { setting_board_choices('H'); computer_move++; }
				else if (game_array[2] == 'C') { setting_board_choices('C'); computer_move++; }
			}
		}
	}

//when the game is over it display the another menu to user to select

	void menu_after_game()
	{
		cout << "1.Restart Play.\n2.Go To Menu\n3.Close\n";
		cin >> menu_choice;
		switch (menu_choice)
		{
		case 1:
			reset_board();
			if (first_player == "computer_player" || second_player == "computer_player") { computer_run(); }
			else { two_player_moves(); }
			break;

		case 2:reset_scores(); reset_board(); main_menu(); break;

		case 3: exit(0);
		}
	}
//switch cases to display the menu system
	void main_menu()
	{
		//display menu system
		cout << "		 TIC TAC TOE\n";
		cout << "			  Menu\n";
		cout << "			  ~~~~~~~~\n";
		cout << "			1. vs COMPUTERs\n";
		cout << "			2. Two Players\n";
		cout << "			3. Help\n";
		cout << "			4. Close\n\n";
		cin >> menu_choice;

		switch (menu_choice)
		{
		//if user select choice 1
		case 1:cout << "CHOOSE:\n1.First Player\n2.Second Player\n";
			cin >> menu_choice;
			if (menu_choice == 1) {
				second_player = "computer_player"; cout << "First Player Enter your virtaul name.\n"; cin >> first_player;
			}
			else { first_player = "computer_player"; cout << "Second Player Enter your virtaul name.\n"; cin >> second_player; }
			computer_run();
			break;

		case 2:
			//if user select choice 2
			cout << "First Player Enter your virtaul name. ";
			cin >> first_player;
			cout << "Second Player Enter your virtaul name. ";
			cin >> second_player;
			two_player_moves();
			break;

		case 3:
			//if user select choice 3
			cout << "Match 3 same symbols in a single line to win the game!\n";
			main_menu(); break;

		case 4: exit(0);
		}
	}

	void reset_scores(){ first_player_score = 0, second_player_score = 0, draw_score = 0, first_player = "", second_player = ""; }
//to reset the board with initial state
	void reset_board()
	{
		total_move_counter = 0;
		game_array[8] = 'I';
		game_array[7] = 'H';
		game_array[6] = 'G';
		game_array[5] = 'F';
		game_array[4] = 'E';
		game_array[3] = 'D';
		game_array[2] = 'C';
		game_array[1] = 'B';
		game_array[0] = 'A';
		player_turn = 1;
		there_is_winner = false;
		computer_move = 0;
	}

	bool timer()
	{
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i<5; ++i)
		{
			cout << "Test" + i;
			std::this_thread::sleep_until(start + (i + 1)*std::chrono::seconds(1));
		}
		return true;
	}
};
//main function to control teh overall program
int main()
{
	TicTacToe a; //create object of TicTacToe class
	a.main_menu();
}