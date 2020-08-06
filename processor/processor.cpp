#include<bits/stdc++.h>
using namespace std;

int hexa2Decimal(string hexVal) 
{    
    int len = hexVal.length(); 
    int base = 1; 
    int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {     
        if (hexVal[i]>='0' && hexVal[i]<='9')
            dec_val += (hexVal[i] - 48)*base;

        else if (hexVal[i]>='A' && hexVal[i]<='F')
            dec_val += (hexVal[i] - 55)*base;

        base = base * 16; 
    } 
      
    return dec_val; 
}

string decToHexa(int num) 
{
    string str = "";
	char c;

	if((num / 16) < 9){
		c = ((num / 16) + 48);
		str += c;
	}
	else{
		c = ((num / 16) + 55);
		str += c;
	}

	if((num % 16) < 9){
		c = ((num % 16) + 48);
		str += c;
	}
	else {
		c = ((num % 16) + 55);
		str += c;
	}

    return str;
} 

class DCache{
public:
	int dcache[256];

	void initialize(){
		ifstream fin("DCache.txt");
		string s="";

		for(int i=0; i<256; i++){
			fin >> s;
			dcache[i] = hexa2Decimal(s);
		}
		fin.close();
	}
};

class ICache{
public:
	string icache[128];

	void initialize(){

		ifstream fin("ICache.txt");

		for(int i = 0; i < 128; i++)
			fin >> icache[i];

		fin.close();
	}
};

class RFile{
public:
	int rfile[16];

	void initialize(){
		ifstream fin("RF.txt");

		string s = "";
		for(int i = 0; i < 16; i++) {
			fin >> s;
			rfile[i] = hexa2Decimal(s);
		}
		fin.close();
	}
};

class Processor{
private:
	DCache dc;
	ICache ic;
	RFile rf;

	bool wc[16];
	int opcodes[4];
	int PC;
	bool active[5], dRAWstall;
	string IR, instructions[5], jumpInst;
	int dReg, A, B, RAWReg[2];
	int jOffset;
	bool RAWStall, jStall, halt, PCDecrement;
	int ALUOut[3], LMD, WBreg[4];
	int numInst, numRAWStalls, numjStalls;
	int IC[13];

public:
	Processor() {
		dc.initialize();
		ic.initialize();
		rf.initialize();

		PC = 0;
		
		RAWStall = false;
		jStall = false;
		halt = false;
		dRAWstall = false;
		
		numInst = 0;
		numRAWStalls = 0;
		numjStalls = 0;

		for(int i = 0; i < 13; i++)
			IC[i] = 0;

		for(int i = 0; i < 16; i++)
			wc[i] = false;

		for(int i = 0; i < 5; i++)
			active[i] = false;	
	}
	
	void IF(){
		if(RAWStall) {
			PC--;
			active[0] = false;
		}
		else if (jStall || halt) {
			active[0] = false;
			return;
		}
		else {
			active[0] = true;
		}
		IR = ic.icache[PC];
		PC++;
		instructions[0] = IR;
	}

	void ID(){
		if(!active[0]) {
			active[1] = false;
			return;
		}
		
		active[1] = true;
		instructions[1] = instructions[0];
		
		opcodes[0] = hexa2Decimal(IR.substr(0, 1));
		
		if(opcodes[0] <= 8) {
			dReg = hexa2Decimal(IR.substr(1, 1));
			A = hexa2Decimal(IR.substr(2, 1));
			B = hexa2Decimal(IR.substr(3, 1));

			if(opcodes[0] == 3) {
				A = dReg;
			}
			
			if(wc[A]) {
				RAWStall = true;
				RAWReg[0] = A;
			}
			if(((opcodes[0] != 8) || (opcodes[0] != 3) || (opcodes[0] != 6)) && (wc[B])) {
				if(!RAWStall){
					RAWStall = true;
					RAWReg[0] = B;
				}
				else{
					dRAWstall = true;
					RAWReg[1] = B;
				}
			}
			else{
				A = rf.rfile[A];
				if(opcodes[0] != 8) {
					B = rf.rfile[B];
				}
				wc[dReg] = true;
			}
		}
		
		else if(opcodes[0] == 9){
			dReg = hexa2Decimal(IR.substr(1, 1));
			A = hexa2Decimal(IR.substr(2, 1));
			B = hexa2Decimal(IR.substr(3, 1));
			
			if(wc[A]) {
				RAWStall = true;
				RAWReg[0] = A;
			}

			if(wc[dReg]){
				if(!RAWStall) {
					RAWStall = true;
					RAWReg[0] = dReg;
				}
				else {
					dRAWstall = true;
					RAWReg[1] = dReg;
				}
			}
			else
				A = rf.rfile[A];
		}
		
		else if(opcodes[0] == 10) {
			jOffset = hexa2Decimal(IR.substr(1, 2));
			if(jOffset >= 128) {
				//Adjusting for 2's complement
				jOffset -= 258;
			}
			
			jStall = true;
			jumpInst = instructions[1];                                                          
		}
		
		else if(opcodes[0] == 11) {
			A = hexa2Decimal(IR.substr(1, 1));
			if(wc[A]) {
				RAWStall = true;
				RAWReg[0] = A;
			}
			else {
				jOffset = hexa2Decimal(IR.substr(2, 2));
				if(jOffset >= 128) {
					//Adjusting for 2's complement
					jOffset -= 258;
				}
				jStall = true;
				jumpInst = instructions[1];
			}
		}
		
		else {
			halt = true;
		}
		
		WBreg[0] = dReg;
		
		if(RAWStall) {
			active[1] = false;
		}
	}

