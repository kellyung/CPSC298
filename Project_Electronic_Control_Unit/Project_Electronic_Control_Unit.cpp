/// @file Project_Electronic_Control_Unit.cpp
/// @brief Implementation file for ElectronicControlUnit class
/// @author kelung@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>


class ElectronicControlUnit
{
public:
    ElectronicControlUnit() {}
    virtual ~ElectronicControlUnit() {}
    
    void handleCommand(char cCommand);
    
private:
    bool m_bActivatedHydraulicJacks;
    bool m_bActivatedBeltTires;
    bool m_bActivatedIRIllumination;
    
    void actuateHydraulicJacks() {
        if (m_bActivatedHydraulicJacks == true) {
            m_bActivatedHydraulicJacks = false;
            std::cout << "Hydraulic Jacks deactivated" << std::endl;
        }
        else if ((m_bActivatedHydraulicJacks == false) && (m_bActivatedBeltTires == true)) {
            m_bActivatedHydraulicJacks = true;
            std::cout << "Hydraulic Jacks activated" << std::endl;
            m_bActivatedBeltTires = false;
            std::cout << "Belt Tires deactivated" << std::endl;
        }
        else {
            m_bActivatedHydraulicJacks = true;
            std::cout << "Hydraulic Jacks activated" << std::endl;
        }
    }
    
    void actuateBeltTires() {
        if (m_bActivatedBeltTires == true) {
            m_bActivatedBeltTires = false;
            std::cout << "Belt Tires deactivated" << std::endl;
        }
        else {
            m_bActivatedBeltTires = true;
            std::cout << "Belt Tires activated" << std::endl;
        }
    }
    
    void actuateIRIllumination() {
        if (m_bActivatedIRIllumination == true) {
            m_bActivatedIRIllumination = false;
            std::cout << "Infrared Illumination deactivated" << std::endl;
        }
        else {
            m_bActivatedIRIllumination = true;
            std::cout << "Infrared Illumination activated" << std::endl;
        }
    }
};


    
void ElectronicControlUnit::handleCommand(char cCommand)
{
    switch (cCommand)
    {
        case 'A':
            actuateHydraulicJacks();
            break;
        case 'B':
            actuateBeltTires();
            break;
        case 'E':
            actuateIRIllumination();
            
    }
}

int main() {
    char command = ' ';
    
    
    while (command != 'X') {
        std::cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << std::endl;
        std::cout << "      (A)" << std::endl;
        std::cout << "  (F) (G) (B)" << std::endl;
        std::cout << "  (E)     (C)" << std::endl;
        std::cout << "      (D)" << std::endl;
        
        std::cin >> command;
        
        if (command != 'X') {
            ElectronicControlUnit Mach_V;
            Mach_V.handleCommand(command);
        }
    }
    
    return 0;
}
