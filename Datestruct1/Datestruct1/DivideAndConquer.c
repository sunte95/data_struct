#include<stdio.h>
#include<stdlib.h>
int Max3(int A, int B, int C) {   /*����3�������е����ֵ*/

	return A > B ? A > C ? A : C : B > C?B:C;
	system("pause");
}
int DivideAndConquer(int List[], int left, int right) { /*���η���List[left]��List[right]��������к�*/
	int MaxLeftSum, MaxRightSum;  /*�������������Ľ�*/
	int MaxLeftBorderSum, MAxRightBorderSum;/*��ſ�ֽ��ߵĽ��*/
	int LeftBorderSum, RightBorderSum;
	int  center, i;
	if (left == right) {     /*�ݹ����ֹ������������ֻ��1������*/
		if (List[left] > 0)
			return List[left];
		else
			return 0;
	}
	/*�����ǡ��֡��Ĺ���*/
	center = (left + right) / 2; /*�ҵ��зֵ�*/
	/*�ݹ����������е�����*/
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);
	/*�������ֽ��ߵ�������к�*/
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) {  /*����������ɨ��*/
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;

	}
	MAxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; 1 <= right; i++) {/*����������ɨ��*/
		RightBorderSum += List[i];
		if (RightBorderSum > MAxRightBorderSum)
			MAxRightBorderSum = RightBorderSum;


	}
	/*���淵�ء��Ρ��Ľ��*/
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MAxRightBorderSum);
	system("pause");
}
int MaxsubseqSum3(int List[], int N) {   /*������ǰ2���㷨��ͬ�ĺ����ӿ�*/
	return DivideAndConquer(List, 0, N - 1);
}