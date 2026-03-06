#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct Token {
    string type;
    string value;
};

struct IRInstruction {
    string opcode;
    string operand1;
    string operand2;
};

unordered_map<string, string> keywords = {
    {"sankhya", "INT"},
    {"agar", "IF"},
    {"dikhao", "PRINT"}
};

bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

vector<Token> tokenizeLine(const string& line) {
    vector<Token> tokens;
    string word;
    stringstream ss(line);

    while (ss >> word) {
        if (keywords.count(word)) {
            tokens.push_back({keywords[word], word});
        } else if (isNumber(word)) {
            tokens.push_back({"NUMBER", word});
        } else if (isalpha(word[0])) {
            tokens.push_back({"IDENTIFIER", word});
        } else {
            tokens.push_back({"SYMBOL", word});
        }
    }
    return tokens;
}

IRInstruction generateIR(const vector<Token>& t) {

    // Declaration
    if (t.size() == 4 &&
        t[0].type == "INT" &&
        t[1].type == "IDENTIFIER" &&
        t[2].value == "=" &&
        t[3].type == "NUMBER") {

        return {"DECLARE", t[1].value, t[3].value};
    }

    // Print
    if (t.size() == 2 &&
        t[0].type == "PRINT" &&
        t[1].type == "IDENTIFIER") {

        return {"PRINT", t[1].value, ""};
    }

    // If
    if (t.size() == 4 &&
        t[0].type == "IF" &&
        t[1].type == "IDENTIFIER" &&
        t[2].value == ">" &&
        t[3].type == "NUMBER") {

        return {"IF", t[1].value, t[3].value};
    }

    return {"UNKNOWN", "", ""};
}

int main() {
    ifstream file("input.ml");
    if (!file) {
        cout << "input.ml not found\n";
        return 1;
    }

    string line;
    vector<IRInstruction> irList;

    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<Token> tokens = tokenizeLine(line);
        IRInstruction instr = generateIR(tokens);
        irList.push_back(instr);
    }

    cout << "=== INTERMEDIATE REPRESENTATION (IR) ===\n";

    for (const auto& instr : irList) {
        if (instr.opcode == "DECLARE")
            cout << "DECLARE " << instr.operand1 << " " << instr.operand2 << endl;

        else if (instr.opcode == "PRINT")
            cout << "PRINT " << instr.operand1 << endl;

        else if (instr.opcode == "IF")
            cout << "IF " << instr.operand1 << " > " << instr.operand2 << endl;

        else
            cout << "UNKNOWN INSTRUCTION" << endl;
    }

    // ===== IR ANALYSIS =====
    int declCount = 0, ifCount = 0, printCount = 0;

    for (const auto& instr : irList) {
        if (instr.opcode == "DECLARE") declCount++;
        if (instr.opcode == "IF") ifCount++;
        if (instr.opcode == "PRINT") printCount++;
    }

    cout << "\n=== IR ANALYSIS SUMMARY ===\n";
    cout << "Declarations: " << declCount << endl;
    cout << "IF Statements: " << ifCount << endl;
    cout << "Print Statements: " << printCount << endl;

    return 0;
}