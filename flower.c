#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to get a random love message
const char* get_message() {
    const char *messages[] = {
        "I love you Meow!",
        "You mean the world to me.",
        "My love grows for you every day. just like this flower",
        "You are my favorite person.",
        "I am so lucky to have you.",
        "Just a little reminder that I adore you.",
        "You make everything better.",
	"I love you Sampoorna",
	"Thanks for burning yourself and giving me light, you are my candle."
    };
    
    // Calculate the number of messages in the array
    int num_messages = sizeof(messages) / sizeof(messages[0]);
    
    // Pick a random index
    int random_index = rand() % num_messages;
    return messages[random_index];
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Grab our random message for this run
    const char* chosen_message = get_message();

    // Define the frames of the ASCII animation
    const char *frames[] = {
        // Frame 1: A little sprout
        "\n\n\n\n"
        "       .\n"
        "      / \\\n"
        "    =======\n",

        // Frame 2: Growing taller
        "\n\n\n"
        "       |\n"
        "      \\|/\n"
        "       |\n"
        "    =======\n",

        // Frame 3: A bud appears
        "\n\n"
        "      ( )\n"
        "       |\n"
        "     \\ | /\n"
        "      \\|/\n"
        "    =======\n",

        // Frame 4: The flower blooms
        "\n"
        "     _(_)_\n"
        "    (_)@(_)\n"
        "      (_)\\\n"
        "       |\n"
        "     \\ | /\n"
        "      \\|/\n"
        "    =======\n"
    };

    int num_frames = sizeof(frames) / sizeof(frames[0]);

    // Animation loop
    for (int i = 0; i < num_frames; i++) {
        // Clear the terminal screen (Linux/Unix specific)
        system("clear");
        
        // Print the persistent message at the top
        printf("\n  *** %s ***\n", chosen_message);
        
        // Print the current frame of the flower
        printf("%s", frames[i]);
        
        // Flush the output buffer to ensure it prints immediately
        fflush(stdout);
        
        // Pause for 800,000 microseconds (0.8 seconds)
        usleep(800000); 
    }

    printf("\n");
    return 0;
}
