#include <iostream>
#include <fstream>

using namespace std;

/*
    Использован метод умножения для каждого эелемента массива и после
    все желменты собраны в хэщ-сумму операцией побитового XOR.
    h(k) = [N*{k*A}], где {} - дробная часть числа, [] - целая часть числа.
    N и A - заданные мной значения. А взято из золотого сечения (sqrt(5)-1)/2,
    N - простое число, k - элементы массива
*/
//var_1
template<typename t>
int hash_func(t& mas, int len) {
    int N = 251;
    double A = 0.618033;
    int res = 255;
    for(int i = 0; i < len; i++) {
        double var = mas[i]*A;
        var = var - int(var);
        int h = int(N*var);
        res = res^h;
    }
    return res;
}

//var_2
template<typename t>
void swap(t* a, t* b) {
    t c = *a;
    *a = *b;
    *b = c;
}

/* 
    This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot 
*/
template<typename t>
int partition(t* mas, int low, int high) {
    t pivot = mas[high];
    int i = low - 1; //Index of smaller element

    for(int j = low; j < high; j++) {
        //move all evements, taht smaller, than pivot to the left
        if(mas[j] <= pivot) {
            i++;
            swap(&mas[i], &mas[j]);
        }
    }
    swap(&mas[i+1], &mas[high]);
    return i + 1;
}

//recursive sort function  
template<typename t>
void quick_sort(t mas, int low, int high) {
    if(low < high) {
        int pi = partition(mas, low, high);

        quick_sort(mas, low, pi-1);
        quick_sort(mas, pi+1, high);
    }
}

//var_3
template<typename t>
void Printf(t& mas, int len, ofstream &out, char* sep = " ") {
     for(int i = 0; i < len-1; i++) {
         out << mas[i] << sep;
     }
     out << mas[len-1] << endl;

}

int main() {
    const int len = 5;
    
    int mas_int[len];
    mas_int[0] = 5;
    mas_int[1] = 3;
    mas_int[2] = 6;
    mas_int[3] = 5;
    mas_int[4] = 9;

    char mas_char[len];
    mas_char[0] = 'a';
    mas_char[1] = 'c';
    mas_char[2] = 'h';
    mas_char[3] = 'y';
    mas_char[4] = 'i';
    
    double mas_double[len];
    mas_double[0] = 1.5;
    mas_double[1] = 3.6;
    mas_double[2] = 2.8;
    mas_double[3] = 9.8;
    mas_double[4] = 0.5;

    bool mas_bool[len];
    mas_bool[0] = 0;
    mas_bool[1] = 1;
    mas_bool[2] = true;
    mas_bool[3] = false;
    mas_bool[4] = 1;

    float mas_float[len];
    mas_float[0] = 1.2;
    mas_float[1] = 2.3;
    mas_float[2] = 3.4;
    mas_float[3] = 1.3;
    mas_float[4] = 2.5;

    ofstream out;
    out.open("out.txt");

    //var_3
    out << "var_3 <-------------------------" << endl;
    Printf(mas_int, len, out, " int ");
    Printf(mas_char, len, out);
    Printf(mas_double, len, out, " double ");
    Printf(mas_bool, len, out);
    Printf(mas_float, len, out, " float ");

    //var_2
    out << "var_2 <-------------------------" << endl;
    quick_sort(mas_int, 0, len-1);
    Printf(mas_int, len, out);
    quick_sort(mas_char, 0, len-1);
    Printf(mas_char, len, out);
    quick_sort(mas_double, 0, len-1);
    Printf(mas_double, len, out);
    quick_sort(mas_bool, 0, len-1);
    Printf(mas_bool, len, out);
    quick_sort(mas_float, 0, len-1);
    Printf(mas_float, len, out);

    //var_1
    out << "var_1 <-------------------------" << endl;
    out << hash_func(mas_int, len) << endl;
    out << hash_func(mas_char, len) << endl;
    out << hash_func(mas_double, len) << endl;
    out << hash_func(mas_bool, len) << endl;
    out << hash_func(mas_float, len) << endl;

    out.close();
    return 0;
}