/* Programmer: Per Stoor
 * Date: 2022-08-11
 * Last changed: 2023-09-17
 * Type of program: My first attempt at a password game.
 *
 * Notes: Working on implementing the high score feature...
 * 
 * Trying to make a choice after failure: keep playing or enter
 * the high score menu.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>        //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     	//STDIN_FILENO

#define STRING_LENGTH 30
#define MENU_TOP_POSITION 1
#define MENU_BOTTOM_POSITION 4

void main_menu_function();
void character_output_function(int difficulty_level);
void exit_function();
void menu_arrow(int real_postion, int next_postion);
int difficulty_function();

int main (int argc, char *argv[]){

    int menu_selection;
	static struct termios oldt, newt;

    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr( STDIN_FILENO, &oldt);
    /*now the settings will be copied*/
    newt = oldt;
    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON);          
    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

		srand(time(NULL));
		system("clear");

		main_menu_function();
		menu_selection= difficulty_function();
		character_output_function(menu_selection);

    /*restore the old settings*/
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

return 0;
}

void main_menu_function(){

	printf("	     Welcome to\n");
	printf("	 ---------------------\n");
	printf("	 |Pers Password Puzzle|\n");
	printf("	 ---------------------\n");
	printf("	     Version 0.6\n");

	printf("\n");
	printf("Here you will test your skills with a keyboard.\n");
	printf("Try and write the words and characters displayed\n");
	printf("without looking at your trusted keys.\n");
	printf("\n");
	printf("For a true challenge, try writing with closed eyes!\n");
	getchar();

}

int difficulty_function(){

	int menu_arrow_position;
	int inputted_keyboard_value;

	menu_arrow_position = 1;
	inputted_keyboard_value = 0;

	while(inputted_keyboard_value != 10){

		system("clear");

		menu_arrow(1, menu_arrow_position);	printf("1. EASY\n");
		menu_arrow(2, menu_arrow_position);	printf("2. MEDIUM\n");
		menu_arrow(3, menu_arrow_position);	printf("3. HARD\n");
							printf("\n");
	/*
	 * This hides the cursor with an ANSI escape sequence
	 * */
	printf("\e[?25l");

		system("stty -echo");
		inputted_keyboard_value = getchar();
		system("stty echo");

		if(inputted_keyboard_value == 65 && menu_arrow_position != MENU_TOP_POSITION){
			menu_arrow_position--;
		}
		else if(inputted_keyboard_value == 66 && menu_arrow_position != MENU_BOTTOM_POSITION){
			menu_arrow_position++;
		}
		else{
			menu_arrow_position = menu_arrow_position;
		}
	}

	/*
	 * This brings the cursor back
	 * */
	printf("\e[?25h");

return menu_arrow_position;
}

