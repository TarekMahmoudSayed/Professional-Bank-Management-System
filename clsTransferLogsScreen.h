#pragma once
#include <iostream>
#include "clsScreen.h"
using namespace std;

class clsTransferLogsScreen : protected clsScreen{

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogsRecord TransferLogRecord) {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;


    }

public :

	static void ShowTransferLogs() {

		vector <clsBankClient::stTransferLogsRecord> vTransferLogs = clsBankClient::GetTransferLogsList();

        string Title = "Transfer Logs Screen";
        string SubTitle = "(" + to_string(vTransferLogs.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "DateTime/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogs.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogsRecord Record : vTransferLogs)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }




};