	void EX(){
		if(!active[1]) {
			if(jStall && (jumpInst == instructions[2])) {
				jStall = false;
				numjStalls++;
			}
			active[2] = false;
			return;
		}

		active[2] = true;
		instructions[2] = instructions[1];
		opcodes[1] = opcodes[0];
		WBreg[1] = WBreg[0];
		
		switch(opcodes[1]) {
			case 0:
				ALUOut[0] = A + B;
				break;
				
			case 1:
				ALUOut[0] = A - B;
				break;
				
			case 2:
				ALUOut[0] = A * B;
				break;
				
			case 3:
				ALUOut[0] = A + 1;
				break;
				
			case 4:
				ALUOut[0] = A & B;
				break;
				
			case 5:
				ALUOut[0] = A | B;
				break;
				
			case 6:
				ALUOut[0] = !A;
				break;
				
			case 7:
				ALUOut[0] = A ^ B;
				break;
				
			case 8:	
			case 9:
				ALUOut[0] = A + B;
				break;
				
			case 10:
				PC = PC + jOffset - 1;
				break;
				
			case 11:
				if(A == 0) {
					PC = PC + jOffset - 1;
				}
				break;	
		}
	}
	void MEM() {
		if(!active[2]) {
			active[3] = false;
			return;
		}
		
		active[3] = true;
		instructions[3] = instructions[2];
		opcodes[2] = opcodes[1];
		WBreg[2] = WBreg[1];
		ALUOut[1] = ALUOut[0];
		
		if(opcodes[2] == 8) {
			LMD = dc.dcache[ALUOut[0]];
		}
		
		else if(opcodes[2] == 9) {
			dc.dcache[ALUOut[0]] = rf.rfile[dReg];
		}
	}

	void WB() {
		if(!active[3]) {
			active[4] = false;
			return;
		}
		
		active[4] = true;
		instructions[4] = instructions[3];
		opcodes[3] = opcodes[2];
		WBreg[3] = WBreg[2];
		ALUOut[2] = ALUOut[1];
		
		if(opcodes[3] < 8) {
			rf.rfile[WBreg[3]] = ALUOut[2];
			wc[WBreg[3]] = false;
		}
		
		else if(opcodes[3] == 8) {
			rf.rfile[WBreg[3]] = LMD;
			wc[WBreg[3]] = false;
		}
		
		if(RAWStall) {
			if(!dRAWstall) {
				if(!wc[RAWReg[0]]) {
					RAWStall = false;
					PC--;
					numRAWStalls++;
				}
			}
			else {
				if(!wc[RAWReg[0]] && !wc[RAWReg[1]]) {
					dRAWstall = false;
					RAWStall = false;
					PC--;
					numRAWStalls++;
				}
			}
		}
		numInst++;
		
		if(opcodes[3] == 15) {
			IC[12]++;
			active[4] = false;

		}
		else {
			IC[opcodes[3]]++;
		}
	}
	void run() {
		int clock = 0;
		bool detect_RAW;
		int RAW_Stall_cycles = 0;
		int Jump_stall_cycles = 0;
		queue<string> Q;
		while(active[0] || active[1] || active[2] || active[3] || active[4] || !halt) {

			clock++;
			WB();
			MEM();
			EX();
			ID();
			IF();

			if(RAWStall){
				detect_RAW = true;
				RAW_Stall_cycles++;
				Q.push("RAW");
			}
			else if(detect_RAW){
				detect_RAW = false;
				RAW_Stall_cycles++;
				Q.push("RAW");
			}
			if(jStall){
				Jump_stall_cycles++;
				Q.push("Branch");
			}
		}
		
		cout << numInst << "\n";
		cout << (IC[0] + IC[1] + IC[2] + IC[3]) << "\n";
		cout << IC[4] + IC[5] + IC[6] + IC[7] << "\n";
		cout << IC[8] + IC[9] << "\n";
		cout << IC[10] + IC[11] << "\n"; 
		cout << (double)clock / numInst << "\n";
		cout << RAW_Stall_cycles + Jump_stall_cycles << "\n";
		int counter_variable_for_this = 1;
		while(!Q.empty()){
			cout << "S" << counter_variable_for_this << " : " << Q.front() << "\n";
			Q.pop();
			counter_variable_for_this++;
		}
		cout << "RAW: " << RAW_Stall_cycles << "\n";
		cout << "Control: " << Jump_stall_cycles << "\n";

		ofstream fwrite("DCache.txt");
		for(int i = 0; i < 256; i++){
			int num = dc.dcache[i];
			if(num <= 0){
				num += 256;
			}
			string str = decToHexa(num);
			fwrite << str << "\n";
		}
	}
};

int main() {
	freopen("output.txt", "w", stdout);
	Processor processor;
	processor.run();
	return 0;
}