//
//  main.cpp
//  Wealth Calculator
//
//  Created by Aaron Knoll on 7/25/17.
//  Licensed under the GNU GPLv3
//  (a copy of which is contained along with this application)
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string printValues(double dollaBills){
    
    string formattedCurrencyVal;
    stringstream stream;
    
    if(dollaBills / 1000000000 >= 1.0){
        stream << fixed << setprecision(2) << (dollaBills / 1000000000);
        formattedCurrencyVal = "$" + stream.str() + "B";
    }else if(dollaBills / 1000000 >= 1.0){
        stream << fixed << setprecision(2) << (dollaBills / 1000000);
        formattedCurrencyVal = "$" + stream.str() + "M";
    }else if(dollaBills / 1000 >= 1.0){
        stream << fixed << setprecision(2) << (dollaBills / 1000);
        formattedCurrencyVal = "$" + stream.str() + "K";
    }else{
        stream << fixed << setprecision(2) << dollaBills;
        formattedCurrencyVal = "$" + stream.str();
    }
    
    return formattedCurrencyVal;
}

int main(int argc, const char * argv[]) {
    
    while (1) {
        
        cout << "Would you like to perform a Simple or Advanced Simulation? S or A\t";
            char simMode;
            cin >> simMode;
        
        system("clear");
        
        
        cout << "At what AGE will you start investing?\t\t";
            int startingAge, ageCounter = 2;
            cin >> startingAge;
        
        cout << "What will be your INITIAL INVESTMENT ($)?\t";
            int initialInvestment;
            cin >> initialInvestment;
        
 //     cout << "What % of the PURCHASE PRICE is needed for a DOWN PAYMENT?\t";
        cout << "What is the necessary DOWN PAYMENT %?\t\t";
            double downPaymentPercentage;
            cin >> downPaymentPercentage;
        
        cout << "What is the assumed CAP RATE %?\t\t\t";
            double capRatePercentage;
            cin >> capRatePercentage;
        
        
        double targetAmt = 1000000000;
        int holdingPeriodDuration = 2;
        
        if (simMode == 'A' || simMode == 'a') {
            cout << "What is your TARGET AMT ($)?\t\t\t";
            
            int tmpTargetAmt;
                cin >> tmpTargetAmt;
            
            if (tmpTargetAmt > 0)
                targetAmt = tmpTargetAmt;
        
            cout << "How many years will you HOLD a property?\t";
            
            int tmpHoldingPeriodDuration;
                cin >> tmpHoldingPeriodDuration;
         
            if (tmpHoldingPeriodDuration > 0)
                holdingPeriodDuration = tmpHoldingPeriodDuration;
            
            ageCounter = holdingPeriodDuration;
        }

        
        double purchasePrice = initialInvestment / (downPaymentPercentage * .01);
        
        double annualCashReturn = capRatePercentage * .01 * purchasePrice;
        double returnAfterHoldingPeriod = holdingPeriodDuration * annualCashReturn;
        double runningTotal = returnAfterHoldingPeriod + initialInvestment;
        
        if (simMode == 'A' || simMode == 'a'){
            cout    << "\n" << left << setw(12) << "Down Payment" << " | " << setw(14) << "Purchase Price" << " | " << setw(18)
                    << "Annual Cash Return" << " | " << setw(25) << "Return after Holding Per." << " | " << setw(13) << "Running Total"
                    << " | " << setw(3) << "Age" << endl;
            cout    << "------------------------------------------------------------------------------------------------------"
                    << endl;
            
        }else{
            cout    << "\n" << left << setw(12) << "Down Payment" << " | " << setw(14) << "Purchase Price" << " | " << setw(18)
                    << "Annual Cash Return" << " | " << setw(19) << "Return after 2 Yrs." << " | " << setw(13) << "Running Total"
                    << " | " << setw(3) << "Age" << endl;
            cout    << "------------------------------------------------------------------------------------------------"
                    << endl;
        }
        
        while (runningTotal < targetAmt){

            if (simMode == 'A' || simMode == 'a'){
                cout    << setw(12) << printValues(initialInvestment) << " | " << setw(14) << printValues(purchasePrice) << " | "
                        << setw(18) << printValues(annualCashReturn) << " | " << setw(25) << printValues(returnAfterHoldingPeriod)
                        << " | " << setw(13) << printValues(runningTotal) << " | " << setw(3) << startingAge + ageCounter << endl;
            }else{
                cout    << setw(12) << printValues(initialInvestment) << " | " << setw(14) << printValues(purchasePrice) << " | "
                << setw(18) << printValues(annualCashReturn) << " | " << setw(19) << printValues(returnAfterHoldingPeriod)
                << " | " << setw(13) << printValues(runningTotal) << " | " << setw(3) << startingAge + ageCounter << endl;
            }
            
            initialInvestment = runningTotal;
            purchasePrice = initialInvestment / (downPaymentPercentage * .01);
            annualCashReturn = capRatePercentage * .01 * purchasePrice;
            returnAfterHoldingPeriod = holdingPeriodDuration * annualCashReturn;
            runningTotal = returnAfterHoldingPeriod + initialInvestment;
            
            ageCounter += holdingPeriodDuration;
            
        }
        
        if (simMode == 'A' || simMode == 'a'){
            cout    << setw(12) << printValues(initialInvestment) << " | " << setw(14) << printValues(purchasePrice) << " | "
            << setw(18) << printValues(annualCashReturn) << " | " << setw(25) << printValues(returnAfterHoldingPeriod) << " | "
            << setw(13) << printValues(runningTotal) << " | " << setw(3) << startingAge + ageCounter << "*\n" << endl;
            
            cout    << "By the looks of it, you'll reach your Target Amt AT or BEFORE the age of "
                    << startingAge + ageCounter << "!" << endl;
        
        }else{
            cout    << setw(12) << printValues(initialInvestment) << " | " << setw(14) << printValues(purchasePrice) << " | "
            << setw(18) << printValues(annualCashReturn) << " | " << setw(19) << printValues(returnAfterHoldingPeriod) << " | "
            << setw(13) << printValues(runningTotal) << " | " << setw(3) << startingAge + ageCounter << "*\n" << endl;
        
            cout    << "By the looks of it, you'll be a Billionaire AT or BEFORE the age of " << startingAge + ageCounter
                    << "!" << endl;
        }
            
        
        cout << "Would you like to perform another simulation? Y or N\t";
            char anotherSim;
            cin >> anotherSim;
        
        if (anotherSim == 'N' || anotherSim == 'n')
            break;
        
        system("clear");

    }
    
    return 0;

}