void character_output_function(int difficulty_level){

	int function_loop_counter1;
	int function_loop_counter2;
	int level_counter;
	int compare_result;
	int password_length_easy;
	int password_length_medium;
	int password_length_hard;
	int exit_value;
	char function_user_inputted_string[STRING_LENGTH];
	char random_password[STRING_LENGTH];
	char program_exit_string1[STRING_LENGTH] = {'q', 'u', 'i', 't','\n','\0'};
	char program_exit_string2[STRING_LENGTH] = {'Q', 'U', 'I', 'T','\n','\0'};
	char program_exit_string3[STRING_LENGTH] = {'Q', 'u', 'i', 't','\n','\0'};
	char program_exit_string4[STRING_LENGTH] = {'Q', '\n','\0'};
	char program_exit_string5[STRING_LENGTH] = {'q', '\n','\0'};
	char program_exit_string6[STRING_LENGTH] = {'e', 'x', 'i', 't','\n','\0'};
	char program_exit_string7[STRING_LENGTH] = {'E', 'X', 'I', 'T','\n','\0'};
	char program_exit_string8[STRING_LENGTH] = {'E', 'x', 'i', 't','\n','\0'};
	char program_exit_string9[STRING_LENGTH] = {'E', '\n','\0'};
	char program_exit_string10[STRING_LENGTH] = {'e', '\n','\0'};
	char program_exit_string11[STRING_LENGTH] = {'y', '\n','\0'};
	char program_exit_string12[STRING_LENGTH] = {'Y', '\n','\0'};
	char program_exit_string13[STRING_LENGTH] = {'y', 'e', 's', '\n','\0'};
	char program_exit_string14[STRING_LENGTH] = {'Y', 'E', 'S', '\n','\0'};
	char program_exit_string15[STRING_LENGTH] = {'N', 'o', '\n','\0'};
	char program_exit_string16[STRING_LENGTH] = {'n', 'o', '\n','\0'};
	char program_exit_string17[STRING_LENGTH] = {'N', 'O', '\n','\0'};
	char program_exit_string18[STRING_LENGTH] = {'N', '\n','\0'};
	char program_exit_string19[STRING_LENGTH] = {'n', '\n','\0'};

	level_counter = 1;
	password_length_easy = 5;
	password_length_medium = 10;
	password_length_hard = 15;

		do {

			if(difficulty_level == 1){

				system("clear");
				printf("		Diffculty: EASY\n");
				printf("level %d\n", level_counter);
				printf("Try and write this without looking:\n");	
				printf("Write Quit/Exit to terminate.");
				printf("\n\n\n\n");	

					for(	function_loop_counter1 = password_length_easy; 
						    function_loop_counter1 > 0;
						    function_loop_counter1--){
							printf("-");
					}

					printf("\n");

					for(	function_loop_counter1 =  0;
						    function_loop_counter1 < password_length_easy;
						    function_loop_counter1++    ){

						random_password[function_loop_counter1] = 
						(rand() % (122 - 97) + 97);
						random_password[function_loop_counter1 + 1] = '\n';
						random_password[function_loop_counter1 + 2] =  '\0';
						printf("%c", random_password[function_loop_counter1]);
					}

					printf("\n");

					for(	function_loop_counter1 = password_length_easy; 
						    function_loop_counter1 > 0;
						    function_loop_counter1--){
							printf("-");
					}

				printf("\n\n\n\n");
				system("stty -echo");
				fgets(function_user_inputted_string, STRING_LENGTH, stdin);
				system("stty echo");
				compare_result = strcmp(random_password, function_user_inputted_string);
				
				if (	(strcmp(function_user_inputted_string, program_exit_string1) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string2) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string3) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string4) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string5) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string6) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string7) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string8) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string9) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string10) == 0) ){
						exit_value = 0;
				}

					if(compare_result == 0){
						system("clear");
						printf("Success!\n");
						printf("Try the NEXT level!\n");
						password_length_easy++;
						level_counter++;
						getchar();
					}
					else if(compare_result != 0 && exit_value != 0){
						system("clear");
						printf("Failure!\n");
						printf("do you want to keep going?(yes/no)\n");
						fgets(function_user_inputted_string, STRING_LENGTH, stdin);
							if(	(strcmp(function_user_inputted_string, program_exit_string16)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string17)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string18)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string19)  == 0) ){	
								exit_function();
							}
					}
					else if(exit_value == 0){
						exit_function();
					}
			}
			else if(difficulty_level == 2){

				system("clear");
				printf("		Diffculty: Medium\n");
				printf("level %d\n", level_counter);
				printf("Try and write this without looking:\n");
				printf("Write Quit/Exit to terminate.");
				printf("\n\n\n\n");

					for(	function_loop_counter1 = password_length_medium; 
						    function_loop_counter1 > 0;
						    function_loop_counter1--){
							printf("-");
					}
					printf("\n");

					for(	function_loop_counter1 =  0;
						    function_loop_counter1 < 10;
						    function_loop_counter1++    ){

						random_password[function_loop_counter1] = 
						(rand() % (122 - 65) + 65);
							if(	(random_password[function_loop_counter1] == 91) ||
								(random_password[function_loop_counter1] == 92) || 
								(random_password[function_loop_counter1] == 93) ||
								(random_password[function_loop_counter1] == 94) ||
								(random_password[function_loop_counter1] == 95) ||
								(random_password[function_loop_counter1] == 96) 
							  ){
								/*
								 * 65 is the ASCII value for A
								 * for simplicity.
								 * */
								random_password[function_loop_counter1] = 65; 
							}
						random_password[function_loop_counter1 + 1] = '\n';
						random_password[function_loop_counter1 + 2] =  '\0';
						printf("%c", random_password[function_loop_counter1]);
					}

					printf("\n");

					for(	function_loop_counter1 = password_length_medium; 
						    function_loop_counter1 > 0;
						    function_loop_counter1--){
							printf("-");
					}
				printf("\n\n\n\n");
				system("stty -echo");
				fgets(function_user_inputted_string, STRING_LENGTH, stdin);
				system("stty echo");
				compare_result = strcmp(random_password, function_user_inputted_string);

				if (	(strcmp(function_user_inputted_string, program_exit_string1) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string2) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string3) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string4) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string5) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string6) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string7) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string8) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string9) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string10) == 0) ){
						exit_value = 0;
				}

					if(compare_result == 0){
						system("clear");
						printf("Success!\n");
						printf("Try the NEXT level!\n");
						password_length_medium++;
						level_counter++;
						getchar();
					}
					else if(compare_result != 0 && exit_value != 0){
						system("clear");
						printf("Failure!\n");
						printf("do you want to keep going?(yes/no)\n");
						fgets(function_user_inputted_string, STRING_LENGTH, stdin);
							if(	(strcmp(function_user_inputted_string, program_exit_string16)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string17)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string18)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string19)  == 0) ){	
								exit_function();
							}
                    }
					else if(exit_value == 0){
						exit_function();
					}
			}
			else if(difficulty_level == 3){


				system("clear");
				printf("		Diffculty: HARD\n");
				printf("level %d\n", level_counter);
				printf("Try and write this without looking:\n");	
				printf("Write Quit/Exit to terminate.");
				printf("\n\n\n\n");	

					for(	function_loop_counter1 = password_length_hard; 
						    function_loop_counter1 > 0;
						    function_loop_counter1--){
							printf("-");
					}
					printf("\n");

						for(	function_loop_counter1 =  0;
						        function_loop_counter1 < 15;
						        function_loop_counter1++    ){

						random_password[function_loop_counter1] = 
						(rand() % (126 - 33) + 33);
						random_password[function_loop_counter1 + 1] = '\n';
						random_password[function_loop_counter1 + 2] =  '\0';
						printf("%c", random_password[function_loop_counter1]);
					}

					printf("\n");
					for(	function_loop_counter1 = password_length_hard; 
						    function_loop_counter1 > 0;
						    function_loop_counter1--){
							printf("-");
					}


				printf("\n");
				system("stty -echo");
				fgets(function_user_inputted_string, STRING_LENGTH, stdin);
				system("stty echo");
				compare_result = strcmp(random_password, function_user_inputted_string);

				if (	(strcmp(function_user_inputted_string, program_exit_string1) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string2) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string3) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string4) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string5) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string6) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string7) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string8) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string9) == 0) ||
					(strcmp(function_user_inputted_string, program_exit_string10) == 0) ){
						exit_value = 0;
				}

					if(compare_result == 0){
						system("clear");
						printf("Success!\n");
						printf("Try the NEXT level!\n");
						password_length_hard++;
						level_counter++;
						getchar();
					}
					else if(compare_result != 0 && exit_value != 0){
						system("clear");
						printf("Failure!\n");
						printf("do you want to keep going?(yes/no)\n");
						fgets(function_user_inputted_string, STRING_LENGTH, stdin);
							if(	(strcmp(function_user_inputted_string, program_exit_string16)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string17)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string18)  == 0) ||
								(strcmp(function_user_inputted_string, program_exit_string19)  == 0) ){	
								exit_function();
							}
                    }
					else if(exit_value == 0){
						exit_function();
					}
			}
			else{
				system("clear");
				printf("Error! Please select Easy, Medium, Hard or High Score from the Main Menu.\n");
				getchar();
				difficulty_level = difficulty_function();
			}
	
		}

		while (exit_value != 0);
}

void exit_function(){

	system("clear");
	printf("Would you like to save your points to the high score?\n");

	system("clear");
	printf("-----------------------\n");
	printf("|Thank you for playing!|\n");
	printf("-----------------------\n");
	printf("\n\n\n");
	printf("Director:			Per Stoor\n");
	printf("Producer:			Per Stoor\n");
	printf("Writer:				Per Stoor\n");
	printf("Co-Writer:			Nikki Pormento Stoor\n");
	printf("*Although this is contested...\n");
	printf("Editor:				Per Stoor\n");
	printf("Programmer:			Per Stoor\n");
	printf("Head of Quality Assurance:	Nikki Pormento Stoor\n");
	printf("Lead Tester:			Nikki Pormento Stoor\n");
	printf("Office Inspiration:		Lucas Henrik Pormento Stoor\n");
	printf("\n\n");
	printf("Pers Password Puzzle will return!\n");
	printf("\n\n\n\n\n");
	printf("Press Enter to quit");
	getchar();
	system("clear");

}

void menu_arrow(int real_position, int next_position){

	if(real_position == next_position){
		printf(">>-----> - ");
	}
	else{
		printf("           ");
	}
}
