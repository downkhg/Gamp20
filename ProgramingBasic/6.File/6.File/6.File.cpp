#include <iostream>
//������: ������ > ������������ > text.txt���� Ȯ���ϱ�
//�ؽ�Ʈ����: �޸���(txt)
void FileTextWirteMain()
{
	FILE* pFile = fopen("text.txt", "w");
	if (pFile)
	{
		int nSize = 10;
		fprintf(pFile,"%d\n",nSize);//1�� �̻��Է��Ҷ� ù�ٿ� ���̸� �����Ѵ�.
		for (int i = 0; i < nSize; i++)
		{
			char strTextBuffer[128];
			sprintf(strTextBuffer, "GamePrograming%d", i);
			fprintf(pFile, "%s\n", strTextBuffer);
		}
		fclose(pFile);
	}
}
void FileTextReadMain()
{
	FILE* pFile = fopen("text.txt", "r");
	if (pFile)
	{
		int nSize;
		fscanf(pFile, "%d", &nSize); //ù�ٿ� ����ȱ��̸� ������ �׸�ŭ �ݺ��Ͽ� �д´�.
		printf("nSize:%d\n", nSize);
		for (int i = 0; i < nSize; i++)
		{
			char strReadBuffer[128];
			fscanf(pFile, "%s", strReadBuffer);
			printf("%s\n", strReadBuffer);
		}
		fclose(pFile);
	}
}
//���̳ʸ�����: �̹���(dat,raw)
void FileBinaryWirteMain()
{

}

void FileBinaryReadMain()
{

}

void main()
{
	FileTextWirteMain();
	FileTextReadMain();
}