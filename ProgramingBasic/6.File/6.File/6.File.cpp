#include <iostream>
//파일탭: 오른쪽 > 상위폴더열기 > text.txt파일 확인하기
//텍스트파일: 메모장(txt)
void FileTextWirteMain()
{
	FILE* pFile = fopen("text.txt", "w");
	if (pFile)
	{
		int nSize = 10;
		fprintf(pFile,"%d\n",nSize);//1줄 이상입력할땐 첫줄에 길이를 저장한다.
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
		fscanf(pFile, "%d", &nSize); //첫줄에 저장된길이를 가져와 그만큼 반복하여 읽는다.
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
//바이너리파일: 이미지(dat,raw)
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