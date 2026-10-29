#include <iostream>
#include <string>


using namespace std;


struct SoilData {


    double landSize;
    int season;
    
    int soilType; 
    double bulkDensity; 
    double currentPh;
    double desiredPh;
    string chemicalDeficiency;   
    
    double materialPrice;              
};


void readInputs(SoilData &data) {
    
    cout << "=====================================================================\n";
    cout << "SOILOSION : MATERIAL QTY. & COSTS CALCULATOR FOR ERODED SOIL RECOVERY       \n";
    cout << "=====================================================================\n\n";


    cout << "--- [ SITE INFORMATION ] -----------------------\n";
    
    cout << "  > Enter eroded land size (in unit?)   : ";
    cin >> data.landSize;


    cout << "  > Select current season (1 = Rainy || 2 = Dry): ";
    cin >> data.season;


    cout << "\n--- [ SOIL METRICS ] ---------------------------\n";
    
    cout << "  > Select soil type:\n";
    cout << "      [1] Clay\n";
    cout << "      [2] Loam\n";
    cout << "      [3] Sand\n";
    cout << "      [4] Silt\n";
    cout << "      Choice: ";
    cin >> data.soilType;


    cout << "  > Enter soil bulk density (in unit?)      : ";
    cin >> data.bulkDensity;


    cout << "  > Enter current pH level                  : ";
    cin >> data.currentPh;


    cout << "  > Enter desired pH level                  : ";
    cin >> data.desiredPh;


    cout << "  > Enter primary chemical deficiency       \n";
    cout << "    (Enter it one word: Nitrogen Phosphorus)  : ";
    cin >> data.chemicalDeficiency;


    cout << "\n--- [ MARKET DATA ] ----------------------------\n";
    
    cout << "  > Enter current material price (PHP/unit/quantity?)   : ";
    cin >> data.materialPrice;


    cout << "\n=====================================================================\n";
    cout << "      Data successfully recorded :) Proceeding to calculate...\n";
    cout << "=====================================================================\n\n";
}


int main() {
    
    SoilData inputData;
    
    readInputs(inputData);


    return 0;
}