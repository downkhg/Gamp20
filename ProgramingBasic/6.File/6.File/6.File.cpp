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
	const int nWidth = 5;
	const int nHeight = 5;
	unsigned char bufferImage[nWidth * nHeight];
	for (int i = 0; i < nWidth * nHeight; i++)
	{
		bufferImage[i] = 10 * i;
	}

	FILE* pFile = fopen("binary.raw", "wb");

	if (pFile)
	{
		fwrite(bufferImage, sizeof(bufferImage), nWidth * nHeight, pFile);
		fclose(pFile);
	}
}
void FileBinaryReadMain()
{
	const int nWidth = 5;
	const int nHeight = 5;
	unsigned char bufferImage[nWidth * nHeight];
	FILE* pFile = fopen("binary.raw", "rb");

	if (pFile)
	{
		fread(bufferImage, sizeof(bufferImage), nWidth * nHeight, pFile);
		fclose(pFile);

		for (int y = 0; y < nHeight; y++)
		{
			for (int x = 0; x < nWidth; x++)
			{
				int nIdx = y * nWidth + x;
				printf("%d,", bufferImage[nIdx]);
			}
			printf("\n");
		}

		/*for (int i = 0; i < nWidth * nHeight; i++)
		{
			if (i % 5 == 0) printf("\n");
			printf("%d,", bufferImage[i]);
		}*/
	}
}

void main()
{
	//FileTextWirteMain();
	//FileTextReadMain();
	//FileBinaryWirteMain();
	FileBinaryReadMain();
}