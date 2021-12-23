#include <stdio.h>

double percent_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS); //퍼센트농도

double ppm_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS);  //ppm농도

double molality_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double VOS, double DOS);  //몰랄농도

double molar_C(double MOSolute, double MWOS, double MolOfSolute, double VOS, double MOSolution, double DOS, double MOSolvent);  //몰농도


int main()
{
	double MOSolute = 1; //용질의 질량
	double MOSolution = 1; //용액의 질량
	double MOSolvent = 1; //용매의 질량
	double MWOS = 1; //용질의 화학식량
	double MolOfSolute = 1; //용질의 몰수
	double VOS = 1; //용액의 부피
	double DOS = 1; //용액의 밀도
	
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n\n");
	printf(" 용질의 질량(g) : "); //용질의 질량
	scanf_s("%lf", &MOSolute);
	printf("\n 용액의 질량(g) : "); //용액의 질량
	scanf_s("%lf", &MOSolution);
	printf("\n 용매의 질량(g) : "); //용매의 질량
	scanf_s("%lf", &MOSolvent);
	printf("\n 용질의 화학식량(g/mol) : "); //용질의 화학식량
	scanf_s("%lf", &MWOS);
	printf("\n 용질의 몰수(mol) : "); //용질의 몰수
	scanf_s("%lf", &MolOfSolute);
	printf("\n 용액의 부피(L) : "); //용액의 부피
	scanf_s("%lf", &VOS);
	printf("\n 용액의 밀도(g/mL) : "); //용액의 밀도
	scanf_s("%lf", &DOS);
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n");

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n┃ 퍼센트농도(%%) : "); printf("%0.2f", percent_C(MOSolute, MOSolution, MOSolvent, MWOS, MolOfSolute, DOS, VOS)); printf("(%%)"); //퍼센트 농도 출력
	printf("\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	printf("\n┃ ppm농도(ppm) : "); printf("%0.2f", ppm_C(MOSolute, MOSolution, MOSolvent, MWOS, MolOfSolute, DOS, VOS)); printf("(ppm)");      //ppm 농도 출력
	printf("\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	printf("\n┃ 몰랄농도(m) : "); printf("%0.2f", molality_C(MOSolute, MOSolution, MOSolvent, MWOS, MolOfSolute,VOS, DOS)); printf("(m)"); //몰랄 농도 출력
	printf("\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	printf("\n┃ 몰농도(M) : "); printf("%0.2f", molar_C(MOSolute, MWOS, MolOfSolute, VOS, MOSolution, DOS, MOSolvent)); printf("(M)");    //몰농도 출력
	printf("\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"); printf("\n\n\n\n\n\n");

	return 0;
}

double percent_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS) {  //퍼센트농도
	double result = 0;
	if (!(MOSolute == 0)) {             //용질의 질량값이 주어질 때
		if (!(MOSolution == 0)) {        // 용액의 질량값이 주어지면
			result = (MOSolute / MOSolution) * 100;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //용매의 질량값이 주어지면
			result = (MOSolute / (MOSolute + MOSolvent)) * 100;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MWOS == 0 && MolOfSolute == 0)) { //용질의 화학식량과 용질의 몰수가 주어질 때
		MOSolute = MWOS * MolOfSolute; // 용질의 질량 = 용질의 화학식량 x 용질의 몰수
		if (!(MOSolution == 0)) {        // 용액의 질량값이 주어지면
			result = (MOSolute / MOSolution) * 100;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //용매의 질량값이 주어지면
			result = (MOSolute / (MOSolute + MOSolvent)) * 100;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(VOS == 0) && !(DOS == 0)) {  // 용액의 부피와 용액의 밀도가 주어질 때
		VOS = VOS * 1000; // L -> mL 변환
		MOSolution = VOS * DOS;
		if (!(MolOfSolute) && !(MWOS == 0)) {  // 용질의 화학식량, 용질의 몰수가 주어지면
			result = ((MolOfSolute * MWOS) / MOSolution) * 100;
			return result;
		}
		else if (!(MOSolute == 0)) { //용질의 질량이 주어지면
			result = (MOSolute / MOSolution) * 100;
			return result;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

double ppm_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS) {  //ppm농도
	double result = 0;
	if (!(MOSolute == 0)) {             //용질의 질량값이 주어질 때
		if (!(MOSolution == 0)) {        // 용액의 질량값이 주어지면
			result = (MOSolute / MOSolution) * 1000000;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //용매의 질량값이 주어지면
			result = (MOSolute / (MOSolute + MOSolvent)) * 1000000;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MWOS == 0) && !(MolOfSolute == 0)) { //용질의 화학식량과 용질의 몰수가 주어질 때
		MOSolute = MWOS * MolOfSolute; // 용질의 질량 = 용질의 화학식량 x 용질의 몰수
		if (!(MOSolution == 0)) {        // 용액의 질량값이 주어지면
			result = (MOSolute / MOSolution) * 1000000;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //용매의 질량값이 주어지면
			result = (MOSolute / (MOSolute + MOSolvent)) * 1000000;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(VOS == 0) && !(DOS == 0)) {  // 용액의 부피와 용액의 밀도가 주어질 때
		VOS = VOS * 1000; // L -> mL 변환
		MOSolution = VOS * DOS;
		if (!(MolOfSolute) && !(MWOS == 0)) {  // 용질의 화학식량, 용질의 몰수가 주어지면
			result = ((MolOfSolute * MWOS) / MOSolution) * 1000000;
			return result;
		}
		else if (!(MOSolute == 0)) {
			result = (MOSolute / MOSolution) * 1000000;
			return result;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

double molality_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double VOS, double DOS) {  //몰랄농도
	MOSolvent = MOSolvent / 1000;
	double result = 0;
	if (!(MolOfSolute == 0)) {  //용질의 몰수가 주어졌을 때
		if (!(MOSolvent == 0)) { //용매의 질량이 주어지면
			result = (MolOfSolute / MOSolvent);
			return result;
		}
		else if (!(MOSolution == 0) && !(MOSolute == 0)) {  //용액의 질량, 용질의 질량이 주어지면
			result = (MolOfSolute / (MOSolution - MOSolute));
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolution == 0)) {  //용질의 화학식량, 용액의 질량이 주어지면
			result = (MolOfSolute / ((MOSolution - (MWOS * MolOfSolute)) * 1000));
			return result;
		}
		else if (!(VOS == 0) && !(DOS == 0) && !(MOSolute == 0)) { // 용액의 부피, 용액의 밀도, 용질의 질량이 주어지면
			VOS *= 1000;
			result = MolOfSolute / ((VOS * DOS) - MOSolute);
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MWOS == 0) && !(MOSolute == 0)) {  //용질의 화학식량, 용질의 질량이 주어졌을 때
		MolOfSolute = MOSolute / MWOS;                 // 용질의 몰수 = 용질의 질량/용질의 화학식량
		if (!(MOSolvent == 0)) {                            //용매의 질량이 주어지면
			result = MolOfSolute / MOSolvent;
			return result;
		}
		else if (!(MOSolution == 0)) {  //용액의 질량이 주어지면
			result = MolOfSolute / (MOSolution - MOSolute);
			return result;
		}
		else if (!(VOS == 0) && !(DOS == 0)) { //용액의 부피와 용액의 밀도가 주어졌을 때
			VOS *= 1000; // L -> mL로 변환
			MOSolution = VOS * DOS; // 용액의 질량 = 용액의 부피 x 용액의 밀도
			result = (MolOfSolute / (MOSolution - MOSolute));
			return result;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

double molar_C(double MOSolute, double MWOS, double MolOfSolute, double VOS, double MOSolution, double DOS, double MOSolvent) {
	double result = 0;
	if (!(VOS == 0)) { //용액의 부피가 주어졌을 때
		if (!(MolOfSolute == 0)) {  //용질의 몰수가 주어지면
			result = MolOfSolute / VOS;
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolute == 0)) {  //용질의 화학식량과 용질의 질량이 주어지면
			result = (MOSolute / MWOS) / VOS;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MOSolution == 0) && !(DOS == 0)) { //용액의 질량, 용액의 밀도가 주어질 때
		VOS = (MOSolution / DOS) / 1000;
		if (!(MolOfSolute == 0)) { //용질의 몰수가 주어지면
			result = MolOfSolute / VOS;
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolute == 0)) { //용질의 화학식량, 용질의 질량이 주어지면
			result = (MOSolute / MWOS) / VOS;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MOSolute == 0) && !(MOSolvent == 0) && !(DOS == 0)) { //용질의 질량, 용매의 질량, 용액의 밀도가 주어질 때
		MOSolution = MOSolute + MOSolvent;
		VOS = (MOSolution / DOS) / 1000;
		if (!(MolOfSolute == 0)) { //용질의 몰수가 주어지면
			result = MolOfSolute / VOS;
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolute == 0)) { //용질의 화학식량, 용질의 질량이 주어지면
			result = (MOSolute / MWOS) / VOS;
			return result;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
