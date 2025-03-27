/*
 * EECS 348 7 - C program for Football score possibilities...
 * Author: Viren Padarthi
 * Collaborators: None
 * Sources: Lecture slides, w3Schools, Grammarly, VSCode, Github
 * Created: 3/20/2025
 *Last Modified: 3/26/2025
 */

#include <stdio.h> // including required directery

void find_combinations(int score) {
    printf("\nPossible combinations of scoring plays for %d:\n", score);
    
    int td_2pt, td_fg, td, fg, safety; //these variables count each score type: 8pt,7pt,6pt,3pt,2pt
    
    // Loop trough all possible numbers of 8point plays (TD + 2pt)
    for (td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        // Loop through all possible numbers of 7point plays (tD + FG)
        for (td_fg = 0; td_fg * 7 <= score - td_2pt * 8; td_fg++) {
            // Loop all possible numbers of 6point plays (TD)
            for (td = 0; td * 6 <= score - td_2pt * 8 - td_fg * 7; td++) {
                // Loop through all possible numbers of 3point plays (FG)
                for (fg = 0; fg * 3 <= score - td_2pt * 8 - td_fg * 7 - td * 6; fg++) {
                    // Calculate remaining points for safeties
                    int remaining = score - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3;
                    
                    // If remaining points can be achieved with safeties (2 points each)
                    if (remaining >= 0 && remaining % 2 == 0) {
                        safety = remaining / 2;
                        //print this combination
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", 
                               td_2pt, td_fg, td, fg, safety);
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        //check if it should stop
        if (score <= 1) {
            break;
        }
        
        // if the input is invalid
        if (score < 0) {
            printf("Invalid score. Please enter a positive number.\n");
            continue;
        }
        
        // print all possible combinations
        find_combinations(score);
    }
    
    return 0;
}