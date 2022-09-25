#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream file_xlsx;
    file_xlsx.open("new_excel.xlsx");

    if(!file_xlsx.is_open()){
        cout<<"Excel no abierto"<<endl;
        exit(0);
    }
    file_xlsx<<"Ejercicio_1\t\tEjercicio_2"<<endl;
    file_xlsx<<"1\t\t2"<<endl;
    file_xlsx.close();
    return 0;
}