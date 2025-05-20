/*
 * ‹ ¡®à â®à­ ï à ¡®â  ü3.1
 * ’¥¬ : "ˆáá«¥¤®¢ ­¨¥ äã­ªæ¨© ‘++ ¢ IDE (¨­â¥£à¨à®¢ ­­®© áà¥¤¥ à §à ¡®âª¨) Qt Creator"
 *  §à ¡®âç¨ª: ‚ á¨­ ‘¥à£¥©
 * ƒàã¯¯ : gr_cpp318
 * OS: Windows
 * locale (ª®¤¨à®¢ª ): ibm866
 */

#include "QApplication.h"
#include <iostream>
#include "probabilities.h"
#include "initialization.h"
#include "animals.h"
#include "min_max.h"
#include "type_cast.h"
#include "elevator.h"
#include "printChar.h"
#include "animal_menu.h"

using namespace std;

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 1
void task1() {
    std::cout << "‡ ¤ ­¨¥ 1" << std::endl;
    calculate_probabilities();
}

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 2
void task2() {
    std::cout << "‡ ¤ ­¨¥ 2" << std::endl;
    testPrintChar();
}

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 3
void task3() {
    std::cout << "‡ ¤ ­¨¥ 3" << std::endl;
    demonstrate_initialization();
}

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 4
void task4() {
    std::cout << "‡ ¤ ­¨¥ 4" << std::endl;
    showAnimalMenu(); // ‚ë§®¢ äã­ªæ¨¨ ¤«ï ®â®¡à ¦¥­¨ï ¨ ®¡à ¡®âª¨ ¢ë¡®à  ¦¨¢®â­®£®
}

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 5
void task5() {
    std::cout << "‡ ¤ ­¨¥ 5" << std::endl;
    find_min_max();
}

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 6
void task6() {
    std::cout << "‡ ¤ ­¨¥ 6" << std::endl;
    demonstrate_type_cast();
}

// ”ã­ªæ¨ï ¤«ï § ¤ ­¨ï 7
void task7() {
    std::cout << "‡ ¤ ­¨¥ 7" << std::endl;
    virtual_elevator();
}


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int choice;

    while (true) {
        // Žá­®¢­®¥ ¬¥­î
        std::cout << "\n‚ë¡¥à¨â¥ § ¤ ­¨¥ (1-7) ¨«¨ 0 ¤«ï ¢ëå®¤ : " << std::endl;
        std::cout << "1. ‚ëç¨á«¥­¨¥ ¢¥à®ïâ­®áâ¨" << std::endl;
        std::cout << "2. à¨¢¥¤¥­¨¥ ¢ à¨ ­â®¢ ¢ë§®¢ " << std::endl;
        std::cout << "3. ¤¥¬®­áâà æ¨¨ à §«¨ç­ëå â¨¯®¢ ¨­¨æ¨ «¨§ æ¨¨" << std::endl;
        std::cout << "4. ‚ë¡®à ¦¨¢®â­®£®" << std::endl;
        std::cout << "5.  ©â¨ ¡®«ìè¥¥/¬¥­ìè¥¥" << std::endl;
        std::cout << "6. à¥®¡à §®¢ ­¨¥ â¨¯®¢ ¤ ­­ëå" << std::endl;
        std::cout << "7. ‚¨àâã «ì­ë© «¨äâ" << std::endl;
        std::cout << "0. ‚ëå®¤ ¨§ ¯à®£à ¬¬ë" << std::endl;
        std::cin >> choice;

        if ((choice >= 1 && choice <= 7) || choice == 0) {
            switch (choice) {
                case 1: task1(); break;
                case 2: task2(); break;
                case 3: task3(); break;
                case 4: task4(); break;
                case 5: task5(); break;
                case 6: task6(); break;
                case 7: task7(); break;
                case 0:
                    std::cout << "‚ëå®¤ ¨§ ¯à®£à ¬¬ë." << std::endl;
                    return 0; // à®áâ® ¢ëå®¤¨¬ ¨§ äã­ªæ¨¨ main
            }
        } else {
            std::cout << "¥¢¥à­ë© ¢ë¡®à § ¤ ­¨ï. ®¦ «ã©áâ , ¯®¯à®¡ã©â¥ á­®¢ ." << std::endl;
        }
    }
    return app.exec();
}
