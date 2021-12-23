#include <stdio.h>

double percent_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS); //�ۼ�Ʈ��

double ppm_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS);  //ppm��

double molality_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double VOS, double DOS);  //������

double molar_C(double MOSolute, double MWOS, double MolOfSolute, double VOS, double MOSolution, double DOS, double MOSolvent);  //����


int main()
{
	double MOSolute = 1; //������ ����
	double MOSolution = 1; //����� ����
	double MOSolvent = 1; //����� ����
	double MWOS = 1; //������ ȭ�нķ�
	double MolOfSolute = 1; //������ ����
	double VOS = 1; //����� ����
	double DOS = 1; //����� �е�
	
	printf("\n");
	printf("������������������������������������������������������������������������\n\n");
	printf(" ������ ����(g) : "); //������ ����
	scanf_s("%lf", &MOSolute);
	printf("\n ����� ����(g) : "); //����� ����
	scanf_s("%lf", &MOSolution);
	printf("\n ����� ����(g) : "); //����� ����
	scanf_s("%lf", &MOSolvent);
	printf("\n ������ ȭ�нķ�(g/mol) : "); //������ ȭ�нķ�
	scanf_s("%lf", &MWOS);
	printf("\n ������ ����(mol) : "); //������ ����
	scanf_s("%lf", &MolOfSolute);
	printf("\n ����� ����(L) : "); //����� ����
	scanf_s("%lf", &VOS);
	printf("\n ����� �е�(g/mL) : "); //����� �е�
	scanf_s("%lf", &DOS);
	printf("\n������������������������������������������������������������������������\n\n\n");

	printf("����������������������������������������������������������������������");
	printf("\n�� �ۼ�Ʈ��(%%) : "); printf("%0.2f", percent_C(MOSolute, MOSolution, MOSolvent, MWOS, MolOfSolute, DOS, VOS)); printf("(%%)"); //�ۼ�Ʈ �� ���
	printf("\n����������������������������������������������������������������������");
	printf("\n�� ppm��(ppm) : "); printf("%0.2f", ppm_C(MOSolute, MOSolution, MOSolvent, MWOS, MolOfSolute, DOS, VOS)); printf("(ppm)");      //ppm �� ���
	printf("\n����������������������������������������������������������������������");
	printf("\n�� ������(m) : "); printf("%0.2f", molality_C(MOSolute, MOSolution, MOSolvent, MWOS, MolOfSolute,VOS, DOS)); printf("(m)"); //���� �� ���
	printf("\n����������������������������������������������������������������������");
	printf("\n�� ����(M) : "); printf("%0.2f", molar_C(MOSolute, MWOS, MolOfSolute, VOS, MOSolution, DOS, MOSolvent)); printf("(M)");    //���� ���
	printf("\n����������������������������������������������������������������������"); printf("\n\n\n\n\n\n");

	return 0;
}

