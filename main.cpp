#include <iostream>

using namespace std;

void romanToDecimal();

int main()
{

    romanToDecimal();

    return 0;
}

void romanToDecimal(){

    string romanInput;

    do{

        int sum = 0;
        bool wrongInput;

        cout << "Put the number in roman format(All letters are capital):";
        cin >> romanInput;
        cout << endl;

        int decimalConvertion[romanInput.length()];

        for(int a = 0;a < romanInput.length();a++){

            char value = romanInput.at(a);

            if(value == 'I'){

                decimalConvertion[a] = 1;

            }
            else if(value == 'V'){

                decimalConvertion[a] = 5;

            }
            else if(value == 'X'){

                decimalConvertion[a] = 10;

            }
            else if(value == 'L'){

                decimalConvertion[a] = 50;

            }
            else if(value == 'C'){

                decimalConvertion[a] = 100;

            }
            else if(value == 'D'){

                decimalConvertion[a] = 500;

            }
            else if(value == 'M'){

                decimalConvertion[a] = 1000;

            }
            else{

                cout << "You gave a wrong input, please try again." << endl << endl;
                wrongInput = true;

            }

        }

        for(int b = 0;b < romanInput.length();b++){

            if(decimalConvertion[b] == decimalConvertion[b+1] && decimalConvertion[b] != decimalConvertion[b+2]){

                decimalConvertion[b+1] += decimalConvertion[b];
                decimalConvertion[b] = 0;

            }
            else if(decimalConvertion[b] == decimalConvertion[b+1] && decimalConvertion[b] == decimalConvertion[b+2]){

                decimalConvertion[b+2] += (decimalConvertion[b] + decimalConvertion[b+1]);
                decimalConvertion[b+1] = 0;
                decimalConvertion[b] = 0;

            }
            else if(decimalConvertion[b] < decimalConvertion[b+1] && b+1 < romanInput.length()){

                decimalConvertion[b+1] -= decimalConvertion[b];
                decimalConvertion[b] = 0;

            }

        }

        for(int c = 0;c < romanInput.length();c++){

            sum += decimalConvertion[c];

        }

        if(romanInput != "stop" && wrongInput != true){

            cout << endl << "Your result in decimal format:" << sum << endl << endl;

        }

    }while(romanInput != "stop");

}
