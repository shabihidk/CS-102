#include<iostream>
#include<unistd.h>        
using namespace std;


void printHeart(string colorCode) {
    cout << colorCode;
    cout << "        ********       ********        \n";
    cout << "       *        *     *        *       \n";
    cout << "      *          *   *          *      \n";
    cout << "     *             *             *     \n";
    cout << "    *                             *    \n";
    cout << "    *                             *    \n";
    cout << "     *                           *     \n";
    cout << "      *                         *      \n";
    cout << "       *                       *       \n";
    cout << "        *                     *        \n";
    cout << "         *                   *         \n";
    cout << "          *                 *          \n";
    cout << "           *               *           \n";
    cout << "            *             *            \n";
    cout << "             *           *             \n";
    cout << "              *         *              \n";
    cout << "               *       *               \n";
    cout << "                *     *                \n";
    cout << "                 *   *                 \n";
    cout << "                  * *                  \n";
    cout << "                   *                   \n";
    cout << "\033[0m";
}
int main(){

string colors[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"};
cout<<"        ********       ********        \n";
sleep(1);
cout<<"       *        *     *        *       \n";
sleep(1);
cout<<"      *          *   *          *      \n";
sleep(1);
cout<<"     *             *             *     \n";
sleep(1);
cout<<"    *                             *    \n";
sleep(1);
cout<<"    *                             *    \n";
sleep(1);
cout<<"     *                           *     \n";
sleep(1);
cout<<"      *                         *      \n";
sleep(1);
cout<<"       *                       *       \n";
sleep(1);
cout<<"        *                     *        \n";
sleep(1);
cout<<"         *                   *         \n";
sleep(1);
cout<<"          *                 *          \n";
sleep(1);
cout<<"           *               *           \n";
sleep(1);
cout<<"            *             *            \n";
sleep(1);
cout<<"             *           *             \n";
sleep(1);
cout<<"              *         *              \n";
sleep(1);
cout<<"               *       *               \n";
sleep(1);
cout<<"                *     *                \n";
sleep(1);
cout<<"                 *   *                 \n";
sleep(1);
cout<<"                  * *                  \n";
sleep(1);
cout<<"                   *                   \n";
sleep(1);



  for (int i = 0; i < 5; ++i) {
        system("cls"); 
        printHeart(colors[i]);
        sleep(1);
    }
    
    system("cls");
    
cout<< " cookies for sale <3 ";

return 0;
}