double percent_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS) {  //�ۼ�Ʈ��
	double result = 0;
	if (!(MOSolute == 0)) {             //������ �������� �־��� ��
		if (!(MOSolution == 0)) {        // ����� �������� �־�����
			result = (MOSolute / MOSolution) * 100;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //����� �������� �־�����
			result = (MOSolute / (MOSolute + MOSolvent)) * 100;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MWOS == 0 && MolOfSolute == 0)) { //������ ȭ�нķ��� ������ ������ �־��� ��
		MOSolute = MWOS * MolOfSolute; // ������ ���� = ������ ȭ�нķ� x ������ ����
		if (!(MOSolution == 0)) {        // ����� �������� �־�����
			result = (MOSolute / MOSolution) * 100;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //����� �������� �־�����
			result = (MOSolute / (MOSolute + MOSolvent)) * 100;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(VOS == 0) && !(DOS == 0)) {  // ����� ���ǿ� ����� �е��� �־��� ��
		VOS = VOS * 1000; // L -> mL ��ȯ
		MOSolution = VOS * DOS;
		if (!(MolOfSolute) && !(MWOS == 0)) {  // ������ ȭ�нķ�, ������ ������ �־�����
			result = ((MolOfSolute * MWOS) / MOSolution) * 100;
			return result;
		}
		else if (!(MOSolute == 0)) { //������ ������ �־�����
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

double ppm_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double DOS, double VOS) {  //ppm��
	double result = 0;
	if (!(MOSolute == 0)) {             //������ �������� �־��� ��
		if (!(MOSolution == 0)) {        // ����� �������� �־�����
			result = (MOSolute / MOSolution) * 1000000;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //����� �������� �־�����
			result = (MOSolute / (MOSolute + MOSolvent)) * 1000000;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MWOS == 0) && !(MolOfSolute == 0)) { //������ ȭ�нķ��� ������ ������ �־��� ��
		MOSolute = MWOS * MolOfSolute; // ������ ���� = ������ ȭ�нķ� x ������ ����
		if (!(MOSolution == 0)) {        // ����� �������� �־�����
			result = (MOSolute / MOSolution) * 1000000;
			return result;
		}
		else if (!(MOSolvent == 0)) {   //����� �������� �־�����
			result = (MOSolute / (MOSolute + MOSolvent)) * 1000000;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(VOS == 0) && !(DOS == 0)) {  // ����� ���ǿ� ����� �е��� �־��� ��
		VOS = VOS * 1000; // L -> mL ��ȯ
		MOSolution = VOS * DOS;
		if (!(MolOfSolute) && !(MWOS == 0)) {  // ������ ȭ�нķ�, ������ ������ �־�����
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

double molality_C(double MOSolute, double MOSolution, double MOSolvent, double MWOS, double MolOfSolute, double VOS, double DOS) {  //������
	MOSolvent = MOSolvent / 1000;
	double result = 0;
	if (!(MolOfSolute == 0)) {  //������ ������ �־����� ��
		if (!(MOSolvent == 0)) { //����� ������ �־�����
			result = (MolOfSolute / MOSolvent);
			return result;
		}
		else if (!(MOSolution == 0) && !(MOSolute == 0)) {  //����� ����, ������ ������ �־�����
			result = (MolOfSolute / (MOSolution - MOSolute));
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolution == 0)) {  //������ ȭ�нķ�, ����� ������ �־�����
			result = (MolOfSolute / ((MOSolution - (MWOS * MolOfSolute)) * 1000));
			return result;
		}
		else if (!(VOS == 0) && !(DOS == 0) && !(MOSolute == 0)) { // ����� ����, ����� �е�, ������ ������ �־�����
			VOS *= 1000;
			result = MolOfSolute / ((VOS * DOS) - MOSolute);
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MWOS == 0) && !(MOSolute == 0)) {  //������ ȭ�нķ�, ������ ������ �־����� ��
		MolOfSolute = MOSolute / MWOS;                 // ������ ���� = ������ ����/������ ȭ�нķ�
		if (!(MOSolvent == 0)) {                            //����� ������ �־�����
			result = MolOfSolute / MOSolvent;
			return result;
		}
		else if (!(MOSolution == 0)) {  //����� ������ �־�����
			result = MolOfSolute / (MOSolution - MOSolute);
			return result;
		}
		else if (!(VOS == 0) && !(DOS == 0)) { //����� ���ǿ� ����� �е��� �־����� ��
			VOS *= 1000; // L -> mL�� ��ȯ
			MOSolution = VOS * DOS; // ����� ���� = ����� ���� x ����� �е�
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
	if (!(VOS == 0)) { //����� ���ǰ� �־����� ��
		if (!(MolOfSolute == 0)) {  //������ ������ �־�����
			result = MolOfSolute / VOS;
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolute == 0)) {  //������ ȭ�нķ��� ������ ������ �־�����
			result = (MOSolute / MWOS) / VOS;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MOSolution == 0) && !(DOS == 0)) { //����� ����, ����� �е��� �־��� ��
		VOS = (MOSolution / DOS) / 1000;
		if (!(MolOfSolute == 0)) { //������ ������ �־�����
			result = MolOfSolute / VOS;
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolute == 0)) { //������ ȭ�нķ�, ������ ������ �־�����
			result = (MOSolute / MWOS) / VOS;
			return result;
		}
		else {
			return 0;
		}
	}
	else if (!(MOSolute == 0) && !(MOSolvent == 0) && !(DOS == 0)) { //������ ����, ����� ����, ����� �е��� �־��� ��
		MOSolution = MOSolute + MOSolvent;
		VOS = (MOSolution / DOS) / 1000;
		if (!(MolOfSolute == 0)) { //������ ������ �־�����
			result = MolOfSolute / VOS;
			return result;
		}
		else if (!(MWOS == 0) && !(MOSolute == 0)) { //������ ȭ�нķ�, ������ ������ �־�����
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
