/// @file <Musical_Note_Frequencies.cpp>
/// @brief <Computing frequency of musical notes>
/// @author <kelung@chapman.edu>

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    // equation used f(k,v) = fr * 2^(v + (k/12))
    // constants
    float reference_frequency = 16.35;
    float speed_of_sound = 345;
    
    // computing frequencies and wavelengths for each note
    float C0_frequency = reference_frequency * pow(2, 0 + (0/12));
    float C0_wavelength = (speed_of_sound*100)/C0_frequency;
    
    float Csharp0_frequency = reference_frequency * pow(2.0, 0 + (1.0/12.0));
    float Csharp0_wavelength = (speed_of_sound*100)/Csharp0_frequency;
    
    float D0_frequency = reference_frequency * pow(2.0, 0 + (2.0/12.0));
    float D0_wavelength = (speed_of_sound*100)/D0_frequency;
    
    float C4_frequency = reference_frequency * pow(2.0, 4.0 + (0/12.0));
    float C4_wavelength = (speed_of_sound*100)/C4_frequency;
    
    float Dsharp7_frequency = reference_frequency * pow(2.0, 7.0 + (3.0/12.0));
    float Dsharp7_wavelength = (speed_of_sound*100)/Dsharp7_frequency;
    
    float C8_frequency = reference_frequency * pow(2.0, 8.0 + (0/12.0));
    float C8_wavelength = (speed_of_sound*100)/C8_frequency;


    cout << "Reference Frequency: " << reference_frequency << " Hz" << endl;
    cout << "Speed of Sound: " << speed_of_sound << " m/s" << endl;
    // C0
    cout << "Note: C0; " << "nu: 0; " << "k: 0; " << "Frequency: " << C0_frequency << " Hz; " << "Wavelength: " << C0_wavelength << " cm" << endl;
    // C#0
    cout << "Note: C#0; " << "nu: 0; " << "k: 1; " << "Frequency: " << Csharp0_frequency << " Hz; " << "Wavelength: " << Csharp0_wavelength << " cm" << endl;
    // D0
    cout << "Note: D0; " << "nu: 0; " << "k: 2; " << "Frequency: " << D0_frequency << " Hz; " << "Wavelength: " << D0_wavelength << " cm" << endl;
    // C4
    cout << "Note: C4; " << "nu: 4; " << "k: 0; " << "Frequency: " << C4_frequency << " Hz; " << "Wavelength: " << C4_wavelength << " cm" << endl;
    // D#7
    cout << "Note: D#7; " << "nu: 7; " << "k: 3; " << "Frequency: " << Dsharp7_frequency << " Hz; " << "Wavelength: " << Dsharp7_wavelength << " cm" << endl;
    // C8
    cout << "Note: C8; " << "nu: 8; " << "k: 0; " << "Frequency: " << C8_frequency << " Hz; " << "Wavelength: " << C8_wavelength << " cm" << endl;
    return 0;
}
