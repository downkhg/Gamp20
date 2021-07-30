#include <stdio.h>

void ArrayMain()
{
	const int nSize = 5;
	int arrScores[nSize] = {100,90,80,70,60};
	int nMemorySize = sizeof(arrScores);
	int nArraySize = nMemorySize / sizeof(arrScores[0]);
	printf("MemorySize/ArraySize:%d/%d\n",nMemorySize,nArraySize);

	/*arrScores[0] = 100;
	arrScores[1] = 90;
	arrScores[2] = 80;
	arrScores[3] = 70;
	arrScores[4] = 60;*/

	for (int i = 0; i < 5; i++)
		printf("[%d]%d,", i, arrScores[i]);
	printf("\n");

	int arrCopyScore[nSize];
	//arrCopyScore = arrScores;
	printf("Score/CopyScore:%d/%d\n",arrCopyScore,arrScores);
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScores[i];
}
//�迭���� �ּҰ��� ã�Ƽ� ����϶�.
//(�ּҰ�, �迭������ ���� ���� ���� ã�°�)
//������: 30,40,50,10,20, �ּҰ��� �˻��ϱ����� ������ ����
//�˰���: 
//���迭�� ���� ���ؼ� ���� ���� ���� �������� ã�´�.
//ù��°���� �����ϰ�, ����Ȱ����� ���� ���� ������ ���� �ּҰ����� ��ä�Ѵ�.
void ArrayFindMinDataMain()
{
	int arrData[5] = { 10,20,30,60,70 };
	int nMin = arrData[0];

	for(int i = 0; i<5; i++)
	{
		if (nMin < arrData[i])
		{
			nMin = arrData[i];
		}
	}
	printf("Min:%d\n",nMin);
}

void main()
{
	ArrayMain();
}