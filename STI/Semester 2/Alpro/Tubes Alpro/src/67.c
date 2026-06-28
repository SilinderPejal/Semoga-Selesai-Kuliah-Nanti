#include <stdio.h>
#include "67.h"

void rokunana(char *args) {
    (void) args;
    static int asciiIndex = 0;

    if (asciiIndex == 0) {
       
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠈⠉⣠⣤⣤⣄⠈⠁⠒⢤⣤⣤⡀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿\n");
        printf("⠀⠀⣠⣶⣿⣿⣶⣎⠁⠀⠀⠀⠀⠻⠋⠁⠈⠀⠀⠀⠈⠉⠻⡇⠀⠀⠀⠀⠛⠛⠛⠛⠛⢻⣿⣿⣿⠟⠁\n");
        printf("⠀⣼⣿⡟⠉⡹⡿⡿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢄⠀⠀⠀⠑⢜⣆⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⠋⠀⠀\n");
        printf("⢠⣿⣿⣧⣶⣷⣦⣄⠀⠀⠀⠀⠀⣀⣠⢤⠤⠤⠤⣵⣤⣤⠐⢒⡏⡄⠀⠀⠀⠀⠀⣼⣿⣿⣿⠃⠀⠀⠀\n");
        printf("⢸⣿⣿⡟⡍⠙⣿⣿⡆⠀⠀⠀⠸⡁⢿⣿⠇⠀⠀⣼⠿⠿⠀⢠⡟⡇⠀⠀⠀⠀⣰⣿⣿⣿⡇⠀⠀⠀⠀\n");
        printf("⠈⣿⣿⡆⣇⢀⣿⣿⡇⠀⠀⠀⠀⠑⠤⣀⡀⠤⠊⠀⠑⠂⠰⠟⠁⡇⠀⠀⠀⢀⣿⣿⣿⣿⠁⠀⠀⠀⠀\n");
        printf("⠀⠙⢿⣿⣾⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀⠀⢠⠁⡹⠋⠩⣭⣤⣤⡀⠀⠀\n");
        printf("⠀⠀⠀⠉⢹⣏⡉⢦⠀⠀⠀⠀⠀⠀⢤⠄⣀⣀⣀⣀⣀⣀⡀⢀⠆⠀⠀⠀⣂⠒⠂⢉⠐⠚⠚⢲⠇⠀⠀\n");
        printf("⠀⡔⠀⠏⠓⢷⣼⡿⡓⡦⡀⠀⠀⠀⠀⠀⣠⣀⣀⡀⠀⠀⢠⠎⠀⠀⠀⠀⠙⠛⠋⠉⠉⠉⠉⠁⠀⠀⠀\n");
        printf("⠀⠈⠈⠑⠒⠛⢇⣨⣿⣼⣃⡀⠀⠀⠀⠀⠀⠉⠀⠀⣀⠴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠷⠶⠶⠶⠶⠶⢒⣉⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⡀⠀⠀⠀⡟⢿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⠁⠀⠀⡇⠀⢻⡿⣿⣶⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠟⠈⡻⣿⡿⣶⠤⢼⣧⣴⡅⠉⠋⡁⣀⣌⣹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣄⡜⠀⠘⠋⠀⣠⣆⣨⣯⠓⠯⠩⠭⠷⠛⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠺⠯⣛⣉⣭⠱⠤⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    }

    else if (asciiIndex == 1) {

        printf("⠀⠀⢀⠤⣂⣤⣬⣭⣭⣭⣔⡠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠔⣵⣾⣿⣿⣿⢿⣿⣿⣿⣿⣎⢂⠀⢲⣤⣤⣤⣤⣀⣒⣒⣒⣒⣂⡠⠤⠤⣄\n");
        printf("⠐⣾⣿⣿⣿⡏⣾⡿⢎⣛⣫⣭⣴⣾⠆⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢼\n");
        printf("⡇⣿⣿⣿⣿⣟⡿⢀⣐⣻⣛⡩⢁⠀⠀⣘⣛⣛⡛⠿⠿⠿⢿⣿⣿⣿⣿⣿⢟⣾\n");
        printf("⡇⣿⣿⣿⣿⣷⣾⣿⣿⣿⣿⣿⣶⡕⠄⠉⠛⠛⠛⠛⡻⣣⣾⣿⣿⣿⢟⣵⣿⠛\n");
        printf("⠃⣿⣿⣿⣿⣿⢋⣥⠭⡻⣿⣿⣿⣿⡌⡄⠀⠀⠀⡐⣼⣿⣿⣿⡿⣣⣾⠏⠀⠀\n");
        printf("⠨⢻⣿⣿⣿⣧⢻⠁⠀⠘⢸⣿⣿⣿⡇⣿⠀⠀⠌⣼⣿⣿⣿⡿⢱⣿⠃⠀⠀⠀\n");
        printf("⠀⢦⢻⣿⣿⣿⣦⣐⣀⣊⣼⣿⣿⡿⢱⡿⠀⠰⣸⣿⣿⣿⣿⢣⣿⠃⠀⠀⠀⠀\n");
        printf("⠀⠀⠣⣙⠿⣿⣿⣿⣿⣿⣿⠿⢛⣵⡿⠃⢀⢃⣿⣿⣿⣿⡟⣾⡇⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠈⠛⠶⣮⣭⣭⣴⣶⡿⠿⠋⠀⠀⢨⣘⣿⡻⠿⠿⢇⣿⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⢀⠔⠒⠂⠠⠤⠭⡀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠛⠛⠛⠻⠃⠀⠀⠀⠀⠀⠀\n"); 
        printf("⢀⠆⠁⠀⡄⠀⠀⠀⠀⠈⢂⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠒⠁⠀⠀⠒⢤⡀⠀⠀\n");
        printf("⠣⠤⢤⠞⠂⠀⣀⠰⠃⠀⠘⣆⢀⣀⠀⠀⠀⠀⢀⠎⠀⢠⡀⠀⠀⠀⢀⠀⠙⡀\n");
        printf("⠀⠀⢸⠀⠈⠭⡀⢈⣡⠔⢶⠁⣹⢩⠃⠀⢀⠀⢸⠀⠀⠀⣑⣠⣤⠀⠙⡦⣀⠜\n");
        printf("⠀⠀⠀⠣⠀⢂⠞⠱⠴⣈⡸⠰⢇⠘⠀⠰⡭⠷⢝⡤⣂⣄⠒⢤⡐⠀⠀⡇⠀⠀\n");
        printf("⠀⠀⠀⠀⠱⠄⣀⢜⢁⡠⠥⠊⠀⠀⠀⠀⠡⡘⡄⠐⡂⠘⢌⡀⠉⠂⡸⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠄⠹⢅⣀⠹⠒⠊⠀⠀⠀\n");
    }

    else {

        printf(" 666666   777777\n");
        printf("66           77 \n");
        printf("I literally cannot do this anymore. I am at my limit. 67. Six. Seven. It started as a joke. Just a funny number. Just a funny number that a kid did in that damn video. But it kept popping up in my reels. What the hell is going on?\\n");
        printf("I ask myself. At first, I thought it was funny. But I kept seeing it. Not by the major but it was JUST SIX SEVEN AFTER SIX SEVENS. I kept blocking those accounts. Nothing worked. I tried a new account altogether. It still appeared. I even made a newer account with a VPN. NOTHING. WORKS.\\n\\n");
        printf("\"SIX SEVENN!\" Haha. Funny. Right? WRONG. This number has systematically dismantled every single aspect of my already pathetic life.\\n\\n");
        printf("I'm a father of two kids. They're the ones who's always stuck to their screens 26/7. I tried asking them how to stop it or at the very least explain what it means. I didn't get a clear answer. Instead, they mimic that blonde guy's hand movements and kept saying \\\"SIX SEVEN\\\" in the most obnoxious tone possible. I felt like crying.\\n\\n");
        printf("I lost my six-figure job last week. I tried to ignore this whole six seven nonsense and just go to my job. We were in the middle of the most important meeting in the company's history. The CFO pulls up the quarterly projections. The presentation hits a page that showed a pie chart. I look at the screen. The percentage? 67 percent out of whatever the topic was.\\n");
        printf("I didn't place it there. I swear I didn't. I swear I remember deliberately putting it as 66 percent just to prevent this exact scenario.\\n\\n");
        printf("I didn't mean to do it. It was a reflex. I swear. I slammed my hand on the mahogany table and screamed \\\"SIX SEVENNN\\\" at the top of my lungs. I started laughing hysterically, pointing at the screen yelling \\\"SIX SEVEN! SIX SEVEN! SIX SEVEN\\\" at the board of directors. Security escorted me out while I was still trying to explain the meme to those old wrinkly dudes.\\n\\n");
        printf("My career is utterly over. I can't even get hired at a cashier job because I'm blacklisted from the local job market. I have ruined my reputation and I cannot fix it no matter how much I beg for forgiveness.\\n\\n");
        printf("But it didn't stop there. My wife left me yesterday. We were driving to see her parents. I looked at the dashboard. The temperature outside? 67 degrees. I started sweating. I looked at the speedometer. 67 mph. I started hyperventilating. I couldn't help myself.\\n");
        printf("I involuntarily moved my hands up and down while saying six seven. I pulled the car over on the highway and refused to drive until the temperature dropped to 66 or rose to 68. She told me I need professional help. She took the ring back. I lost the divorce. I lost the kids. I lost all of my money. I'm dirt poor.\\n\\n");
        printf("I see it everywhere now. My phone battery? 67 percent. The change in my pocket? 67 cents. The page number in my book? 67. I can’t sleep. I can’t eat. I close my eyes and I just see the number floating in the void. It haunts me. It mocks me.\\n");
        printf("I am a shell of a man, destroyed by a double-digit integer. Is this what god does to his strongest soldier? I can't take it.\\n\\n");
        printf("SIX SEVENNNN SIX. SEVEN. 67 67 67 67 67 GOD DAMN IT SIX SEVEN SIX SEVEN SEX SEVEN SIX SEVEN SIX SEVENNN SIX SEVENNNN SIX SEVENNNN SIX SEVENNNN SIX SEVENNNN\\n");
    } // ⁶🤷⁷

    asciiIndex++;

    if (asciiIndex >= 3) {
        asciiIndex = 0;
    }
}